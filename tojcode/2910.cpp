#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
double PI = acos(-1.0);
int main()
{
    double w, h, r, ans1, ans2, ans;
    while (scanf("%lf%lf", &w, &h) != EOF && w &&h)
    {
        r = min(w / 2.0, h /(2.0 * PI + 2.0));
        ans1 = PI * r * r * w;
        r = min(w / (2.0 * PI), h / 3.0);
        ans2 = PI * r * r * (h - 2.0 * r);
        ans = max(ans1, ans2);
        printf("%.3lf\n", ans);
    }
    return 0;
}
