#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int t;
    int a,b,c;
    cin>>t;
    for(int cas=1;cas<=t;cas++)
    {
       cin>>a>>b>>c;
       int ans=0;
       int temp;
       temp=min(a/2,c);
       ans+=temp;a-=temp*2;c-=temp;
       temp=min(a/2,b);
       ans+=temp;a-=temp*2;c-=temp;
       ans+=c/2;c-=c/2*2;
       temp=min(b,c);
       ans+=temp;b-=temp;c-=temp;
       ans+=a/3;a-=a/3*3;
       ans+=b/2;b-=b/2*2;
       temp=min(a,c);
       ans+=temp;a-=temp;c-=temp;
       temp=min(a,b);
       ans+=temp;a-=temp;b-=temp;
       ans+=(a%3!=0)+(b%2!=0)+(c%2!=0);
       cout<<"Case "<<cas<<": "<<ans<<endl;
    }
}
           
