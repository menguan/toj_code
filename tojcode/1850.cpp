#include<iostream>
#include<algorithm>
#define eps 1e-9
using namespace std;
struct cd
{
  int id;
  double len;
  double fre;
}c[1000000];
bool cmp(cd a,cd b)
{
  return (a.len/a.fre-b.len/b.fre<eps);
}
int main()
{
  int t;
  while(cin>>t)
  {
    for(int i=0;i<t;i++)
    {
      cin>>c[i].id>>c[i].len>>c[i].fre;
      
    }
    sort(c,c+t,cmp);
    int num;
    cin>>num;
    cout<<c[num-1].id<<endl;
  }
}          
 