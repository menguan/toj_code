#include<iostream>
using namespace std;
void f1(int a)
{
    for(int i=1;i<=a;i++)
    {
       for(int j=2*a-1;j>0;j--)
       {   
           if(j>=(a+i))
           cout<<" ";
           
           else if(j==1&&i==a)
           cout<<"*"<<endl;
           else if(j>(a-i)&&j<(a+i))
           cout<<"*";
       }
       cout<<endl;
    }
    
}       
void f2(int a,int b)
{   
    int c=b;
    int d=0;
         for(int i=1;i<=b;i++)
    {   
        for(int j=c-1;j>=0;j--)
        {
            if(j==0)
            break;
            else
            cout<<" ";
        }
        c--;
        for(int j=1;j<=a;j++)
        {
            cout<<"*";
        }
        
        cout<<endl;
        
     }
     cout<<endl;
}                      

void f3(int a,int b)
{
    for(int i=1;i<=b;i++)
    {
        for(int j=1;j<=a;j++)
        {
            if(j==a)
            cout<<"*"<<endl;
            else
            cout<<"*";
        }
    }
    cout<<endl;
}               
int main()
{
    int a;
    while(cin>>a&&a!=-1)
    {
        if(a==1)
        {    
            int t1;
            cin>>t1;
            f1(t1);
        }
        if(a==2)
        {
            int t2,t3;
            cin>>t2>>t3;
            f2(t2,t3);
        }
        if(a==3)
        {
            int t4,t5;
            cin>>t4>>t5;
            f3(t4,t5);
        }
    }            
            
    
    
    
    return 0;
}