#include<list>
#include<string>
#include<iostream>
using namespace std;
class Vozac
   {public:
      static list<Vozac*>V;
      int brzina1;
      string naziv;
      string vrsta;
      int polozaj;
      int broj_krugova;
      int mode;
      int zamrzni;
      Vozac(string i,int b);
      string ime();
      int brzina();
      int polozajNaStazi();
      int predjeno();
      Vozac &fokus();
      Vozac &prestizi(Vozac& B);
      bool izguraj();
      void brani();
      static void protokVremena(int k=1);
      static list<Vozac*>svi();
    };

class crnaKapa:public Vozac
   {public:
     crnaKapa(string ime, int brzina);
   };
class bijelaKapa:public Vozac
   {public:
     bijelaKapa(string ime,int brzina);

   };
