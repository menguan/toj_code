#include<stdio.h>
#include<string.h>
#include<iostream>
#include<cstring>
using namespace std; 
int main()
{
    int i, j, flag, cnt;
    double h, d, n, f, dis, e;
    while(scanf("%lf%lf%lf%lf", &h, &d, &n, &f) != EOF && h)
    {
        e = d*f/100;
        for(flag=0,dis=cnt=0; !flag; cnt++)
        {
            if(d-e*cnt >= 0) dis += (d - e*cnt);
            if(dis > h) flag = 1;
            else
            {
                dis -= n;
                if(dis < 0) flag = -1;
            }
        }
        if(flag == 1) printf("success on day %d\n", cnt);
        else if(flag == -1) printf("failure on day %d\n", cnt);
    }
    return 0;
}