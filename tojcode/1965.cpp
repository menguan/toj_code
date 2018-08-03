#include<cstring>
#include<iostream>
using namespace std;
int n;
int a[25][4];
int b[25];
int pos[25];
int cnt;
int dfs(int dep)
{
     int i;
     if(dep==n*n)
     {
         return 1;
     }
     else
     {
         for(i=0;i<cnt;i++)
         {
            if(b[i]==0)
            {
               continue;
            }
            else
            {
               if(dep>=n)
               {
                     if(a[pos[dep-n]][2]!=a[i][0])
                     {
                            continue;
                     }
               }
               if(dep%n!=0)
               {
                      if(a[pos[dep-1]][1]!=a[i][3])
                      {
                             continue;
                      }
               }
               b[i]--;
               pos[dep]=i;
               if(dfs(dep+1)==1)
                    return 1;
               else
                   b[i]++;
            }
         }
     }
     return 0;
}
int main()
{
    int i,j,cas=0;
    int e,r,t,y;
    while(cin>>n,n)
    {
          if(cas) cout<<endl;
          cas++;
          cnt=0;
          memset(b,0,sizeof(b));
          memset(a,0,sizeof(a));
          memset(pos,0,sizeof(pos));
          for(i=0;i<n*n;i++)
          {
             cin>>e>>r>>t>>y;
             for(j=0;j<cnt;j++)
             {
                  if(a[j][0]==e&&a[j][1]==r&&a[j][2]==t&&a[j][3]==y)
                         {
                             
                           b[j]++;
                            break;
                         }
             }
             if(j==cnt)
             {
                  a[cnt][0]=e;
                  a[cnt][1]=r;
                  a[cnt][2]=t;
                  a[cnt][3]=y;
                  b[cnt]=1;
                  cnt++;
             }
          }
          if(dfs(0))
          {
             cout<<"Game "<<cas<<": Possible"<<endl;
          }
          else
          {
             cout<<"Game "<<cas<<": Impossible"<<endl;
          }

    }

}
