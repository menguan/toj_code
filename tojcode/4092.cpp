#include<iostream>
#include<cstring>
#include<string>
using namespace std;
int a[10];
char t1[10][5]={"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
char t2[10][5]={"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
char t3[10][5]={"","I","II","III","IV","V","VI","VII","VIII","IX"};
void print(int num,int n)
{
     for(int i=0;i<n;i++)  cout<<"(";
     cout<<t1[num/100];
     num=num%100;
     cout<<t2[num/10];
     num=num%10;
     cout<<t3[num];
     for(int i=0;i<n;i++)  cout<<")";
}     
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
      int num;        
      cin>>num;
      int cou=0;
      while(num)
      {
        a[cou++]=num%1000;
        num/=1000;
      } //cout<<cou<<endl;             
      for(int i=cou-1;i>=0;i--)
      {
        print(a[i],i);
      }
      cout<<endl;
    }
}      
          
      
      
