#include<iostream>
#include<cstring>
#include<vector>
#include<ctype.h>
using namespace std;
int in[30];
char map[60][30];
int con[30][30];
bool vis[30];
bool used[30];
vector<int> ans;
int main()
{
    int n;
    while(cin>>n)
    {
        ans.clear();
        memset(con,0,sizeof(con));
        memset(in,0,sizeof(in));
        memset(vis,0,sizeof(vis));
        memset(used,0,sizeof(used));
        for(int i=0;i<n;i++)
        {
           for(int j=0;j<20;j++)
           {
               cin>>map[i][j];
               if(isupper(map[i][j]))
                 vis[map[i][j]-'A']=1;
           }
        }
        for(int i=n-1;i>0;i--)
        {
           for(int j=0;j<20;j++)
           {
               if(map[i][j]!=map[i-1][j])
               {
                  if(isupper(map[i][j])&&isupper(map[i-1][j]))
                  {
                     if(con[map[i][j]-'A'][map[i-1][j]-'A']==0)
                     {
                       con[map[i][j]-'A'][map[i-1][j]-'A']=1;
                       in[map[i-1][j]-'A']++;
                     }
                  }
               }
           }
        }
        int sum=0;
        int cnt=0;
        for(int i=0;i<30;i++)
          if(vis[i])
            sum++;
        while(cnt<sum)
        {
            for(int i=0;i<30;i++)
            {
                if(vis[i]&&!used[i])
                {
                   if(in[i]==0)
                   {
                       ans.push_back(i);
                       used[i]=1;
                       cnt++;
                       for(int j=0;j<30;j++)
                       {
                          if(con[i][j])
                            in[j]--;
                       }
                       break;
                   }
                }
            }
        }
        for(int i=0;i<sum;i++)
          cout<<(char)(ans[i]+'A');
        cout<<endl;
    }
}  
                                                                                                                                                                     
