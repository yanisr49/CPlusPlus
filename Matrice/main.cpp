
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <CMatList.h>
#include <CLoad.h>

using namespace std;

int main()
{
    string c = "matrice1.txt";
    CLoad l;
    l.LODAddFilename(c);
    c = "matrice2.txt";
    l.LODAddFilename(c);

    l.LODLoadFromFile();
    system("pause");
    return 0;
}

