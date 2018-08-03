#include <stdio.h>
#include <string.h>

int k;
char str[100];

int set(int r,int a,int b)
{
    int i,s = 1;
    for(i = 0; i<b; i++)
        s*=a;
    return s*r;
}

void change(int a,int b)
{
    int num = 0,i,r;
    int len = strlen(str);
    for(i = 0; i<len; i++)
    {
        if(str[i] >= '0' && str[i] <= '9')
            r = str[i] - '0';
        else if(str[i] >= 'A' && str[i] <= 'F')
            r = str[i] - 'A' + 10;
        if(r)
            num+=set(r,a,len-1-i);
    }
    k = 0;
    while(num)
    {
        r = num%b;
        if(r < 10 && r >=0)
            str[k++] = r+'0';
        else
            str[k++] = r+55;
        num/=b;
    }
}

int main()
{
    int a,b,i;
    while(~scanf("%s%d%d",str,&a,&b))
    {
        change(a,b);
        if(k>7)
        {
            printf("  ERROR\n");
            continue;
        }
        for(i = 1; i<=7-k; i++)
        {
            printf(" ");
        }
        for(i = k-1; i>=0; i--)
        {
            printf("%c",str[i]);
        }
        printf("\n");
    }

    return 0;
}