#include<iostream>
#include<cstring>

#include<stdio.h>
using namespace std;
struct f
{
	int u;
	int v;
	int w;
	int cost;
}a[25];
int ans;
int num[8];

int n,m,c;
bool jud(int pos)
{
	for(int i=a[pos].u;i<a[pos].v;i++)
	{
		num[i]+=a[pos].w;
		if(num[i]>n)
		  return 0;
	}
	return 1;
}  
void dfs(int dep,int sum)
{
	//cout<<dep<<" "<<sum<<endl;
	//system("pause");
	if(dep==c)
	{
		
		if(sum>ans)
		  ans=sum;
		return;
	}
	dfs(dep+1,sum);
	int temp[8];
	for(int i=0;i<=m;i++)
	  temp[i]=num[i];
	if(jud(dep))
	{
		dfs(dep+1,sum+a[dep].cost);
	}
	for(int i=0;i<=m;i++)
	  num[i]=temp[i];
	return;
}
int main()
{
	while(~scanf("%d%d%d",&n,&m,&c))
	{
		if(n+m+c==0)  return 0;
		memset(a,0,sizeof(a));
		memset(num,0,sizeof(num));
		
		for(int i=0;i<c;i++)
		{
			scanf("%d%d%d",&a[i].u,&a[i].v,&a[i].w);
			a[i].cost=(a[i].v-a[i].u)*a[i].w;
		}
		ans=0;
		dfs(0,0);
		printf("%d\n",ans);
	}
}
		
