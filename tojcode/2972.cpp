#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int a[1000010];
int main()
{
    long long ans;
    long long sum;
    int t;int n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        sum=0;
        ans=0;    
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            //sum+=a[i];
        }
        //sum/=n;
        sort(a,a+n);
        for(int i=0;i<n;i++)
        {
           ans+=abs(a[n/2]-a[i]);
        }
        cout<<ans<<endl;
    }
}     
              
    
