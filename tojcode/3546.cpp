#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
bool vis[20010];
int prime[10010];
int ans[20010];
int main()
{
    memset(vis,0,sizeof(vis));
    int cnt=0;
    for(int i=2;i<=20000;i++)
    {
         if(!vis[i])
         {
              prime[cnt++]=i;
              for(int j=i+i;j<=20000;j+=i)
              {
                   vis[j]=1;
              }   
         }    
    }
    //cout<<cnt<<endl;
   // system("pause");
    memset(ans,0,sizeof(ans));
    /*
    for(int i=1;i<=2000;i++)
    {
          if(i%100==0)
          cout<<i<<endl;
          if(i%2==0)
          {
               for(int j=1;j<cnt;j++)
               {
                    if(prime[j]>i/2)
                      break;
                    for(int k=j+1;k<cnt;k++)
                    {
                          if(prime[k]+prime[j]>i)
                            break;
                          if(prime[k]+prime[j]==i)
                            ans[i]++;
                    }
               }
          }   
          else
          {
             for(int j=1;j<cnt;j++)
               {
                    if(prime[j]>i/3)
                      break;
                    for(int k=j+1;k<cnt;k++)
                    {
                          if(prime[k]+prime[j]>i*2/3)
                            break;
                          for(int l=k+1;l<cnt;l++)
                          {
                                    
                            if(prime[k]+prime[j]+prime[l]>i)
                              break;
                            if(prime[k]+prime[j]+prime[l]==i)  
                              ans[i]++;
                          }
                    }
               }
          }             
    }
    */
    for(int i=1;i<cnt;i++)
	{
		for(int j=0;prime[i]+j<20000;j+=2)
			ans[prime[i]+j]+=ans[j];
        for(int j=1;j<i&&prime[i]+prime[j]<=20000;j++)
    	     ans[prime[i]+prime[j]]++;
    }             
    int n;
    while(cin>>n)
      cout<<ans[n]<<endl;
}    
