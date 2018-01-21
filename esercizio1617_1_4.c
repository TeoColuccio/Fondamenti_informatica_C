#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 53 // una singola riga puo' avere al massimo 50 caratteri + 2 speciali imposti dall'editor, + \0

void EVAL(char *file, int *nrighe, int *totalch, int *maxriga, float *avgriga) {
  char riga[MAX]; // stringa dove copiare le righe 
  int i;
  int chriga; // numero di caratteri di una riga
  float sommariga = 0; // somma di caratteri di tutte le righe
  FILE *f; // file da leggere

  *nrighe = 0; *totalch = 0; *maxriga = 0; // azzera i parametri entranti

  f = fopen(file, "r"); // apro il file in lettura

  while (fgets(riga, MAX, f) != NULL) { //
    chriga = 0; i = 0; *nrighe++; // azzero i caratteri della riga e la variabile contatore, poi aggiungo una riga alla conta

    while (riga[i] != '\0') { // fin quando non trova il terminatore
      chriga++; // incremento il numero di caratteri
      if (riga[i] != ' ') *totalch++; // incremento il numero totale di caratteri
      i++; // passo al carattere successivo
    }
    if (chriga > *maxriga) *maxriga = chriga; // aggiorno o meno il numero della riga con piu' caratteri
  }    
    sommariga+= chriga; // sommo i caratteri della riga corrente alla conta generale dei caratteri
  if (*nrighe != 0) *avgriga = sommariga/(*nrighe); // creo una media di caratteri

  fclose(f); // chiudo il file
}

int main() {
  int nr, totch, maxr;
  float avgr; 

  EVAL("text.txt", &nr, &totch, &maxr, &avgr);
  printf("Numero righe: %d\n Numero totale di caratteri: %d\n Numero massimo di caratteri in una riga: %d\n Numero medio di caratteri per riga: %f\n", nr, totch, maxr, avgr);
  return 0;
}
