#include<iostream>
#include<string>
using namespace std;
void date(int b)
{
    int a=b+1;
    int sum=0;
    bool leap=0;
    int year;
    string month;
    int day;
    for(int i=0;;i++)
    {
        if((i%4==0&&i%100!=0)||i%400==0)
          {
            sum+=366;
            leap=1;
          }  
        else
          {
            sum+=365;
            leap=0;
          }  
        if(sum>=a)
        {
            year=2000+i;
            if(leap==1)
            {
                int days=a+366-sum;
                if(days<=31)
                {
                    month="01";
                    day=days;
                    break;
                }
                else if(days<=60&&days>31)
                {
                    month="02";
                    day=days-31;
                    break;
                }    
                else if(days<=91&&days>60)
                {
                    month="03";
                    day=days-60;
                    break;
                }else if(days<=121&&days>91)
                {
                    month="04";
                    day=days-91;
                    break;
                }else if(days<=152&&days>121)
                {
                    month="05";
                    day=days-121;
                    break;
                }else if(days<=182&&days>152)
                {
                    month="06";
                    day=days-152;
                    break;
                }else if(days<=213&&days>182)
                {
                    month="07";
                    day=days-182;
                    break;
                }else if(days<=244&&days>213)
                {
                    month="08";
                    day=days-213;
                    break;
                }else if(days<=274&&days>244)
                {
                    month="09";
                    day=days-244;
                    break;
                }else if(days<=305&&days>274)
                {
                    month="10";
                    day=days-274;
                    break;
                }else if(days<=335&&days>305)
                {
                    month="11";
                    day=days-305;
                    break;
                }else if(days<=366&&days>335)
                {
                    month="12";
                    day=days-335;
                    break;
                }
            }
            else if(leap==0)
            {            
                int days=a+365-sum;
                if(days<=31)
                {
                    month="01";
                    day=days;
                    break;
                }
                else if(days<=59&&days>31)
                {
                    month="02";
                    day=days-31;
                    break;
                }    
                else if(days<=90&&days>59)
                {
                    month="03";
                    day=days-59;
                    break;
                }else if(days<=120&&days>90)
                {
                    month="04";
                    day=days-90;
                    break;
                }else if(days<=151&&days>120)
                {
                    month="05";
                    day=days-120;
                    break;
                }else if(days<=181&&days>151)
                {
                    month="06";
                    day=days-151;
                    break;
                }else if(days<=212&&days>181)
                {
                    month="07";
                    day=days-181;
                    break;
                }else if(days<=243&&days>212)
                {
                    month="08";
                    day=days-212;
                    break;
                }else if(days<=273&&days>243)
                {
                    month="09";
                    day=days-243;
                    break;
                }else if(days<=304&&days>273)
                {
                    month="10";
                    day=days-273;
                    break;
                }else if(days<=334&&days>304)
                {
                    month="11";
                    day=days-304;
                    break;
                }else if(days<=365&&days>334)
                {
                    month="12";
                    day=days-334;
                    break;
                }
            }
        }
     }
     if(day<10)
       cout<<year<<"-"<<month<<"-0"<<day;
     else           
       cout<<year<<"-"<<month<<"-"<<day;
}       
int main()
{
    int a;
    while(cin>>a)
    {
        if(a==-1)
        {
            return 0;
        }    
        string w;
        if(a%7==0)
        {
            w="Saturday";
        }
        if(a%7==1)
        {
            w="Sunday";
        } 
        if(a%7==2)
        {
            w="Monday";
        } 
        if(a%7==3)
        {
            w="Tuesday";
        } 
        if(a%7==4)
        {
            w="Wednesday";
        } 
        if(a%7==5)
        {
            w="Thursday";
        } 
        if(a%7==6)
        {
            w="Friday";
        }
        date(a);
        cout<<" "<<w<<endl;
    }     
    return 0;
} 