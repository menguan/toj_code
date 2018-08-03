#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
int n, num[10010], Max;
int vis[1000010];
int main() {
    while (~scanf("%d", &n) && n) {
    Max = 0;
    memset(vis,0,sizeof(vis));
    for (int i = 0; i < n; i ++) {
    scanf("%d", &num[i]);
    vis[num[i]] ++;
    Max = max(vis[num[i]], Max);
    }
    sort(num, num + n);
    printf("%d\n", Max);
    for (int i = 0; i < Max; i ++) {
    printf("%d", num[i]);
    for (int j = i + Max; j < n; j += Max)
        printf(" %d", num[j]);
    puts("");
    }
    }
}
