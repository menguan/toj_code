#include<iostream>
#include<algorithm>
using namespace std;
int a[100010];
int main()
{
    int n,m;
    long long sum;
    cin>>n;
    while(n--)
    {
      sum=0;
      cin>>m;
      for(int i=0;i<m;i++)
        cin>>a[i];
      sort(a,a+m);
      for(int i =0;i<m-1;i++)
      {
        sum+=a[i];
        }
        cout<<sum<<endl;
}}