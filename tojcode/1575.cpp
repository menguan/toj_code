#include<iostream>
using namespace std;
const double PI=3.14159265358979;
int main()
{
    int a;
    cin>>a;
    int i=1;
    while(a--)
    {
        double X,Y;
        cin>>X>>Y;
        double area=X*X*PI/2+Y*Y*PI/2;
        int time=(int)area/50+1;
        cout<<"Property "<<i<<": This property will begin eroding in year "<<time<<"."<<endl;
        i++;
    }
    cout<<"END OF OUTPUT."<<endl;
    return 0;
} 