#include<iostream>
using namespace std;
int main()
{
    int n;
    int a;
    long long ans;
    long long sum;
    while(cin>>n,n)
    {
        sum=ans=0;
        for(int i=0;i<n;i++)
        {
            cin>>a;
            sum+=a;
            if(sum>0)ans+=sum;
            else ans-=sum;
        }
        cout<<ans<<endl;
    }
    return 0;
}