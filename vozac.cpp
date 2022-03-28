#include "vozac.h"

std::list<Vozac*> Vozac::V;

Vozac::Vozac(string i,int b)
   { brzina1=b;
     naziv=i;
     polozaj=0;
     broj_krugova=0;
     V.push_back(this);
     zamrzni=2;
     mode=0;
   }

crnaKapa::crnaKapa(string i,int b) : Vozac(i,b)
   {
       vrsta="crnaKapa";
   }

bijelaKapa::bijelaKapa(string i,int b) : Vozac(i,b)
   {
       vrsta="bijelaKapa";
   }
string Vozac::ime()
  {
      return naziv;

  }

int Vozac::brzina()
   {
       return brzina1;
   }

int Vozac::polozajNaStazi()
   {
       return polozaj;
   }

int Vozac::predjeno()
   { int pom;
       pom=broj_krugova*360+polozaj;
   return pom;
   }

Vozac& Vozac::fokus()
   { Vozac *pom;
     list<Vozac*>::iterator li;
     int i,kontrola=0;
if(vrsta=="bijelaKapa")
  {for(i=polozaj+1;i<360;i++)
        {for(li=V.begin();li!=V.end();li++)
             if((*li)->polozaj==i && (*li)->zamrzni){pom=*li;kontrola=1;break;}
         if(kontrola)break;
        }
    if(!kontrola)
     {
         for(i=0;;i++)
            {for(li=V.begin();li!=V.end();li++)
                if((*li)->polozaj==i && (*li)->zamrzni){pom=*li;kontrola=1;break;}
             if(kontrola)break;
            }

     }
  }
if(vrsta=="crnaKapa")
   {
     for(i=0;i<polozaj;i++)
       for(li=V.begin();li!=V.end();li++)
             if((*li)->polozaj==i && (*li)->zamrzni){pom=*li;kontrola=1;}

      if(!kontrola)
           for(i=359;i>polozaj;i--)
               {
                   for(li=V.begin();li!=V.end();li++)
                   {
                       if((*li)->polozaj==i && (*li)->zamrzni){pom=*li;kontrola=1;break;}
                   }
                if(kontrola)break;
               }

   }

return *pom;
   }


Vozac& Vozac::prestizi(Vozac &B)
   {

    if(B.mode==0 && B.brzina1<2*brzina1 && B.zamrzni && zamrzni)
       {
           if(B.polozaj<polozaj) {polozaj=B.polozaj+1;
                                  broj_krugova++;
                                 }
           else{ polozaj=B.polozaj+1;
                 if(polozaj==360) {polozaj=0;broj_krugova++;}

               }
       }
   else if(B.zamrzni && zamrzni)
      {
          if(B.polozaj<polozaj) {polozaj=B.polozaj-1;
                                 broj_krugova++;
                                 if(polozaj<0) {polozaj=359;broj_krugova--;}

                                }
           else{
                 polozaj=B.polozaj-1;
               }

     }
    return *this;
   }
list<Vozac*>Vozac::svi()
   {list<Vozac*>n;
    n=V;
    return n;
   }


bool Vozac::izguraj()
   {
     if(zamrzni && vrsta=="crnaKapa")
        { Vozac &p=fokus();


           if(p.mode==0)
                 { p.zamrzni=0;
                   if(p.polozaj<polozaj)polozaj=p.polozaj;
                   else {polozaj=p.polozaj;broj_krugova--;}
                   zamrzni--;
                   return true;
                 }
           else
                 { int pom=p.polozaj;
                   p.polozaj++;
                   if(p.polozaj==360) {p.polozaj=0;p.broj_krugova++;}
                   if(polozaj>pom)polozaj=pom;
                   else {broj_krugova--;polozaj=pom;}
                   p.mode=0;
                 }
        }
    return false;
   }

void Vozac::brani()
   { if(vrsta=="bijelaKapa")
           mode=1;
   }
void Vozac::protokVremena(int k)
   { list<Vozac*>::iterator li;

     for(li=V.begin();li!=V.end();li++)
        if((*li)->zamrzni)
        {
            for(int i=1;i<=k;i++)
                {
                 (*li)->polozaj=(*li)->polozaj+(*li)->brzina1;
                       while((*li)->polozaj>=360)
                       {
                           (*li)->broj_krugova++;
                           (*li)->polozaj-=360;
                       }
                 if((*li)->broj_krugova==50)break;
                }
        }
   }
