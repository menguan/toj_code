#include <stdio.h>
#include <cstring>
int child[1000010];
int main() {
    int n, d, i, c, ans = 0, max = 0;
    memset(child,0,sizeof(child));
    scanf("%d%d", &n, &d);
    for(i = 0; i < n; i++){
        scanf("%d", &c);
        if(c > max)
            max = c;
        child[c]++;
    }

    for(i = 0; i <= max; i++)
        if(child[i] > d)
            ans += ((child[i] - d) / (d - 1)+((child[i] - d) % (d - 1)!=0));
    printf("%d\n", ans);
   // while(1);
}


