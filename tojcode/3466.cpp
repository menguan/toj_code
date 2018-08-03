#include<iostream>
#include<algorithm>
using namespace std;
struct car
{
  int id;
  int speed;
  int con;
}c[1100];
bool cmp(car a, car b)
{
  if(a.speed!=b.speed)
    return a.speed>b.speed;
  else
    return a.con>b.con;
}      
int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int n;
    int k;
    cin>>n>>k;
    for(int i=0;i<n;i++)
    {
      cin>>c[i].id>>c[i].speed>>c[i].con;
    }
    sort(c,c+n,cmp);
    cout<<c[k-1].id<<endl;
  }
}    
    