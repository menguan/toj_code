#include<iostream>
#include<string>
#include<cstring>
#include<map>
#include<stdio.h>
using namespace std;
const int MAX = 1005;
int main()
{
	int cas;
	scanf("%d", &cas);
	while(cas--)
	{
		getchar();
		char str[MAX];
		gets(str);

		int len = strlen(str);
		string nameStr = "";
		int nameNum = 0;
		map <string,int>name1;
		map <int,string>nameF;

		for(int i = 0; i <= len; i++)
		{
			if(str[i] != ' ' && str[i] != '\0')
				nameStr += str[i];
			else
			{
				name1[nameStr] = ++nameNum;
				nameF[nameNum] = nameStr;
				nameStr = "";
			}
		}

		gets(str);
		int n;
		scanf("%d", &n);
		int temp = n % nameNum;
		int ans;
		for(int i = 1; i < nameNum; i++)
		{
			nameF[i+nameNum] = nameF[i];
		}
		if(temp == 0)
		{
			if(name1[str] == 1)
				ans = nameNum;
			else
				ans = name1[str] - 1;
		}
		else
		{
			ans = name1[str] + temp - 1;
		}
		cout<<nameF[ans]<<endl;
	}
}
