#include<stdio.h>
#include<cstring>
char str[120];
int pos(int now, int len)
{
    int i,j,k,t;
    for(i=now;i<len;i++)
    {
       if(str[i]==')')
       {  
           return i;
       }
       else if(str[i]>='1'&&str[i]<='9')
       { 
           if(str[i+1]!='(')
           {
              
              for(j=0;j<(str[i]-'0');j++)
              {
                  printf("%c",str[i+1]);
              }
              i++;
           }
           else
           { 
              for(j=0;j<(str[i]-'0');j++)
              {
                  k=pos(i+2,len);
              }
              i=k;
           }
       }
       else
       {
           printf("%c",str[i]);
       }
    }
}
int main()
{
    int n,len;
    scanf("%d",&n);
    while(n--)
    {
       scanf("%s",str);
       len=strlen(str);
       pos(0,len);
       printf("\n");
    }
    return 0;
}
