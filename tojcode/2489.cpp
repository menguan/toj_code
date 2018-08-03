#include<iostream>
using namespace std;
char a[15][20]={"0","0","6","12","90","360","2040","10080","54810","290640","1588356","8676360","47977776","266378112","1488801600"};
int main()
{
  int n;
  cin>>n;
  while(n--)
  {
    int m;
    cin>>m;
    cout<<a[m]<<endl;
  }
}   