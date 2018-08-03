#include<iostream>
#include<cstring>
#include<string>
#include<stdio.h> 
using namespace std;
char sen[100000];
int main()
{
  string s;
  
  while(cin>>s)
  {
    if(s=="ENDOFINPUT")
      return 0;
    getchar();
    if(s=="START")
    {
        cin.getline(sen,100000);
        
        cin>>s;
    }
    int len=strlen(sen);
    for(int i=0;i<len;i++)
    {
      if((int)sen[i]<65||(int)sen[i]>90)
        {cout<<sen[i];continue;}
        
      int t=sen[i];
      if(t>=70)
        cout<<(char)(t-5);
      else
        cout<<(char)(t+21);
    }
    cout<<endl;
  }
}                      
            
  
   