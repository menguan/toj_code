#include <cstring>
#include <iostream>//参考网上   建图巧妙 
using namespace std;

bool map[1000][1000],vis[1000];
int match[1000];
int R,C,u,v;

bool find_path ( int r )
{
 for ( int i = 1; i <= v; i++ )
 {
  if ( map[r][i] && !vis[i] )
  {
   vis[i] = true;
   if ( 0 == match[i] || find_path(match[i]) )
   {
    match[i] = r;
    return true;
   }
  }
 }
 return false;
}

int Hungary()
{
 int ans = 0;
 for ( int i = 1; i <= u; i++ )
 {
  memset(vis,0,sizeof(vis));
  if ( find_path ( i ) )
   ans++;
 }
 return ans;
}

void construct ()
{
 int i,j;
 char temp[100][100];
 int U[100][100], V[100][100];
 memset(map,0,sizeof(map));
 memset(match,0,sizeof(match));
    u = v = 0;

 for ( i = 1; i <= R; i++ )
  for ( j = 1; j <= C; j++ )
   cin >> temp[i][j];

 for ( i = 1; i <= R; i++ )
 {
  for ( j = 1; j <= C; j++ )
  {
   if ( temp[i][j] == '*' )
   {
    u++;
    while ( j <= C && temp[i][j] == '*' )
    {
     U[i][j] = u;
     j++;
    }
   }
  }
 }
 for ( j = 1; j <= C; j++ )
 {
  for ( i = 1; i <= R; i++ )
  {
   if ( temp[i][j] == '*' )
   {
    v++;
    while ( i <= R && temp[i][j] == '*' )
    {
     V[i][j] = v;
     i++;
    }
   }
  }
 }

 for ( i = 1; i <= R; i++ )
 {
  for ( j = 1; j <= C; j++ )
  {
   if ( temp[i][j] == '*' )
    map[U[i][j]][V[i][j]] = true;
  }
 }
}
 

int main()
{
 cin >> R >> C;
 construct();
 cout << Hungary() << endl;
 return 0;
}

