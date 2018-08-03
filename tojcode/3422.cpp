#include<stdio.h>
#include<string.h>
#define MAX 200005
int f[MAX],sum[MAX];
int n,m;
void init()
{
memset(sum,0,sizeof(int)*(n+2));
for(int i=0;i<=n;i++) f[i]=i;
}
int find(int x)
{
if(f[x]==x) return x;
int tx=find(f[x]);
sum[x]+=sum[f[x]];
f[x]=tx;
return tx;
}
void unio(int x,int y,int tx,int ty,int w)
{
f[ty]=tx;
sum[ty]=sum[x]-sum[y]+w;
}
int main()
{
int ans=0,x,y,w,tx,ty;
while(scanf("%d%d",&n,&m)!=EOF)
{
init();ans=0;
for(int i=1;i<=m;i++)
{
scanf("%d%d%d",&x,&y,&w);
//x--;
tx=find(x);ty=find(y);
if(tx==ty&&sum[y]-sum[x]!=w) ans++;
else if(tx!=ty) unio(x,y,tx,ty,w);
}
printf("%d\n",ans);
}
return 0;
}
