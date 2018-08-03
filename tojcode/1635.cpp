#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
int n;
double a[2000];
int main() {
    while (scanf("%d", &n), n) {
        for (int i = 0; i < n; i++)
            scanf("%lf", a + i);
        sort(a, a + n);
        double y = 1.0;
        for (int i = 1; i < n; i++) {
            y += sqrt(4.0 - (a[i] - a[i - 1]) * (a[i] - a[i - 1]) / 4.0);
        }
        printf("%.4f %.4f\n", (a[0] + a[n - 1]) / 2, y);
    }
}
