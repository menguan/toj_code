#include<iostream>
#include<stdio.h>
using namespace std;
char s[100];
int main()
{
  while(gets(s))
  {
    int hh=(s[0]-'0')*10+s[1]-'0';
    int mm=(s[2]-'0')*10+s[3]-'0';
    int ss=(s[4]-'0')*10+s[5]-'0';
    int cc=(s[6]-'0')*10+s[7]-'0';
    long long ans=(hh*360000+mm*6000+ss*100+cc)*125/108;
    printf("%.7d\n", ans);  
  }
}    
    