#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<iomanip>
using namespace std;
int f[100];
int r[100];
double temp;
int main()
{
    int m,n;
    while(cin>>m,m)
    {
       
       cin>>n;
       vector<double> v;
       for(int i=0;i<m;i++)
        cin>>f[i];
       for(int i=0;i<n;i++)
         cin>>r[i];
       for(int i=0;i<m;i++)
       {
         for(int j=0;j<n;j++)
         {
           v.push_back(f[i]*1.0/r[j]);
         }           
       }
       sort(v.begin(),v.end());
      temp=v[1]/v[0];
      double ans=temp;
      for(int i=2;i<v.size();i++)
      {
           temp=v[i]/v[i-1];
           if(temp>ans)
             ans=temp;
      }    
      cout<<setprecision(2)<<fixed<<ans<<endl;
    }
}                   
