#include<iostream>
using namespace std;
void f(int n)
{
  if(n==2)
    cout<<"1 1"<<endl;
  else if(n==3)
    cout<<"7 7"<<endl;
  else if(n==4)
    cout<<"4 11"<<endl;
  else if(n==5)
    cout<<"2 71"<<endl;
  else if(n==6)
    cout<<"6 111"<<endl;
  else if(n==7)
    cout<<"8 711"<<endl;       
  else if(n==8)
    cout<<"10 1111"<<endl;
  else if(n==9)
    cout<<"18 7111"<<endl;
  else if(n==10)
    cout<<"22 11111"<<endl;
  else if(n==11)
    cout<<"20 71111"<<endl;
  else if(n==12)
    cout<<"28 111111"<<endl;
  else if(n==13)
    cout<<"68 711111"<<endl;
  else if(n==14)
    cout<<"88 1111111"<<endl;
  else
  {
    int zhouqi=(n-15)/7;
    int num=(n-14)%7;
    if(num==1)
      cout<<108;
    else if(num==2)
      cout<<188;
    else if(num==3)
      cout<<200;
    else if(num==4)
      cout<<208;
    else if(num==5)
      cout<<288;
    else if(num==6)
      cout<<688;
    else if(num==0)
      cout<<888;            
    
    if(zhouqi)
    while(zhouqi--)
      cout<<8;
    cout<<" ";
    zhouqi=(n-2)/2;
    num=n%2;
    
    if(num)
      cout<<7;
    else
      cout<<1;
    while(zhouqi--)
      cout<<1;
    cout<<endl;
  }
}      
                                                                        
int main()
{
  int n,t;
  cin>>n;
  while(n--)
  {
    cin>>t;
    f(t);
  }  
}    