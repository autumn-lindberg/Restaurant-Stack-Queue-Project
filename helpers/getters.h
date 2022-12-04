#pragma once
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

char * getWordFromFile(ifstream & inFile, char delimeter);
int getIntFromFile(ifstream & inFile, char delimeter);
char getCharFromFile(ifstream & inFile, char delimeter);
char * getWordFromUser();
int getIntFromUser();
int getIntFromUser(int max);
char getCharFromUser();

