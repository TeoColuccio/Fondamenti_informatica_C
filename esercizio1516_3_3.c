#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct el {
    double val;
    struct el *next;
    struct el *prec;
};

int leggi(struct el *lista, int *numericaricati) {
    struct el *nuovo; // creo un elemento d'appoggio 
    char *str, nome_file[100]; // creo 2 stringhe, una ci andranno le singole righe del file, e l'altra il nome del file inserito da terminale
    int res = 0; // res e' il valore da ritornare: 0 in caso tutto vada a buon fine, e -2 nel caso qualcosa vada storto
    FILE *f; // creo l'oggetto file

    printf("Inserisci il nome di un file: \n");
    scanf("%s", nome_file); // acquisisce il nome file da terminale

    while (lista != NULL && lista->next != NULL) lista = lista-> next; // faccio scorrere la lista fino all'ultimo elemento

    f = fopen(nome_file, "r"); // apro il file in f

    if (f == NULL){ // se non riesce a leggere il file...
        perror("Errore"); // ..stampa un errore 
    }

    *numericaricati = 0; // azzero la variebile contenente i numeri caricati
    str = (char*) malloc(sizeof(char)*20); // alloco la stringa
    while(f != NULL && !feof(f)){ // fin quando non termina il file non termina
        nuovo = (struct el*) malloc(sizeof(struct el)); // creo ogni volta un elemento nuovo
        str = fgets(str, 20, f); // la stringa conterra' tutta una riga, ovvero, al massimo 20 elementi

        if (nuovo == NULL || str == NULL){ // se non riesce ad allocare memoria, o a leggere la stringa..
            res = -2; // esce dal ciclo e ritorna un errore
            break;
        }

        nuovo -> val = atof(str); // popolo ogni singolo elemento
        nuovo->prec = lista;
        nuovo->next = NULL;

        if (lista != NULL) { // condizione necessaria se la lista iniziale e' vuota
            lista->next = nuovo; // il primo elemento ora e' il primo "nuovo"
        }

        lista = nuovo; // aggiorno l'indirizzo della lista

        (*numericaricati)++; // aggiorno il numero degli elementi processati ad ogni ciclo
    }

    fclose(f); // chiudo il file

    return res; // ritorno un valore 
}

void cambia (struct el *lista) {
  struct el *tmp = lista; // creo una lista temporanea
  
  while (tmp -> next != NULL) tmp = tmp -> next; // sposto tmp all'ultimo elemento della lista
  tmp -> prec->next=NULL; // il penultimo elemento ora punta a null 
  tmp -> prec = NULL; // ora tmp e' il primo elemento dalla lista, quindi l'elemento precedente e' null
  lista -> prec = tmp; // // sposto tmp in prima posizione
  tmp -> next = lista; // il 'vecchio' primo elemento, ora viene dopo tmp;
}

int main () {
    struct el *primo = NULL;
    int letti;

    leggi(primo, &letti);
    
    printf("%d caratteri processati\n", letti);
    
    cambia(primo);

  return 0;
}
