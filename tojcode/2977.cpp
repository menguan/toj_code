#include<iostream>
#include<cstring>
using namespace std;
char a[50];
int main()
{
  int n;
  while(cin>>n,n)
  {
    cin>>a;
    int r=0,y=0;
    for(int i=0;i<n;i++)
    {
      if(a[i]=='B')
      {
        if(r==7)
        {
          cout<<"Red"<<endl;
          break;
        }
        else
        {
          cout<<"Yellow"<<endl;
          break;
        }
      }
      else if(a[i]=='L')
      {
        if(y==7)
        {
          cout<<"Yellow"<<endl;
          break;
        }
        else
        {
          cout<<"Red"<<endl;
          break;
        }
      }
      else if(a[i]=='R')
        r++;
      else if(a[i]=='Y') 
        y++;
    }
  }
}               
   