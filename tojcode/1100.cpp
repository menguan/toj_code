#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
bool factor(int a,int b)
{
     int r;
     r=a%b;
     while(r)
     {
          a=b;
          b=r;
          r=a%b;
     }
     if(b==1)
       return  1;
     else
       return 0;
}
int main()
{
    int a;
    while(cin>>a,a)
    {
        int count=0;
        int sum=a*(a-1)/2;
        int b[a];
        for(int i=0;i<a;i++)
        {
            cin>>b[i];
        }
        for(int i=0;i<a-1;i++)
        {
            for(int j=i+1;j<a;j++)
            {
                if(factor(b[i],b[j])==1)
                     count++;
            }
        }
        
        
        if(count==0)
            cout<<"No estimate for this data set."<<endl;
        else
        {
            double t=sqrt((6*sum)*1.0/count);
            
            cout<<setprecision(6)<<fixed<<t<<endl;
        }
    }
    return 0;
} 