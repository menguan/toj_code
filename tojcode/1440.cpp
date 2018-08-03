#include<iostream>
#include<cstring>
#include<stdio.h>
using namespace std;
const char* Table[65] = {"1","3","9","27","81","243","729","2187","6561",
"19683","59049","177147","531441","1594323","4782969","14348907",
"43046721","129140163","387420489","1162261467","3486784401",
"10460353203","31381059609","94143178827","282429536481",
"847288609443","2541865828329","7625597484987","22876792454961",
"68630377364883","205891132094649","617673396283947","1853020188851841",
"5559060566555523","16677181699666569","50031545098999707",
"150094635296999121","450283905890997363","1350851717672992089",
"4052555153018976267","12157665459056928801","36472996377170786403",
"109418989131512359209","328256967394537077627","984770902183611232881",
"2954312706550833698643","8862938119652501095929","26588814358957503287787",
"79766443076872509863361","239299329230617529590083","717897987691852588770249",
"2153693963075557766310747","6461081889226673298932241","19383245667680019896796723",
"58149737003040059690390169","174449211009120179071170507","523347633027360537213511521",
"1570042899082081611640534563","4710128697246244834921603689","14130386091738734504764811067",
"42391158275216203514294433201","127173474825648610542883299603",
"381520424476945831628649898809"};

int main()
{
 long long t;
 int a[65],i;
 while(cin>>t,t)
 {
  for(i=0;i<65;i++)
   a[i]=0;
  printf("{");
  if(t>1)
  {
   t--;
   i=0;
   while(t)
   {
    a[i]=t%2;
    t=t/2;
    i++;
   }
   for(i=0;i<65;i++)
   {
    if(a[i])
    {
     printf(" %s",Table[i]);
     break;
    }
   }
   i++;
   for(;i<65;i++)
   {
    if(a[i])
    {
     printf(", %s",Table[i]);
    }
   }
  }
  printf(" }\n");
 }
 return 0;
}
