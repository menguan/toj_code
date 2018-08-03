#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
char map[55][55];
int n;
long long num[50][50];
int main()
{
int i,j,k;
while(scanf("%d",&n),n!=-1)
{
for(i=0;i<n;i++)
scanf("%s",map[i]);
memset(num,0,sizeof(num));
num[0][0]=1;
for(i=0;i<n;i++)
for(j=0;j<n;j++)
{
k=map[i][j]-'0';
if(k==0)continue;
if(j+k<n)
num[i][j+k]+=num[i][j];
if(i+k<n)
num[i+k][j]+=num[i][j];
}
printf("%lld\n",num[n-1][n-1]);
}
return 0;
}
