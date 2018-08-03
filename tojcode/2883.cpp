#include<iostream>
#include<string>
using namespace std;
char f(string s,char a)
{
    if(s=="South")
    {  
       if(a=='-'||a=='+')
       return '+';
       else
       return '|';
    }
    if(s=="North")
    {  
       if(a=='-'||a=='+')
       return '+';
       else
       return '|';
    }
    if(s=="East")
    {  
       if(a=='|'||a=='+')
       return '+';
       else
       return '-';
    }
    if(s=="West")
    {  
       if(a=='|'||a=='+')
       return '+';
       else
       return '-';
    }
}
int main()
{
  int count=1;
  int m,n,step;
  while(cin>>m>>n>>step)
  {
    if(m==0&&n==0&&step==0)
      return 0;
    
    char map[m][n];
    for(int i=0;i<m;i++)
    {
     for(int j=0;j<n;j++)
     {
       map[i][j]='.';
     }
    }
    map[0][0]='+';
    int startm=0,startn=0;   
    string s;int steps;
    while(step--)
    {
      cin>>s>>steps;
      steps++;
      if(s=="South")
      {
        while(steps--)
        {
          map[startm][startn]=f(s,map[startm][startn]);
          if(steps)
          startm++;
        }
      }
      if(s=="North")
      {
        while(steps--)
        {
          map[startm][startn]=f(s,map[startm][startn]);
          if(steps)
          startm--;
        }
      }
      if(s=="West")
      {
        while(steps--)
        {
          map[startm][startn]=f(s,map[startm][startn]);
          if(steps)
          startn--;
        }
      }
      if(s=="East")
      {
        while(steps--)
        {
          map[startm][startn]=f(s,map[startm][startn]);
          if(steps)
          startn++;
        }
      }
    }
    cout<<"Scenario #"<<count++<<":"<<endl;
    for(int i=0;i<m;i++)
    {
     for(int j=0;j<n;j++)
     {
       cout<<map[i][j];
     }
     cout<<endl;
    }
   }
} 