/*
  file:	    Interface.h
  
  brief:    Defines Interface - function prototypes for Exer�ise 3 from Task 3
 
  autor:    Shalai Markiian
 */


#ifndef INTERFACE_H
#define INTERFACE_H

#include "Functions.h"

bool Interface( char* str, char* toEnter ); // realizes user interface for initialization variables with some values

void Start(); // lanches main functions

char ReadChar(  char* str ); // reads and handles char symbols entered from keyboard

bool PresenceOfTheSymbol( char* str, char* symbol ); // returns true in case the symbol, selected by user, is present in the sentence, entered from keyboard  

#endif /* _INTERFACE_H_ */