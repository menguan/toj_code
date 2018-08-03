#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
struct node
{
  int time;
  int now;
};
node first,next;
bool num[100010];
int n,end;
int BFS()
{
  queue<node> number;
  first.now=n;
  first.time=0;
  number.push(first);
  num[first.now]=1;
  while(!number.empty())
  {
    first=number.front();
    number.pop();
    if(first.now==end)  return first.time;
    if(first.now%2==0)
    {
      next.now=first.now/2;
      if(num[next.now]==0)
      {
        num[next.now]=1;
        next.time=first.time+1;
        number.push(next);
      }
    }
      next.now=first.now*2;
      if(num[next.now]==0&&next.now<100000)
      {
        num[next.now]=1;
        next.time=first.time+1;
        number.push(next);
      }
      next.now=first.now+1;
      if(num[next.now]==0&&next.now<100000)
      {
        num[next.now]=1;
        next.time=first.time+1;
        number.push(next);
      }
  }
  return -1;
}    
      
           
int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    memset(num,0,sizeof(num));
    cin>>n>>end;
    cout<<BFS()<<endl;
  }
}    
    
    
 