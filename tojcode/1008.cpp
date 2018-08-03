#include<stdio.h>
#include<string.h>

int main()
{
    int n,m,a[1000],i,j,t[1000],k,l;
    char s1[1000],s2[1000],b,c;
    while(scanf("%d",&n),n)
    {
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        for(i=0;i<n;i++)
        {
            j=i;
            for(t[i]=1;;t[i]++)
            {
                j=a[j]-1;
                if(i==j)
                {
                    break;
                }
            }
        }
        while(scanf("%d",&m),m)
        {
            getchar();
            gets(s1);
            j=strlen(s1);
            for(i=0;i<j;i++)
            {
                if(s1[i]=='/n')
                {
                    s1[i]=' ';
                }
            }
            for(i=j;i<=n;i++)
            {
                s1[i]=' ';
            }
            s1[n]=0;
            for(i=0;i<n;i++)
            {
                k=m%t[i];
                j=i;
                while(k--)
                {
                    j=a[j]-1;
                }
                s2[j]=s1[i];
            }
            s2[n]=0;
            for(i=n;s2[i]==' ';i--)
            {
                s2[i]=0;
            }
            printf("%s\n",s2);
        }
        printf("\n");
    }
    return 0;
}
