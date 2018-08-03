#include<iostream>
#include<cmath>
#include<stdio.h>
#include<ctype.h>
using namespace std;
const double PI=acos(-1.0);
int main(){
    int i;
    int a,b,c;
    char cmd[1111];
    while(gets(cmd))
    {
        double ans=0;
        a=b=c=0;
        for(i=0;cmd[i];i++)
        {
            if(isdigit(cmd[i]))
            {
                while(cmd[i]&&isdigit(cmd[i]))
                {
                    a=a*10+cmd[i]-'0';
                    i++;
                }
                break;
            }
        }
        for(;cmd[i];i++)
        {
            if(isdigit(cmd[i]))
            {
                while(cmd[i]&&isdigit(cmd[i]))
                {
                    b=b*10+cmd[i]-'0';
                    i++;
                }
                break;
            }
        }
        for(;cmd[i];i++)
        {
            if(isdigit(cmd[i]))
            {
                while(cmd[i]&&isdigit(cmd[i]))
                {
                    c=c*10+cmd[i]-'0';
                    i++;
                }
                break;
            }
        }
     
        double r=a*b/(10.0*100)+c*2.54/2;
        ans=r*2*PI;
        printf("%s: %.0f\n",cmd,ans);
    }
}
     
