#include<stdio.h>
#include<cstring>
int a[30][30],use[30][30];
int n,m,ans,sum;
void backtrack(int p)
{
int i;
 for(i=1;i<=m;i++)
 {
   if(use[p][i]||use[i][p])continue;
   if(!a[p][i])continue;
   use[p][i]=1;
   use[i][p]=1;
   sum++;
   if(ans<sum)
    ans=sum;
   backtrack(i);
   use[p][i]=0;
   use[i][p]=0;
   sum--;
 }
}
int main()
{
 int i,st,ed;
 while(scanf("%d%d",&n,&m)!=EOF)
 {
   if(n==0&&m==0)
    break;
   memset(a,0,sizeof(a));
   for(i=1;i<=m;i++)
   {
    scanf("%d%d",&st,&ed);
    st++;ed++;
    a[st][ed]=1;
    a[ed][st]=1;
   }
   ans=0;
   for(i=1;i<=n;i++)
   {
    memset(use,0,sizeof(use));
      sum=0;
      backtrack(i);
   }
   printf("%d\n",ans);
 }
 return 0;
}