#include<iostream>
#include<cmath>
#include<stdio.h>
#include<cstring>
#include<iomanip> 
using namespace std;
struct Point{
    double x, y;
}p[200];
int n;
int gcd(int a, int b){ 
    int tmp;
    while(b != 0){
        tmp = b;
        b = a % b;
        a = tmp;
    }
    return a;
}

double area(){//求任意多边形面积 
    double s;
    s = p[0].y * (p[n-1].x-p[1].x);
    for(int i = 1; i < n; i ++)
        s += p[i].y * (p[i-1].x-p[(i+1)%n].x);
    return fabs(s/2);
}

 

int main(){
    int t, i, testCase, dx, dy;
    scanf("%d", &testCase);
    for(t = 1; t <= testCase; t ++){
        scanf("%d", &n);
        int in_num, on_num = 0;
        p[0].x = p[0].y = 0;
        for(i = 1; i <= n; i ++){
            scanf("%d%d", &dx, &dy);
            on_num += gcd(abs(dx),abs(dy));
            p[i].x = p[i-1].x + dx;
            p[i].y = p[i-1].y + dy;
        }
        double sum = area();
        in_num = (int)sum - on_num/2 + 1;
        printf("Scenario #%d:\n%d %d %.1lf\n\n", t, in_num, on_num, sum);
    }
    return 0;
}
