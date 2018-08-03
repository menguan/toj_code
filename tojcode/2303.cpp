#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<sstream>
using namespace std;
string sig="negative";
string tmp[31]={"zero","one","two","three","four","five","six","seven","eight",
"nine","ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen",
"seventeen","eighteen","nineteen","twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety",
"hundred","thousand","million"};
int position(string str)
{
    for(int i=0;i<31;i++) if(tmp[i]==str) return i;
}
int val(int n)
{
    if(n>=20&&n<=27) return (n-18)*10;
    else if(n==28) return 100;
    else if(n==29) return 1000;
    else if(n==30) return 1000000;
    return n;
}
int main()
{
    string s;
    while(getline(cin,s),s!="")
    {
        istringstream sin(s);
        string str[100];
        int len=0;
        while(sin>>str[len]) len++;
        int cnt=0,tmp=0;
        for(int i=0;i<=len;i++)
        {
            if(i==len) {cnt+=tmp;break;}
            if(str[i]==sig) {printf("-");continue;}
            int tag=val(position(str[i]));
            if(tag==100) tmp*=tag;
            else if(tag>100) tmp*=tag,cnt+=tmp,tmp=0;
            else tmp+=tag;
        }
        printf("%d\n",cnt);
    }
    return 0;
}
