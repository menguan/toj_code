#include<stdio.h>//模板 
#include<cstring>
#include<algorithm>
using namespace std;
int map[120][120],low[120],dep[120];
int f[120],n,depth,root;
bool flag[120];
void dfs(int m)
{
     dep[m]=depth;
     low[m]=depth;
     depth++;
     flag[m]=1;
     int i,j,k;
     for(i=1;i<=n;i++){
       if(map[m][i]){
         if(!flag[i]){
            dfs(i);
            low[m]=min(low[m],low[i]);
            if(low[i]>=dep[m]&&m!=1)
              f[m]++;
            else if(m==1)  root++;
         }
         else
           low[m]=min(low[m],dep[i]);
       }
     }
}
int main()
{
    int i,j,k;
    while(scanf("%d",&n),n){
      memset(map,0,sizeof(map));
      memset(f,0,sizeof(f));
      memset(low,0,sizeof(low));
      memset(flag,0,sizeof(flag));
      memset(dep,0,sizeof(dep));
      root =0;
      while(scanf("%d",&k),k){
        while(getchar()!='\n'){
          scanf("%d",&j);
          map[k][j]=map[j][k]=1;
        }
      }
      root=0;
      depth=1;
      dfs(1);
      int ans=0;
      if(root>1)  ans++;
      for(i=2;i<=n;i++)
        if(f[i])  ans++;
     printf("%d\n",ans);
    }
}                             
                                                                           
                      
                      
