#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int n;
struct te
{
  string name;
  int t[4];
  int time[4];
  int cor;
  int pen;
}team[10000];
bool cmp1(te a,te b)
{
  return a.cor<=b.cor;
}
bool cmp2(te a,te b)
{
  return a.pen<=b.pen;
}    
int main()
{
  int t;
  cin>>t;
  int n=t;
  int num=0; 
  while(t--)
  {
    cin>>team[num].name;
    for(int i=0;i<4;i++)
      cin>>team[num].t[i]>>team[num].time[i];
    team[num].cor=team[num].pen=0;
    for(int i=0;i<4;i++)
    {
      if(team[num].time[i])
      {
        team[num].cor++;
      }
    }
    for(int i=0;i<4;i++)
    {
      if(team[num].time[i])
      {
        team[num].pen+=team[num].time[i];
        team[num].pen+=((team[num].t[i]-1)*20);
      }
    }
    num++;
  }
  sort(team,team+n,cmp1);
  int u=1;
  for(int i=n-2;i>=0;i--)
  {
    if(team[i].cor==team[n-1].cor)
    {
      u++;
    }
    else
    {
      break;
    }
  }
  sort(team+n-u,team+n,cmp2);
  
  cout<<team[n-u].name<<" "<<team[n-u].cor<<" "<<team[n-u].pen<<endl;
  //while(1);
}            
        
        
         