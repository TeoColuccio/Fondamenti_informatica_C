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


int Query(struct tabella *lista, char nometab, char *parametri_campo) {
  struct tabella *tmp = lista; // creo una variabile d'appoggio cosi' da non modificare lista
  struct campo *camp = NULL; // creo un campo di appoggio

  strcpy(*parametri_campo, "create table ") ; // inizializzo la stringa che eventualmente verra' stampata con i paramentri del campo
  strcat(*parametri_campo, nometab); // aggiungo nometab a parametricampo
  strcat(*parametri_campo, "("); // aggiungo nometab a parametricampo

  if (lista == NULL) { printf("La lista e' vuota"); return 0; } // se la lista e' vuota 

  while (tmp != NULL) { // scorro la lista fino a quando termina
    if (strcmp((tmp -> nometabella), nometab) == 0) { // confronto i nomi delle tabelle della lista con il parametro 
      if (tmp -> nextcampo == NULL) return 0;  //se trovo la tabella, ma a questa non e' associato alcun campo
      else { 
        camp = tmp -> nextcampo; // copio il campo della tabella nella variable d'appoggio
        while (camp != NULL) { // fin quando non trova un campo non valido...
          strcat(*parametri_campo, camp -> nomecampo); // ...concateno il nome e il tipo del campo nella stringa iniziale
          strcat(*parametri_campo, " "); 
          strcat(*parametri_campo, camp -> tipocampo); 
          strcat(*parametri_campo, ","); 
        
          camp = camp -> nextcampo; // faccio scorrere i campi
        }
        strcat(*parametri_campo, ")"); // aggiungo ')' alla stringa  
        
        return 1; // ritorno un risultato positivo
      }
    }
    
    tmp = tmp -> nexttabella; // faccio scorrere la lista
  }
  return 0;
}

// creo una tabella ed un campo di prova
struct campo campo1;
strcpy(campo1.nomecampo), "primo_campo";
strcpy(campo1.tipocampo),"char";

struct tabella tab1;
strcpy(tab1.nometabella, "prima");
nexttabella = NULL;

tab1 -> nextcampo = *campo1;

int main() {
  char *nometab, *parametricampo; 

  printf("Inserisci il nome di una tabella da ricercare: \n"); 
  scanf("%s", nometab);

  if (query(lista, nometab, &parametricampo) == 0) printf("Tabella non trovata..\n");
  else {
    printf("Tabella trovata...");
    printf("%s\n", parametricampo);
  }

  return 0;
}




        
