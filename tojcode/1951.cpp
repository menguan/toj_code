#include<iostream>
using namespace std;
void f(int a,int i)
{
  if(a==0)
  return ;
  else if(a>0&&a!=1)
  cout<<" + "<<a<<"x^"<<i;
  else if(a<0&&a!=-1)
  cout<<" - "<<(-1)*a<<"x^"<<i;
  else if(a==1)
  cout<<" + "<<"x^"<<i;
  else if(a==-1)
  cout<<" - "<<"x^"<<i;
} 
void f2(int a)
{
  if(a==0)
  return ;
  else if(a>0&&a!=1)
  cout<<" + "<<a<<"x";
  else if(a<0&&a!=-1)
  cout<<" - "<<(-1)*a<<"x";
  else if(a==1)
  cout<<" + "<<"x";
  else if(a==-1)
  cout<<" - "<<"x";
}   
int main()
{
  int a[10];
  while(cin>>a[1]>>a[2]>>a[3]>>a[4]>>a[5]>>a[6]>>a[7]>>a[8]>>a[9])
  {
    if(!a[1]&&!a[2]&&!a[3]&&!a[4]&&!a[5]&&!a[6]&&!a[7]&&!a[8]&&!a[9])
    {  cout<<0<<endl;
       continue;
    }
    if(!a[1]&&!a[2]&&!a[3]&&!a[4]&&!a[5]&&!a[6]&&!a[7]&&!a[8]&&a[9])
    {
      if(a[9]>0)
      cout<<a[9]<<endl;
      else
      cout<<"-"<<(-1)*a[9]<<endl;
      continue;
    }  
    int count=1,mi=8;
    while(!a[count])
    {
      count++;
      mi--;
    }
    if(mi>1)  
    { if(a[count]!=0&&a[count]!=1&&a[count]!=-1)
     cout<<a[count]<<"x^"<<mi;
     else if(a[count]==1)
     cout<<"x^"<<mi;
     else if(a[count]==-1)
     cout<<"-x^"<<mi;
    }
    
    if(mi>1) 
    for(int i=mi-1,j=count+1;i>1;i--,j++)
    {
      f(a[j],i);
    }
    if(mi!=1)
    f2(a[8]);
    else
    { if(a[8]!=0&&a[8]!=1&&a[8]!=-1)
     cout<<a[8]<<"x";
     else if(a[8]==1)
     cout<<"x";
     else if(a[8]==-1)
     cout<<"-x";
    }
    if(a[9]>0)
    cout<<" + "<<a[9]<<endl;
    else if(a[9]<0)
    cout<<" - "<<(-1)*a[9]<<endl;
    else
    cout<<endl;
       
  }
} 