#include<iostream>
using namespace std;
void f(int &p1,int &p2,char a,char b)
{
    if(a=='R'&&b=='S')
        p1++;
    if(a=='S'&&b=='P')
        p1++;
    if(a=='P'&&b=='R')
        p1++;    
    if(a=='R'&&b=='P')
        p2++;
    if(a=='S'&&b=='R')
        p2++;
    if(a=='P'&&b=='S')
        p2++;
}         
        
    
int main()
{
    int a;
    cin>>a;
    while(a--)
    {
        int t,p1=0,p2=0;
        cin>>t;
        for(int i=0;i<t;i++)
        {
            char a,b;
            cin>>a>>b;
            f(p1,p2,a,b);
        }
        if(p1>p2)
          cout<<"Player 1"<<endl;
        else if(p2>p1)
          cout<<"Player 2"<<endl;
        else
          cout<<"TIE"<<endl;
    }
    return 0;
}