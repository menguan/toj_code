#include<iostream>
#include<stdio.h>
using namespace std;
int n,m;
struct xds
{
	int a,b,sum,info;
}tree[300001];
void build(int p,int a,int b )
{
	tree[p].a=a;
	tree[p].b=b;
	tree[p].sum=tree[p].info=0;
	if(a==b)return;
	build(p<<1,a,(a+b)>>1);
	build((p<<1)+1,((a+b)>>1)+1,b);
}
void update(int p,int a,int b)
{
	int ls=(p<<1);
	int rs=(p<<1)+1;
	int mid=(tree[p].a+tree[p].b)>>1;
	if(a<=tree[p].a&&tree[p].b<=b)
	{
		tree[p].info^=1;
		tree[p].sum=tree[p].b-tree[p].a+1-tree[p].sum;
		return;
	}
	if(tree[p].a==tree[p].b)return;
	if(tree[p].info)
	{
		tree[ls].info^=1;
		tree[ls].sum=tree[ls].b-tree[ls].a+1-tree[ls].sum;
		tree[rs].info^=1;
		tree[rs].sum=tree[rs].b-tree[rs].a+1-tree[rs].sum;
		tree[p].info=0;
    }
	if(a<=mid) update(ls,a,b);
	if(b>mid) update(rs,a,b);
	tree[p].sum=tree[ls].sum+tree[rs].sum;
}

int query(int p,int a,int b)
{
	int ls=(p<<1);
	int rs=(p<<1)+1;
	int mid=(tree[p].a+tree[p].b)>>1;
	if(tree[p].a==a&&tree[p].b==b||tree[p].a==tree[p].b)
	  return tree[p].sum;
	if(tree[p].info)
	{
		tree[ls].info^=1;
		tree[ls].sum=tree[ls].b-tree[ls].a+1-tree[ls].sum;
		tree[rs].info^=1;
		tree[rs].sum=tree[rs].b-tree[rs].a+1-tree[rs].sum;
		tree[p].info=0;
    }  
    if(b<=mid) return query(ls,a,b);
    else if(a>mid) return query(rs,a,b);
    else return query(ls,a,mid)+query(rs,mid+1,b);
}

int main()
{
 	int a,b,c;
 	scanf("%d%d",&n,&m);
 	build(1,1,n);
 	while(m--)
 	{
		scanf("%d%d%d",&a,&b,&c);
		if(a)  printf("%d\n",query(1,b,c));
		else  update(1,b,c);
	}
	//while(1);
}
		
	
