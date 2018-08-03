#include<iostream> 
#include<cstring> 
using namespace std;
int i=0,j=0; 
char w[1001][100],in[100]; 

void visit() 
{ 
  cin>>in;
  i++; 
  j=i; 
  strcpy(w[i],in); 
  cout<<w[i]<<endl; 
} 

void back() 
{ 
  if(i==0)
    cout<<"Ignored"<<endl; 
  else 
  { 
    i--; 
    cout<<w[i]<<endl; 
  } 
} 

void forward() 
{ 
  if(i==j)
    cout<<"Ignored"<<endl; 
  else 
  { 
    i++; 
    cout<<w[i]<<endl; 
  } 
} 

main() 
{ 
  strcpy(w[0],"http://www.acm.org/"); 
  while(1) 
  { 
  cin>>in; 
  switch(in[0]) 
  { 
    case 'V':visit();break; 
    case 'B':back();break; 
    case 'F':forward();break; 
    case 'Q':return 0; 
  } 
  } 
  while(1);
}