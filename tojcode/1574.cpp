#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
int main()
{
    double month[12];
    double sum;
    for(int i=0;i<12;i++)
    {
        cin>>month[i];
        sum+=month[i];
    }
    
    if(sum==0)
    cout<<"$0.00"<<endl; 
    cout<<"$"<<setprecision(2)<<fixed<<sum/12.0<<endl;
    
    return 0;
} 