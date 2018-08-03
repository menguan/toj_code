#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;
unsigned long f(char str[],int base)
{
         int len=strlen(str);
         unsigned long long  sum=0;
         
         for(int i=len-1,k=0;i>=0;i--,k++)
         {
              int t=str[i]-'0';
              sum+=t*(unsigned long long)pow(base,k*1.0);
         }
         return sum;
}   
int main()
{
    char s1[10000],s2[10000];
    int b1,b2;
    unsigned long long n1,n2;
    while(cin>>s1>>b1>>s2>>b2)
    {
         n1=f(s1,b1);
         n2=f(s2,b2);
         if(n1<n2)
           cout<<"<"<<endl;
         else if(n1==n2)
           cout<<"="<<endl;
         else
           cout<<">"<<endl;
    }
}                         
