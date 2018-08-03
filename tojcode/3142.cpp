#include<iostream>
#include<algorithm>
using namespace std;
int d[2000];
int main()
{
  int n,m;
  cin>>n>>m;
  for(int i=1;i<=m;i++)
    cin>>d[i];
  sort(d+1,d+m+1); 
  int price=0;
  int maxv=0;
  int v; 
  for (int i=m;i>=1;i--)
 {
   
 if (n>=m-i+1)
 v=(m-i+1)*d[i];
 else v=n*d[i];
 if (v>=maxv)
 {
 maxv=v;
 price=d[i];
 }
 }
 cout<<price<<" "<<maxv<<endl;
 //while(1);
} 