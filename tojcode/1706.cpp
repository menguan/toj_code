#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdio>

using namespace std;

int n,m;
int set[5000];

void init(int n)
{
	for(int i=0;i<=n;i++)
		set[i]=i;
}

int find(int a)
{

	int root=a;
	int temp;
	while(set[root]!=root)
		root=set[root];
	while(set[a]!=root)
	{
		temp=a;
		a=set[a];
		set[temp]=root;
	}
	return root;
}

bool merge(int a,int b)
{
	int x=find(a);
	int y=find(b);
	if(x==y)
		return false;
	set[x]=y;
	return true;
}

bool jud(int a,int b)
{
    return find(a)!=find(b);
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int k=1;k<=t;k++)
    {
       scanf("%d%d",&n,&m);
       init(n*2);
       int x,y;
       bool fg=1;
       for(int i=1;i<=m;i++)
       {
           scanf("%d%d",&x,&y);
           if(jud(x,y)||jud(x+n,y+n))
                merge(x,y+n),merge(x+n,y);
           else
                fg=0;
       }
       if(fg)
        printf("Scenario #%d:\nNo suspicious bugs found!\n",k);
       else
        printf("Scenario #%d:\nSuspicious bugs found!\n",k);
       printf("\n");
    }
    return 0;
}
