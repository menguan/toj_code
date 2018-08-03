#include<iostream>
#include<stdio.h>
const double PI=3.1415927;
using namespace std;
int main()
{
    double dia,t;
    int r,count=1;
    while(cin>>dia>>r>>t&&r!=0)
    {
        double dis=PI*dia*r/12/5280;
        double m=dis/t*3600;
        cout<<"Trip #"<<count<<": ";
        printf("%.2f",dis);
        cout<<" ";
        printf("%.2f\n",m);
        
        count++;
    }
    return 0;
} 