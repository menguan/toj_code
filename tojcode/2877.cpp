#include<iostream>
using namespace std;
double a[200001],b[200001];
int main()
{
  int n,n1,n2;
  double sum1,sum2,av1,av2;
  cin>>n;
  while(n--)
  {
    cin>>n1>>n2;
    sum1=0;
    sum2=0;
    for(int i=0;i<n1;i++)
    {
      cin>>a[i];
      sum1+=a[i];
    }
    av1=sum1/n1;
    for(int i=0;i<n2;i++)
    {
      cin>>b[i];
      sum2+=b[i];
    }
    av2=sum2/n2;
    int count=0;
    for(int i=0;i<n1;i++)
    {
      if(a[i]<av1&&a[i]>av2)
      count++;
    }
    cout<<count<<endl;
  }
}        
  