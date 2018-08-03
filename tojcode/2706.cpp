#include<iostream>
using namespace std;
int main()
{
    int n,a[30];
    cin>>n;
    for(int i=0;i<=n;i++)
        cin>>a[i];
    if(n<=1)
        cout<<"YES"<<endl;
    else if(n==2)
    {
        if(a[1]*a[1]-4*a[0]*a[2]>=0)
            cout<<"NO"<<endl;
        else
            cout<<"YES"<<endl;
    }        
    else if(n>2)
        cout<<"NO"<<endl;
    
}
