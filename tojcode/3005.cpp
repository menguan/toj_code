#include<iostream>
#include<string>
#include<stdio.h>
using namespace std;
int main()
{
    int a,count=1;
    cin>>a;
    while(a--)
    {
        long double a;
        string s;
        cin>>a>>s;
        if(s=="kg")
        {
            double t=a*2.2046;
            
            printf("%d %.4f ",count,t);
            cout<<"lb\n";
        }
        else if(s=="l")
        {    
            double t=a*0.2642;
            printf("%d %.4f ",count,t);
            cout<<"g\n";
        }
        else if(s=="lb")
        {    
            double t=a*0.4536;
            printf("%d %.4f ",count,t);
            cout<<"kg\n";
        }
        else if(s=="g")
        {    
            double t=a*3.7854;
            printf("%d %.4f ",count,t);
            cout<<"l\n";
        }
        count++;
    }
    return 0;
} 