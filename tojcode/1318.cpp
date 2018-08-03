#include<iostream>
#include<cstring>
#include<stdio.h> 
#include<algorithm>
using namespace std;
int t;int n;
int a[50010];
long long b[50010];
long long pre[50010];
long long las[50010];
int len;long long ans;
int main()
{
   scanf("%d",&t);
   while(t--)
   {
     ans=0;
     scanf("%d",&n);
     for(int i=1;i<=n;i++)
       scanf("%d",&a[i]);
     scanf("%d",&len);  
     b[len]=0;
     for(int i=1;i<=len;i++)
     {
        b[len]+=a[i];
     }
     for(int i=len+1;i<=n;i++)
     {
        b[i]=b[i-1]+a[i]-a[i-len];
     }
     pre[len]=b[len];
     for(int i=len+1;i<=n-2*len;i++)
       if(b[i]>pre[i-1])
         pre[i]=b[i];
       else
         pre[i]=pre[i-1];
     las[n]=b[n];
     for(int i=n-1;i>=2*len;i--)
       if(b[i]>las[i+1])
         las[i]=b[i];
       else
         las[i]=las[i+1];
     for(int i=2*len;i<=n-len;i++)
       ans=max(ans,pre[i-len]+b[i]+las[i+len]);            
     printf("%lld\n",ans);
   }
}                 
