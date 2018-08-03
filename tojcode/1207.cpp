#include<iostream>
#include<cstdlib>
#include<stdio.h>
#include<string.h>
#include<string.h>
using namespace std;
int sg[50];
int num[7];
bool dfs(int sum)
{
    if(sum>=31) return 0;
    for(int i=1;i<=6;i++)
    {
        if(num[i]&&sum+i<=31)
        {
            --num[i];
            if(dfs(sum+i)==0) 
            {++num[i];return 1;}
             ++num[i];
        }
    }
    return 0;
}
int main()
{
    char str[35];
    while(scanf("%s",str)!=EOF)
    {
        int sum=0;
        int l=strlen(str);
        for(int i=1;i<=6;i++)
        num[i]=4;
        for(int i=0;i<l;i++)
        {
            sum+=str[i]-'0';
            num[str[i]-'0']--;
        }printf("%s ",str);
        if(sum>=31)
        {
            
            if(l&1) puts("A");
            else puts("B");
            continue;
        }
        
        if(dfs(sum))
		{
			if(l&1)  puts("B");
            else puts("A");
		}
        else
        {
         if(l&1)  puts("A");
         else puts("B");
       }
    }
}
