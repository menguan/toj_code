#include<stdio.h>
#include<string.h>
#include<iostream>
#include<queue>
using namespace std;
int dx[] = {1,-1,0,0};
int dy[] = {0,0,-1,1};
int hash[105][105][4];
char as[105][105];
int n,m,si,sj,di,dj;
struct nd
{
    int x,y,dir,st;
}tmp,t;
bool isok(int x,int y)
{
    if(x<0||y<0||x==n||y==m||as[x][y]=='#')return false;
    return true;
}
int bfs()
{
    int i;
    queue<nd>que;
    t.x = si;
    t.y = sj;
    t.dir = 1;
    t.st = 0;
    que.push(t);
    hash[si][sj][0] = hash[si][sj][1] = hash[si][sj][2] = hash[si][sj][3] = 0;
    while(!que.empty())
	{
        t = que.front(); que.pop();
        for(i = 0; i < 4; ++ i){
            tmp.x = t.x + dx[i];
            tmp.y = t.y + dy[i];
            if(isok(tmp.x,tmp.y)){
                tmp.st = t.st + 1;
                tmp.dir = i;
                if(t.dir!=i)tmp.st++;
                if((i==0&&t.dir==1)||(i==1&&t.dir==0)||(i==2&&t.dir==3)||(i==3&&t.dir==2))tmp.st++;
                if(tmp.st<hash[tmp.x][tmp.y][i])
				{
                    que.push(tmp);
                    hash[tmp.x][tmp.y][i] = tmp.st;
                }
            }
        }
    }
    i = 1000000;
    if(i>hash[di][dj][0])i=hash[di][dj][0];
    if(i>hash[di][dj][1])i=hash[di][dj][1];
    if(i>hash[di][dj][2])i=hash[di][dj][2];
    if(i>hash[di][dj][3])i=hash[di][dj][3];
    if(i<1000000)return i;
    return -1;
}
int main()
{
    int i,j,k,t,cas=0;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&n,&m);
        for(i = 0; i < n; ++ i)scanf("%s",as[i]);
        for(i = 0; i < n; ++ i)
            for(j = 0; j < m; ++ j)
			{
                if(as[i][j]=='S'){si=i;sj=j;}
                if(as[i][j]=='T'){di=i;dj=j;}
                hash[i][j][0]=hash[i][j][1]=hash[i][j][2]=hash[i][j][3]=1000000;
            }
			k = bfs();
			printf("%d\n",k);
    }
    return 0;
}
