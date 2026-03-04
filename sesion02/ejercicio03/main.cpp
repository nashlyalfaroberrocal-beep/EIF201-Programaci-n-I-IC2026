#include <iostream>
#include "Matriz.h"

int main()
{
    int matriz[Rows][Columns];

    ReadMatriz(matriz);

    PrintMatriz(matriz);

    RowsAddition(matriz);

    ColumnsAddition(matriz);

    DiagonalAddition(matriz);

    return 0;
}