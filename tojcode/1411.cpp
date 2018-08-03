#include<cstdio>
#include<cmath>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;

const int maxn = 500 + 10;
const int INF = 1000000000;

struct Edge {
  int x, y;
  double d;
};

int n,m,s;
int fa[maxn];
int x[maxn],y[maxn];
Edge e[maxn*maxn];
bool cmp(Edge mm,Edge nn){  return mm.d<nn.d; }
int find(int x){return x == fa[x]?x:fa[x] = find(fa[x]);}

double Dist(int i,int j){return hypot(x[i]-x[j],y[i]-y[j]);}

double MST(){
    int cnt = 0;
    double ret;
    for(int i = 0;i < n;i++) fa[i] = i;
    sort(e,e+m,cmp);
    for(int i = 0;i < m;i++){
        int a = e[i].x;
        int b = e[i].y;
        double d = e[i].d;
        int Y = find(b);
        int X = find(a);
        if(X != Y){
            fa[X] = Y;
            if(++cnt == n-s) ret = d;
            if(cnt == n-1) break;
        }
    }
    return ret;
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        m = 0;
        scanf("%d%d",&s,&n);
        for(int i = 0;i < n;i++)
            scanf("%d%d",&x[i],&y[i]);
        for(int i = 0;i < n;i++)
            for(int j = i+1;j < n;j++)
              e[m++] = (Edge){i,j,Dist(i,j)};
        double ans = MST();
        printf("%.2lf\n",ans);
    }
}
