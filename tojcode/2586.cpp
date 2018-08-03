#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
bool vis[10][10];
bool is[10][10][10][10];
int dir[4][2]={1,0,0,1,-1,0,0,-1};
char d[4]={'E','S','W','N'};
struct node
{
    int x,y;
    int step;
    char s[40];
}st,en,tmp;
int x1,x2,y1,y2;
int main()
{
    while(scanf("%d%d",&st.x,&st.y)!=EOF)
    {
        if(st.x==0&&st.y==0)
            return 0;
        scanf("%d%d",&en.x,&en.y);
        memset(st.s,0,sizeof(st.s));
        st.step=0;
        memset(vis,0,sizeof(vis));
        memset(is,0,sizeof(is));
        for(int i=0;i<3;i++)
        {
            scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
            if(x1==x2)
            {
                if(y1>y2) swap(y1,y2);
                for(int j=y1;j<y2;j++)
                {
                    is[x1][j+1][x1+1][j+1]=1;
                    is[x1+1][j+1][x1][j+1]=1;
                    //cout<<x1<<" "<<j+1<<" to "<<x1+1<<" "<<j+1<<endl;
                }
            }
            if(y1==y2)
            {
                if(x1>x2) swap(x1,x2);
                for(int j=x1;j<x2;j++)
                {
                    is[j+1][y1][j+1][y1+1]=1;
                    is[j+1][y1+1][j+1][y1]=1;
                    //cout<<j+1<<" "<<y1<<" to "<<j+1<<" "<<y1+1<<endl;
                }
            }
        }
        queue<node> q;
        q.push(st);
        vis[st.x][st.y]=1;
        while(!q.empty())
        {
           tmp=q.front();
           q.pop();

           if(tmp.x==en.x&&tmp.y==en.y)
           {
               tmp.s[tmp.step]='\0';
               cout<<tmp.s<<endl;
               break;
           }
           node tt;
           for(int i=0;i<4;i++)
           {
               strcpy(tt.s,tmp.s);
               tt.step=tmp.step;
               tt.x=tmp.x+dir[i][0];
               tt.y=tmp.y+dir[i][1];
               if(tt.x>6||tt.y>6||tt.x<1||tt.y<1)
                  continue;
               if(vis[tt.x][tt.y])
                  continue;
               if(is[tmp.x][tmp.y][tt.x][tt.y]==1)
                  continue;
               vis[tt.x][tt.y]=1;
               tt.s[tt.step]=d[i];
               tt.step++;
               q.push(tt);
           }
        }


    }
}
