#include<cstdio>//网上看得水题代码 自己加的注释
#include<cstring>
#include<cmath>
using namespace std;
int c[210][210],dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
char s[210][210];
bool isMax(int i,int j,int &k)
{
    int t,tx,ty;
    s[i][j]='2';//每次搜索后标记
    if(c[i][j]<2)//判断头尾是否可以延伸
    {
        for(t=0;t<4;t++)
        {
            tx=i+dir[t][0];
            ty=j+dir[t][1];
            if(s[tx][ty]=='0'&&c[tx][ty]==1)
                k++;
        }
    }
    for(t=0;t<4;t++)
    {
        tx=i+dir[t][0];
        ty=j+dir[t][1];
        if(s[tx][ty]=='1')
        {
            if(c[tx][ty]>2)//判断是不是蛇
                return false;
            return isMax(tx,ty,k);
        }
    }
    return true;
}

int main()
{
    int n,m,i,j,k,no;
    while(scanf("%d%d",&n,&m)&&(n+m))
    {
        memset(c,0,sizeof(c));
        for(i=0;i<=n+1;i++)
            s[i][0]='2',s[i][m+1]='\0';
        for(j=0;j<=m+1;j++)
            s[0][j]=s[n+1][j]='2';
        for(i=1;i<=n;i++)
            scanf("%s",s[i]+1);
        for(i=1;i<=n;i++)
            for(j=1;j<=m;j++)
                for(k=0;k<4;k++)
                    if(s[i+dir[k][0]][j+dir[k][1]]=='1')
                        c[i][j]++;
        for(i=1,no=0;i<=n;i++)
            for(j=1;j<=m;j++)
                if(s[i][j]=='1'&&c[i][j]<2)
                {
                    k=0;
                    if(isMax(i,j,k)&&!k)
                        no++;
                }
        printf("%d\n",no);
    }
}
