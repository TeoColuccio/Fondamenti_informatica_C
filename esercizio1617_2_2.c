#include <stdio.h>
#include <stdlib.h>

typedef struct cliente { // creo struct cliente
  char cf[17]; // codice fiscale
  int priorita; // priorita', 0 oppure 1
  struct cliente *next; // puntatore all'elemento successivo
  } tElemento; // rinomino typedef struct cliente in tElemento

typedef tElemento * tElemPtr; // rinomino struct tElemento *

int insPriorita1(tElemPtr *testa, tElemPtr *ultimo, tElemPtr new); // inserisce nella coda di priorita' 1
int insPriorita0(tElemPtr *testa, tElemPtr *ultimo, tElemPtr new); // inserisce nella coda di priorita' 0
void visualizza(tElemPtr lista); // stampa la lista

int main(int argc, char *argv[]) {
  tElemPtr primo = NULL; // creo il primo puntatore della lista 
  tElemPtr ultimo = NULL; // creo l'ultimo puntatore della lista
  tElemPtr temp = NULL; // creo un puntatore temporaneo

  int i, numClienti = 0;  
  int prior;

  if (argc == 1) {
    printf("\nErrore: inserire il numero di clienti\n"); // errore se non inserisco il numero di clienti da aggiungere
    return -1;
  }
  else {
    numClienti = atoi(argv[1]); // converto argv in int
    printf("Verranno inseriti %d clienti", numClienti); // stampo il numero di clienti che verrano aggiunti
  }

  for(i = 0; i < numClienti; i++) {
    temp = (tElemPtr)malloc(sizeof(tElemento)); // temp puntatore dinamico ad un tElemento
    if (temp == NULL) return 0; // ???
    
    temp -> next = NULL; // punta NULL perche' potrebbe essere l'ultimo elemento

    printf("Inserire il CF (16 caratteri): "); // chiede di inserire il codice fiscale
    scanf("%s", &(temp->cf)); // inserisco il valore in cf di temp

    do {
      printf("\nInserire la priorita' (0 o 1): "); // chiede di inserire la priorita'
      scanf("%d", &prior); 
    } while (prior != 0 && prior != 1);

    temp -> priorita = prior; // inserisce il valore in priorita di temp

    if (prior == 1) // utilizzo le funzioni per l'inserimento
      insPriorita1(&primo, &ultimo, temp);
    else 
      insPriorita0(&primo, &ultimo, temp);
  }

  printf("\n Eseuzione terminata correttamente. ");
  visualizza(primo);
  return 0;
}

int insPriorita1(tElemPtr * ptesta, tElemPtr *pultimo, tElemPtr new) {
  tElemPtr temp = *ptesta; // copio ptesta in temp

  if (new -> priorita == 0) return 0; // priorita' non valida per questa funzione

  if (*ptesta == NULL) { // se la lista e' vuota 
    *ptesta = new;
    *pultimo = new;
    return 1;
  }
  
  if ((*ptesta) -> priorita == 0) { // se in testa c'e' un cliente con priorita' 0, questo verra' dopo il nuovo cliente con priorita' 1
    new -> next = *ptesta;
    *ptesta = new;
  }

  else {
    while ((temp -> next != NULL) && ((temp -> next)-> priorita == 1)) { //se la lista ha piu' di un elemento, ed il prossimo ha priotita' 1
      temp = temp -> next; // passa all'elemento successivo
    }
    if (temp -> next != NULL) new -> next = temp -> next; // se trovo un elemento non nullo, avra' di sicuro priorita' 0, quindi verra' prima l'elemento new
    else *pultimo = new; // se non c'e' nessun elemento con priorita' 0, new sara' l'ultimo elemento

    temp -> next = new; // in ogni caso, new sara' puntato da temp -> next, ovvero sara' l'ultimo elento di priorita' 1
  }
  
  return 1;
}

int insPriorita0(tElemPtr *ptesta, tElemPtr *pultimo, tElemPtr new) {
  tElemPtr temp = *pultimo;

  if(new -> priorita == 1) return 0; // priorita' non valida per questa funzione
  if(*ptesta == NULL) { // se la lista e' vuota, new sara' l'unico elemento
    *ptesta = new; 
    *pultimo = new;
  }
  
  return 1;
}

void visualizza(tElemPtr lista) {
  printf("\n\n ***Coda clienti: ***\n");

  while(lista != NULL) { // se la lista non e' vuota, stampa le informazioni di ogni singolo elemento
    printf("\nCF cliente: %s - priorita': %d\n", lista->cf, lista->priorita);
    lista = lista -> next; // passa all'elemento successivo
  }
}

