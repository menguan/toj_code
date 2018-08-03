#include <iostream>
#include <cstring>
#include <stdio.h>
#include <algorithm>
#include <ctype.h>
using namespace std;
#define maxn 30
using namespace std;
int m;
struct tree
{
	int left,right;
	char c;
}t[maxn];
void add(int n,char val)
{
	if(t[n].c==0)
	{
		t[n].c=val;
	}
	else if(t[n].c<val)
	{
		if(t[n].right==0)
			t[n].right=m++;
		add(t[n].right,val);
	}
	else
	{
		if(t[n].left==0)
			t[n].left=m++;
		add(t[n].left,val);
	}
}
void display(int n)
{
	cout<<t[n].c;
	if(t[n].left!=0)
		display(t[n].left);
	if(t[n].right!=0)
		display(t[n].right);
}
int main()
{
	char str[1000];
	while(1)
	{
		memset(t,0,sizeof(t));
		cin>>str;
		int len;
		len=strlen(str);
		m=2;
		char s;
		while(1)
		{
			cin>>s;
			if(isupper(s))
				str[len++]=s;
			if(s=='*'||s=='$')
				break;
		}

		int i;
		for(i=len-1;i>=0;i--)
			add(1,str[i]);

		display(1);
		cout<<endl;

		if(s=='$')
			break;
	}
}
