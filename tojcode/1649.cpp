#include<iostream>

#include<cstring>

#include<string>

using namespace std;

 

int main()

{

       int n,k;

       cin>>n;

       for(k=0;k<n;k++)

       {

              char t[2000];

              int a,b,i,j,l;

              int x,y;

              char map[32][33]={0};

              cin>>a>>b;

              cin>>t;

              l=strlen(t)-1;


              x=31-b;

              y=a;

              for(i=0;i<l;i++)

              {

                     if(t[i]=='E')

                     {

                            map[x+1][y+1]='X';

                            

                            y++;

                     }

                     else if(t[i]=='N')

                     {

                            map[x][y+1]='X';


                            x--;

                     }

                     else if(t[i]=='W')

                     {

                            map[x][y]='X';

                            y--;

                     }

                     else if(t[i]=='S')

                     {

                            map[x+1][y]='X';

                            x++;

                     }

              }

              cout<<"Bitmap #"<<k+1<<endl;

              for(i=0;i<32;i++)

              {

                     for(j=1;j<33;j++)

                     {

                            if(map[i][j]!='X')

                                   map[i][j]='.';

                            cout<<map[i][j];

                     }

                     cout<<endl;

              }

              cout<<endl;

       }

       return 0;

}

