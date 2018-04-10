#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <CMatList.h>
#include <CLoad.h>

using namespace std;

int main()
{
    char * c = "test.txt";
    CLoad l;
    l.LODAddFilename(c);
    l.LODLoadFromFile();
    system("pause");
    return 0;
}
