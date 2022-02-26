#include <stdio.h>
#include "Interface.h"


#include "matrix.h"

// проверка утечек памяти
#define __CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#define DEBUG_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
#define new DEBUG_NEW
//

int main(void)
{

  //  printf("Hello world! \n");
    //dialog();
    test_float();
    test_complex();

    scanf("%*c");
    _CrtDumpMemoryLeaks();
    return 0;
}
