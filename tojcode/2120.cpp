#include<iostream>
#include<queue>
using namespace std;
int main()
{
  
  long long z,i,m,l,test=1;
  while(cin>>z>>i>>m>>l&&(z+i+m+l))
  {
    queue<long long>q;
    l=((z*l)+i)%m;
    q.push(l);
    int count=0;
    while(1)
    {
      l=((z*l)+i)%m;
      q.push(l);
      count++;
      if(l==q.front())
        break; 
    }
    cout<<"Case "<<test++<<": ";
    cout<<count<<endl;    
  }
}      
   