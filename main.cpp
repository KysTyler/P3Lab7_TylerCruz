/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Tyler C
 *
 * Created on November 27, 2020, 1:13 PM
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include "Persona.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    srand(time(NULL));
    vector<Persona> Persons;
    int mainOption = 0;
    while(mainOption){
        cout << "********MENU*************" << 
                "1) Registrar" << 
                "2) Ingresar" << endl;
        cout << "Ingrese su option" << endl;
        cin >> mainOption;
        switch(mainOption){
            case 1:{
                int key;
                string name,srName,password;
                cout << "Ingrese su nombre: " << endl;
                cin >> name;
                cout << "Ingrese su apellido: " << endl;
                cin >> srName;
                cout << "Ingrese su password: " << endl;
                cin >> password;
                key = 1 + (rand() % 15);
                Persona person(name,srName,password,key);
                
                break;
            }
            case 2:{
                break;
            }
                
                
        }
    }

    return 0;
}

