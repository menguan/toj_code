#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
    int a;
    cin>>a;
    int count=1;
    while(a--)
    {
        int b,c;
        cin>>b>>c;
        double d;
        if(b%2==0||c%2==0)
        {
            d=b*c*1.0;
            cout<<"Scenario #"<<count<<":"<<endl;
            cout<<setprecision(2)<<fixed<<d<<endl;
            cout<<endl;
        }
        else
        {
            d=b*c*1.0-1+1.414;
            cout<<"Scenario #"<<count<<":"<<endl;
            cout<<setprecision(2)<<fixed<<d<<endl;
            cout<<endl;
        }
        count++;
    }
    return 0;
}  