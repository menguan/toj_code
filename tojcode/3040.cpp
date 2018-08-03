#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
char a[10000005];
int ans[10000005];
int cas;
int main()
{
    cas=1;
    while(scanf("%s",a))
    {
        if(a[0]=='0')
            break;
        int len=strlen(a);
        ans[len]=0;
        for(int i=len-1; i>=0; i--)
        {
            ans[i]=a[i]-'0'-ans[i+1];
            if(ans[i]<0)
            {
                ans[i]+=10;
                if(i-1>=0)
                  a[i-1]--;
            }
        }
        printf("%d. ",cas++);
        if(ans[0]<=0)
        {
            printf("IMPOSSIBLE\n");
        }
        else
        {
            for(int i=0; i<len; i++)
            {
                printf("%d",ans[i]);
            }
            printf("\n");
        }
    }
}
