#include<iostream>//高科技
#include<cmath>
#include<algorithm>
#include<stdio.h>
using namespace std;

#define max_v 0x7fffffff

int n;
int map[110][2];
int arr[8][2]={ {-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1},{-1,0} };
double min_len;


void search( int xi,int yi )
{
    int i;
    double tmp = 0;
    for(i=0;i<n;++i)
    {
        tmp += sqrt((double)(xi - map[i][0])*(xi - map[i][0])
            + (yi - map[i][1])*(yi - map[i][1]));
    }
    if( tmp < min_len )
    {
        min_len = tmp;
        for( i=0;i<8;++i)
        {
            search(arr[i][0]+xi,arr[i][1]+yi);
        }
    }
    return ;
}

int main()
{
    int i,x,y;
    int min_x,min_y;
    int max_x,max_y;
    cin>>n;
    min_x = min_y = max_v;
    max_x = max_y = 0;
    for(i=0;i<n;++i)
    {
        cin>>map[i][0]>>map[i][1];
        if( min_x > map[i][0] ) min_x=map[i][0];
        if( max_x < map[i][0] ) max_x=map[i][0];
        if( min_y > map[i][1] ) min_y=map[i][1];
        if( max_y < map[i][1] ) max_y=map[i][1];
    }
    x = (min_x+max_x) >> 1;
    y = (min_y+max_y) >> 1;
    min_len = 0x7fffffff;
    search(x,y);
    cout<<min_len<<endl;
    return 0;
}
