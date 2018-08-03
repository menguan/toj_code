#include<iostream>
using namespace std;
int main()
{
    int a,count=1;
    int b[51];
    while(cin>>a,a)
    {    
        int sum=0,ave=0,move=0;
        for(int i=1;i<=a;i++)
        {
              cin>>b[i];
              sum+=b[i];
        }
        ave=sum/a;
        for(int i=1;i<=a;i++)
        {
            if(b[i]>ave)
            move+=(b[i]-ave);
        }
        cout<<"Set #"<<count<<endl;
        cout<<"The minimum number of moves is "<<move<<"."<<endl;
        cout<<endl;
        count++;
     }
            
     return 0;
}            
   