#include <cstdio>//这个题意。。。
#include <string>
#include <queue>
using namespace std;
int main()
{
    double A, R, P;
    char U[ 3 ], V[ 50 ];
    queue<string> q;
    while (1) {
        scanf( "%lf %s %lf ", &A, U, &R );
        gets( V );
        if ( A < 0 )
            break;
        P = A / R * 100;
        if ( P < 1 )
            q.push( string( V ) );
        else
            printf( "%s %.1lf %s %.lf%%\n", V, A, U, P );
    }
    printf( "Provides no significant amount of:\n" );
    while ( !q.empty() ) {
        printf( "%s\n", q.front().c_str() );
        q.pop();
    }
}
