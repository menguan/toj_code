#include <stdio.h>
#include <cstring>  //网上代码 
#define MAX_LEN 5001

int len,flag;
char code[MAX_LEN];
char hash[]="NOP";

int print(int n)
{
    int i=0;
    for(i=0;i<n;i++)
        putchar(code[i]);
    putchar('\n');
    return 0;
}

int check(int n)
{
    int i,j;
    int tmp=n/2;
    for(i=1;i<=tmp;i++)
    {
        for(j=n-1;j>=n-i;j--)
            if(code[j]!=code[j-i])
                break;
        if(j==n-i-1)
            return 0;
    }
    return 1;
}

int dfs(int depth)
{
    if(depth>len)
    {
        flag=1;
        print(depth-1);
        return 0;
    }
    int i;
    for(i=0;i<3;i++)
    {
        code[depth-1]=hash[i];
        if(check(depth))
            dfs(depth+1);
        if(flag==1)
            return 0;
    }
    return 0;
}

int main(void)
{
    while(scanf("%d",&len)!=EOF)
    {
        flag=0;
        if(len==0)
            break;
        dfs(1);
        if(flag==0)
            putchar('\n');
    }
    return 0;
}