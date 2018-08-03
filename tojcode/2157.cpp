#include<iostream>
using namespace std;
int main()
{
  int n,_n,num,count=1;
  cin>>n;
  while(n--)
  {
    cin>>_n>>num;
    int re=0;
    for(int i=2;(i+1)*i<=2*num;i++)
    {
      if((num-(i+1)*i/2)%i==0)
        re++;
    }
    cout<<count++<<" "<<re<<endl;
  }
}     