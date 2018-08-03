#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<ctype.h>
using namespace std;
char s[5000];
int main()
{
    int t;int dot,ee;
    cin>>t;
    while(t--)
    {
        cin>>s;
        bool flag=1;dot=ee=0;
        int len=strlen(s);
        if(s[0]=='+'||s[0]=='-'||isdigit(s[0]))
        {
            for(int i=1;i<=len;i++)
            {
                if(flag==0)break;
                if(!isdigit(s[i])&&!isdigit(s[i-1])&&s[i-1]!='.'&&s[i-1]!='E'&&s[i-1]!='e')
                   flag=0;
                else if(s[i]=='.')
                {
                    dot++;
                    if(!isdigit(s[i - 1])||!isdigit(s[i + 1])) flag=0;
                    if(dot>1) flag=0;
                    if(ee>0)  flag=0;
                }
                else if(s[i]=='e'||s[i]=='E')
                {
                    ee++;
                    if(!isdigit(s[i-1]))
                        flag=0;
                    if(ee>2)
                        flag=0;
                }

            }
            if(!isdigit(s[len-1]))flag=0;
            if(flag)
                cout<<"LEGAL"<<endl;
            else
                cout<<"ILLEGAL"<<endl;
        }
        else
                cout<<"ILLEGAL"<<endl;
    }

}
