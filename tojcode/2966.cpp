#include<iostream>
#include<cstring>
using namespace std;
char num[20];
int main()
{
  while(cin>>num)
  {
    int len=strlen(num);
    if(num[0]==num[1])
    {
      if(num[0]=='0')
      {
        char temp=num[0];
        num[0]=num[7];
        num[7]=temp;
      }  
      for(int i=0;i<len;i++)
      {
        if(i%2==0)
        {
          cout<<num[0];
        }
        else
        {
          cout<<num[7];
        }    
      }
      cout<<endl;
    }
    else
    {
      if(num[0]=='0')
      {
        char temp=num[0];
        num[0]=num[7];
        num[7]=temp;
      } 
      for(int i=0;i<len/2;i++)
        cout<<num[0];
      for(int i=0;i<len/2;i++)
        cout<<num[7];
      cout<<endl;
    }
  }
}          