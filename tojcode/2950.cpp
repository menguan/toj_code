#include<iostream>
using namespace std;
int main()
{
    int b[9];
    int sum=0;
    for(int i=0;i<9;i++)
    {
      cin>>b[i];
      sum+=b[i];
    }  
    for(int i=0;i<9;i++)
    for(int j=i+1;j<9;j++)
    {
      if(sum-b[i]-b[j]==100)
      {
        b[i]=0;
        b[j]=0;
      }
    }
    for(int i=0;i<9;i++)
    if(b[i])
    cout<<b[i]<<endl;
  
} 