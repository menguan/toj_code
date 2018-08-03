#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int maxn = 10005;

struct Node {
    int res;
    int pre;
    int digit;
} q[maxn];
int a[maxn], vis[maxn];
int n, m;

void print(int u) {
    if (q[u].pre == -1)
        return;
    print(q[u].pre);
    printf("%d", q[u].digit);
}

int bfs() {
    q[0].digit = 0;
    q[0].pre = -1;
    q[0].res = 0;
    memset(vis, 0, sizeof(vis));
    int front = 0, rear = 1;
    while (front < rear) {
        Node tmp = q[front];
        for (int i = 0; i < m; i++) {
            int t = (tmp.res * 10 + a[i]) % n;
            if (a[i] == 0 && tmp.pre == -1)
                continue;
            if (!vis[t]) {
                vis[t] = 1;
                Node tmp;
                tmp.digit = a[i];
                tmp.pre = front;
                tmp.res = t;
                q[rear++] = tmp;
            }
            if (t == 0) {
                print(rear-1);
                printf("\n");
                return 1;
            }
        }
        front++;
    }
    return 0;
}

int main() {
    while (scanf("%d%d", &n, &m) != EOF) {
        for (int i = 0; i < m; i++)
            scanf("%d", &a[i]);
        if (n == 0) {
            printf("0\n");
            continue;
        }
        sort(a, a+m);
        if (!bfs())
            printf("0\n");
    }
    return 0;
}
//888888888888888888888888888888888888888888888888888888888888888888888888888
//****************************************************************************
//**************************************************************************