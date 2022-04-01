#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <cmath>
#include "funcs.h"


int main()
{
//main just tests out a bunch of different ciphers and produces the correct outputted version
std::string sentence = "I am going to the park after watching the new movie that just came out this saturday night.";
std::string encrypt = encryptCaesar(sentence, 7);
std::cout << "This is the encrypted message:\n\n " << encrypt << "\n" << std::endl;


std::string decoded = decoder(encrypt);
std::cout << "This is the decrypted message:\n\n " << decoded << "\n" << std::endl;
decoded = decoder("SDQMF VAN, KAG NDAWQ FTQ OAPQ!");
std::cout << "This is the encrypted message:\n\n " << "SDQMF VAN, KAG NDAWQ FTQ OAPQ!\n" << std::endl;
std::cout << "This is the decrypted message:\n\n " << decoded << "\n" << std::endl;





return 0;



}
