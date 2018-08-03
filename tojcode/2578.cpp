#include <stdio.h>
typedef struct structType{
    char name[9];
    char used;
    char moved;
}structType;
int main()
{
    structType a[21], b[21];
    int z, n, m, i, j;
    int src, obj;
    scanf("%d", &z);
    while (z--){
        scanf("%d %d", &n, &m);
        for (i=1; i<=n; i++){
            scanf("%s", a[i].name);
            a[i].moved = 0;
            b[i].used = 0;
        }
        while (m--){
            scanf("%d %d", &src, &obj);
            b[obj] = a[src];
            b[obj].used = 1;
            a[src].moved = 1;
        }
        for (i=1; i<=n; i++){
            if (!a[i].moved){
                for (j=1; j<=n; j++){
                    if (!b[j].used){
                        b[j] = a[i];
                        b[j].used = 1;
                        break;
                    }
                }
            }
        }
        for (i=1; i<n; i++)
            printf("%s ", b[i].name);
        printf("%s\n", b[n].name);
    }
    return 0;
}