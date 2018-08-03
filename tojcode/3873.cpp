/*aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
aaaaa    aaaaa  aaa  aaaaa                 aaaaaa
aaaaaaaa aaaaa  aa  aaaaaaaaaaaaaaaaaaaaa  aaaaaa 
aaaaa    aaaaa    aaaaaaaaaaaaaaaaaaaa   aaaaaaaa
aaaaa aaaaa          aaaaaaaaaaaaaaa   aaaaaaaaaa
aaaaa aaaaaaaa   aaaaaaaaaaaaaaaaa   aaaaaaaaaaaa
aaaaa    aaaaa     aaaaaaaaaaaa    aaaaaaaaaaaaaa
aaaaaaaa aaaaa  aa  aaaaaaaaa   aaaaaaaaaaaaaaaaa
aaaaaa a aaaaa   aa  aaaaaa   aaaaaaaaaaaaaaaaaaa
aaaaaaa  aaaaa  aaaaa aaaaa                aaaaaa
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<queue>
using namespace std;
char map[5005][5005];
bool visit[5005][5005];
struct node
{
	int x;
	int y;
	int val;
};
int dir[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
int n1,n2,cost;
int go(int x,int y)
{
	if(0<=x&&x<n1&&0<=y&&y<n2&&map[x][y]!='#')
	return 1;
	return 0;
}
int bfs(int x1,int y1,int x2,int y2)
{
	int i,j,k;
	queue<node>q;
	node st,ed,re;
	memset(visit,0,sizeof(visit));
	st.x=x1;
	st.y=y1;
	st.val=0;
	visit[x1][y1]=1;
	q.push(st);
	while(!q.empty())
	{
		st=q.front();
		q.pop();
		if(st.x==x2&&st.y==y2)
		return st.val;
		for(k=0;k<4;k++)
		{
			ed.x=st.x+dir[k][0];
			ed.y=st.y+dir[k][1];
			if(!visit[ed.x][ed.y]&&go(ed.x,ed.y))
			{
				visit[ed.x][ed.y]=1;
				if(map[ed.x][ed.y]=='*')
				ed.val=st.val+cost;
				else
				ed.val=st.val;
				q.push(ed);
				if(map[ed.x][ed.y]=='P')
				{
					for(i=0;i<n1;i++)
					for(j=0;j<n2;j++)
					{
						if(!(i==ed.x&&j==ed.y)&&map[i][j]=='P')
						{
							re.x=i;
							re.y=j;
							re.val=ed.val;
							visit[i][j]=1;
							q.push(re);
						}
					}
				}
			}
		}
	}
	return -1;
}
int main()
{
	int i,j,ans;
	int x1,y1,x2,y2;
	while(scanf("%d%d%d",&n1,&n2,&cost)!=EOF)
	{
		for(i=0;i<n1;i++)
		scanf("%s",map[i]);
		for(i=0;i<n1;i++)
		for(j=0;j<n2;j++)
		{
			if(map[i][j]=='Y')
			{
				x1=i;
				y1=j;
			}
			else if(map[i][j]=='C')
			{
				x2=i;
				y2=j;
			}
		}
		ans=bfs(x1,y1,x2,y2);
		if(ans==-1)
		printf("Damn teoy!\n");
		else
		printf("%d\n",ans);
	}
	return 0;
}
