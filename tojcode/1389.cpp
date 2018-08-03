#include<iostream>
#include<cstring>
using namespace std;
bool map[200][200];
int n,m;
bool judge(int p,int q)
{
     for(int i=1;i<=m;i++)
        if(map[p][i]!=map[q][i])
          return 0;
    return 1;
}      
int f()
{
    int i,j;int ret=1;
    for(i=2;i<=n;i++)
    {
         for(j=1;j<i;j++)
         {
             if(judge(i,j))
               break;
         }
         if(j==i)
           ret++;
    }
    return ret;
}               
int main()
{
    cin>>n>>m;
    int a,b;
    memset(map,0,sizeof(map));
    while(cin>>a>>b)
    {
        map[a][b]=1;          
    }
    cout<<f()<<endl;
    //while(1);
}      
