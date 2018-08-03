#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;

int A, B, n, m;
struct robot
{
    int x, y, dir;
}a[105];

bool judge(int k)
{
    if(a[k].x <= 0 || a[k].x > A || a[k].y <= 0 || a[k].y > B)
    {
        printf("Robot %d crashes into the wall\n",k);
        return true;
    }
    for(int i = 1; i <= n; i++)
    {
        if(i == k)
            continue;
        if(a[k].x == a[i].x && a[k].y == a[i].y)
        {
            printf("Robot %d crashes into robot %d\n",k,i);
            return true;
        }
    }
    return false;
}

int main()
{
    int T, i, j;
    char ch;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d%d",&A, &B, &n, &m);
        for(i = 1; i <= n; i++)
        {
            scanf("%d %d %c",&a[i].x, &a[i].y, &ch);
            if(ch == 'E')
                a[i].dir = 0;
            else if(ch == 'S')
                a[i].dir = 1;
            else if(ch == 'W')
                a[i].dir = 2;
            else if(ch == 'N')
                a[i].dir = 3;
        }
        bool flag = false;
        int num, cnt;
        for(i = 0; i < m; i++)
        {
            scanf("%d %c %d",&num, &ch, &cnt);
            if(ch == 'F')
            {
                if(!flag)
                {
                    for(j = 0; j < cnt; j++)
                    {
                        if(a[num].dir == 0)
                            a[num].x++;
                        else if(a[num].dir == 1)
                            a[num].y--;
                        else if(a[num].dir == 2)
                            a[num].x--;
                        else if(a[num].dir == 3)
                            a[num].y++;
                        flag = judge(num);
                        if(flag)
                            break;
                    }
                }
            }
            else if(ch == 'L')
                a[num].dir = (a[num].dir - cnt % 4 + 4) % 4;
            else if(ch == 'R')
                a[num].dir = (a[num].dir + cnt % 4) % 4;
        }
        if(!flag)
            printf("OK\n");
    }
    return 0;
}
