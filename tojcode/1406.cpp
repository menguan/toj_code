#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;
char maze[3][6]={" /\\", "/__\\"};
char ans[3000][3000];
int rr,cc;
void outone (int r,int c)
{
    for(int i=0;i<3;i++)
    ans[r][c+i]=maze[0][i];
    for(int i=0;i<4;i++)
    ans[r+1][c+i]=maze[1][i];
}
void rec(int r,int c,int n)
{
    if(1==n)
    {
        outone(r,c);
        return ;
    }
    rec(r,c,n-1);
    rec(r+(1<<(n-1)),c-(1<<(n-1)),n-1);
    rec(r+(1<<(n-1)),c+(1<<(n-1)),n-1);
}
void output()
{
    for(int i=0;i<rr;i++)
    {
        for(int j=0;j<cc-rr+i+1;j++)
        {
            printf("%c",ans[i][j]);
        }
        printf("\n");
    }
}
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        if(n==0) break;
        rr=1<<n;
        cc=1<<(n+1);
        for(int i=0;i<rr;i++)
        for(int j=0;j<cc;j++)
        ans[i][j]=' ';
        rec(0,(1<<n)-2,n);
        output();
        printf("\n");
    }
}

