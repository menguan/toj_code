#include <cstdio>
#include <cstring>
using namespace std;
/*
struct b_tree
{
	char data;
	b_tree *l;
	b_tree *r;
} *h;

b_tree *Create(char *pre, char *in, int n)
{
	b_tree *s;
	char *p;
	if (n <= 0) return NULL;
	s = new b_tree;
	s -> data = *pre;
	for (p = in; p < in + n; p++)
		if (*p == *pre) break;
	int k = p - in;
	s -> l = Create(pre + 1, in, k);
	s -> r = Create(pre + k + 1, p + 1, n - k - 1);
	return s;
}
*/
struct b_tree
{
	char data;
	b_tree *l;
	b_tree *r;
} *h;

b_tree *Create(char *pre, char *in, int n)
{
	b_tree *s;
	char *p;
	if (n <= 0) return NULL;
	s = new b_tree;
	s -> data = *pre;
	for (p = in; p < in + n; p++)
		if (*p == *pre) break;
	int k = p - in;
	s -> l = Create(pre + 1, in, k);
	s -> r = Create(pre + k + 1, p + 1, n - k - 1);
	return s;
}

void Post(b_tree *t)
{
	if (t != NULL)
	{
		Post(t -> l); Post(t -> r);
		printf("%c", t -> data);
	}
}

int main()
{
	char s1[30], s2[30];
	while (scanf("%s%s", s1, s2) != EOF)
	{
		h = Create(s1, s2, strlen(s1));
		Post(h);
		printf("\n");
	}
}
