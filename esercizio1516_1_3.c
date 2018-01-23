#include <stdio.h>
#include <stdlib.h>

typedef struct elemento_lista { // definisco l'elemento della lista
  int val;
  struct elemento_lista *next;
  struct elemento_lista *prec;
} elem_lista;

typedef elem_lista * listaPtr;
listaPtr primo = NULL; // la lista e' inizialmente vuota

listaPtr inserisciCoda(listaPtr lista, int val) {
  listaPtr tmp, nuovo;
  nuovo = (listaPtr) malloc(sizeof(elem_lista)); // alloco nuovo, puntatore ad un nuovo elemento 
  if (nuovo == NULL) {printf("Memoria terminata\n"); return lista; } // nel caso la malloc fallisse
  
  nuovo -> val = val; nuovo -> next = NULL; nuovo -> prec = NULL; // inizializzo il nuovo elemento
  if (lista == NULL) return nuovo; // nel caso la lista fosse nuova
  tmp = lista; // copio l'indirizzo del primo elemento in tmp

  while (tmp -> next != NULL) tmp = tmp -> next; // scorre la lista

  // aggancio il nuovo elemento
  tmp -> next = nuovo;
  nuovo -> prec = tmp;

  return lista;
}

void stampa(listaPtr lista) {
  listaPtr prec = NULL; // da qualsiasi elemento parta la lista, mi assicuro di stampare sia i precedenti che i successivi

  while (lista != NULL) {
    printf("%d <-> ", lista -> val); // stampo il valore
    prec = lista; // prec e' ora list
    lista = lista -> next; // scorre la lista
  }
  printf("NULL\n"); // indico che la lista e' terminata

  printf("Precedenti");
  while (prec != NULL) {
    printf("%d <-> ");
    prec = prec -> prec; // la lista scorre ora all'indietro
  }
  printf("NULL"); // indico che la lista e' terminata
}

void cerca(listaPtr lista, int val, listaPtr *elem, int *pos) {
  *elem = lista; // assegno ad elem la lista, cosi' da non modificare quella originale
  *pos = 0; // inizialmente ci troviamo in posizione 0
  
  while (*elem != NULL) {
    (*pos)++; // scorrendo la lista, incrementiamo ogni volta il contatore pos
    if ((*elem) -> val == val) return; // se trova l'elemento, la funzione termina
    else *elem = (*elem) -> next; // scorre la lista
  }

  *elem = NULL; *pos = 0; // nel caso non trovasse l'elemento cercato
}

listaPtr cancella(listaPtr lista, int pos1, listaPtr elem1, int pos2, listaPtr elem2) {
  listaPtr tmp, canc, end; // tmp e' sara' il primo elemento dell'intervallo da cancellare, end l'ultimo, e canc di volta in volta tutti gli elementi da cancellare
  int fine; // variabile di stato per il ciclo

  if (elem1 == NULL || elem2 == NULL) { // { Nel caso uno dei due elementi fosse NULL
    printf("Intervallo non valido\n");
    return lista;
  }

  // controllo chi e' il maggiare tra pos1 e pos2, cosi' da creare l'intervallo
  if (pos1 <= pos2) {
    tmp = elem1; 
    end = elem2;
  }
  else { 
    tmp = elem2;
    end = elem1;
  }

  fine = 0; // azzero la variabile di stato, cosi' da far partire il ciclo

  while (tmp != NULL && !fine) {
    if (tmp -> prec != NULL) tmp -> prec -> next = tmp -> next; // aggiorna, se esiste, l'elemento precedente

    else lista = tmp -> next; // la lista parte ora dall'elemento successivo
    if (tmp -> next != NULL) tmp -> next -> prec = tmp -> next; // Se esiste, aggiorna l'elemento successivo

    if (tmp == end) fine = 1; // se siamo giunti all'ultimo elemento, lo stato cambia ed il ciclo non verra' piu' ripetuto

    canc = tmp; // elemento da eliminare

    tmp = tmp -> next; // scorre la lista

    free(canc); // libera la memoria
  }

  return lista; // ritorna la lista modificata
}

int main() {
  int i, val, v1, v2, pos1, pos2;
  listaPtr elem1, elem2, primo;

  for (i = 0; i < 9; i++) {
    val = i + 1; // assegnamo un valore che coincide con la posizione
    primo = inserisciCoda(primo, val); // utilizzo la funzione per creare una lista
  }
  stampa(primo); // stampo la lista
  
  // richiedo il valore da cercare
  printf("Valore da cercare: \n"); scanf("%d", &v1);

  printf("Cerco l'elemento %d della lista...\n", v1);
  cerca(primo, v1, &elem1, &pos1); // cerco l'elemento
  if (elem1 != NULL && pos1 != 0) printf("Trovato in posizione: %d\n", pos1); 
  else printf("Elemento non trovato\n");
  
  cancella(primo, pos1, elem1, pos2, elem2); // cancello la lista
  stampa(primo); // verifico se la lista e' stata eleminata correttamente

  return 0;
}
