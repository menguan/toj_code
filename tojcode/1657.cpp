#include <stdio.h>
#include <string>
#include <algorithm>
#include <cstring> 
using namespace std;
char str[100000];
int main()
{
    int len,i,j,cnt,s,e;
    while(gets(str))
    {
        len = strlen(str);
        i = s = e = 0;//s是否是一个非连续子串的首位 e之前是否是一个非连续子串 
        while(1)
        {
            cnt = 1;
            while(str[i] == str[i+cnt] && cnt<10 && i<len)
            cnt++;
            if(i == len)
            {
                if(e)
                printf("1");
                break;
            }
            else if(cnt!=1)
            {
                s = 0;
                if(e)
                {
                    printf("1");
                    e = 0;
                }
                if(cnt<10)
                printf("%d%c",cnt,str[i]);
                else
                printf("%d%c",--cnt,str[i]);
            }
            else
            {
                e = 1;
                if(!s)
                {
                    printf("1");
                    s = 1;
                }
                printf("%c",str[i]);
                if(str[i] == '1')
                printf("%c",str[i]);
            }
            i+=cnt;
        }
        printf("\n");
    }

    return 0;
}
