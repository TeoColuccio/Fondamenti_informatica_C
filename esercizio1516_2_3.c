#include <stdio.h>
#include <string.h>

struct campo {
  char nomecampo[40];
  char tipocampo[50];
  struct campo *nextcampo;
};

struct tabella {
  char nometabella[100];
  struct tabella *nexttabella;
  struct campo *nextcampo;
};

struct tabella *lista = NULL;


int Query(struct tabella *lista, char nometab, char *parametricampo) {
  struct tabella *tmp = lista; // creo una variabile d'appoggio cosi' da non modificare lista
  struct campo *camp = NULL; // creo un campo di appoggio

  *parametricampo = "create table " ; // inizializzo la stringa che eventualmente verra' stampata con i paramentri del campo
  *parametri_campo = strcat(*parametricampo, nometab); // aggiungo nometab a parametricampo
  *parametri_campo = strcat(*parametricampo, '('); // aggiungo nometab a parametricampo

  if (lista == NULL) { printf("La lista e' vuota"); return 0; } // se la lista e' vuota 

  while (tmp != NULL) { // scorro la lista fino a quando termina
    if (strcmp((tmp -> nometabella), nometab) == 0) { // confronto i nomi delle tabelle della lista con il parametro 
      if (tmp -> nextcampo == NULL) { print("La tabella e' stata trovata, ma non ha un campo valido"); return 0; } //se trovo la tabella, ma a questa non e' associato alcun campo
      else { 
        camp = tmp -> nextcampo; // copio il campo della tabella nella variable d'appoggio
        while (camp != NULL) { // fin quando non trova un campo non valido...
          *parametri_campo = strcat(*parametricampo, tmp -> nextcampo -> nomecampo); // ...concateno il nome e il tipo del campo nella stringa iniziale
          *parametri_campo = strcat(*parametricampo, ' '); 
          *parametri_campo = strcat(*parametricampo, tmp -> nextcampo -> tipocampo); 
          *parametri_campo = strcat(*parametricampo, ','); 
        
          camp = camp -> nextcampo; // faccio scorrere i campi
        }
        *parametri_campo = strcat(*parametricampo, ')'); // aggiungo ')' alla stringa  
        
        return 1; // ritorno un risultato positivo
      }
    }
    
    tmp = tmp -> nexttabella; // faccio scorrere la lista
  }
}

        
