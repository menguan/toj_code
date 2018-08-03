#include <iostream>//网上看的水题 不动了
#include <cstring>
using namespace std;
#define MAXN 5010
struct poly{ int deg,x[MAXN];};
void read(poly &f)
{
       cin>>f.deg;
       for (int i=f.deg-1; i>=0; --i) cin>>f.x[i];
}
void mult(poly f,poly g,poly &r)
{
       memset(r.x,0,sizeof(r.x));
       for (int i=0; i<f.deg; ++i)
              for (int j=0; j<g.deg; ++j)
                     r.x[i+j] = (r.x[i+j]+f.x[i]*g.x[j])%2;
       r.deg = f.deg+g.deg-1;
}
void mod(poly &m,poly h)
{
       int i;
       while (1){
              for (i=m.deg-1; i>=0&&(!m.x[i]); --i);
              if (i<h.deg-1){
                     m.deg = i+1;
                     break;
              }
              for (int j=h.deg-1; j>=0; --i,--j)
                    m.x[i] = (m.x[i]+h.x[j])%2;
       }
}
int main()
{
       int t;
       cin>>t;
       while(t--)
       {
            poly f,g,h,m;
            read(f);
            read(g);
            read(h);
            mult(f,g,m);
            mod(m,h);
            cout<<m.deg<<' ';
            for (int i=m.deg-1; i>0; --i) cout<<m.x[i]<<' ';
            cout<<m.x[0]<<endl;
       }
}
