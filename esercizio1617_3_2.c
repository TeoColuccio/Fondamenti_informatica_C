#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define NSEMI 4 // cuori, quadri, fiori, picche
#define NVALORI 13 // asso, 2, 3...
#define MING 2 // minimo di giocatori
#define MAXG 4 // massimo di giocatori
#define CARTEG 5// carte per ogni giocatore

const char semi[NSEMI][7] = {"cuori", "quadri", "fiori", "picche"};
const char valori[NVALORI][6] = {"asso", "2", "3", "4", "5", "6", "7", "8", "9", "dieci", "fante", "donna", "re"};

// semplificazione della funzione rand(), per essere utilizzata facilmente nel programma
int seme() { return rand() % NSEMI;}
int valore() { return rand() % NVALORI;}

int main() {
  int num_giocatori, s, v, usata; // s = seme, v = valore
  int g, c; // variabili del mazzo

  typedef struct {int s; int v;} carta;

  typedef carta giocatore[CARTEG]; // creo un vettore di carte e lo rinomino giocatore, ovvero la mano
  giocatore giocatori[MAXG]; // creo un vettore di giocatori

  int mazzo[NSEMI][NVALORI]; // struttura di supporto per verificare se la carta sia gia' stata estratta (1), oppure no (-1)

  for(g = 0; g < NSEMI; g++) {
    for (c = 0; c < NVALORI; c++) {
      mazzo[g][c] = -1; // inizializzo il mazzo
    }
  }

  srand(time(NULL)); // inizializzo il seme per la generazione di numeri pseudocasuali
  
  do { // inserisci il numero di giocatori
    printf("Numero di giocatori: ");
    scanf("%d\n", &num_giocatori);
  } while (num_giocatori < MING || num_giocatori > MAXG); // finche' il numero inserito non sia un numero valido

  for(g = 0; g < num_giocatori; g++) { // per quanti sono i giocatori
    printf("==Assegno le carte al giocatore: %d==\n", g+1);
    for(c = 0; c < CARTEG; c++) {
      usata = 1; // variabile di stato, 1 o 0
      printf("==Assegno la carta %d, al giocatore %d==\n", c+1, g+1); // indica il numero della carta e il numero del giocatore in questione
      do { // genero un seme ed un valore casuali
        s = seme(); 
        v = valore();
        if (mazzo [s][v] == -1) { // se la carta e' libera...
          mazzo[s][v] = 1; // ora diventa utilizzata
          usata = 0; // aggiorno lo stato
        }
      } while (usata == 1); // finche' non varia lo stato
    
      // aggiorno il giocatore con i nuovi dati
      giocatori[g][c].s = s;
      giocatori[g][c].v = v;
    }
  }
  printf("\n== Stampa carte assegate ==\n");
  for (g = 0; g < num_giocatori; g++) { // per quanti sono i giocatori
    printf("\nGiocatore %d - Carte: ", g+1);
    for (c = 0; c < CARTEG; c++) { // per quante sono le carte
      printf("%s di %s", valori[giocatori[g][c].v], semi[giocatori[g][c].s]); // stampa le stringhe associate al valore dell'indice
      if (c < CARTEG-1) printf(" , "); // stampa un "," per separare
    }
  }
}
