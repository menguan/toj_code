#include<iostream>
using namespace std;
int main()
{
    int a;
    cin>>a;
    int count=1;
    while(a--)
    {
        long long m,n;
        cin>>m>>n;
        long long t=(m+n)*(n-m+1)/2;
        cout<<"Scenario #"<<count<<":"<<endl;
        cout<<t<<endl<<endl;
        count++;
    }
    return 0;
}    