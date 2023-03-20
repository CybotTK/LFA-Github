#include <iostream>
#include <fstream>
#include <deque>
#include <cstring>
using namespace std;

ifstream f("dfa.in");

int q, delta[200][150], v[100];
int stare, stare1, stare2, fin;
char litera;
deque <int> drum;
string sir;

int main()
{
  f>>q;
  f.get();
  getline(f, sir);
  drum.push_back(1);
  for (int i=0;i<200;i++)
    for (int j=0;j<150;j++)
      delta[i][j]=-1;

  for (int i=1;i<=q;i++)
  { f>>stare>>fin;
    v[stare]=fin;
  }

  cout<<sir<<'\n';

  if(sir.size()==0 && v[1]==1)
  { cout<<"E acceptat\n";
    cout<<drum.front()<<'\n';
    drum.pop_front();
    return 0;
  }

  while(f>>stare1>>litera>>stare2)
  { delta[stare1][litera-'0']=stare2;
  }

  f>>sir;
  stare=1;
  for(int i=0; sir[i] ;i++)
  { stare=delta[stare][sir[i]-'0'];
    if (stare==-1)
    { cout<<"Nu e acceptat";
      return 0;
    }
    else drum.push_back(stare);
  }

  if (v[stare]==1)
  { cout<<"E acceptat\n";
    while(drum.size()){
      cout<<drum.front()<<" ";
      drum.pop_front();
    }
  }
  else cout<<"Nu e acceptat";
  return 0;
}
