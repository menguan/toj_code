#include <iostream>
#include <algorithm>
#include <stdio.h>

using namespace std ;

struct Rect{
    int x, y ;
} rect[6] ;

bool cmp( Rect r1, Rect r2 )
{
    if( r1.x != r2.x )
        return r1.x < r2.x ;
    else
        return r1.y < r2.y ;
}

bool equal( Rect r1, Rect r2 )
{
    return r1.x==r2.x && r1.y==r2.y ;
}

int main()
{
    int i, x, y ;
    while( cin>>rect[0].x>>rect[0].y ){
        
        for( i=1; i<6; ++i ){
            cin>>rect[i].x>>rect[i].y;
            if( rect[i].x > rect[i].y )
                swap( rect[i].x, rect[i].y ) ;    
            }
            if( rect[0].x > rect[0].y )
                swap( rect[0].x, rect[0].y ) ;  
        
        sort( rect, rect+6, cmp );
        if( !equal(rect[0],rect[1]) || !equal(rect[2],rect[3]) || !equal(rect[4],rect[5]) ||
            rect[0].x!=rect[2].x || rect[0].y!=rect[4].x || rect[2].y!=rect[4].y )
            cout<<"IMPOSSIBLE"<<endl;
        else
            cout<<"POSSIBLE"<<endl;
    }
    return 0 ;
}

