#include <stdio.h>
#include <string.h>

#define CAR 50 // 50 caratteri max per stringa
#define STRINGHE 36 // numero max di stringhe

typedef char str[36]; // char crea ora un vettore di stringhe
str vett[50]; // creo vett, ovvero 36 stringhe da 50 caratteri max
int posizione = -1; // indice delle stringhe, inizialmente e' negativo

int main() {
  int i, j, currvocale; // currvocale contiene il carattere della vocale
  int ok; // variabile di stato, se e' vero stampa la stringa altrimenti no

  strcat(vett[0], "alta"); // popolo vett
  strcat(vett[1], "arte");
  strcat(vett[2], "arete");
  strcat(vett[3], "idea");
  posizione = 3; // ora posizione vale 3
  
  for (i = 0; i<=posizione;i++) { // cicla ogni stringa 
    j = 0;
    currvocale = 'a';
    
    while ((vett[i][j] != '\0') && ok)  // scansione stringa 
      if ((vett[i][j] == 'a') ||
          (vett[i][j] == 'e') ||
          (vett[i][j] == 'i') ||
          (vett[i][j] == 'o') || 
          (vett[i][j] == 'u')) {
        if (vett[i][j] >= currvocale) { // controlla se 
          currvocale = vett[i][j]; j++; // aggiorna la vocale
        }
        else ok = 0; // altrimenti setta lo stato a 0
      }
      else j++; // passa al carattere successivo

      if(ok) printf("ok %s\n", vett[i]); // se ok e' vero stampa ok e la tringa
      else printf("notok %s\n", vett[i]); // altrimenti stampa notok 
    
  }
}
