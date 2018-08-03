#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    long long a,b,c,s[100010];
    long long ans;long long temp;
    while(cin>>a>>b>>c)
    {
       for(int i=0;i<c;i++)
         s[i]=(b+i)/c-(a-1+i)/c;
       ans=s[0]/2;
       for(int i=1;i<c;i++)
       {
          if(c%2==0&&i==c/2)
          {
             temp=s[i]/2;
             ans+=temp;
          }
          else
          {
              temp=min(s[i],s[c-i]);
              ans+=temp;
              s[i]-=temp;s[c-i]-=temp;
          }
       }
       cout<<ans<<endl;
    }
}                
          
                                   
                         
