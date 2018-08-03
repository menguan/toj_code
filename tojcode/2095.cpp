#include<iostream>
#include<stdio.h>
#include<iomanip>
using namespace std;
int main()
{
  int sH,sM,eH,eM;
  int pass,m1,m2;

  
  printf("Initial time  Final time  Passes\n");

 while(scanf("%d%d%d%d",&sH,&sM,&eH,&eM)!=EOF)
 {
  m1=(sH)*60+sM;
  m2=(eH)*60+eM;
  pass=(m2*11)/720-(m1*11)/720;

  if(m1>m2)
   pass+=11;
  cout<<"       ";
  if(sH<10)
    cout<<"0";
  cout<<sH<<":";
  if(sM<10)
    cout<<"0";
  cout<<sM;
  cout<<"       ";
  if(eH<10)
    cout<<"0";
  cout<<eH<<":";
  if(eM<10)
    cout<<"0";
  cout<<eM; 
  cout<<setw(8)<<pass<<endl;   
 }
 
}
