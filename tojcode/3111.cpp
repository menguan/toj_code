#include<cstdio>
#include<cstring>
#include<cmath>
#define N 100010
int du[2][N];
int main()
{
    int i,j,n,m,k,kk,top,pre,tt;
    double sum;
    while(scanf("%d%d%d",&n,&m,&kk),n||m||kk){
        sum=pow(m,n);   
        for(i=1;i<=m;i++)du[0][i]=1;
        top=m;tt=0;
        for(i=2;i<=n;i++){
            memset(du[!tt],0,sizeof(du[tt]));
            for(j=top;j>=1;j--){
                for(k=1;k<=m;k++){
                    du[!tt][j+k]+=du[tt][j];
                }
            }
            tt=!tt; top+=m;
        }
        double ans=0;
        for(i=n;i<=kk;i++)
            ans+=du[tt][i]*1.0/sum;
        for(i=kk+1;i<=top;i++)
            ans+=du[tt][i]*(i-kk)*1.0/sum;
        printf("%.8f\n",ans);
    }
}
