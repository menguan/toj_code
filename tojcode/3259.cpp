#include<iostream>
#include<cstring>
using namespace std;
bool vis[1000200];
int num[1000200];
void init()
{
     memset(vis,0,sizeof(vis));
     memset(num,0,sizeof(num));
     for(int i=1;i<1000200;i++)
     {
          for(int j=i;j<1000200;j+=i)
            num[j]++;
     }
     for(int i=1;i<1000200;i++)
     {
          if(i%num[i]==0)
            vis[i]=1;
     }          
}
int fac(int p)
{
    int ret=0;
    for(int i=1;i*i<=p;i++)
    {
            if(i*i==p)
              ret++;
            else if(p%i==0)
              ret+=2;
    }
    return ret;
}          
                
int main()
{
    init();
    /*vis[2]=1;
    vis[1]=1;
    
    for(int i=1;i<=1000000;i++)
    {
        if(vis[i])
        {
             if(i%fac(i)!=0)
               vis[i]=0;
        }
    }*///for(int i=0;i<10;i++){ if(vis[i])  cout<<i<<endl;}
    int low,high;
    while(cin>>low>>high)
    {
        int count=0;
        for(int i=low;i<=high;i++)
        {  if(vis[i]) count++;}
        cout<<count<<endl;
    }
}
