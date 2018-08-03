#include<iostream>
#include<iomanip>
using namespace std;

double change[6][6];
int c[100];
int main()
{
  for(int i=1;i<=5;i++)
  {
    for(int j=1;j<6;j++)
    {
      cin>>change[i][j];
    }
  }
  int t;
  double money;
  while(cin>>t,t)
  {
    for(int i=1;i<=t;i++)
    {
      cin>>c[i];
    }
    c[0]=1;
    cin>>money;
    for(int i=0;i<t;i++)
    {
      money*=change[c[i]][c[i+1]];
      money=(int)(money*100+0.5);
      money/=100;
    }
    money*=change[c[t]][c[0]];
    money=(int)(money*100+0.5);
    money/=100;
    cout<<setprecision(2)<<fixed<<money<<endl;
  }
}              