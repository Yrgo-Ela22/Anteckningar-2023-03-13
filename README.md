# Anteckningar 2023-03-13
Implementering av drivrutiner för läsning/skrivning till/från EEPROM-minnet i C.
Vid nedtryckning av en tryckknapp ansluten till pin 13 (PORTB5) läses innehållet på adress 1000
i EEPROM-minnet, vilket skrivs ut i terminalen, följt av att samma värde + 1 skrivs tillbaka
till samma adress. Ifall knappen trycks ned kontinuerlig sker läsning/skrivning till/från EEPROM-minnet
en gång i sekunden. 

Testa att dra ut mikrodatorn vid ett visst värde. Koppla seddan in den igen och tryck på knappen.
Notera att det tidigare värdet är bibehållet, då EEPROM-minnet är icke-flyktigt (som programminnet).
Samtidigt går det att skriva och läsa till EEPROM-minnet (likt dataminnet), så EEPROM-minnet utgör
något av en hybrid av programminnet och dataminne.
