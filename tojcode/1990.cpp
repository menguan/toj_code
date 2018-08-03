#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;
struct f
{
  int front;
  int back;
  double ratio;
}c[21];
bool cmp(f a,f b)
{
  return (a.ratio<b.ratio);
}
int main()
{
  int a[3],b[7];
  for(int i=0;i<3;i++)
    cin>>a[i];
  for(int i=0;i<7;i++)
    cin>>b[i];
  int count=0;  
  for(int i=0;i<3;i++)
  for(int j=0;j<7;j++)
  {
    c[count].front=i+1;
    c[count].back=j+1;
    c[count].ratio=a[i]*1.0/b[j]*1.0;
    count++;
  }
  sort(c,c+21,cmp);
  for(int i=0;i<21;i++)
  {
    cout<<setprecision(2)<<fixed<<c[i].ratio<<" "<<c[i].front<<" "<<c[i].back<<endl;
  }
  
}                
  