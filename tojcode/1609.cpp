#include<iostream>
#include<cstring>
using namespace std;
int de[30];
int flag[30];
int main()
{
  int n,m,c,count=1;
  while(cin>>n>>m>>c&&(n||m||c))
  {
    memset(flag,0,sizeof(flag));
    int maxn=0;
    int now=0;
    for(int i=1;i<=n;i++)
      cin>>de[i];
    int op;
    bool be=0;
    while(m--)
    {
       cin>>op;
       if(flag[op]==0)
       {
         flag[op]=1;
         now+=de[op];
         if(now>c)
           be=1;
         if(now>maxn)
           maxn=now;
       }
       else
       {
         flag[op]=0;
         now-=de[op];
       }
     }
     cout<<"Sequence "<<count++<<endl;
     if(be)
     {
       cout<<"Fuse was blown."<<endl<<endl;
     }
     else
     {
       cout<<"Fuse was not blown."<<endl;
       cout<<"Maximal power consumption was "<<maxn<<" amperes."<<endl<<endl;
     }
   }
 }      

  
          
           
       
       
       