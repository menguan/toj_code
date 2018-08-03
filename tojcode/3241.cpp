#include<iostream>
#include<cstring>
using namespace std;
int t;
int prime[500000];
int pnum;
bool vis[1000010];
bool is[1000010];
void init()
{
   pnum=0;
   for(int i=2;i<1000010;i++)
   {
       if(!vis[i])
       {
           prime[pnum++]=i;
           for(int j=i+i;j<1000010;j+=i)
           {
               vis[j]=1;
           }
       }
   }
   for(int i=0;i<pnum;i++)
   {
           if(prime[i]*prime[i]>1000000)
             break;
           else
             is[prime[i]*prime[i]]=1;
   }            
}
int main()
{
  memset(vis,0,sizeof(vis));
  memset(is,0,sizeof(is));
  init();
  
  cin>>t;
  int y;
  while(t--)
  {      
    cin>>y;
    if(y%2&&y>4&&is[y-4])
      cout<<"yes"<<endl;
    else
      cout<<"no"<<endl;
  }
}    
        
                               
   
