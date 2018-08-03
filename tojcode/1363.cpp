#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int g[310][310];
int main(){
    char str[30];
    int n;
    while(cin>>n,n)
    {
        memset(g,0,sizeof(g));
        int u,v;
        while(cin>>u>>v&&u+v)
        {
            scanf("%s",str);
            for(int i=0;i<strlen(str);i++)
                g[u][v]=g[u][v]|(1<<(str[i]-'a'));
        }

        int i,j,k;
        for(k=1;k<=n;k++)
            for(i=1;i<=n;i++)
                for(j=1;j<=n;j++)
                    if(g[i][k]&g[k][j])
                        g[i][j]=g[i][j] | (g[i][k] & g[k][j]);

        while(cin>>u>>v&&u+v)
        {
            if(g[u][v])
            {
                int num=g[u][v];
                int tt=0;
                while(num){
                  if(num&1)
                  cout<<(char)('a'+tt);
                  tt++;
                  num>>=1;
                }
                cout<<endl;
            }
            else
                cout<<'-'<<endl;
        }
        cout<<endl;
    }
    return 0;
}
