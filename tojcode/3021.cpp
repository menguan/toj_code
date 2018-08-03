#include <cstdio>//直接找个自带互相转换函数的  其实之前写过两个 都是单方向转 
#include <cstring>
#include <iostream>
using namespace std;
#define MAXN 55
char srca[MAXN], cas[MAXN], sums[MAXN];

inline int getVal(char ch) {
    switch (ch) {
    case 'I': return 1;
    case 'V': return 5;
    case 'X': return 10;
    case 'L': return 50;
    case 'C': return 100;
    case 'D': return 500;
    case 'M': return 1000;
    default:  return 0;
    }
}

int R2I(char str[]) {
    int i, len = strlen(str);
    int val = 0;
    for (i=0; i<len; ++i) {
        if (str[i]=='C' && (str[i+1]=='D'||str[i+1]=='M'))
            val -= 100;
        else if (str[i]=='X' && (str[i+1]=='L'||str[i+1]=='C'))
            val -= 10;
        else if (str[i]=='I' && (str[i+1]=='X'||str[i+1]=='V'))
            val -= 1;
        else
            val += getVal(str[i]);
    }
    return val;
}

void f1(int *p, int *q, char str[], int a, int b, char ca, char cb, char cc) {
    int x = *p, t=a/9;
    int i = *q;
    if (x >= a) {
        x -= a;
        str[i++] = ca;
        str[i++] = cc;
    }
    if (x >= b) {
        x -= b;
        str[i++] = cb;
    }
    if (x >= (a-b)) {
        x -= (a-b);
        str[i++] = ca;
        str[i++] = cb;
    }
    while (x >= t) {
        str[i++] = ca;
        x -= t;
    }
    *p = x;
    *q = i;
}

void I2R(int x, char str[]) {
    int i = 0;
    while (x >= 1000) {
        str[i++] = 'M';
        x -= 1000;
    }
    f1(&x, &i, str, 900, 500, 'C', 'D', 'M');
    f1(&x, &i, str, 90, 50, 'X', 'L', 'C');
    f1(&x, &i, str, 9, 5, 'I', 'V', 'X');
    str[i] = '\0';
}

int main() {
    int c;
    int n, case_n = 1;

    while(scanf("%d", &n)!=EOF && n) {
        c = 0;
        while (n--) {
            scanf("%s", srca);
            c += R2I(srca);
        }
        I2R(case_n, cas);
        I2R(c, sums);
        printf("Case %s: %s\n", cas, sums);
        ++case_n;
    }
}
