/*
  Copyright (c) 2013, Intel Corporation

  Redistribution and use in source and binary forms, with or without modification,
  are permitted provided that the following conditions are met:

  * Redistributions of source code must retain the above copyright notice,
  this list of conditions and the following disclaimer.
  * Redistributions in binary form must reproduce the above copyright notice,
  this list of conditions and the following disclaimer in the documentation
  and/or other materials provided with the distribution.
  * Neither the name of Intel Corporation nor the names of its contributors
  may be used to endorse or promote products derived from this software
  without specific prior written permission.

  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
  ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
  WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
  ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
  (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
  ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
  SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

/* Program demonstrating writing/reading to/from gpio pins. */

#include "gpio.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int output_pins[] = {D0, D1, D2};
int input_pin = D13;
int i;
int c;
int j;

 /* Continuously blinks 3 LEDs attached to digital pins in output_pins[] on the Galileo */
void all_blink() {
	// set output_pins to Output
	for (i = 0; i < sizeof(output_pins) / sizeof(int); ++i) {
		if (setGPIO_Out(output_pins[i]))
			exit(1);
	}

	// Continuously write to pins
	i = 0;
	while (1) {
		GPIO_Write(output_pins[0], (i+0)%3);
		GPIO_Write(output_pins[1], (i+1)%3);
		GPIO_Write(output_pins[2], (i+2)%3);
		sleep(1);
		++i;
	}
}

 /* Function to turn RBG sensor to change its color to Red, Blue and Green if reading 1 from input_pin */
void all_blink_with_switch() {
  // set output_pins to Output
  for (i=0;i<(sizeof(output_pins) / sizeof(int));i++)
    if (setGPIO_Out(output_pins[i]))
      exit(1);
  if (setGPIO_In(input_pin))
      exit(1);

  // Continuously write to pins
  i = 0;
  while (1) {
    if ((GPIO_Read(input_pin)) == 1) {
      GPIO_Write(output_pins[0], (i+0)%3);
      GPIO_Write(output_pins[1], (i+1)%3);
      GPIO_Write(output_pins[2], (i+2)%3);
      // sleep(1);
      ++i;
    }
    else {
      GPIO_Write(output_pins[0], 0);
      GPIO_Write(output_pins[1], 0);
      GPIO_Write(output_pins[2], 0);
    }
  }
}

 /* Function to blink Red LED in 1 second intervals. */ 
 void blink_light(int pin) { 
   // set output_pin[0] to Output 
   if (setGPIO_Out(pin)) { 
     exit(1); 
   } 

   // Continuously write to pin 
   int i; 
   i = 0; 
   while (1) { 
     GPIO_Write(pin, 1); 
     sleep(1); 
     GPIO_Write(pin, 0); 
     sleep(1); 
     ++i; 
   } 
 }

 /* Function to read from pin */ 
 void read_pin(int pin) { 
   // set pin to Input 
   if (setGPIO_In(pin)) { 
     exit(1); 
   } 

   while (1) { 
     // continuously read value 
     printf("Value: %d\n", GPIO_Read(pin)); 
     //sleep(1); 
   } 

 } 

int main() {

  /* Example Read from input_pin */
  // read_pin(input_pin);

  /* Example Write to pins */
  // blink_light(output_pins[0]);
  // all_blink();

  /* Example Read and Write to pins */
  all_blink_with_switch();

  return 0;
}
