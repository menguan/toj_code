#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
int a[5][12];
int n,m;
bool vis[20];
int las[5];
int ans;
void dfs(int per,int pos,int now)
{
	//cout<<per<<" "<<pos<<" "<<now<<" "<<las[per]<<endl;
	if(per==4)
	{
		ans=max(ans,now);
		return ;
	}
	for(int i=pos;i<=n;i++)
	{
		
		if(!vis[i])
		if(a[per][i]!=-1)
		{//if(per==1) cout<<i<<endl;
			if(las[per]-a[per][i]>=0)
			{
				las[per]-=a[per][i];
				vis[i]=1;
				//cout<<per<< " "<<i<<endl;
			//	system("pause");
				dfs(per,i+1,now+1);
				vis[i]=0;
				las[per]+=a[per][i];
			}
		}
	}
	dfs(per+1,1,now);
	return ;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		for(int j=1;j<=3;j++)
		{
			for(int i=1;i<=n;i++)
			{
				scanf("%d",&a[j][i]);
			}
		}
	    memset(vis,0,sizeof(vis));
		for(int i=1;i<=3;i++)las[i]=m;
		ans=0;
		dfs(1,1,0);
        printf("%d\n",ans);
    }
	
}	
