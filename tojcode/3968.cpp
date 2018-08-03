#include<iostream>
#include<cstring>
#include<stdio.h>
#include<algorithm>
#include<queue>
using namespace std;
typedef long long LL;
struct Node{
	LL c,wei;
	bool operator < (const Node &a)const
	{
		return c > a.c;
	}
};
LL n,len,f[12];

void init()
{
	f[0]=1;
	for(int i=1;i<=18;i++)
		f[i]=f[i-1]*10;
}

void bfs()
{
	Node p,q;
	priority_queue<Node>Q;
	p.c=0;p.wei=0;
	Q.push(p);
	while(!Q.empty())
	{
		p=Q.top();
		Q.pop();
		if(p.wei == len)
		{
			printf("%lld\n",p.c);
			return ;
		}
		for(int i=0;i<10;i++)
		{
			LL t=p.c+i*f[p.wei];
			if(t*t%f[p.wei+1] == n%f[p.wei+1])
			{
				q.c=t;q.wei=p.wei+1;
				Q.push(q);
			}
		}
	}
	printf("None\n");
}

void solve()
{
	LL t=n;
	len=0;
	while(t)
	{
		len++;
		t/=10;
	}
	bfs();
}

int main()
{
    init();
    int T;
    scanf("%d",&T);
    while(T--)
    {
    	scanf("%lld",&n);
    	solve();
    }
}
