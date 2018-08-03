#include<iostream>
using namespace std;
bool a[10010];
void f()
{
  a[1]=1;
  a[2]=1;
  a[3]=0;
  a[4]=1;
  a[5]=1;
  a[6]=0;
  a[7]=1;
  for(int i=8;i<10010;i++)
  {
    if(a[i-5]==0||a[i-4]==0||a[i-2]==0||a[i-1]==0)
    {
      a[i]=1;
    }
    else
      a[i]=0;
  }
}
int main()
{
  f();
  int n;
  while(cin>>n,n)
  {
    if(a[n])
      cout<<"Happy"<<endl;
    else
      cout<<"Unhappy"<<endl;
  }
} 