#include<iostream>
#include<cstring>
#include<stdio.h>
using namespace std;
int a[100010];
int big[100010];
int sml[100010];
int bef[300010];
int aft[300010];
int main()
{
    int N,B;int q;
    memset(bef,0,sizeof(bef));
    memset(aft,0,sizeof(aft));
    long long ans=0;
    scanf("%d%d",&N,&B);
    for(int i=1;i<=N;i++)
    {  scanf("%d",&a[i]);
       if(B==a[i])
         q=i;
    }      
    big[0]=sml[0]=0;
    for(int i=1;i<=N;i++)
    {
         big[i]=big[i-1];
         sml[i]=sml[i-1];
         if(a[i]<B)  big[i]++;
         else if(a[i]>B)  sml[i]++;
    }
    for(int i=0;i<q;i++)
    {
      bef[big[i]-sml[i]+N]++;
      //cout<<big[i]<<" "<<sml[i]<<" "<<bef[big[i]-sml[i]+N]<<endl;
    }
    for(int i=q;i<=N;i++)
    {
      aft[big[i]-sml[i]+N]++;
      //cout<<big[i]<<" "<<sml[i]<<" "<<bef[big[i]-sml[i]+N]<<endl;
    }
    for(int i=0;i<2*N+1;i++)
        ans+=bef[i]*aft[i];
    cout<<ans<<endl;
    //while(1);
}           
