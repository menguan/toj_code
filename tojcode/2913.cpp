#include <iostream>//线段树 和 rmq  去网上找了个短点的照打 
#include <algorithm>
#include <stdio.h>
#include <cstring>
using namespace std;
int num[200000],f[200000][20],lef[200000],rig[200000],ind[200000];
int main()
{
	int n,q,p,i,j,k,m,s,e,ans;
	scanf("%d",&n);
	while(n)
	{
		scanf("%d",&q);
		m=999999999,k=0;
		for(i=0;i<n;i++)
		{
			scanf("%d",&p);
			if(i&&p!=m)
			{
				rig[k]=i-1;
				num[k++]=rig[k]-lef[k]+1;
				lef[k]=i;
			}
			ind[i]=k;
			m=p;
		}
		rig[k]=n-1;
		num[k]=rig[k]-lef[k]+1;
		for(i=0;i<=k;i++)
			f[i][1]=num[i];
		p=1;
		for(i=2;p<k;i++)
		{
			for(j=0;j+p*2<=k+1;j++)
				f[j][i]=max(f[j][i-1],f[j+p][i-1]);
			p*=2;
		}
		for(i=0;i<q;i++)
		{
			scanf("%d%d",&s,&e);
			p=ind[e-1]-ind[s-1];
			if(p==0)
				ans=e-s+1;
			else if(p==1||p==2)
			{
				ans=max(rig[ind[s-1]]-s+2,e-lef[ind[e-1]]);
				if(p==2)
					ans=max(ans,num[ind[s-1]+1]);
			}
			else
			{
				p-=2;
				m=1,j=0;
				while(p)
					p/=2,m*=2,j++;
				m/=2;
				ans=max(f[ind[s-1]+1][j],f[ind[e-1]-m][j]);
				ans=max(ans,rig[ind[s-1]]-s+2);
				ans=max(ans,e-lef[ind[e-1]]);
			}
			printf("%d\n",ans);
		}
		scanf("%d",&n);
	}
	return 0;
}
