#include<iostream>
#include<string>
using namespace std;
string s1[100];

int main()
{
  int n,m;
  cin>>n;
  for(int i=0;i<n;i++)
  {
    cin>>s1[i];
  }
  cin>>m;
  string s;
  while(m--)
  {
     cin>>s;
     bool flag=0;
     for(int i=0;i<n;i++)
     {
       if(s.find(s1[i])<1000)
       {  cout<<"A new hero discovered"<<endl;
          flag=1;
          break;
       }
     }
     if(!flag)
       cout<<"Just an ordinary person"<<endl;
  }
}   