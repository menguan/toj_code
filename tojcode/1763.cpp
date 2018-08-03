#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int c[22][22], n, ans, set[22];

void dfs(int id, int sum)
{
    int i;

    set[id] = 1;
    for (i = 0; i < n; i++) {
        if (set[i] == 1)
            sum -= c[id][i];
        else sum += c[id][i];
    }
    //cout<<sum<<endl;
    if (sum > ans) ans = sum;

    for (i = id + 1; i < n; i++)
    {
        dfs(i, sum);
        set[i] = 0;
    }
}

int main()
{
    int i, j;
    scanf ("%d", &n);
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
             scanf ("%d", &c[i][j]);
    memset (set, 0, sizeof (set));
    ans = 0;
    dfs(0, 0);
    printf ("%d\n", ans);
    //while(1);
}

