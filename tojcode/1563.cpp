#include<stdio.h>
#include<string.h>
int len;

int mult(int *num,int *temp,int n)
{
    int i,t=0;
    for(i=0;i<len;++i)
    {
        t=num[i]*n+t;
        temp[i]=t%10;
        t/=10;
    }
    if(t)
        return 0;
    return 1;
}

int Judge(int *num,int *temp)    
{
    int i,j,k;
    for(i=0;i<len;++i)
    {
        k=0;
        if(temp[i]==num[0])
        {
            j=i;
            while(k<len&&num[++k]==temp[(++j)%len]);
            if(k==len)
                return 1;  
        }
    }
    return 0;
}

int main()
{
    char s[65];
    int num[65];
    int temp[65];
    int i,j,flag;
    while(gets(s))
    {
        flag=1;
        len=strlen(s);
        memset(num,0,sizeof(num));
        for(i=len-1,j=0;i>=0;--i)
            num[j++]=s[i]-'0';
        for(i=2;i<=len;++i)
        {
            memset(temp,0,sizeof(temp));
            if(mult(num,temp,i))    
            {
                if(Judge(num,temp)==0)
                {
                    printf("%s is not cyclic\n",s);
                    flag=0;
                    break;
                }
            }
            else 
            {
                printf("%s is not cyclic\n",s);
                flag=0;
                break;
            }

        }
        if(flag)
            printf("%s is cyclic\n",s);
    }
    return 0;
}