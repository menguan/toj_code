#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int cop[210];
int id[210];
int dp[210][210][210];
int t,n,m,q;
bool cmp(int aa,int bb)
{
	return cop[aa]<cop[bb];
}
int main()
{
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		//
		for(int i=1;i<=n;i++)
	    {
			cin>>cop[i];
			id[i]=i;
		}
		id[0]=0;
		cop[0]=-1;
		int u,v,w;
		memset(dp,-1,sizeof(dp));
		for(int i=1;i<=m;i++)
		{
			cin>>u>>v>>w;
			u++,v++;
			dp[0][u][v]=dp[0][v][u]=w;
		}
		sort(id+1,id+n+1,cmp);
		int pos;
		for(int k=1;k<=n;k++)
		{
			pos=id[k];
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=n;j++)
				{
					if(dp[k][i][j]<0||dp[k][i][j]>dp[k-1][i][j])
					  dp[k][i][j]=dp[k-1][i][j];
					if(i==j) continue;
					if(dp[k-1][i][pos]>=0&&dp[k-1][pos][j]>=0)
					{
						if(dp[k][i][j]<0)
						  dp[k][i][j]=dp[k-1][i][pos]+dp[k-1][pos][j];
						dp[k][i][j]=min(dp[k][i][j],dp[k-1][i][pos]+dp[k-1][pos][j]); 
		         	}
				}
			}
		}
		//cout<<"kk"<<endl;
		cin>>q;
		while(q--)
		{
			cin>>u>>v>>w;
			//cout<<"Kk"<<endl;
			u++,v++;
			int i;
			for(i=1;i<=n&&cop[id[i]]<=w;i++);//cout<<w<<" "<<cop[id[i]]<<"kk"<<endl;
			//cout<<i<<endl;
			cout<<dp[i-1][u][v]<<endl;
		}
		cout<<endl;
	}
}

 
