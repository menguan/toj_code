#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
  double a,b,c,d;
  while(cin>>a>>b>>c>>d)
  {
    if(a==0&&b==0&&c==0&&d==0)
      return 0;
      
    if(a>b)
    {
      int temp=a;
      a=b;
      b=temp;
    }
    if(c>d)
    {
      int temp=c;
      c=d;
      d=temp;
    }
    
    double aa=c/a;
    double bb=d/b;
    if(aa>=1&&bb>=1)
     { cout<<"100%"<<endl;continue;}
    double cc=min(aa,bb);
    cout<<(int)(cc*100)<<"%"<<endl;
  }
}     