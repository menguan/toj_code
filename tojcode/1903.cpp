#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string.h>
using namespace std;
struct node
{
    char s[10];//单词 
    char st[10];//单词内部排序后 
    bool operator<(const node&b)const
    {
       return strcmp(s,b.s)<0;
    }
}a[110];
int main()
{
    char s[10];
    int i,n=0;
    while(scanf("%s",s),s[0]!='X')
    {
        strcpy(a[n].s,s);
        sort(s,s+strlen(s));
        strcpy(a[n].st,s);
        n++;
    }
    sort(a,a+n);
    bool flag;
    while(scanf("%s",s),s[0]!='X')
    {
        sort(s,s+strlen(s));
        flag=0;
        for(i=0;i<n;i++)//所有单词遍历浪费时间但写着省事 
          if(strcmp(a[i].st,s)==0)
            flag=1,printf("%s\n",a[i].s);
        if(!flag)
        puts("NOT A VALID WORD");
        puts("******");
    }
    return 0;
}
