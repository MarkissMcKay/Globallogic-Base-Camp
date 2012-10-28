/*
  file:	    Interface.h
  
  brief:    Defines Interface - function prototypes for Exerñise 28 from Task 3
 
  autor:    Shalai Markiian
 */


#ifndef INTERFACE_H
#define INTERFACE_H

#include "Functions.h"

bool Interface( char* str, char* toEnter ); // realizes user interface for initialization variables with some values

void Start(); // lanches main functions

char ReadChar(  char* str ); // reads and handles char symbols entered from keyboard

#endif /* _INTERFACE_H_ */