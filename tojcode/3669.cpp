#include<iostream>
#include<iomanip>
#include<algorithm>
using namespace std;
int main()
{
  double sum,v,ave;
  int t,n,m,k,count=1;
  cin>>t;
  while(t--)
  {
    cin>>n>>m>>k;
    sum=0; 
    for(int i=0;i<n;i++)
    {
      cin>>v;
      sum+=v;
    }
    ave=sum/n;  
    //cout<<ave<<endl;  
    cout<<"Case "<<count++<<": ";
    cout<<setprecision(5)<<fixed<<ave*m<<endl;
  }
}      
    