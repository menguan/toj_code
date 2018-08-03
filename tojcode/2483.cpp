#include<iostream>
using namespace std;
int main()
{   
    int n; 
    int ad,notad,re,adp;
    cin>>n;
    while(n--)
    {
      cin>>notad>>re>>adp;
      ad=re-adp;
      if(ad>notad)
      cout<<"advertise"<<endl;
      if(ad==notad)
      cout<<"does not matter"<<endl;
      if(ad<notad)
      cout<<"do not advertise"<<endl;
    }
    return 0;
}      