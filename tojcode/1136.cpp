#include<iostream>
using namespace std;
long long f[5843];
int prime[4]={2,3,5,7};
int main()
{
    int n;
    f[1]=1;
    for(int i=2;i<=5842;i++)
    {
        f[i]=2000000001;
        for(int j=0;j<4;j++)
        {
            for(int k=i-1;k>=1;k--)
            {
                if(f[k]*prime[j]<=f[i-1])
                   break;
                if(f[k]*prime[j]<f[i])
                   f[i]=f[k]*prime[j];
            }    
        }    
    }
    while(cin>>n,n)   
    {
        cout<<"The "<<n;
        if(n%10==1&&n%100!=11)cout<<"st ";
        else if(n%10==2&&n%100!=12)cout<<"nd ";
        else if(n%10==3&&n%100!=13)cout<<"rd ";
        else  cout<<"th ";
        cout<<"humble number is "<<f[n]<<"."<<endl;
    } 
    return 0;    
}   