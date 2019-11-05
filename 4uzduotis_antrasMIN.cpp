#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int kiekis(ifstream &read);
void skaitom(int skaiciai[], int kiek, ifstream &read);
void rasom(int skaiciai[], int kiek, string txt, ofstream &write);
int didziausias(int skaiciai[], int kiek);
void indeksai(int skaiciai[], int kiekis, int indeksai[], int &indeksaiKiekis, int didziausias);
void sukeisti(int skaiciai[], int kiekis, int indeksai[], int indeksaiKiekis);

int main()
{
    ifstream read("duom.txt");
    ofstream write("rez2.txt");

    int kiek(kiekis(read));
    int skaiciai[kiek];
    skaitom(skaiciai, kiek, read);
    string txt = "Skaiciai ";
    int maksimalus(didziausias(skaiciai, kiek));
    int indeksas[kiek], dNr;
    indeksai(skaiciai, kiek, indeksas, dNr, maksimalus);
    rasom(skaiciai, kiek, txt, write);
    write << "Didziausias elementas " << maksimalus << "\n";
    rasom(indeksas, dNr, "didziausiu indeksai", write);
    sukeisti(skaiciai, kiek, indeksas, dNr);
    rasom(skaiciai, dNr, "sukeiciam su nuliais ", write);

    read.close();
    write.close();

    return 0;
}

int kiekis(ifstream &read)
{
    int kiek = 0;
    read >> kiek;

    return kiek;
}

void skaitom(int skaiciai[], int kiek, ifstream &read)
{
    for (int i= 0; i < kiek; i++) {
        read >> skaiciai[i];
    }
}

void rasom(int skaiciai[], int kiek, string txt, ofstream &write)
{
    write << txt << " masyvas ";
    for(int i = 0; i < kiek; i++){
        write << skaiciai[i] << " ";
    }
    write << endl;

}

int didziausias(int skaiciai[], int kiek)
{
    /*int did(skaiciai[0]);
    for (int i = 0; i < kiek; i++) {
        if (did < skaiciai[i]){
            did = skaiciai[i];
        }
    }*/

    int did = *max_element(skaiciai, skaiciai + kiek);

    return did;
}

void indeksai(int skaiciai[], int kiekis, int indeksai[], int &indeksaiKiekis, int didziausias)
{
    indeksaiKiekis = 0;

    for (int i = 0; i < kiekis; i ++){
        if (skaiciai[i] == didziausias){
            indeksai[indeksaiKiekis] = i;
            indeksaiKiekis++;
        }
    }

}

void sukeisti(int skaiciai[], int kiekis, int indeksai[], int indeksaiKiekis)
{
    for (int i = 0; i <indeksaiKiekis; i++){
        skaiciai[indeksai[i]] = 0;
    }

}
