#include <stdio.h>
#include <stdlib.h>

#define MAX 10

struct elemento {
  int codice; // numero da 1 a 10
  char valore; 
  struct elemento *prossimo;
};

struct elemento *vett[MAX]; // vettore di puntatore a lista
struct elemento *lista=NULL; // creo una lista

void stampa (struct elemento *vett[MAX]) {
  int i = 0;
  while (vett[i] != NULL) {
    printf("Codice :%d, valore: %d\n", vett[i]->codice, vett[i]->valore);
    i++;
  }
}

void stampa_lista(struct elemento *lista) {
  while (lista != NULL) {
    printf("Codice :%d, valore: %d\n", lista->codice, lista->valore);
    lista= lista->prossimo;
  }
}

int lungh(struct elemento *lista) {
  int i = 0;

  while (lista != NULL) {
  lista = lista->prossimo;
  i++;
  }
  return i;
}
  
void insert (struct elemento *p, int pos, struct elemento *vett[MAX]) {
  struct elemento *tmp = vett[pos - 1];
  int i = pos -1;

  if (p == NULL) { printf("L'elemento non e' valido\n"); return; }

  if ((pos < 1) || (pos > 100)) { printf("Posizione non valida\n"); return; } 
  
  if (vett[pos - 1] == NULL) vett[pos -1] = p;
  else {
    while (i < 10) {
      if (vett[i] == NULL) {
        vett[i] = p;
        break;
      }
      i++;
    }
    return;
  }
}

int estrai(struct elemento **lista, struct elemento **estratto) {
  struct elemento *tmp = *lista;

  if (*lista == NULL) return -1;
  if (estratto == NULL) return -2;
  if (tmp->prossimo == NULL) {
    *estratto = tmp; 
    *lista = NULL;
    return 0;
  }
  while (tmp -> prossimo -> prossimo != NULL) tmp=tmp->prossimo;

  (*estratto) = tmp-> prossimo;
  tmp->prossimo = NULL;

  return lungh(*lista);
}

int sposta (struct elemento **lista, struct elemento *v[MAX]) {
  struct elemento *el = NULL;
  int ris;

  if (lista == NULL) return -1;
  
  ris = estrai (lista, &el);
  while (ris > 0) {
    insert(el, el->codice, vett);
    ris = estrai(lista, &el);
  }
  if (ris == -2) return -2;
  else return 1;
}

int main() {
  int i;
  int pos = 8;
  struct elemento *tmp = lista;
  struct elemento *estratto;

  struct elemento *b = malloc(sizeof(struct elemento));
  b->codice = 777;
  b->valore = 123;
  b->prossimo = NULL;
  
  for (i = 0; i < 6; i++) {
    struct elemento *a = malloc(sizeof(struct elemento));
    a->codice = i;
    a->valore = 2;
    a->prossimo = NULL;

    vett[i] = a;
  }

  for (i = 0; i < 2; i++) {
    struct elemento *c = malloc(sizeof(struct elemento));
    c->codice = i;
    c->valore = 7;
    c->prossimo = NULL;
    
    if (tmp == NULL) lista = c;
    else tmp->prossimo = c;
    tmp = c;
  }
  printf("lughezza: %d\n", lungh(lista));
  stampa_lista(lista);
  printf("nuova lughezza: %d\n", estrai(&lista, &estratto));
  stampa_lista(lista);

  return 0;
}
