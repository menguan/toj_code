#include<stdio.h>
int dir[8][2]={{1,1},{1,0},{0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1}};
char str1[100][100],str2[100][100];
int n;
int bfs(int x,int y)
{
int count,xx,yy,i;
count=0;
for(i=0;i<8;i++)
{
xx=x+dir[i][0];
yy=y+dir[i][1];
if(xx<=0||yy<0||xx>n||yy>=n)
continue;
if(str1[xx][yy]=='*')
count++;
}
return count;
}
int main()
{
int i,j,k,frag,s=0;
while(scanf("%d",&n)!=EOF)
{
for(i=1;i<=n;i++)
{
scanf("%s",str1[i]);
}
frag=0;
for(i=1;i<=n;i++)
{
scanf("%s",str2[i]);
for(j=0;j<n;j++)
{
if(str2[i][j]=='x')
{
if(str1[i][j]=='*')
frag=1;
}
}
}
if(frag==1)
{
for(i=1;i<=n;i++)
{
for(j=0;j<n;j++)
{
if(str1[i][j]=='*')
{
printf("*");
}
else
{
if(str2[i][j]=='x')
printf("%d",bfs(i,j));
else
printf(".");
}
}
printf("\n");
}
}
else
{
for(i=1;i<=n;i++)
{
for(j=0;j<n;j++)
{
if(str2[i][j]=='x')
printf("%d",bfs(i,j));
else
printf(".");
}
printf("\n");
}
}
}
return 0;
 
}
