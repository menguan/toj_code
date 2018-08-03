#include<iostream>
#include<set>
using namespace std;
int main()
{
  int t,n;
  char c;
  multiset<int> num; 
  while(cin>>t,t)
  {
     num.clear();
     while(t--)
     {
       cin>>c;
       if(c=='B')
       {
         cin>>n;
         num.insert(n);
       }
       if(c=='G')
       {
         cout<<*num.begin()<<endl;
         num.erase(num.begin());
       }
     }
   }
 }    