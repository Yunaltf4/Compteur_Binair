#include <Adafruit_CircuitPlayground.h>

int num = 0;

void setup() {
  CircuitPlayground.begin();
  show();
}

void loop() {
  //Ajouter 1 si il depasse pas 1023
  if (CircuitPlayground.rightButton() && num < 1023) {
    num++;
    show();
    delay(200);
  }
  //Ajouter 1 si il est pas sous 0
  if (CircuitPlayground.leftButton() && num > 0) {
    num--;
    show();
    delay(200);
  }
}
  //Regarder a la led (entre 0-9) et montrer si on a besoin
void show() {
  for (int i = 0; i < 10; i++) {
    checker(1 << i, i);
  }
}
  /*Comparer le num et le div si il montre qu'il y a un bit a la position de div dans le num 
    Allume la led
    sinon
    Garde la lumiere fermer 
  */
void checker(int div, int led) {
  if (num & div){
    CircuitPlayground.setPixelColor(led, 255, 0, 0);
  }
  else{
    CircuitPlayground.setPixelColor(led, 0, 0, 0);
  }
}