#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int N = 1010;
struct option
{
    char a[5], b[5];
};
int go[N][N];
option cat[N], dog[N];
int visit[N];
int match[N];
int c,d,v;
int cnt_cat, cnt_dog;
bool dfs (int u)
{
    for (int i = 0; i < cnt_dog; i++)
        if (go[u][i] && !visit[i])
        {
            visit[i] = true;
            if (match[i] == -1 || dfs(match[i]))
            {
                match[i] = u;
                return 1;
            }
        }
    return 0;
}
int main()
{
    int t;
    char a[5];
    char b[5];
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d%d", &c, &d, &v);
        cnt_cat = 0;
        cnt_dog = 0;
        for (int i = 0; i < v; i++)
        {
            scanf("%s%s", a, b);

            if (a[0] == 'C')
            {
                strcpy(cat[cnt_cat].a, a);
                strcpy(cat[cnt_cat].b, b);
                cnt_cat++;
            }
            else
            {
                strcpy(dog[cnt_dog].a, a);
                strcpy(dog[cnt_dog].b, b);
                cnt_dog++;
            }
        }
        memset(go, false, sizeof(go));
        for (int i = 0; i < cnt_cat; i++)
            for (int j = 0; j < cnt_dog; j++)
                if (strcmp(cat[i].a, dog[j].b) == 0 || strcmp(cat[i].b, dog[j].a) == 0)
                    go[i][j] = true;

        int ans = 0;
        memset(match, -1, sizeof(match));
        for (int i = 0; i < cnt_cat; i++)
        {
            memset(visit, false, sizeof(visit));
            if (dfs(i))
                ans++;
        }

        printf("%d\n", v-ans);
    }
    return 0;
}
