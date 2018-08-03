#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
#define maxn 28
int a[maxn];
int ppow[maxn];
bool vis1[maxn];
vector <int> ans[2];
void init()
{
	ppow[0] = 1;
	for(int i = 1;i <= 20;i++)
		ppow[i] = ppow[i-1]*3;
}
int main()
{
	//freopen("in.txt","r",stdin);
	init();
	int m;
	while(scanf("%d",&m)!=EOF)
	{
		ans[0].clear();
		ans[1].clear();
		memset(vis1,0,sizeof(vis1));
		memset(a,0,sizeof(a));
		int pos = 0;
		while(m)
		{
			a[pos++] = m%3;
			m/=3;
		}
//		for(int i=pos-1;i>=0;i--)
//		 cout<<a[i];
//		cout<<endl;  
		for(int i = 0;i < pos;i++)
		{
			if(a[i] == 3)
			{
				a[i] = 0;
				a[i+1]++;
			}
			if(a[i] == 2)
			{
				vis1[i] = 1;
				a[i] = 0;
				a[i+1]++;
			}
		}
		int ans1 = 0,ans2 = 0;
		for(int i = 0;i <= pos;i++)
		{
			if(vis1[i] == 1)
			{
				ans[0].push_back(i);
				ans1++;
			}
			if(a[i]) 
			{
				ans[1].push_back(i);
				ans2++;
			}
		}
		printf("%d",ans1);
		for(int i = 0;i < ans[0].size();i++)
			printf(" %d",ppow[ans[0][i]]);
		printf("\n%d",ans2);
		for(int i = 0;i < ans[1].size();i++)
			printf(" %d",ppow[ans[1][i]]);
		printf("\n");
	}
	return 0;
}
