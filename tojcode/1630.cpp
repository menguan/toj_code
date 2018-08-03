#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int s[100010];
int gcd(int a,int b)
{
    return !b?a:gcd(b,a%b);
}
int main()
{
    char a[100010],b[100010];
    while( scanf("%s",a)&&strcmp(a,"-1") )
    {
        scanf("%s",b);
        int len1=strlen(a),len2=strlen(b),i,j,r,sum;
    memset(s,0,sizeof(s));
    r=len1>len2?len1:len2;
    for(j=0; j<r; j++)//枚举 取最大 
    {
        for(i=0; i+j<r; i++)//i移动的距离 
        if(a[j+i]==b[i])
        s[j]+=2;               
        for(i=0; i+j<r; i++)
        if(a[i]==b[j+i])     
        s[r+j]+=2;
    }                          
    for(i=0,sum=0; i<r+j; i++)
    {
        if(sum<s[i])
        sum=s[i];            
    }
    printf("appx(%s,%s) = ",a,b);
    if(len1+len2==sum)
      printf("1\n");
    else if(sum==0)
      printf("0\n");
    else
    {
        int t=gcd(sum,len1+len2);
        printf("%d/%d\n",sum/t,(len1+len2)/t);
    }
    }
} 
