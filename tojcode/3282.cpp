#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
vector<long long> now;
vector<long long> temp;
long long a[30];
int main()
{
    int t;int n;long long m;
    cin>>t;
    while(t--)
    {
         cin>>n>>m;
         for(int i=0;i<n;i++)
           cin>>a[i];
         now.clear();temp.clear();
         int nsum=0;
         nsum=a[n-2]+a[n-1];
         now.push_back(a[n-2]-a[n-1]);
         for(int i=n-3;i>=0;i--)
         {
             temp=now;
             //cout<<"kk"<<endl;
             //for(int i=0;i<now.size();i++) cout<<now[i]<<" ";
             //cout<<endl;
             now.clear();
             temp.push_back(nsum);
             nsum+=a[i];
             for(int j=0;j<temp.size();j++)
             {
                 now.push_back(a[i]-temp[j]);
                 now.push_back(a[i]+temp[j]);
             }
         }
         bool flag=0;
         for(int i=0;i<now.size();i++)
         {
                    
                    if(now[i]==m)
                      {flag=1;break;
                      }
         }
         if(flag)
           cout<<"Yes"<<endl;
         else
           cout<<"No"<<endl;
    }
}       
