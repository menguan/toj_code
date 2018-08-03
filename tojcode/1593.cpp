#include<iostream>
#include<cstring>
using namespace std;
char htm[100];
int main()
{
    int a;
    cin>>a;
    int count=1;
    while(a--)
    {
        cin>>htm;
        int len=strlen(htm);
        int stop;
        cout<<"URL #"<<count<<endl;
        count++;
        cout<<"Protocol = ";
        for(int i=0;i<len;i++)
        {
            if(htm[i]!=':')
            cout<<htm[i];
            else
            {
             stop=i+3;
             break;
            }
        }
        cout<<endl;
        
        bool po=1,pa=1;
        cout<<"Host     = ";
        for(int i=stop;i<len;i++)
        {
            if(htm[i]!=':'&&htm[i]!='/')
            cout<<htm[i];
            
            if(i==len-1)
            {
               po=0;pa=0;
            }
            
            if(htm[i]==':')
            {
              stop=i+1;
              break;
            }
            else if(htm[i]=='/')
            {
              po=0;
              stop=i+1;
              break;
            }
        }
        cout<<endl;
        cout<<"Port     = ";
        if(po==0)
          cout<<"<default>";
        else
        {
            for(int i=stop;i<len;i++)
            {
              if(htm[i]!='/')
              cout<<htm[i];
              
              if(i==len-1)
              pa=0;
              
              if(htm[i]=='/')
              {
                stop=i+1;
                break;
              }
            }  
        }
        cout<<endl;
        cout<<"Path     = ";
        if(pa==0)
          cout<<"<default>";
        else
        {
          for(int i=stop;i<len;i++)
          {
            cout<<htm[i];
          }
        }
        cout<<endl<<endl;
     }
     return 0;
} 