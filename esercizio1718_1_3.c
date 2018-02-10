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

void crea_lista(struct list_t *l, int valore) {
  struct list_t *elem = (struct list_t*) malloc(sizeof(struct list_t));
  elem->valore = valore;
  elem->next = NULL;

  if (l == NULL) {
    l = elem;
  }
  else {
    while (l != NULL) l=l->next;
    l->next = elem;
  }
}

int main() {
  struct list_t *l;
  struct list_t a, b, c;
  
/*  l->a;
  a->valore = 1;
  a->next = b;
  b->valore = 2;
  b->next = NULL;
*/

/*  while(a != NULL) {
    printf("%d: \n", a->valore);
    a = a->next;
  }
*/
  return 0;
}
