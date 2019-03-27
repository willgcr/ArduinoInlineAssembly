/*

Just a demonstration on how to use inline assembly code
with arduino - The board used was Uno-R3

For more information take a look at:
http://www.nongnu.org/avr-libc/user-manual/inline_asm.html
http://ww1.microchip.com/downloads/en/DeviceDoc/Atmel-42735-8-bit-AVR-Microcontroller-ATmega328-328P_Datasheet.pdf

This is free and unencumbered software released.
Anyone is free to copy, modify, publish, use, compile, sell, or
distribute this software, either in source code form or as a compiled
binary, for any purpose, commercial or non-commercial, and by any
means.

Willian Gabriel Cerqueira da Rocha
willianrocha[at]riseup[dot]net
https://wgrocha.github.io

*/

void setup () {
  Serial.begin (9600);
  asm ("sbi 0x4, 0x5");
  int sTime = micros ();
  asm ("ldi r18, 0");
  asm ("loop_label:");
  asm ("sbi %0, 0x5" :: "I" _SFR_IO_ADDR (PORTB));
  asm ("cbi %0, 0x05" :: "I" _SFR_IO_ADDR (PORTB));
  asm ("inc r18");
  asm ("cpi r18, 100");
  asm ("brlt loop_label");
  int eTime = micros ();
  Serial.println (eTime - sTime);
}

void loop () {
}
