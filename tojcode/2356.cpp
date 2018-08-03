#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std ;

int main()
{
    int c ;
    int N,F,B ;
    int a , b;
    int init[1005] ;
    cin >> c ;
    while(c--)
    {
        cin >> N >> F >> B ;
        memset(init,0,sizeof(init)) ;
        for(int i = 0 ; i < N ;  i ++)
        {
            cin >> a >> b  ;
            if(b == 1) init[i] = 3*F - a ;
            else init[i] = F + a ;
        }
        sort(init,init+N) ;

        int ans = 0 ;
        int left = B % N ;
        if(left == 0)
        {
            ans = ( B/N - 1 ) * 2 * F + init[N-1];
        }
        else
        {
            //cout<<"kk"<<endl;
            ans =B / N * 2 * F + init[left-1] ;
        }
        cout << ans << endl;
    }
}
