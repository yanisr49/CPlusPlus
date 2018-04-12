<<<<<<< HEAD
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
=======
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
>>>>>>> 038852243f194254dc8a55b9a872b8c004daede0
