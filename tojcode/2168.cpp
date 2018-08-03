#include<iostream>
#include<string>
#include<algorithm>
#include<map>
#include<vector>
#include<cstring>
using namespace std;
string s[100010];
pair<char,int> score[20];
int n;int m;int p;long long ans;
bool vis[20];
void dfs(int pos)
{
     
     string str="";
     long long ret=0;
     for(int i=0;i<p;i++)
     {
         if(vis[i])
         {
              str+=score[i].first;
              ret+=score[i].second;
         }
     }
     //cout<<pos<<" "<<str<<" "<<ret<<endl;
     //system("pause");
     if(ret>ans)
     {
       //cout<<ret<<endl;
       if(binary_search(s,s+n,str))
         ans=ret;
     }
     if(pos==p)
       return ;
     vis[pos]=1;  
     dfs(pos+1);
     vis[pos]=0;
     dfs(pos+1);
}             
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
         cin>>s[i];
         sort(s[i].begin(),s[i].end());
    }
    sort(s,s+n);
    cin>>m;
    while(m--)
    {
       memset(vis,0,sizeof(vis));
       cin>>p;
       ans=0;
       for(int i=0;i<p;i++)
       {
           cin>>score[i].first>>score[i].second;
       }
       sort(score,score+p);
      // for(int i=0;i<p;i++)
      //   cout<<score[i].first<<" "<<score[i].second<<endl;
       dfs(0);
       cout<<ans<<endl;
    }
    //while(1);
}                         
    
