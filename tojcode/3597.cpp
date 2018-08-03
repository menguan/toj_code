#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<iomanip>
using namespace std;
//const double pi=4.0*atan(1.0);
const double pi=acos(-1.0);
int main()
{
    //cout<<pi<<endl;
    double a,b;
    while(scanf("%lf%lf",&a,&b)==2){
        printf("%.2lf\n",asin(b/400/a)*180/pi);
    }
    return 0;
}

