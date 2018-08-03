#include<stdio.h>//求三角形垂心 直接用了
struct point{ double x,y;}p[4];
int main(){
    int n;
    double ax,ay,s1,s2,s3,s4;
    scanf("%d",&n);
    while(n--) {  scanf("%lf%lf%lf%lf%lf%lf",&p[1].x,&p[1].y,&p[2].x,&p[2].y,&p[3].x,&p[3].y);
    s1 = (p[1].x - p[2].x)*p[3].x + (p[1].y - p[2].y)*p[3].y;  s2 = (p[2].x - p[3].x)*p[1].x + (p[2].y - p[3].y)*p[1].y;
    s3 = -(p[2].y - p[1].y)*s2 + (p[3].y - p[2].y)*s1;  s4 = (p[2].y - p[1].y)*(p[3].x - p[2].x) - (p[3].y - p[2].y)*(p[2].x - p[1].x);
    ax = s3/s4;  s3 = s1*(p[3].x - p[2].x) - s2*(p[2].x - p[1].x);  ay = s3/-s4;
    printf("%.4lf %.4lf\n",ax+0.0000000001,ay+0.0000000001); } return 0;}
