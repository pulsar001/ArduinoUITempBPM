

#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>
#include <unistd.h>
#include <RF24/RF24.h>

using namespace std;
RF24 radio(22,0);
const uint64_t pipes[2] = {0xC2C2C2C2C2,0xE7E7E7E7E7};
bool radioNumber = 1;
char msg[31] ;

/********************************/



int main(int argc, char** argv){

printf("RF24/examples/GettingStarted/\n");


  radio.begin();
  radio.openReadingPipe(0,pipes[1]);

  // optionally, increase the delay between retries & # of retries
  radio.setRetries(15,15);
  // Dump the configuration of the rf unit for debugging
  radio.printDetails();
  radio.powerUp();
  radio.startListening();

  
  if (radio.available())
 //radio.read(&msg,sizeof(msg));
  printf("msg");



/********* Role chooser ***********/
    else

  printf("\n ************ Role Setup ***********\n");
  

  return 0;
}

