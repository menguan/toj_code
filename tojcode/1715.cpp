#include<iostream>
#include<cmath>
#include<stdio.h>
using namespace std;
const double PI = 3.14159265358;
int main()
{
   int a;
   int k;
   double n;
   double R,r;
      
   cin>>a;
   for(k=1;k<=a;k++)
   {
       cin>>R>>n;
       double angle =PI/n;
       r=R*sin(angle)/(sin(angle)+1);
       cout<<"Scenario #"<<k<<":"<<endl;
       
       printf("%.3f\n",r);
       
       cout<<endl;
   }
   return 0;
};
}