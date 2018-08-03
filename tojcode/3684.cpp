#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;
int a[110][110][110], n;
int lowbit(int i)
{
    return i&(-i);
}
void update(int i, int j, int k, int x)
{
    int tj, tk;
    while(i <= n)
    {
        tj = j;
        while(tj <= n)
        {
            tk = k;
            while(tk <= n)
            {
                a[i][tj][tk] += x;
                tk += lowbit(tk);
            }
            tj += lowbit(tj);
        }
        i += lowbit(i);
    }
}

int sum(int i, int j, int k)   
{
    int tj, tk, sum = 0;
    while(i > 0)
    {
        tj = j;
        while(tj > 0)
        {
            tk = k;
            while(tk > 0)
            {
                sum += a[i][tj][tk];
                tk -= lowbit(tk);
            }
            tj -= lowbit(tj);
        }
        i -= lowbit(i);
    }
    return sum;
}

int main()
{
    int t, k;
    int x1, y1, z1, x2, y2, z2;
    while(scanf("%d %d", &n, &t) != EOF)
    {
        memset(a, 0, sizeof(a));
        while(t--)
        {
            scanf("%d", &k);
            if(k == 0)
            {
                scanf("%d%d%d", &x1, &y1, &z1);
                printf("%d\n", sum(x1, y1, z1)&1);
            }
            else if(k == 1)
            {
                scanf("%d%d%d%d%d%d", &x1, &y1, &z1, &x2, &y2, &z2);
                update(x2+1, y2+1, z2+1, 1);
                update(x1, y2+1, z2+1, 1);
                update(x2+1, y1, z2+1, 1);
                update(x2+1, y2+1, z1, 1);
                update(x1, y1, z2+1, 1);
                update(x2+1, y1, z1, 1);
                update(x1, y2+1, z1, 1);
                update(x1, y1, z1, 1);
            }
        }
    }

    return 0;
}
