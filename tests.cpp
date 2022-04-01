#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "funcs.h"
#include <string>
#include <iostream>


TEST_CASE("Tests that the decoder works"){

CHECK(decoder("Wkh prylh wkhdwhu lv vr idu dzdb. Pdbeh zh vkrxog mxvw jude vrph slccd dqg zdwfk wkh Irrwedoo jdph.") == "The movie theater is so far away. Maybe we should just grab some pizza and watch the Football game.");

}

TEST_CASE("Using a fully capital letter sentence"){
CHECK(decoder("SDQMF VAN, KAG NDAWQ FTQ OAPQ!!") == "GREAT JOB, YOU BROKE THE CODE!!");
}

TEST_CASE("Tests the decoder using input stored in a string"){
  std::string sentence = "P ht nvpun av aol whyr hmaly dhajopun aol uld tvcpl aoha qbza jhtl vba aopz zhabykhf upnoa.";
  CHECK(decoder(sentence) == "I am going to the park after watching the new movie that just came out this saturday night.");
}



// add your tests here
