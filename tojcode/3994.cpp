#include<iostream>
#include<cstring>
using namespace std;
char a[50];
char b[20];
char c[20];
int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    cin>>a;
    int len=strlen(a);
    int lenb;
    int lenc;
    int xi;
    if(a[len-1]=='0')
      xi=10;
    else
      xi=a[len-1]-'0';
    
    for(int i=1,j=0;;i++,j++)
    {
       if(a[i]=='+')
         break;
         
       b[j]=a[i];
       lenb=j;
    }
    b[lenb+1]='\0';
    for(int i=lenb+3,j=0;;i++,j++)
    {
      if(a[i]==')')
        break;
        
      c[j]=a[i];
      lenc=j;
    }
    c[lenc+1]='\0';
    if(xi==1)
      cout<<"C(1,0)*"<<c<<"^1+C(1,1)*"<<b<<"^1"<<endl;
    else
      {
        cout<<"C("<<xi<<",0)*"<<c<<"^"<<xi;
        for(int i=1;i<xi;i++)
        {
          cout<<"+";
          cout<<"C("<<xi<<","<<i<<")*"<<b<<"^"<<i<<"*"<<c<<"^"<<xi-i;
        }
        cout<<"+C("<<xi<<","<<xi<<")*"<<b<<"^"<<xi<<endl;
      }     
      
  }
}  