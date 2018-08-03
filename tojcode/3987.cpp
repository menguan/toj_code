#include<iostream>
#include<cmath>
#define eps 1e-6
using namespace std;
int main()
{
    int a;
    cin>>a;
    while(a--)
    {
        long long b;
        cin>>b;
        bool t=0;
        if(b<0)
        {
          b*=-1;
          t=1;
        }      
        double c=pow(b,1/3.0);
        
        int d=(int)(c+eps);
        
        if(abs(d-c)<eps)
            {
              if(t==1)
                cout<<d*(-1)<<endl;
              else
                cout<<d<<endl;
              if(a!=0)
              cout<<endl;
            }   
        else
            {
              cout<<"Wrong Message!"<<endl;
              if(a!=0)
              cout<<endl;
            }   
    } 
    return 0;
}  