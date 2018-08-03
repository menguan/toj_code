#include<iostream>
#include<cstring>
#include<string>
using namespace std;
long long a[200];
long long b[200];
int main()
{
    int t;
    string s;
    cin>>t;
    int cas=1;
    while(t--)
    {
        memset(a,-1,sizeof(a));
        cin>>s;
        int len=s.length();
        a[s[0]]=1;
        long long cnt=0;
        for(int i=1;i<len;i++)
        {
           if(a[s[i]]==-1)
           {
               a[s[i]]=cnt;
               if(cnt==0) cnt+=2;
           else cnt++;
           }

        }
        long long bas=cnt;
        if(bas==0)bas=2;
        long long now=1;
        unsigned long long ans=0;
        for(int i=len-1;i>=0;i--)
        {
            //cout<<a[s[i]]<<" "<<now<<endl;
            ans+=a[s[i]]*now;
            now*=bas;

        }
        cout<<"Case #"<<cas++<<": ";
        cout<<ans<<endl;
    }
}
