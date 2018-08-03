#include<stdio.h>
#include<cstring>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define mid (l+r)>>1
const int maxn = 1000010;
int sum[maxn<<2];
int col[maxn<<2];
int k,res[100010];
int max(int a,int b){
    return a>b?a:b;
}
void pushup(int rt){
    sum[rt]=max(sum[rt<<1],sum[rt<<1|1]);
}
void pushdown(int rt){
    if(col[rt]){
        sum[rt<<1]+=col[rt];
        sum[rt<<1|1]+=col[rt];
        col[rt<<1]+=col[rt];
        col[rt<<1|1]+=col[rt];
        col[rt]=0;
    }
}
/*
void set_up(int i)
{
    a[i].n = max(a[2*i].n,a[2*i+1].n);
}

void set_down(int i)
{
    if(a[i].lazy)
    {
        a[2*i].n += a[i].lazy;
        a[2*i].lazy+=a[i].lazy;
        a[2*i+1].n += a[i].lazy;
        a[2*i+1].lazy+=a[i].lazy;
        a[i].lazy = 0;
    }
}

void init(int l,int r,int i)
{
    a[i].l = l;
    a[i].r = r;
    a[i].n = 0;
    a[i].lazy = 0;
    if(l!=r)
    {
        int mid = (l+r)>>1;
        init(l,mid,2*i);
        init(mid+1,r,2*i+1);
    }
}
*/

void update(int L,int R,int c,int l,int r,int rt){
     if(L<=l&&r<=R){
         col[rt]+=c;
         sum[rt]+=c;
         return ;
     }
     pushdown(rt);
     int m=mid;
     if(L<=m) update(L,R,c,lson);
     if(R>m) update(L,R,c,rson);
     pushup(rt);
}
int query(int L,int R,int l,int r,int rt){
    if(L<=l&&r<=R){
        return sum[rt];
    }
    pushdown(rt);
    int m=mid, ret=0;
    if(L<=m)    ret=max(ret,query(L,R,lson));
    if(R>m)   ret=max(ret,query(L,R,rson));
    return ret;
}
int main(){
      int t,i,j,q,a,b,cases=1,tot;
     scanf("%d",&t);
     while(t--){
         tot=0;
         memset(col,0,sizeof(col));
         memset(sum,0,sizeof(sum));
         scanf("%d%d",&k,&q);
         for(i=1;i<=q;i++){
              scanf("%d%d",&a,&b);b--;
              if(query(a,b,1,1000000,1)<k){
                  res[++tot]=i;
                  update(a,b,1,1,1000000,1);
              }
         }
         printf("Case %d:\n",cases++);
         for(i=1;i<=tot;i++){
             printf("%d ",res[i]);
         }
         printf("\n\n");
     }
}
