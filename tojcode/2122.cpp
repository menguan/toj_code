#include<iostream>
#include<cstring> 
using namespace std;
int flagi[100];
bool flagc[100];
int main()
{
  int t;
  while(cin>>t,t)
  {
    for(int i=0;i<100;i++)
      flagi[i]=flagc[i]=0;
    char s;
    char ss[20];
    int num;
    int sum1=0,sum2=0;
    while(t--)
    {
      cin>>s;
      cin>>num;
      cin>>ss;
      if(strcmp(ss,"incorrect")==0)
      {
        flagi[s-'A']++;
      }
      else
      {
        
        
          sum1++;
          if(flagi[s-'A'])
          {
            sum2+=(num+20*flagi[s-'A']);
          
          }
          else
          {
            sum2+=num;
          }
          flagc[s-'A']=1;
        
      }
    }
    cout<<sum1<<" "<<sum2<<endl;
  }
} 