#include <iostream>//优先队列
#include <cstdio>
#include <queue>
#include <string.h>
#include <algorithm>
using namespace std;
#define M 1010
struct point{
  int x,y,step;
  bool operator< (const point&p)const{
    return step>p.step;
  }
}p,newp;
int n,m,visted[M][M],sx,sy,ex,ey;
int addx[4]={1,-1,0,0};
int addy[4]={0,0,1,-1};
int map[M][M];
void init(){
  p.x=sx;p.y=sy;
  p.step=map[sx][sy];
  visted[sx][sy]=1;
}
int bfs(){
  priority_queue<point> qq;
  qq.push(p);
  while(!qq.empty()){
	p=qq.top();
	qq.pop();
	for(int i=0;i<4;++i){
	  int newx=p.x+addx[i];
	  int newy=p.y+addy[i];
	  if(newx>0&&newx<=n&&newy>0&&newy<=m){
	    if(newx==ex&&newy==ey)
			return p.step;
		if(!visted[newx][newy]){
		  newp.x=newx;
		  newp.y=newy;
		  newp.step=map[newx][newy]+p.step;
		  qq.push(newp);
		  visted[newx][newy]=1;
		}
	  }
	}
  }
  return 0;
}
int main(){
	//freopen("1.txt","r",stdin);
	while(scanf("%d%d",&n,&m),n,m){
		char cc;
		memset(map,0,sizeof(map));
		memset(visted,0,sizeof(visted));
		for(int i=1;i<=n;++i){
		  for(int j=1;j<=m;++j)
		  {
			  cin>>cc;
			  if(cc=='X')
				  map[i][j]=0;
			  else
				  map[i][j]=1;
		  }
		}
		scanf("%d%d%d%d",&sx,&sy,&ex,&ey);
		init();
		int x=bfs();
		printf("%d\n",x+map[ex][ey]);
	}
  return 0;
}
