/********************************************************************************
* main.c: Demonstration av skrivning och l�sning till och fr�n EEPROM-minnet.
*         En tryckknapp ansluten till pin 13 (PORTB5). Vid nedtryckning av
*         tryckknappen l�ses inneh�llet p� adress 1000 i EEPROM-minnet och
*         skrivs ut i terminalen, f�ljt av att ineh�llet p� adressen
*         inkrementeras. En sekunds f�rdr�jning implementeras s� att
*         nedtryckning av tryckknappen medf�r en skrivning per sekund.
********************************************************************************/
#include "serial.h"
#include "button.h"
#include "eeprom.h"

/********************************************************************************
* main: Initierar systemet med en tryckknapp p� pin 13 (PORTB5) samt seriell 
*       �verf�ring med en baud rate (�verf�ringshastighet) p� 9600 kbps. 
*       Programmet h�lls sedan ig�ng s� l�nge matningssp�nning tillf�rs, d�r 
*       tryckknappen l�ses av kontinuerligt. Vid nedtryckning l�ses inneh�llet
*       p� EEPROM[1000:1001] och skrivs ut i terminalen, f�ljt av att det
*       avl�sta v�rdet + 1 skrivs tillbaka.
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

