
#include <iostream>
#include <iomanip>
#include "Matriz.h"

void ReadMatriz(int matriz[Rows][Columns]){
    for (int i=0; i<Rows;i++){
        for(int y=0;y < Columns;y++){
            std::cout<< "digite el valor [" <<i<< "][" <<y<< "]: ";
            std::cin>> matriz[i][y];
        }
    }
}

void PrintMatriz(int matriz[Rows][Columns]){
    std::cout<< "Matriz registrada "<< std::endl;

    for (int i=0; i< Rows;i++){
        for (int y=0;y <Columns; y++){
            std::cout<<std::setw(5) << matriz[i][y];
        }
        std::cout << std::endl;
    }
}

void RowsAddition(int matriz[Rows][Columns]) {
    for (int i =0; i< Rows;i++){
        int suma= 0;

        for (int y=0; y< Columns; y++){
            suma = suma + matriz[i][y];
        }

        std::cout << "Suma de la fila " << i << ": " << suma << std::endl;
    }
}

void ColumnsAddition(int matriz[Rows][Columns]){
    for (int y = 0; y < Columns;y++) {
        int suma =0;

        for (int i = 0; i < Rows; i++){
            suma = suma + matriz[i][y];
        }
        std::cout << "Suma de la columna " << y << ": " << suma << std::endl;
    }
}

void DiagonalAddition(int matriz[Rows][Columns]) {
    int suma= 0;

    for (int i = 0;i < Rows; i++){
        suma = suma + matriz[i][i];
    }
    std::cout << "la suma diagonal principal es: " << suma << std::endl;
}