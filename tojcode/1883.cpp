#include<iostream>
#include<algorithm>
#include<stdio.h>
using namespace std;
struct M
{
	int l,r;
}a[500005];
int n,m;
void set()
{
	for(int i=0;i<m;++i)
		scanf("%d%d",&a[i].l,&a[i].r);
}
inline bool cmp(M x,M y) 
{ 
	return x.l < y.l ;
} 
int main()
{
	while(scanf("%d%d",&n,&m),n&&m)
	{
		set();
		sort(a,a+m,cmp);
		int l=1,tag=0,maxx=0;
		for(int i=0;i<m;++i)
		{
			if(a[i].l<=l)
			{
				if(maxx<a[i].r)  maxx=a[i].r;
			}
			else
			{
				l=maxx;
				tag++;
				if(l>=n) break;
				i--;
			}
		}
		if(l<n)tag++;
		printf("%d\n",tag);
	}
}

