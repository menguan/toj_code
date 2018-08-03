#include <iostream>
#include <cstdio>
using namespace std;

int T, N, x[3], y[3];
double sumx, sumy, sumarea;

int main()
{
    scanf("%d", &T);
    while(T--)
    {
        sumx = sumy = sumarea = 0.0;
        scanf("%d", &N);
        scanf("%d %d %d %d", x, y, x+1, y+1);
        N -= 2;
        while(N--)
        {
            scanf("%d %d", x+2, y+2);
            
            double s = ((x[1] - x[0]) * (y[2] - y[0]) - (x[2] - x[0]) * (y[1] - y[0])) / 2.0;
            sumx += ((x[0] + x[1] + x[2]) * s);
            sumy += ((y[0] + y[1] + y[2]) * s);

            sumarea += s;

            x[1] = x[2];
            y[1] = y[2];
        }
        printf("%.2lf %.2lf\n", sumx / sumarea / 3 , sumy / sumarea / 3);
    }
    return 0;
}
