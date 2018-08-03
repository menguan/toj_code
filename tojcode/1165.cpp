#include<iostream>
#include<stdio.h>
#include<cstring>
#include<ctype.h>
#include<iomanip>
using namespace std;
char s[101010];
int main()
{
    int n;
    scanf("%d\n",&n);
    int cas=1;
    while(n--)
    {
        gets(s);
        bool ip=0,ii=0,iu=0;
        double p=0,i=0,u=0;
        for(int j=0;j<strlen(s);j++)
        {
            if(s[j]=='=')
            {
                   if(s[j-1]=='P')
                   {
                       ip=1;
                       int d=1;
                       bool dian=0;
                       double dd=0.1;
                       for(int k=j+1;s[k]!='W';k++)
                       {
                           if(isdigit(s[k]))
                              {
                                  if(dian)
                                  {

                                    p+=dd*(s[k]-'0');dd=dd/10.0;}
                                  else{
                                    p=p*10;
                                    p=p+s[k]-'0';
                                  }
                              }
                              if(s[k]=='.')
                                dian=1;
                              if(s[k]=='M')
                                p=p*1000000;
                                if(s[k]=='m')
                                p=p/1000.0;
                                if(s[k]=='k')
                                p=p*1000;
                       }
                   }
                   if(s[j-1]=='I')
                   {
                       ii=1;
                       int d=1;
                       bool dian=0;
                       double dd=0.1;
                       for(int k=j+1;s[k]!='A';k++)
                       {
                           if(isdigit(s[k]))
                              {
                                  if(dian)
                                  {

                                    i+=dd*(s[k]-'0');dd=dd/10.0;}
                                  else{
                                    i=i*10;
                                    i=i+s[k]-'0';
                                  }
                              }
                              if(s[k]=='.')
                                dian=1;
                              if(s[k]=='m')
                                i=i/1000.0;
                                if(s[k]=='M')
                                i=i*1000000;
                                if(s[k]=='k')
                                i=i*1000;
                       }
                   }
                   if(s[j-1]=='U')
                   {
                       iu=1;
                       int d=1;
                       bool dian=0;
                       double dd=0.1;
                       for(int k=j+1;s[k]!='V';k++)
                       {
                           if(isdigit(s[k]))
                              {
                                  if(dian)
                                  {

                                    u+=dd*(s[k]-'0');dd=dd/10.0;}
                                  else{
                                    u=u*10;
                                    u=u+s[k]-'0';
                                  }
                              }
                              if(s[k]=='.')
                                dian=1;
                              if(s[k]=='k')
                                u=u*1000;
                                if(s[k]=='m')
                                u=u/1000.0;
                                if(s[k]=='M')
                                u=u*1000000;
                       }
                   }
            }
        }
        cout<<"Problem #"<<cas++<<endl;
        if(ip==0)
        {
            cout<<"P="<<setprecision(2)<<fixed<<u*i<<"W"<<endl<<endl;
        }
        else if(ii==0)
        {
            cout<<"I="<<setprecision(2)<<fixed<<p/u<<"A"<<endl<<endl;
        }
        else if(iu==0)
        {
            cout<<"U="<<setprecision(2)<<fixed<<p/i<<"V"<<endl<<endl;
        }

    }
}

