#include<cstdio>//不明白它的这个复杂度为何能过
#include<cstring>
using namespace std;
#define ll long long
int x[5005],y[5005];
ll h[5005];
int f[2000005];
int main(){
    int T; scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d%d",&x[i],&y[i]);
            h[i]=y[i]*y[i]-(y[i]-y[1])*(y[i]-y[1]);
        }
        memset(f,-1,sizeof(f));
        //for(int i=x[1];i<=2*x[n];i++)
        //    f[i]=-1;
        f[x[1]]=0;
        for(int i=2;i<=n;i++){
            for(int j=x[i]-1;j>=x[1];j--){
                if(f[j]==-1)
                    continue;
                if((x[i]-j)*(x[i]-j)>h[i])
                    break;
                int tt=2*x[i]-j;
                if(f[tt]==-1 || f[tt]>f[j]+1)
                    f[tt]=f[j]+1;
                if(tt>x[n] && (f[x[n]]==-1 || f[x[n]]>f[tt]))
                    f[x[n]]=f[tt];
            }
        }
        printf("%d\n",f[x[n]]);
    }
    return 0;
}
