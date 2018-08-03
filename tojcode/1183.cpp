#include<iostream>
#include<algorithm>
using namespace std;

int b[9] = { 1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000 };

long long count ( int n, int id )
{
    long long left, m, sum = 0;
    for ( int i = 1; i < 9; i++ )
    {
        left = n / b[i] - (id==0);
        sum += left * b[i-1];
        m = (n % b[i] - n % b[i-1]) / b[i-1]; 
        if ( m > id ) sum += b[i-1];
        else if ( m == id ) sum += n % b[i-1] + 1;
        if ( n < b[i] ) break;
    }
    return sum;
}

int main()
{
    int x, y;
    while ( cin>>x>>y&& (x||y) )
    {
        if ( x > y ) swap(x,y);
        for ( int i = 0; i <= 9; i++ )
        {    cout<<count(y,i)-count(x-1,i);
          if(i!=9)
          cout<<" ";
        }  
        cout<<endl;
    }
    return 0;
}