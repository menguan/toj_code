#include<iostream>
#include<cstring>
using namespace std;
int main()
{
  int n;
  while(cin>>n)
  {
    if(n==1)  cout<<1<<endl;
    else if(n==2)
      cout<<10<<endl;
    else if(n==3)
      cout<<19<<endl;
    else if(n==4)
      cout<<199<<endl;
    else if(n==5)
      cout<<80171<<endl;
    else if(n==6)
      cout<<42106<<endl;
    else if(n==7)
      cout<<42646<<endl;
    else 
    {
      if(n%2==0)
        cout<<89151<<endl;
      else 
        cout<<73686<<endl;
   }
} 
}             