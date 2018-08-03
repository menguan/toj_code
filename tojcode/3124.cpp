#include<iostream>
#include<cstring>
#include<cmath>
#define eps 0.5
using namespace std;
struct po
{
   double x,y;
}p[10010];
int n;       
double area(){//求任意多边形面积 
    double s;
    s = p[0].y * (p[n-1].x-p[1].x);
    for(int i = 1; i < n; i ++)
        s += p[i].y * (p[i-1].x-p[(i+1)%n].x);
    return fabs(s/2);
}
int main()
{
    while(cin>>n,n)
    {
       for(int i=0;i<n;i++)
         cin>>p[i].x>>p[i].y;
       if(n<=2)
         cout<<0<<endl;
       else    
         cout<<(int)(area()+eps)<<endl;
    }
}                 
