#pragma once
#include <iostream>
#include <string>
#include <vector>
char shiftChar(char c, int rshift);
std::string encryptCaesar(std::string plaintext, int rshift);
std::string loop(std::string encrypted_string);
std::vector<double> frequencies(std::string encrypted, int total_characters);
double distance(std::vector<double> v1, std::vector<double> v2);
std::string decoder(std::string encrypt);
// add prototypes here
