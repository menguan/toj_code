#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
    double n,m,q;
    while(cin>>n>>m>>q)
    {
       double ans=(m+1-q)/(m+2);
       printf("%.4f\n",ans);
    }
}                
