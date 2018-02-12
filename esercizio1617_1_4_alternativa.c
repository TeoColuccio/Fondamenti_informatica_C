#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void EVAL(char *nomefile, int *nrighe, int *totchar, int *maxchar, float *avgchar) {
  FILE *file = fopen(nomefile, "r"); // apro il file in file
  char riga[50]; // creo la riga generica di 50 caratteri
  int i = 0; 
  /* Azzero le variabili */
  *nrighe = 0;
  *totchar = 0;
  *maxchar = 0;
  *avgchar = 0;

  if (file == NULL) { // se il file e' NULL, stampa l'errore e ritorna
    printf("Non ho potuto aprire il file..\n");
    return; // nel caso il file non esista
  }
  
  while (fgets(riga, 50, file) != NULL) { // fin quando il file non e' finito... (tutto il resto succede per ogni singola riga
    for (i = 0; i < 50 && riga[i] != '\0'; i++) { // ...ciclo la riga
      if (riga[i] != ' ') (*totchar)++; // se il carattere corrente non e' uno spazio, aumento il totale
    }
    (*nrighe)++; // incremento righe
    if (*maxchar < strlen(riga)) *maxchar = strlen(riga); // se l'attuale riga piu' lunga e' piu' corta della riga corrente, aggiorno la riga maggiore
    *avgchar = *avgchar * (float) (*nrighe - 1) + (float)strlen(riga); // calcolo la media..
    *avgchar = *avgchar / (float) *nrighe;
  }
  fclose(file); // chiudo il file
}

int main() {
  int n, t, m;
  float f;
  EVAL("testo.txt", &n, &t, &m, &f);

  printf("Numero righe: %d, numero caratteri: %d, numero massimo di caratteri per riga: %d, media di caratteri per riga: %f\n", n, t, m, f);

  return 0;
}
