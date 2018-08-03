#include<stdio.h>
#include<string>
#include<cstring>
#include<iostream>
using namespace std;
char a[105][105],b[105][105];
int main()
{
int t,r,c,n,i,j;
bool flag=0;
scanf("%d",&t);
while(t--)
{if(flag)
          printf("\n");
flag=1;
scanf("%d%d%d",&r,&c,&n);
for(i=0;i<r;i++)
scanf("%s",a[i]);
while(n--)
{
for(i=0;i<r;i++)
strcpy(b[i],a[i]);
for(i=0;i<r;i++)
for(j=0;j<c;j++)
{
if(a[i][j]=='R')
{
if(a[i][j-1]=='S') b[i][j-1]='R';
if(a[i][j+1]=='S') b[i][j+1]='R';
if(a[i-1][j]=='S') b[i-1][j]='R';
if(a[i+1][j]=='S') b[i+1][j]='R';
}
else if(a[i][j]=='S')
{
if(a[i][j-1]=='P') b[i][j-1]='S';
if(a[i][j+1]=='P') b[i][j+1]='S';
if(a[i-1][j]=='P') b[i-1][j]='S';
if(a[i+1][j]=='P') b[i+1][j]='S';
}
else if(a[i][j]=='P')
{
if(a[i][j-1]=='R') b[i][j-1]='P';
if(a[i][j+1]=='R') b[i][j+1]='P';
if(a[i-1][j]=='R') b[i-1][j]='P';
if(a[i+1][j]=='R') b[i+1][j]='P';
}
}
for(i=0;i<r;i++)
strcpy(a[i],b[i]);
}
for(i=0;i<r;i++)
printf("%s\n",a[i]);

}
return 0;
}
