#include <stdio.h>
#include <stdlib.h>

struct list_t { // definisco la struct
  int info; 
  struct list_t *next;
}; 

struct list_t *lista1 = NULL, *lista2 = NULL, *lista3 = NULL; // alloco 3 list_t

struct list_t *merge(struct list_t *prima, struct list_t *seconda) {
  struct list_t *terza = NULL; // creo una terza list_t
  int current = 1; // 1 indica la prima list_t e 2 indica la seconda
  struct list_t *temp; // creo elemento da usare temporaneamente
  struct list_t *new; // new sara' la nuova lista

  while ((prima != NULL) && (seconda != NULL)) { // controllo se entrambe le liste sono non nulle
    new = malloc(sizeof(struct list_t)); // creo l'elemento
    if (new == NULL) return terza; // lista ultimata
    new -> next = NULL;

    if (current == 1) { // estraggo i dati dalla prima lista
      new -> info = prima -> info;
      prima = prima -> next; // faccio scorrere la lista
      current = 2; 
    }
    else {  // estraggo i dati dalla seconda lista
      new -> info = seconda -> info;
      seconda = seconda -> next;
      current = 1;
    }

    if (terza == NULL) { // inserisce in coda
      terza = new;
      temp = terza;
    }
    else {
      temp -> next = new;
      temp = temp -> next;
    }
  }

  if (prima == NULL) { // nel caso la prima lista fosse nulla
    while (seconda != NULL) {
      new = malloc(sizeof(struct list_t));
      if (new == NULL) return terza;
      new -> next = NULL;
      new -> info = seconda -> info;
      seconda = seconda -> next;

      if (terza == NULL) {
        terza = new;
        temp = terza;
      }
      else {
        temp -> next = new;
        temp = temp -> next;
      }
    }
  }
  else {
    while (prima == NULL) {
      new = malloc(sizeof(struct list_t));
      if (new == NULL) return terza;
      
      new -> next = NULL;
      new -> info = prima -> info;
      prima = prima -> next;
      if (terza == NULL) { 
        terza = new; 
        temp = terza;
      }
      else {
        temp -> next = new; 
        temp = temp -> next;
      }
    }
  }
}
