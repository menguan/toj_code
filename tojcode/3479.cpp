#include<iostream>
#include<algorithm>
using namespace std;
struct cow
{
  int st;
  int end;
}c[60000];
bool cmp(cow a, cow b)
{
  return a.end<b.end;
}
int main()
{
  int n;
  cin>>n;
  for(int i=0;i<n;i++)
  {
    cin>>c[i].st>>c[i].end;
  }
  sort(c,c+n,cmp);
  int now=0;
  int count=0;
  for(int i=0;i<n;i++)
  {
    if(c[i].st>=now)
    {
      count++;
      now=c[i].end;
    }
  }
  cout<<count<<endl;
  //while(1);
}        
    
  