//凸函数都可以用  求极值 针对题来说还是很好理解的

#include <iostream>//第一次看到的三分 直接用了
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

#define EPS 1e-7
#define MAXN 50050
double x[MAXN], w[MAXN];
int n;

double Cal(double pos){
    double ans = 0;
    for(int i = 1; i <= n; i ++){
        double tmp = abs(pos - x[i]);
        ans += w[i] * tmp * tmp * tmp;
    }
    return ans;
}

double Solve(){
    double Left, Right;
    double mid, midmid;
    double mid_value, midmid_value;
    Left = x[1];
    Right = x[n];
    while(Left + EPS < Right){
        mid = (Left + Right) / 2;
        midmid = (mid + Right) / 2;
        mid_value = Cal(mid);
        midmid_value = Cal(midmid);
        if(mid_value <= midmid_value)
            Right = midmid;
        else
            Left = mid;
    }
    return Cal(Left);
}

int main(){
    int t;
    int cnt = 0;
    cin>>t;
    while(t --){
        cnt ++;
        scanf("%d", &n);
        for(int i = 1; i <= n; i ++){
            cin>>x[i]>>w[i];
        }
        printf("Case #%d: %.0lf\n", cnt, Solve());
    }
}
/*
1
4
0.6 5
3.9 10
5.1 7
8.4 10
*/
/*
1
4
-99999 14
90000 14
99998 13
99999 14
*/

/*
while(fabs(left-right)>eps)
        {
            mid=(left+right)/2;
            midmid=(mid+right)/2;
            if(cal(mid)<cal(midmid))
                right=midmid;
            else
                left=mid;
        }
        */
