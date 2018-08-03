#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
struct f
{
  string name;
  int w;
}man[20];
bool cmp(f a, f b)
{
  return a.w>b.w;
}
int main()
{
  string s;
  int b,c;
  int count=0;
  bool flag=0;
  while(cin>>s)
  {
    if(s=="START")
    {
      if(flag)
        cout<<endl;
      flag=1;  
      count=0;
    }
    else if(s=="END")
    {
      sort(man,man+count,cmp);
      
      for(int i=0;i<count;i++)
      {
        cout<<man[i].name<<endl;
      }
      
    }
    else
    {
      cin>>b>>c;
      man[count].w=c-b;
      man[count].name=s;
      count++;
    }
  }
 }     
                