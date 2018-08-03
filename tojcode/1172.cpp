#include<iostream>
#include<cstring>
#include<stdio.h>
using namespace std;
int map[205][205],pri;
char a[100],b[100];
char name[205][100];
int cou=0;
int find()
{
	for(int i=1;i<202;i++)
	{
		if(strcmp(name[i],a)==0)
		return i;
	}
	int len=strlen(a);
	for(int i=0;i<len;i++)
	{
		name[cou][i]=a[i];
	}
	name[cou][len]='\0';
	cou++;
	return cou-1;
}
int find1()
{
	for(int i=0;i<202;i++)
	{
		if(strcmp(name[i],b)==0)
		return i;
	}
	int len=strlen(b);
	for(int i=0;i<len;i++)
	{
		name[cou][i]=b[i];
	}
	name[cou][len]='\0';
	cou++;
	return cou-1;
}
int main()
{
	int n,m,cases=1;
	while(cin>>n>>m,n||m)
	{
		for(int i=0;i<202;i++)
		{
			for(int j=0;j<202;j++)
			map[i][j]=-1;
		}
		memset(name,0,sizeof(name))  ;
		cou=1;
		while(m--)
		{
			cin>>a>>b>>pri;
			int t1=find(); 
			int t2=find1();
			map[t1][t2]=map[t2][t1]=pri;
		}
		for(int k=1;k<=n;k++)
		{
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=n;j++)
				map[i][j]=max(map[i][j],min(map[i][k],map[k][j]));
			}
		}
		printf("Scenario #%d\n",cases++);
		cin>>a>>b;
		int t1=find();
		int t2=find1();

		printf("%d tons\n\n",map[t1][t2]);
	}
	return 0;
}
	
	
