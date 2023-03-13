/********************************************************************************
* main.c: Demonstration av skrivning och läsning till och från EEPROM-minnet.
*         En tryckknapp ansluten till pin 13 (PORTB5). Vid nedtryckning av
*         tryckknappen läses innehållet på adress 1000 i EEPROM-minnet och
*         skrivs ut i terminalen, följt av att inehållet på adressen
*         inkrementeras. En sekunds fördröjning implementeras så att
*         nedtryckning av tryckknappen medför en skrivning per sekund.
********************************************************************************/
#include "serial.h"
#include "button.h"
#include "eeprom.h"

/********************************************************************************
* main: Initierar systemet med en tryckknapp på pin 13 (PORTB5) samt seriell 
*       överföring med en baud rate (överföringshastighet) på 9600 kbps. 
*       Programmet hålls sedan igång så länge matningsspänning tillförs, där 
*       tryckknappen läses av kontinuerligt. Vid nedtryckning läses innehållet
*       på EEPROM[1000:1001] och skrivs ut i terminalen, följt av att det
*       avlästa värdet + 1 skrivs tillbaka.
********************************************************************************/
int main(void)
{
   struct button b1;
   button_init(&b1, 13);

   serial_init(9600);
   
   while (1)
   {
      if (button_is_pressed(&b1))
      {
         const uint16_t data = eeprom_read_word(1000);

         serial_print_string("Retrieved data from EEPROM: ");
         serial_print_unsigned(data);
         serial_print_new_line();

         eeprom_write_word(1000, data + 1);
         delay_ms(1000);
      }
   }

   return 0;
}

