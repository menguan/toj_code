#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

using namespace std;

int gcd(int a,int b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}

int extendGCD(int a,int b,int &x,int &y)
{
    if(b==0)
    {
        x=1;
        y=0;
        return a;
    }
    int gcdab=extendGCD(b,a%b,x,y);
    int t=x;
    x=y;
    y=t-a/b*y;
    return gcdab;
}

int main()
{
    int a,b,n;
    while(scanf("%d%d%d",&a,&b,&n)&&(a!=0||b!=0||n!=0))
    {
        int x,y;
        int gcdab=gcd(a,b);
        a/=gcdab;
        b/=gcdab;
        n/=gcdab;
        gcdab=extendGCD(a,b,x,y);
        int newx=((x*n)%b+b)%b;
        int newy=(n-a*newx)/b;
        if(newy<0) newy=-newy;
        y=((y*n)%a+a)%a;
        x=(n-b*y)/a;
        if(x<0) x=-x;
        if(x+y>newx+newy)
            x=newx,y=newy;
        printf("%d %d\n",x,y);
    }
    return 0;
}

