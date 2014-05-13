gpio
====

C Library for GPIO pins

This library was written partially by Patrick Holmes of Intel.
I expanded Patrick's code to give full input/output support for all 14 gpio pins on the Galileo.

USAGE:
  int SetGPIO_Out(int pin);
      --initializes pin for output.
        <pin> refers to the pin being written to.
      returns 0 on success, otherwise there's an error.
  
  int SetGPIO_In(int pin);
      --initializes pin for input.
        <pin> refers to the pin being read from.
      returns 0 on success, otherwise there's an error.
   
      
  ***Pins MUST be initialized before they can be read from or written to!***

  int GPIO_Write(int pin, int val);
      --write val to the specified pin.
        <pin> refers to the pin being written to.
        <val> is the value being written, and should be either 0 or 1.
      returns 0 for success, otherwise there's an error.
  
  int GPIO_Read(int pin);
      --read value of the specified pin.
        <pin> refers to the pin being read from.
      returns 0 or 1 specifying pin value, otherwise there's an error.
