#include<iostream>
#include<string>
using namespace std;
int main()
{
    string a,b;
    while(cin>>a>>b)
    {
        if(a=="0"&&b=="0")
          return 0;
        int count=0;
        bool kk[100];
        for(int i=0;i<100;i++)
            kk[i]=0;
        
        int y=0; 
        int a1=a.length();
        int b1=b.length();
        
        for(int a2=a1-1,b2=b1-1,i=1;a2>=0&&b2>=0;a2--,b2--,i++)
        {
            int a3=a[a2]-'0';
            int b3=b[b2]-'0';
            if(kk[i-1]==0)
            {
                if(a3+b3>9)
                {
                  count++;
                  kk[i]=1;
                }
                else
                  kk[i]=0;
            }
            else if(kk[i-1]==1)
            {
                if(a3+b3+1>9)
                {
                  count++;
                  kk[i]=1;
                }
                else
                  kk[i]=0;
           }
           y=i;
        }
        if(a1>b1)
        {  
          for(int i=y;i+1<=a1;i++)            
          if(a1>b1&&((a[a1-i-1]-'0')==9)&&kk[i]==1)
          {
            count++;
            kk[i+1]=1;
          }
        }
        else if(b1>a1)
        {  
          for(int i=y;i+1<=b1;i++)            
          if(b1>a1&&((b[b1-i-1]-'0')==9)&&kk[i]==1)
          {
            count++;
            kk[i+1]=1;
          }
        }        
        if(count==1)
          cout<<"1 carry operation."<<endl;
        else if(count==0)
          cout<<"No carry operation."<<endl;
        else
          cout<<count<<" carry operations."<<endl;
    }
    return 0;
} 