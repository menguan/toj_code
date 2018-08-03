#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int i=1;
    double a[100];
    a[0]=0.6;
    a[1]=0.7;
    for(int i=2;i<100;i++)
    {
        a[i]=a[i-1]*0.6+a[i-2]*0.5;
    }    
    
    while(n--)
    {
        int k;
        cin>>k;
        cout<<"Case "<<i<<": ";
        i++;
        cout<<setprecision(2)<<fixed<<a[k-1]<<endl;
    }
    return 0;
}   