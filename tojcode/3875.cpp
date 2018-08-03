#include<iostream>
#include<stdio.h>
#include<cstring>
#include<algorithm>
using namespace std;
struct f
{
  int dps,health;
} ri[30];    
int n;
bool cmp(f mm,f nn)
{
     if(mm.dps*nn.health==mm.health*nn.dps)
     {
           return mm.health<nn.health;
     }
     return mm.dps*nn.health>mm.health*nn.dps;
}
                                
int main()
{
    while(~scanf("%d",&n))
    {
       memset(ri,0,sizeof(ri));
       int ans=0;
       int sumdps=0;
       for(int i=0;i<n;i++)
       {
          scanf("%d%d",&ri[i].dps,&ri[i].health);
            sumdps+=ri[i].dps;
       }
       sort(ri,ri+n,cmp);
       for(int i=0;i<n;i++)
       {
         ans+=(sumdps*ri[i].health);
         sumdps-=ri[i].dps;
       }
       cout<<ans<<endl;
    }
}                                 
