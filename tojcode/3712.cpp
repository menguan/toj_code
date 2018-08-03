#include<iostream>
#include<stdio.h>
#include<cstring>
using namespace std;
int h[100010];
int up[100010];
int down[100010];
int n;
int main()
{
    int start;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&h[i]);
        up[i]=down[i]=1;
    }
       
        int ans=-1;
        for(int i=1;i<n;i++)
          if(h[i]>=h[i-1])
            up[i]=up[i-1]+1;
        for(int i=n-2;i>=0;i--)
          if(h[i]>=h[i+1])
            down[i]=down[i+1]+1;
        for(int i=0;i<n;i++)
        {
           if(up[i]+down[i]-1>ans)
             ans=up[i]+down[i]-1;
        }
        cout<<ans<<endl;
    //while(1);
}       