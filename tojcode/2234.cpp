#include <iostream>
#include <cstring>
using namespace std;

char a[100], b[100], s[100];
int aa[100], bb[100], num[100];
int la, lb, flag;

int getnum(char c)
{
	if (c >= '0' && c <= '9')
		return c - '0';
	else
		return c - 'A' + 10;
}

char getch(int c)
{
	if (c >= 0 && c <= 9)
		return c + '0';
	else
		return c - 10 + 'A';
}
void init()
{
	memset(aa, 0, sizeof(aa));
	memset(bb, 0, sizeof(bb));
	memset(num, 0, sizeof(num));
	la = strlen(a); lb = strlen(b);
	for (int i = la - 1, j = 0; i > 0; i--)
		aa[j++] = getnum(a[i]);
	for (int i = lb - 1, j = 0; i > 0; i--)
		bb[j++] = getnum(b[i]);
}

void compare()
{
	if (la < lb)  flag = 0;
	else if (la > lb) flag = 1;
	else
	{
		for (int i = la - 2; i >= 0; i--)
			if (aa[i] < bb[i])
			{
				flag = 0; break;
			}
			else if (aa[i] > bb[i])
			{
				flag = 1; break;
			}
	}
}

void print()
{
	bool start = 0;
	for (int i = 23; i >= 0; i--)
	{
		if (num[i] != 0)
			start = 1;
		if (start)
			cout<<getch(num[i]);
	}
	cout<<endl;
}
void jian(int c[],int d[],int lc,int ld)
{
     
            for (int i = 0; i < lc - 1; i++)
			{
				if (c[i] >= d[i])
					num[i] = c[i] - d[i];
				else if (c[i] < d[i])
				{
					c[i] += 16; c[i + 1]--; 
					for (int j = i + 1; j + 1 < lc - 1; j++)
					{
						if (c[j] < 0)
							c[j] += 16, c[j + 1]--;
						else break;
					}
					num[i] = c[i] - d[i];
				}
			}
}

void solve()
{
	flag = -1;
	if (a[0] == '-' && b[0] == '+')
	{
		cout<<a<<" "<<b<<endl;
		compare();
		if (flag == -1)
			cout<<"+0"<<endl;
		else if (flag == 0)
		{
			cout<<"+";
			jian(bb,aa,lb,la);
			print();
		}
		else
		{
			cout<<"-";
			jian(aa,bb,la,lb);
			print();
		}
		
	}
	else if (a[0] == '+' && b[0] == '-')
	{
		cout<<b<<" "<<a<<endl;
		compare();
		if (flag == -1)
			cout<<"+0"<<endl;
		else if (flag == 0)
		{
			cout<<"-";
			jian(bb,aa,lb,la);
			print();
		}
		else
		{
			cout<<"+";
			jian(aa,bb,la,lb);
			print();
		}
	}
	else
	{
		compare();
		if (a[0] == '+')
		{
			if (flag == 0 || flag == -1)
				cout<<a<<" "<<b<<endl;
			else
				cout<<b<<" "<<a<<endl;
			cout<<"+";
		}
		else
		{
			if (flag == 0 || flag == -1)
				cout<<b<<" "<<a<<endl;
			else
				cout<<a<<" "<<b<<endl;
			cout<<"-";
		}
		for (int i = 0; i < 23; i++)
		{
			num[i] += aa[i] + bb[i];
			if (num[i] >= 16)
				num[i] -= 16, num[i + 1]++;
		}
		print();
	}
}

int main()
{
	while(cin>>a>>b)
	{
		if (a[1] == '0' && b[1] == '0')
			break;
		init();
		solve();
	}
}
