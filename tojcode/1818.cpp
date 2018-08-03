#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
    double m,n;
    cin>>m;
    if(m==999)
    {
      cout<<"End of Output"<<endl;
      return 0;
    }
    while(cin>>n)
    {
        if(n==999)
        {
              cout<<"End of Output"<<endl;
              return 0;
        }
        double k=n-m;
        printf("%.2f\n",k);
        m=n;
    }
    return 0;
}