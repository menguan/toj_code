#include<cstring>
#include<cmath>
#include<cstdio>
using namespace std;
int num[1001][16];
int main()
{
memset(num,0,sizeof(num));
 num[1][0]=num[1][3]=num[1][6]=num[1][12]=num[1][15]=1;
for(int i=2;i<=1000;i++)
{
 num[i][0]=num[i-1][15];
 num[i][3]=num[i-1][15]+num[i-1][12];
 num[i][6]=num[i-1][15]+num[i-1][9];
 num[i][9]=num[i-1][6];
 num[i][12]=num[i-1][15]+num[i-1][3];
 num[i][15]=num[i-1][15]+num[i-1][12]+num[i-1][6]+num[i-1][3]+num[i-1][0];
}
int cas,n;
while(scanf("%d",&cas)==1)
{
for(int i=1;i<=cas;i++)
{
scanf("%d",&n);
printf("%d %d\n",i,num[n][15]);
}
 
}
return 0;
}
