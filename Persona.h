/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Persona.h
 * Author: Tyler C
 *
 * Created on November 27, 2020, 1:20 PM
 */
#include <string>
#include <vector>
#ifndef PERSONA_H
#define PERSONA_H

using namespace std;

class Persona {
public:
    Persona();
    
    Persona(const Persona& orig);
    virtual ~Persona();
    
    Persona(string,string,string,int);
    
    
    string getName();
    string getsrName();
    string getPassword();
    int getKey();
    vector<string> getMessage();
    void setMessage(string);
    
public:
    string name;
    string srName;
    string password;
    int key;
    vector<string> listmessages;
};

#endif /* PERSONA_H */

