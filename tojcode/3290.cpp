#include<iostream>
#include<cstring>
#include<stdio.h>
#include<algorithm>
using namespace std;
long long a[10010];int n;
int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        cin>>n;
        for(int i=0;i<n;i++)
            cin>>a[i];
        if(n%2)
          a[n++]=0;
        int now=0;
        sort(a,a+n);
        for(int i=0;i<n;i+=2)
            now^=(a[i+1]-a[i]);
        if(now)
            puts("windy will win");
        else
            puts("wqb will win");
    }
}
