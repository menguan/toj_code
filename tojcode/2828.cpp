#include<iostream>
#include<cstring>
using namespace std;
bool ff[20000];
int main()
{
  int f,k,l,i;
  memset(ff,0,sizeof(ff));
  cin>>f>>k;
  int count=f;
  while(k--)
  {
    cin>>l>>i;
    for(int k=l;k<=f;k+=i)
    {
      if(ff[k]==0)
      {
        ff[k]=1;
        count--;
      }
    }
  }
  cout<<count<<endl;
  //while(1);
}        