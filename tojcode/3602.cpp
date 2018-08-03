#include <iostream>
#include <cstring>
#include<stdio.h>
#define maxn 15
using namespace std;
int n;
bool v[1 << maxn], flag;
void print(int state) {
    for (int i = 0; i < n; i++)
        if ((1 << i) & state) printf("X");
        else printf("O");
    printf("\n");
}
void dfs(int step, int state) {
	
	if (flag) return;
	if (step == (1 << n) && !state) {
		flag = true;
		print(state);
		return;
	}
	if (!v[state]) {
		v[state] = 1;
		for (int i = 0; i < n; i++)
			if (!flag) dfs(step + 1, state^(1 << i));
		v[state] = 0;
	}
	if (flag) print(state);
} 
 
int main() 
{
    memset(v,0,sizeof(v));
	scanf("%d",&n);
	dfs(0, 0);
	//system("pause");
}
