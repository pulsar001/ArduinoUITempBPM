

#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>
#include <unistd.h>
#include <RF24/RF24.h>

using namespace std;
RF24 radio(22,0);
const uint64_t pipes[2] = { 0xF0F0F0F0E1LL, 0xF0F0F0F0D2LL };
bool radioNumber = 1;
static char msg[15]="" ;
char msg1[5]="Recu";
char msg2[3]="17";
int r;
int n;

/*unsigned long msg;*/



/******************************/



int main(int argc, char** argv){

printf("RF24/examples/GettingStarted/\n");

  radio.begin();
  radio.enableDynamicPayloads();
  radio.setRetries(5,15);
  radio.printDetails();
  radio.openWritingPipe(pipes[1]);
  radio.openReadingPipe(1,pipes[0]);
  radio.startListening();
  
   
	while (1)
	{
    radio.powerUp();
   if ( radio.available() )
    {
     
     

      while (radio.available())
      {
        radio.read( &msg,sizeof(msg) );
       
        printf("%s\n -- ",msg);
      n=atoi (msg);
      r=atoi(msg2);
        delay(500);
             
    if(n>r) 
     {
        radio.stopListening();
        radio.write(msg1,sizeof(msg1));
     delay(1000);
        n=0;
        r=0;}else
         radio.startListening();}

  
}

}}
