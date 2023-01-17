#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <cmath>

using namespace std;

int veleveliu_sk(int G, int Z, int R);

int main()
{
    ifstream duom("Duomenys.txt");
    ofstream rez("Rezultatai.txt");
    int n, G=0, Z=0, R=0;
    duom >> n;
    for (int i = 0; i < n; i++)
    {
        char temp;
        int x;
        duom >> temp >> x;
        if (temp=='G')G += x;
        else if (temp=='Z')Z += x;
        else R += x;
    }
    int sk = veleveliu_sk(G, Z, R);
    rez << sk << '\n';
    rez << "G = " << G - sk * 2 << '\n';
    rez << "Z = " << Z - sk * 2 << '\n';
    rez << "R = " << R - sk * 2 << '\n';
    duom.close();
    rez.close();
    return 0;
}

int veleveliu_sk(int G, int Z, int R)
{
    int ats;
    if (G <= Z && G <= R) ats = G / 2;
    else if (Z <= G && Z <= R) ats = Z / 2;
    else ats = R / 2;
    return ats;
}