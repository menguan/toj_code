#include<iostream>
#include<cmath>
using namespace std;
double x[600],y[600];
int main()
{
  int n;
  int id1,id2;
  cin>>n;
  double max=0;
  for(int i=0;i<n;i++)
  {
    cin>>x[i]>>y[i];
  }
  for(int i=0;i<n-1;i++)
  {
    for(int j=i+1;j<n;j++)
    {
      
      double temp=hypot(x[i]-x[j],y[i]-y[j]);
      if(temp>max)
      {
        id1=i+1;id2=j+1;
        max=temp;
      }
    }
  }
  cout<<id1<<" "<<id2<<endl;
  //while(1);        
}  
  
  
  