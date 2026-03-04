#include <iostream>
#include <string>
#include <cctype>
#include "Nombre.h"

void NameProcess(std::string name){
    std::string FirtsName = "";
    std::string FirtsLastname = "";

    int SpaceCounter = 0;

    for (int i=0;i < name.length();i++){
        if (name[i] == ' '){
            SpaceCounter++;
            continue;
        }
if (SpaceCounter == 0){
            FirtsName += name[i];
        }
        else if (SpaceCounter == 1){
            FirtsLastname += name[i];
        }
    }

    int vocals = 0;

    for (int i = 0; i < name.length(); i++){
        char letter = std::tolower(name[i]);

       if (letter == 'a' || letter == 'e' || letter == 'i' ||
            letter == 'o' || letter == 'u'){
            vocals++;
        }
    }


    std::string Capital = name;

    for (int i= 0;i < Capital.length(); i++){
        Capital[i] = std::toupper(Capital[i]);
    }


    std::cout<< "Primer nombre: "<< FirtsName <<std::endl;
    std::cout<< "Primer apellido: "<< FirtsLastname <<std::endl;
    std::cout<< "Cantidad de vocales "<< vocals <<std::endl;
    std::cout<< "Nombre en mayusculas :"<< Capital <<std::endl;
    std::cout<< "Longitud total: "<< name.length() <<std::endl;
}