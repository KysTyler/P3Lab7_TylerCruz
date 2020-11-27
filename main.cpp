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
string ceaserCipher(string messageToBeCiphered, int keys);

/*
 * 
 */
int main(int argc, char** argv) {
    srand(time(NULL));
    vector<Persona*> Persons;
    int mainOption = 0;
    while (mainOption != 3) {
        cout << "********MENU*************" << endl
                << "1) Registrar" << endl
                << "2) Ingresar" << endl
                << "3) Salir" << endl;
        cout << "Ingrese su option" << endl;
        cin >> mainOption;
        switch (mainOption) {
            case 1:
            {
                int key;
                string name, srName, password;
                cout << "Ingrese su nombre: " << endl;
                cin >> name;
                cout << "Ingrese su apellido: " << endl;
                cin >> srName;
                cout << "Ingrese su password: " << endl;
                cin >> password;
                key = 1 + (rand() % 15);
                Persona* person = new Persona(name, srName, password, key);
                Persons.push_back(person);

                break;
            }
            case 2:
            {
                int validatingEntrance = 0, secundaryOption;
                string name, password;
                cout << "-Menu Ingresar-" << endl;
                cout << "Ingrese su nombre: " << endl;
                cin >> name;
                cout << "Ingrese su password: " << endl;
                cin >> password;
                for (int i = 0; i < Persons.size(); i++) {
                    if (name == Persons.at(i)->getName() && password == Persons.at(i)->getPassword()) {
                        validatingEntrance = 1;
                    }
                }
                if (validatingEntrance == 1) {
                    cout << "1) Enviar Mensaje" << endl
                            << "2) Ver mensaje" << endl
                            << "3) Ver key" << endl
                            << "4) Salir" << endl;
                    cout << "Ingrese su opcion: " << endl;
                    cin >> secundaryOption;
                    switch (secundaryOption) {
                        case 1:
                        {
                            int personPos, numKey;
                            string message;
                            cout << "¡RECUERDA PONER '_' Y NO PONER ESPACIOS SINO QUEDA UN LOOP!"
                            cout << "Printing persons: " << endl;
                            for (int i = 0; i < Persons.size(); i++)
                                cout <<"Person #" << i <<"Name: " << Persons.at(i)->getName() << " SrName: " << Persons.at(i)->getsrName() << endl;
                            cout << "Ingrese la posicion del usuario al que quieres mandar mensaje: " << endl;
                            cin >> personPos;
                            cout << "Ingrese el mensaje: " << endl;
                            cin >> message;
                            numKey = Persons.at(personPos)->getKey();
                            //string messageEncrypted = ceaserCipher(message,numKey);
                            Persons.at(personPos)->setMessage(message);
                            break;
                        }
                        case 2:
                        {
                            for(int i =0;i <Persons.size();i++){
                                for(int j = 0;j < Persons.at(i)->getMessage().size();j++){
                                    cout << "Message: " <<Persons.at(i)->getMessage().at(j) << endl;
                                }
                                cout << endl;
                            }
                            break;
                        }
                        case 3:
                        {  
                            string name;
                            cout << "Ingrese su nombre: " << endl;
                            cin >> name;
                            for(int i = 0;i<Persons.size();i++)
                                if(Persons.at(i)->getName() == name)
                                    cout << "Tu llave es: " << Persons.at(i)->getKey() << endl;
                            break;
                        }
                        case 4:
                        {
                            break;
                        }

                    }
                } else {
                    cout << "USER NOT FOUND!!!!!" << endl;

                }
                break;
            }
            case 4:{
                string chain;
                cout << "Ingrese un string: " <<endl;
                cin >> chain;
                ceaserCipher(chain,3,"");
            }

        }
    }

    return 0;
}

//string split(string messageToBeCiphered,int movements){
//    for(int i=0;i < messageToBeCiphered.size();i++){
//        
//    }
//    
//    return messageToBeCiphered;
//}

string ceaserCipher(string messageToBeCiphered, int keys,string newMessage) {
    string partOfMessage = "";
    if(keys == 0){
        return newMessage;
    }
    int flag = 1;
    for (int i = 0; i < messageToBeCiphered.size(); i+=keys) {
        for (int j = 0; j < keys; j++) {
            partOfMessage += messageToBeCiphered[i];
        }
        for(int k = 0;k<partOfMessage.size();k++){
            if (flag) {
                newMessage += char(int(partOfMessage[k]+keys));
                flag = 0;
            }else if(!flag){
                newMessage += char(int(partOfMessage[k]+keys));
                flag = 1;
            }
        }
        partOfMessage = "";
    }

    ceaserCipher(messageToBeCiphered,keys - 1,newMessage);
}
