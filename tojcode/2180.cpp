#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<stdio.h>
using namespace std;
int main()
{
  int a,b,t;
  scanf("%d",&t);
  int cas=1;
  while(t--)
  {
     scanf("%d/%d",&a,&b);
     printf("case %d: [",cas++);
     bool flag=0;
     if(a<0)
     {
        a=a*(-1);
        int tmp=a/b+1;
        a=tmp*b-a;
        flag=1;
        printf("%d,",-tmp);
     }
     if(flag&&a==b)
     {
       printf("1]\n");
       continue;
     }
     if(!flag)
     {
     if(a%b==0)
     {
       if(a==b)
         printf("0,%d]\n",a/b);
       else
         printf("%d,1]\n",a/b-1);
       continue;
     }
     
     if(a>b)
     {
       int tmp=a/b;
       a=a-tmp*b;
       printf("%d,",tmp);
     }
     else
       printf("0,");
     }    
     while(b%a!=0)
     {
        int tmp=b/a;
        b=b-tmp*a;
        swap(a,b);
       // cout<<a<<" "<<b<<endl;
        // system("pause");
        printf("%d,",tmp);
     }
     printf("%d,1]\n",b/a-1);
     
   }
}  
