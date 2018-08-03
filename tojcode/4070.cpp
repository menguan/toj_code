#include<iostream>
#include<cstring>
#include<queue>//1r 2 g 3 b
using namespace std;
char map[50];
bool visit[50];
bool flag=0;
int ans;
void dfs(int now,int len,char co,int cost)
{
     if(now==len)
     {
       flag=1;
       if(ans>cost)
         ans=cost;
       return;  
         }                  
     for(int i=now;i<len;i++)
     {
       
       if(map[i]=='G'&&co=='R'&&visit[i]==0)
       {
         visit[i]=1;
         dfs(i+1,len,'G',cost+(i-now+1)*(i-now+1));
         visit[i]=0;
         }
       else if(map[i]=='B'&&co=='G'&&visit[i]==0)
       {
         visit[i]=1;
         dfs(i+1,len,'B',cost+(i-now+1)*(i-now+1));
         visit[i]=0;
         }
       else if(map[i]=='R'&&co=='B'&&visit[i]==0)
       {
         visit[i]=1;
         dfs(i+1,len,'R',cost+(i-now+1)*(i-now+1));
         visit[i]=0;
         }
          
     }
     return ;
}        
                                           
int main()
{ 
    int t;
    cin>>t;
    while(t--)
    {
      memset(visit,0,sizeof(visit));
      cin>>map;
      ans=1000000000;
      visit[0]=1;
      int len=strlen(map);
      
      dfs(1,len,'R',0);
      if(flag==0||ans==1000000000)
        cout<<"-1"<<endl;
      else  
      cout<<ans<<endl;
}      
    }           
