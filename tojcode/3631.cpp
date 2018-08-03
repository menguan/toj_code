#include <cstdio>
#include<cmath>
#include<cstring>
using namespace std;
double g[110][110], a[110][110];
double ans[110][110];
int n;
double cal(int x) {
    double ans = 1;
    for (int i = 1; i <= x; i++)
        ans *= i;
    return ans;
}
void init() {
    for (int i = 0; i < n; i++)
    for(int j=0;j<n;j++)
    {
       if(i==j)
        g[i][j] = 1;
       else
        g[i][j]=0;
        }
}
void mul() {
    double c[110][110];
    for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
      c[i][j]=0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++)
                c[i][j] += g[i][k] * a[k][j];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) g[i][j] = c[i][j];
}/*}
void mul2() {
    double c[110][110];
    memset(c, 0, sizeof(c));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++)
                c[i][j] += a[i][k] * a[k][j];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) a[i][j] = c[i][j];
}*//*
void get(int x) {
    while (x) {
        if (x & 1) mul();
        x >>= 1;
        mul2();
    }
}*/
int main() {
    while(scanf("%d",&n)&&n){
        if(n==1) {
            double a;
            scanf("%lf",&a);
            printf("%.2lf \n",exp(a));
        }
        else{                init();
            for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
              ans[i][j]=0;
            for(int i=0;i<n;i++) for(int j=0;j<n;j++) scanf("%lf",&a[i][j]);
            for(int i=1;i<=50;i++){
//get(i);
                mul();
                double tt = cal(i);
                for (int i = 0; i < n; i++)
                    for (int j = 0; j < n; j++)
                        ans[i][j] += g[i][j] / tt;
            }
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (i == j) ans[i][j]+=1;

                    printf("%.2lf ", ans[i][j]);
                }
                printf("\n");
            }
        }

    }
}
