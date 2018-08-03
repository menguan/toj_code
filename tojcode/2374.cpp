#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

#define maxn 50000

int ak[maxn], bk[maxn], b[maxn], k[maxn];
char st[maxn];
int n;

int value(char ch)
{
    return ch >= '0' && ch <= '9' ? ch - '0' : ch - 'A' + 10;
}

void make(char *st, int f[])
{
    int len = strlen(st);
    for (int i = 0; i < len; i++)
    {
        if (i & 1)
            f[i >> 1] += value(st[i]);
        else
            f[i >> 1] = value(st[i]) << 4;
    }
}

int main()
{
    scanf("%s", st);
    n = strlen(st) / 2;
    make(st, ak);
    scanf("%s", st);
    make(st, bk);
    b[0] = 32;
    for (int i = 0; i < n; i++)
    {
        k[i] = b[i] ^ bk[i];
        b[i + 1] = k[i] ^ ak[i];
    }
    k[n] = b[n] ^ bk[n];
    for (int i = 0; i < n + 1; i++)
        printf("%02X", k[i]);
    puts("");
}
