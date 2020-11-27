/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Persona.cpp
 * Author: Tyler C
 * 
 * Created on November 27, 2020, 1:20 PM
 */

#include "Persona.h"
#include <string>
using namespace std;

Persona::Persona() {
}

Persona::Persona(string name,string srName,string password,int key) {
    this->name = name;
    this->srName = srName;
    this->password = password;
    this->key = key;
}

Persona::Persona(const Persona& orig) {
}

Persona::~Persona() {
}

