#include<stdio.h>
#include<string.h>
struct node
{
	int max;
	int min;
	int l;
	int r;
};
node tree[200000];
int h[50010];
int maxn,minn;

int MAX(int a,int b)
{
	if(a>b)
		return a;
	else
		return b;
}

int MIN(int a,int b)
{
	if(a>b)
		return b;
	else
		return a;
}

void build(int l,int r,int root)
{
	tree[root].l=l;
	tree[root].r=r;
	if(l==r)
	{
		tree[root].max=h[l];
		tree[root].min=h[l];
		return;
	}
	int mid=(l+r)>>1;
	build(l,mid,root*2);
	build(mid+1,r,root*2+1);	
	tree[root].max=MAX(tree[2*root].max,tree[2*root+1].max);
	tree[root].min=MIN(tree[2*root].min,tree[2*root+1].min);
}

void findmax(int l,int r,int root)
{
	if(tree[root].l==l&&tree[root].r==r)
	{
		if(tree[root].max>maxn)
			maxn=tree[root].max;
		return;
	}
	int mid=(tree[root].l+tree[root].r)>>1;
	if(mid>=r)
		findmax(l,r,root*2);
	else if(mid<l)
		findmax(l,r,root*2+1);
	else 
	{
		findmax(l,mid,root*2);
		findmax(mid+1,r,root*2+1);
	}
}

void findmin(int l,int r,int root)
{
	if(tree[root].l==l&&tree[root].r==r)
	{
		if(tree[root].min<minn)
			minn=tree[root].min;
		return;
	}
	int mid=(tree[root].l+tree[root].r)>>1;
	if(mid>=r)
		findmin(l,r,root*2);
	else if(mid<l)
		findmin(l,r,root*2+1);
	else 
	{
		findmin(l,mid,root*2);
		findmin(mid+1,r,root*2+1);
	}
}

int main()
{
	int n,q,i,a,b;
	scanf("%d%d",&n,&q);
	for(i=1;i<=n;i++)
		scanf("%d",&h[i]);
	build(1,n,1);
	while(q--)
	{
		maxn=0;
		minn=99999999;
		scanf("%d%d",&a,&b);
		findmax(a,b,1);
		findmin(a,b,1);
		printf("%d\n",maxn-minn);
	}
	return 0;
}
 
int main()
{
    int n,q,i,a,b;
    scanf("%d%d",&n,&q);
    for(i=1;i<=n;i++)
      scanf("%d",&h[i]);
    build(1,n,1);
    while(q--)
    {
       maxn=0;
       minn=999999999;
       scanf("%d%d",&a,&b);
       findmax(a,b,1);
       findmin(a,b,1);
       printf("%d\n",maxn-minn);
    }
}  