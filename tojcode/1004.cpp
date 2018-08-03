#include <stdio.h>
#define min(x,y) (x<y?x:y)
#define max(x,y) (x>y?x:y)
#define maxn 2000
#define max_junc 45

struct node
{
	int junc1, junc2;
	bool v;
} st[maxn];

int degree[max_junc];
int start, n, m, top, stack[maxn];

void init() 
{
	for (int i = 0; i < max_junc; i++) degree[i] = 0;
	start = n = m = top = 0;
	for (int i = 0; i < maxn; i++) 
		st[i].v = false;
}

bool is_euler()
{
	for (int i = 1; i <= m; i++)
		if (degree[i] & 1) return false;
	return true;
}

void DFS(int v)
{
	for (int i = 1; i <= n; i++)
		if (!st[i].v && (st[i].junc1 == v || st[i].junc2 == v))
		{
			st[i].v = true;
			int next = st[i].junc1 == v ? st[i].junc2 : st[i].junc1;
			DFS(next);
			stack[top++] = i;
		}
}

int main()
{
	int x, y, z;
	while (scanf("%d%d", &x, &y) != EOF, x + y)
	{
		init();
		do
		{
			if (start == 0) start = min(x, y);
			scanf("%d", &z);
			n++;
			//m = max(m, max(x, y));
			m = max(m, max(x, y));
			degree[x]++, degree[y]++;
			st[z].junc1 = x, st[z].junc2 = y;
		} while (scanf("%d%d", &x, &y) != EOF, x + y);
		
		if (!is_euler()) printf("Round trip does not exist.\n");
		else
		{
			DFS(start);
			for (int i = top - 1; i >= 0; i--)
			{
				printf("%d", stack[i]);
				if (i) printf(" ");
			}
			printf("\n");
		}
		printf("\n");
	}
}
