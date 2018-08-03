

#include<iostream>

#include<map>

#include<string>

#include<algorithm>

using namespace std;

struct type

{

    string pname;

    int chi;

}f[ 100 ];

map<string,int> S;

string s;

bool cmp(type a,type b)

{

    if( a.chi > b.chi )return 1;

    return 0;

}

int main()

{

 int n,m;

 while( cin>>n )

 {
/*   map<string,string>party;
  map<string,int>count;
  
  vector<string>name;
  int n;
 
  cin>>n;getchar();
  int maxn=0;
  int con=0;
  while(n--)
  {
    getline(cin,s1);
    getline(cin,s2);
    name.push_back(s1);
    con++;
    party[s1]=s2;
    count[s1]=0;
    
  }
*/

     S.clear();

     getline(cin,s);

     for(int i=0;i<n;i++)

     {

       getline(cin,s);

        S[ s ] = i;

        f[ i ].chi = 0;

    

        getline(cin,f[i].pname);

     }

     cin>>m;

     getline(cin,s);

     for(int i=0;i<m;i++)

     {

       getline(cin,s);

       if( S.find( s ) == S.end() )continue;

       f[ S[ s ] ].chi++;

     }

    

     sort(f,f+n,cmp);

     if( f[0].chi == f[1].chi )

     {

        cout<<"tie"<<endl;

     }

     else cout<<f[0].pname<<endl;

 }

}

