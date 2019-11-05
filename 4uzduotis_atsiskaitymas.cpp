#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
 ifstream in("duom.txt");
 ofstream out("rez.txt");
 int kiekis();
 void skaitom(int Masyvas[], int kiek);
 void rasom (int Masyvas[], int kiek, string txt);


int main()
{
    int n(kiekis());//masyvo elementu skaicius
    int A[n];//Musu masyvas is bylos
    skaitom(A, n);
    rasom(A, n, "Musu");
    sort(A, A+n);
    rasom(A, n, "Surikiuotas");


    in.close();
    out.close();
  return 0;
}
//----------------------------------
  int kiekis()
  {
      int kiek(0), laikinas;
      while(!in.eof()){
        in>>laikinas;
        kiek++;
      }
      in.seekg(0);
      return kiek;
  }
//-----------------------------------

void skaitom(int Masyvas[], int kiek)
{
    for(int i=0; i<kiek; i++)
    {
        in>>Masyvas[i];
    }
}
//------------------------------------
void rasom (int Masyvas[], int kiek, string txt)
{
    out<<txt<<" masyvas"<<endl;
    for(int i=0; i<kiek; i++)
    {
        out<<Masyvas[i]<<" ";
    }
    out<<endl;
}
