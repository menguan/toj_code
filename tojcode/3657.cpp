#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
#define N 50005
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define ls rt<<1
#define rs rt<<1|1
char st[50005];
int the[30];
int main() {
    while (~scanf("%s", st)) {
        memset(the, 0, sizeof(the));
        int len = strlen(st);
        bool flag = true;
        int tot = 0;
        for (int i = 0; i < len; ) {
            char ch = st[i];
            //the[ch - 'A']++;
            int k = i;
            while (k < len && ch == st[k]) k++;
            k = k - i;
            if (k == 1 || k == 2) tot++;
            else {
                int t = 1, x = k;
                while (x >= 2 * t) {
                    x -= t;
                    tot++; t++;
                }
                tot++;
            }
            i += k;
            the[ch - 'A'] += k;
            //if (k == 1 && i >= 2 && st[i] == st[i - 2]) tot -= 2;
        }
        int num = tot;
        if (st[0] == st[len - 1] && the[st[0] - 'A'] == 2) flag = false;
        //printf("%d", the[0]);
        int lim = 2 * tot - 1; tot--;
        //printf("%d", tot);
        if ((num & 1) && tot <= 0) flag = false;
        //printf("%d\n", tot);
        if (!flag) puts("No");
        else puts("Yes");
    }
}