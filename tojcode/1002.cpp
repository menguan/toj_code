#include<iostream>
#include<string>
using namespace std;
const char h[19][20]={"pop","no", "zip", "zotz", "tzec", "xul", "yoxkin", "mol", "chen", "yax", "zac", "ceh", "mac", "kankin", "muan", "pax", "koyab", "cumhu","uayet"};
const char t[20][20]={"imix", "ik", "akbal", "kan", "chicchan", "cimi", "manik", "lamat", "muluk", "ok", "chuen", "eb", "ben", "ix", "mem", "cib", "caban", "eznab", "canac", "ahau"};
    
int days(string s,string month,int year)
{
    int dday,mday,yday;
    int l=s.length();
    if(l==3)
    {
        dday=(s[0]-'0')*10+(s[1]-'0')+1;
    }
    else if(l==2)
    {
        dday=s[0]-'0'+1;
    }
    for(int i=0;i<19;i++)
    {
        if(month==h[i])
        {
            mday=i*20;
        }
    }
    yday=year*365;
    
    return dday+mday+yday;
}    
void holly(int days)
{
    int day,f,year;
    
    if(days%260!=0)
    {
      year=days/260;
      f=(days%260)%13;
      day=(days%260)%20;
      if(f==0)
        f+=13;
      if(day!=0)
        cout<<f<<" "<<t[day-1]<<" "<<year<<endl;
      else 
        cout<<f<<" "<<t[19]<<" "<<year<<endl;
    }
    else if(days%260==0)
    {
        year=days/260-1;
        cout<<13<<" "<<"ahau"<<" "<<year<<endl;
    }        
}        
    
int main()
{
    int a;
    cin>>a;
    cout<<a<<endl;
    while(a--)
    {
        string s,month;
        int year;
        cin>>s>>month>>year;
        holly(days(s,month,year));                
    }
    return 0;
}  