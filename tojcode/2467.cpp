#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <cmath>
#include <queue>
#include <set>
#include <stack>
#include <iomanip>
#define M 205
using namespace std;
string s1, s2, s;
int a[M], b[M], c[2 * M], flag, l1, l2;
int aa, bb, cc, tt;


void pre_check()
{
	if (s1[0] == '-') aa = -1, s1 = s1.substr(1, s1.size() - 1);
	else if (isdigit(s1[0])) aa = 1;
	else if (s1[0] == '+') aa = 1, s1 = s1.substr(1, s1.size() - 1);
	
	if (s2[0] == '-') bb = -1, s2 = s2.substr(1, s2.size() - 1);
	else if (isdigit(s2[0])) bb = 1;
	else if (s2[0] == '+') bb = 1, s2 = s2.substr(1, s2.size() - 1);
	
	if (s1 == "0") aa = 0;
	if (s2 == "0") bb = 0;
	
	int ii; flag = 1;
	l1 = s1.size(); l2 = s2.size();
	
	if (l1 < l2) flag = -1;
	else if (l1 == l2)
	{
		for (ii = 0; ii < l1; ii++)
		{
			if (s1[ii] < s2[ii])
			{
				flag = -1; break;
			}
			if (s1[ii] > s2[ii]) break;
		}
	}
	if (flag == -1)
	{
		string tmp = s1; s1 = s2; s2 = tmp;
		swap(l1, l2);
	}
	tt = flag;
	if (ii == l1) tt = 0;
}

void pre_make()
{
	memset(a, 0, sizeof(a));
	memset(b, 0, sizeof(b));
	for (int i = l1 - 1, cnt = 0; i >= 0; i--)
		a[cnt++] = s1[i] - '0';
	for (int i = l2 - 1, cnt = 0; i >= 0; i--)
		b[cnt++] = s2[i] - '0';
}

void print()
{
	flag = 0;
	for (int i = 2 * M - 1; i >= 0; i--)
	{
		if (c[i]) flag = 1;
		if (flag) printf("%d", c[i]);
	}
	if (!flag) printf("0");
	printf("\n");
}

void cal_plus()
{
	memset(c, 0, sizeof(c));
	for (int i = 0; i < M; i++)
		c[i] = a[i] + b[i];
	for (int i = 0; i < M * 2; i++)
		if (c[i] >= 10)
			c[i] -= 10, c[i + 1]++;
	print();
}

void cal_minus()
{
	memset(c, 0, sizeof(c));
	for (int i = 0; i < M; i++)
		c[i] = a[i] - b[i];
	for (int i = 0; i < M * 2; i++)
		if (c[i] < 0)
			c[i] += 10, c[i + 1]--;
	print();
}

void cal_multiply()
{
	memset(c, 0, sizeof(c));
	for (int i = 0; i < M; i++)
	{
		int cnt = 0;
		for (int j = 0; j < M; j++)
			c[i + cnt++] += a[i] * b[j];
	}
	for (int i = 0; i < M * 2; i++)
		while (c[i] >= 10)
			c[i] -= 10, c[i + 1]++;
	print();
}

void solve()
{
	if (aa > 0 && bb > 0)
	{
		if (tt == 1)
			cal_plus(), cal_minus();
		else if (tt == 0)
		{
			cal_plus(); printf("0\n");
		}
		else if (tt == -1)
		{
			cal_plus(); printf("-"); cal_minus(); 
		}
		cal_multiply();
	}
	else if (aa > 0 && bb < 0)
	{
		if (tt == 1)
			cal_minus(), cal_plus();
		else if (tt == 0)
		{
			printf("0\n"); cal_plus();
		}
		else if (tt == -1)
		{
			printf("-"); cal_minus(); cal_plus();
		}
		printf("-"); cal_multiply();
	}
	else if (aa < 0 && bb > 0)
	{
		if (tt == 1)
		{
			printf("-"); cal_minus(); 
		}
		else if (tt == 0)
			printf("0\n");
		else if (tt == -1)
			cal_minus(); 
		printf("-"); cal_plus();
		printf("-"); cal_multiply();
	}
	else if (aa < 0 && bb < 0)
	{
		printf("-"); cal_plus();
		if (tt == 1)
		{
			printf("-"); cal_minus();
		}
		else if (tt == 0)
			printf("0\n");
		else if (tt == -1)
			cal_minus();
		cal_multiply();
	}
	else if (aa == 0)
	{
		if (bb < 0) printf("-");
		cout << s1 << endl;
		if (bb > 0) printf("-");
		cout << s1 << endl;
		printf("0\n");
	}
	else if (bb == 0)
	{
		if (aa < 0) printf("-");
		cout << s1 << endl;
		if (aa < 0) printf("-");
		cout << s1 << endl;
		printf("0\n");
	}
}
int main()
{
	int cas = 0;
	while (cin >> s1 >> s2)
	{	
		if (s1 == "0" && s2 == "0") break;
		if (cas) printf("\n");
		pre_check();
		pre_make();
		solve();
		cas++;
	}
}
/*//已注明转载 ...................................................................................................................*/ 