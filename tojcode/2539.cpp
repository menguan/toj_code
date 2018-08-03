#include <stdio.h>
#include <string.h>
char s1[100],s2[100],s3[200],s[200],s0[200];
int main()
{
    int i,n1;
    scanf("%d",&n1);
    for (i=1;i<=n1;i++)
    {
        printf("%d ",i);
        int i,j,n,t;
    scanf("%d",&n);
    scanf("%s%s%s",s1,s2,s3);
    strcpy(s,s1);
    strcat(s,s2);
    strcpy(s0,s);
    for (t=0;strcmp(s,s3)!=0;t++)
    {
        for (j=0;j<n;j++) s1[j]=s[j];
        for (i=0;i<n;i++,j++) s2[i]=s[j];
        for (i=0,j=0;i<n;i++,j+=2){s[j]=s2[i];s[j+1]=s1[i];}
        if (strcmp(s0,s)==0) {t=-1;break;}
    }
    printf("%d\n",t);
    }
}
