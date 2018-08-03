#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
    int n;
    cout<<"PERFECTION OUTPUT"<<endl;
    while(cin>>n,n)
    {
        int sum=0;
        for(int i=1;i<=n/2;i++)
        {
            if(n%i==0)
                sum+=i;
        }
        cout<<setw(5)<<n<<"  ";
        if(sum==n)
            cout<<"PERFECT"<<endl;
        else if(sum<n)
            cout<<"DEFICIENT"<<endl;
        else if(sum>n)
            cout<<"ABUNDANT"<<endl;
    }
    cout<<"END OF OUTPUT"<<endl;

    return 0;
}