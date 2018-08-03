#include<iostream>
#include<cmath>
#define eps 0.00000001
using namespace std;
int main()
{
    double t;
   while(cin>>t&&t)
   {
     int st=33;
     bool flagfu=0;
     if(t<0){
       flagfu=1;
       t=-t;
     }  
     while(st--)
     {
       long double temp1=pow(t,1.0/st*1.0)+eps;
       long double temp2=pow(((int)temp1)*1.0,st);
       
       if(fabs(t-temp2)<eps)
       {
         if(st%2==0&&flagfu)
           continue;
         else
           break;  
       }
     }
     cout<<st<<endl;
  }
}         