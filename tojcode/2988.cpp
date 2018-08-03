#include<iostream>
using namespace std;
int main(){
  int t;
  cin>>t;
  int n,l,w;
  int p,s;
  while(t--)
  {
    cin>>n>>l>>w;
    double time=l*1.0/w;
    int count=0;
    while(n--)
    {
      cin>>p>>s;
      if(s<=0)
        count++;
      else
      {
        if(s>=w&&p!=0)
        {}
        else if(p==0)
        count++;
        
        else  if(p*1.0/(w-s)<=time)
        {
          count++;
        }
      }
    }
    cout<<count<<endl;
  }
}          