#include <stdio.h>

#define DIM 10

int vett1[DIM] = {1, 2, 4, 6, 7, 8, 8, 8, 8, 3};
int vett2[DIM] = {7, 6, 7, 8, 8, 8, 8, 3, 1, 2};

int EQS();

int main() {
    int i;
    
    for(i=0;i <10; i++) { // stampa vett1 iniziale
        printf("%d", vett1[i]);
    }
    
    printf("\n");
    
    for(i=0;i <10; i++) { // stampa vett2 iniziale
        printf("%d", vett2[i]);
    }
    printf("\n");
    
    EQS(); // chiamo la funzione
    
    return 0;
}

int EQS() {
  int i, temp, c, t;

  // controllo se i vettori sono già uguali
  for(c=0;vett1[c] == vett2[c] && c<DIM; c++);
  //se c==10 allora sono riuscito a finire il ciclo e i vettori sono già uguali

  for (t=0; t < 10 && c != 10; t++) { // conto gli scorrimenti, che potranno essere massimo 10

    // scorro circolarmente
    temp = vett2[DIM - 1];
    for (i=0; i<DIM-1; i++){
      vett2[DIM - 1 - i] = vett2[DIM - i - 2];
    }
    vett2[0] = temp;

    // controllo se vettori sono diventati uguali
    for(c=0;vett1[c] == vett2[c] && c<DIM; c++);
  }

  for(i=0;i <10; i++) { // stampo vett1 finale
    printf("%d", vett1[i]);
  }

  printf("\n");

  for(i=0;i <10; i++) { //stampo vett2 finale
    printf("%d", vett2[i]);
  }

  if (t < 10) {
    printf("\nScorrimenti: %d\n", t); 
    return 0; // stampo il numero degli scorrimenti
  }
  printf("\nNon e' stato possibile rendere i vettori uguali\n"); return -1;
}
