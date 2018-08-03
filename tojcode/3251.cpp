#include<iostream>
using namespace std;
void f(int day,int month)
{
    int sum=0;
    if(month==2)
    sum+=31;
    if(month==3)
    sum+=59;
    if(month==4)
    sum+=90;
    if(month==5)
    sum+=120;
    if(month==6)
    sum+=151;
    if(month==7)
    sum+=181;
    if(month==8)
    sum+=212;
    if(month==9)
    sum+=243;
    if(month==10)
    sum+=273;
    if(month==11)
    sum+=304;
    if(month==12)
    sum+=334;
    if(month==1)
    sum+=0;
    
    sum+=day;
    if(sum%7==6)
        cout<<"Tuesday"<<endl;
    if(sum%7==0)
        cout<<"Wednesday"<<endl;
    if(sum%7==1)
        cout<<"Thursday"<<endl;
    if(sum%7==2)
        cout<<"Friday"<<endl;
    if(sum%7==3)
        cout<<"Saturday"<<endl;
    if(sum%7==4)
        cout<<"Sunday"<<endl;
    if(sum%7==5)
        cout<<"Monday"<<endl;                        
}
int main()
{
    int a,b;
    cin>>a>>b;
    f(a,b);
    
    return 0;
}  