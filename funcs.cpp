#include <iostream>
#include <string>
#include <cmath>
#include "funcs.h"
#include <vector>


std::string decoder(std::string encrypt){
  std::vector<double>eng_frequencies{0.082, 0.015, 0.027, 0.047, 0.13, 0.022, 0.02, 0.062, 0.069, 0.0016, 0.0081, 0.04, 0.027, 0.067, 0.078, 0.019, 0.0011, 0.059, 0.062, 0.096, 0.027, 0.0097, 0.024, 0.0015, 0.02, 0.0078};
//english language eng_frequencies

//count the total size of the string without spaces and punctuation marks to get an accurate percentage later on
  int count_total_size = 0;
  for (int i = 0; i < encrypt.length(); i++){
    if (isalpha(encrypt[i])){
      count_total_size += 1;
    }
  }

//initialize variables used in the functions
  std::string answer = "";
  std::vector<double>arr;
  double length_rep = 0;
  double min_length = 100;
//loops through 26 iterations of the caesar cipher
  for (int x = 0; x < 26; x++){
//sets encrypt as that specific cipher rotation
  encrypt = loop(encrypt);
  //sets the array arr as the array of frequencies for that specific cipher rotation
  arr = frequencies(encrypt, count_total_size);
//set a double variable to equal the distance between the english frequencies and the cipher frequencies
  length_rep = distance(arr, eng_frequencies);

  //if this variable min_length is greater than the length of this rotation set min_length as this new lower length
  //also set the answer variable as this specific rotation because that is the closest to english distance wise
  if (min_length > length_rep){
    min_length = length_rep;
    answer = encrypt;
  }



}//returns the answer string
return answer;}



//checks the two vectors one for english frequencies and one from the specific version of the cipher
double distance(std::vector<double> v1, std::vector<double> v2){
  //set a total variable to count up all the differences squared for each of the 26 letters
  double total = 0.0;
  for (int i = 0; i < 26; i++){
    total = total + pow((v2[i] - v1[i]), 2);
  }
  //square root the total like the distance formula says
  total = sqrt(total);
  //return the length of the distance
  return total;
}



std::vector<double> frequencies(std::string encrypted, int total_characters){
  //empty array of 26 positions each corresponding to a letter
  std::vector<double>arr{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
  char letters[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
  char letters2[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
//two arrays one for lowercase letters and one for uppercase letters
//nested for loop to loop through the letters of the cipher and the letters of the alphabet
  for (int i = 0; i < total_characters; i++){
    for (int x = 0; x < 26; x++){
      //if the specific letter is equal to a letter from the alphabet arrays that specific position is incremented in the originally empty array
      if (encrypted[i] == letters[x] || encrypted[i] == letters2[x]){
        arr[x] += 1;
      }
    }
  }
  //calculate the frequency of each letter divide the number of letters by the total calculated previously
  for (int z = 0; z < 26; z++){
    arr[z] = arr[z] / total_characters;
  }
  return arr;}
















/*
if (encrypted[i] == 'a' || encrypted[i] == 'A'){
  arr[0] += 1;
}
if (encrypted[i] == 'b' || encrypted[i] == 'B'){
  arr[1] += 1;
}



  }


}
*/






char shiftChar(char c, int rshift){
  //shifts characters by aa certain number of positions
  int a = int(c);
  if (a >= 'A' && a <= 'Z'){
    a = 'A' + (a - 'A' + rshift + 26) %26;
}
if(a >= 'a' && a <= 'z')
{
a = 'a' + (a - 'a' + rshift + 26) %26;
}


return char(a);
}




std::string encryptCaesar(std::string plaintext, int rshift){
  //encrypts a string message by shifting the characters of the string a certain number of positions each
  int len = plaintext.length();
  std::string str = "";
  char let;
  for (int i = 0; i < len; i++){
    let = shiftChar(plaintext[i], rshift);
    str = str + let;

  }
  //std::cout << str << std::endl;
return str;


}


std::string loop(std::string encrypted_string){
  //loops through the encryptCaesar function to get the next rotation
    encrypted_string = encryptCaesar(encrypted_string, 1);
return encrypted_string;
}

// add functions here
