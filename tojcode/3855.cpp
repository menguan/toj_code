#include<iostream>
#include<iomanip>
#include<string>
using namespace std;
int main()
{
  int n,m;
  char dish[101][101];
  string s;
  double price[101];
  while(cin>>n>>m)
  {
     for(int i=0;i<n;i++)
     {
       cin>>dish[i]>>price[i];
     }
     double sum=0;
     for(int j=0;j<m;j++)
     {
       cin>>s;
       for(int i=0;i<n;i++)
       {
         if(dish[i]==s)
         sum+=price[i];
       }
     }
     cout<<setprecision(2)<<fixed<<sum<<endl; 
  }
}        
       