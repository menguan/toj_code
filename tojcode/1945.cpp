#include<iostream>
using namespace std;
int main()
{
  for(int a=6;a<=200;a++)
  {
    for(int b=2;b<a-2;b++)
    {
      for(int c=b+1;c<a-1;c++)
      {
        for(int d=c+1;d<a;d++)
        {
          if(a*a*a==b*b*b+c*c*c+d*d*d)
            cout<<"Cube = "<<a<<", Triple = ("<<b<<","<<c<<","<<d<<")"<<endl;
        }
      }
    }
  }
 
} 