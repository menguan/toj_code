#include<iostream>
using namespace std;
int worda[6];
int wordb[6];
int wordc[6];
char s[20];
void fa(int n)
{
  for(int i=0;i<6;i++)
    worda[i]=0;
  for(int i=5;i>=0;i--)
  {
    worda[i]=n%2;
      n/=2;
    if(!n)
      break;
  }
}      
void fc(int n)
{
  for(int i=0;i<6;i++)
    wordc[i]=0;
  for(int i=5;i>=0;i--)
  {
    wordc[i]=n%2;
      n/=2;
    //cout<<wordc[i]<<endl;  
    if(!n)
      break;
  }
  //for(int i=0;i<6;i++)
    //cout<<wordc[i]<<endl;
}   
void fb(int n)
{
  for(int i=0;i<6;i++)
    wordb[i]=0;
  for(int i=5;i>=0;i--)
  {
    wordb[i]=n%2;
      n/=2;
    if(!n)
      break;
  }
}         
          
   
int main()
{
  int t,count=1;int a,b,c;
  cin>>t;
  while(t--)
  {
    cin>>s;
    a=(s[0]-'0')*10+(s[1]-'0');
    b=(s[3]-'0')*10+(s[4]-'0');
    c=(s[6]-'0')*10+(s[7]-'0');
    cout<<count++<<" ";
    fa(a);
    fb(b);
    fc(c);
    //for(int i=0;i<6;i++)
    //cout<<wordc[i]<<endl;
    for(int i=0;i<6;i++)
    {
      cout<<worda[i]<<wordb[i]<<wordc[i];
    }
    cout<<" ";
    for(int i=0;i<6;i++)cout<<worda[i];
    for(int i=0;i<6;i++)cout<<wordb[i];
    for(int i=0;i<6;i++)cout<<wordc[i];
    cout<<endl;
  }
}    