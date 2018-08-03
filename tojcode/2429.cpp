#include<iostream>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<stdio.h>
using namespace std;

char ss[20005][25];
int num[20005];
int n,m;

int cmp(const void * a,const void * b)
{
    int i,ans;
    char *s1,*s2;
    s1=(char *)a;
    s2=(char *)b;
    for(i=0;i<m;i++)
    {
        ans=s1[i]-s2[i];
        if(ans==0)
           continue;
        else
           return ans;
    }
    return ans;
}

int main()
{
    int i,j,sum;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        if(n==0&&m==0)
           break;
        for(i=0;i<n;i++)
           scanf("%s",ss[i]);
        qsort(ss,n,sizeof(ss[0][0])*25,cmp);
        memset(num,0,sizeof(num));
        for(i=1,sum=0;i<=n;i++)
        {
            if(strcmp(ss[i],ss[i-1])==0)
               sum++;
            else
            {
                num[sum]++;
                sum=0;
            }
        }
        for(i=0;i<n;i++)
           printf("%d\n",num[i]);
    }
    
    return 0;
}
