#include <iostream>
#include <fstream>
#include <string>

using namespace std;

ifstream f1("gramatica.in");
ifstream f2("cuvinte.in");

char SimbolCurent;
int NrProductii=0, CateCuv=0;

struct ProductiiStructura{
    char Neterminal1;
    char terminal;
    char Neterminal2;
} ReguliDeProductie[1000];

bool VerificareCuvant(char *cuvant){  
    
    if(cuvant[0]=='\0') //am ajuns la finalul cuvantului
    { if (SimbolCurent=='^') return true; 

      for (int i=0;i<NrProductii;i++)
      { if (ReguliDeProductie[i].Neterminal1==SimbolCurent &&
            ReguliDeProductie[i].terminal=='^' &&
            ReguliDeProductie[i].Neterminal2=='^')
            return true; 
      }
      return false;
    }
    else{ //inca parcurgem cuvantul
        char SmbAux=SimbolCurent;
        for (int i=0;i<NrProductii;i++)
        { if (ReguliDeProductie[i].Neterminal1==SmbAux &&
              ReguliDeProductie[i].terminal==cuvant[0])
          { SimbolCurent=ReguliDeProductie[i].Neterminal2;
            if (VerificareCuvant(cuvant+1)) return true;
          }
        }
        return false;
    }
}

int main()
{

{//Citire

    f1>>NrProductii;
    for (int i=0;i<NrProductii;i++)
    { f1>>ReguliDeProductie[i].Neterminal1;
      f1>>ReguliDeProductie[i].terminal;
      f1>>ReguliDeProductie[i].Neterminal2;
    }

    // for (int i=0;i<NrProductii;i++)
    //     cout<<ReguliDeProductie[i].Neterminal1<<" "<<ReguliDeProductie[i].terminal<<" "<<ReguliDeProductie[i].Neterminal2<<'\n';
}

    f2>>CateCuv;

    while(CateCuv)
    {
        SimbolCurent='S';//mereu simbolul curent e 'S'

        char* CuvDeGasit=new char[150];
        f2>>CuvDeGasit;
        
        if (VerificareCuvant(CuvDeGasit)) 
            cout<<"Cuvantul "<<CuvDeGasit<<" face parte din gramatica.\n";
        else cout<<"Cuvantul "<<CuvDeGasit<<" nu face parte din gramatica.\n";

        delete[] CuvDeGasit;
        CateCuv--;
    }

}
