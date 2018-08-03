#include<iostream>
#include<algorithm>
#include<cstring>
#include<stdio.h>
using namespace std;
struct node
{
    int x, y;
}n[64*84+1];
short a[256][256];
char str[64*80+1], b[81];
bool cmp(node t1, node t2)
{
    if (a[t1.x][t1.y] == a[t2.x][t2.y])
    {
        if (t1.x == t2.x) return t1.y < t2.y;
        return t1.x < t2.x;
    }
    return a[t1.x][t1.y] > a[t2.x][t2.y];
}

int main ()
{
    int num;
    while (scanf("%d\n", &num), num)
    {    
        memset(a, 0, sizeof(a));
        str[0] = 0;
        for (int i = 0; i < num; i++)
        {
            gets(b);
            strcat(str, b);
        }
        int len = strlen(str);
        int cou = 0;
        for (int i = 1; i < len; i++)
        {
            if (a[str[i-1]][str[i]]==0)
            {
                n[cou].x = str[i-1];
                n[cou++].y = str[i];
            }
            a[str[i-1]][str[i]]++;
        }
        sort(n, n + cou, cmp);
        for (int i = 0; i < 5; i++)
            printf("%c%c %d %.6lf\n", n[i].x, n[i].y,
            a[n[i].x][n[i].y], a[n[i].x][n[i].y]*1.0/(len-1));
        printf("\n");
    }
    return 0;
}