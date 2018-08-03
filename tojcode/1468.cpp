#include<iostream>
#include<stdio.h>
using namespace std;
int t, y, m, d;
int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d%d", &y, &m, &d);
        if ((m == 9 && d == 30)||(!((m+d)%2)))
          printf("YES\n");
        else 
          printf("NO\n");
    }
    return 0;
}