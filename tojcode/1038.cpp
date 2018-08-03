#include<stdio.h>
#include<math.h>
#include<string.h>
int s[32767],num=1;
bool u[32767];
void preper()
{
    int i,j;
    memset(u,true,sizeof(u));
    for(i=2;i<=32767;i++)
    {
        if(u[i]) s[num++]=i;
        for(j=1;j<num;j++)
        {
            if(i*s[j]>32767) break;
            u[i*s[j]]=false;
            if(i%s[j]==0) break;
        }
    }
}
int main()
{
    int i,a,b,sum=1,count=0;
    char c;
    preper();
    while(1)
    {
        scanf("%d",&a);
        if(a==0) break;
        scanf("%d",&b);
        sum*=floor(pow(a,b)+0.5);
        c=getchar();
        if(c=='\n')
        {
            sum-=1;
            for(i=num-1;i>=1;i--)
            {
                if(sum%s[i]==0)
                {
                    count=0;
                    while(sum%s[i]==0)
                    {
                        count++;
                        sum/=s[i];
                    }
                if(sum!=1)    printf("%d %d ",s[i],count);
                else {printf("%d %d\n",s[i],count); break;}
                }
            }
            sum=1;
        }
    }
    return 0;
}
