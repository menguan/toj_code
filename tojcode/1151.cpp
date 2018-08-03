#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
#define MAXN 1010
int map[MAXN][MAXN];
int next[MAXN];
int head;
int n;
int in[MAXN];
int out[MAXN];
int vis[MAXN];
vector<int> e[MAXN];
int main()
{
    int i, j, k;
    while(cin>>n)
    {
        memset(out,0,sizeof(out));
        memset(in,-1,sizeof(in));
        memset(vis,0,sizeof(vis));
        for(int i=0;i<n;i++)
        {
            e[i].clear();
            for(int j=0;j<n;j++)
            {
               cin>>map[i][j];
            }
        }
        int f=0;
        for(int i=1;i<n;i++)
        {
            if(map[i][f])
            {
                in[i]=f;
                f=i;
                continue;
            }
            int d1=f,d2=in[f];
            while(d2!=-1)
            {
                if(map[d1][i]&&map[i][d2])
                    break;
                d1=in[d1];
                d2=in[d2];
            }
            in[d1]=i;
            in[i]=d2;
        }
        //queue<int> q;
        cout<<1<<endl<<n<<endl;

        //while(n--)
        //{
        //    int tmp=q.front();
        //    q.pop();
        //    cout<<tmp+1;
        //    if(n)
        //        cout<<" ";
        //}
        for(int i=0;i<n;i++)
        {
            if(i)cout<<" ";
            cout<<f+1;
            f=in[f];
        }
        cout<<endl;
    }
    return 0;
}
