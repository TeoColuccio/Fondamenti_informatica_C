#include <stdio.h>
#include <stdlib.h>

struct list_t{
  int valore;
  struct list_t *next;
};

struct list_t *lista=NULL;

int conta(struct list_t* lista, int valore) {
  int i = 1, contatore =  0;
  struct list_t* tmp = lista;
  
  if (lista == NULL) return 0;

  while (lista != NULL) {
    if ((i != 3) && (lista->next != NULL) && (lista->valore == valore)) contatore++; 
    lista = lista->next;
    i++;
  }
  return contatore;
}
void crea_lista_vuota(struct list_t **l, int valore) {
  struct list_t *elem = (struct list_t*) malloc(sizeof(struct list_t));
  elem->valore = valore;
  elem->next = NULL;
  *l = elem;
}


void crea_lista(struct list_t **l, int valore) {
  struct list_t *tmp = *l;
  if (*l == NULL) crea_lista_vuota(l, valore);

  else {
    struct list_t *elem = (struct list_t*) malloc(sizeof(struct list_t));
    if (elem == NULL) return; 

    elem->valore = valore;
    elem->next = NULL;
    
    while (tmp->next != NULL) {
      tmp=tmp->next;
    }
    tmp->next = elem;
  }
}

int main() {

/* Inserimento manuale:
  int i;
  struct list_t *tmp = lista;
 * for (i = 0; i < 10; i++) {
    struct list_t *a = malloc(sizeof(struct list_t));
    a->valore = i;
    a->next = NULL;
    if (tmp == NULL) lista = a;
    else tmp->next = a;
  tmp = a;
  }
*/

  crea_lista(&lista, 1);
  crea_lista(&lista, 2);
  crea_lista(&lista, 3);
  crea_lista(&lista, 4);

  while (lista != NULL) { 
    printf("%d \n", lista->valore);
    lista = lista->next;
  }

  return 0;
}
