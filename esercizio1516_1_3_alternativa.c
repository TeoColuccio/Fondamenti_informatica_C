#include <stdio.h>
#include <stdlib.h>

typedef struct elemento_lista {
  int val;
  struct elemento_lista *next;
  struct elemento_lista *prec;
} elem_lista;
typedef elem_lista * listaPtr;

listaPtr primo = NULL;

void cerca(listaPtr lista, int val, listaPtr *elem, int *posizione) {
  int i = 0;
  if (lista == NULL) { *elem = NULL; return; }

  while (lista != NULL) {
    if (lista->val == val) { *elem = lista; *posizione = i; return; }
    lista=lista->next;
    i++;
  }
  *elem=NULL; 
  *posizione = 0;
  return;
}

listaPtr cancella(listaPtr lista, listaPtr elemento1, listaPtr elemento2, int *pos1, int *pos2) {
  listaPtr tmp = lista;
  listaPtr canc;
  int i = 0;

  if (lista == NULL || elemento1 == NULL || elemento2 == NULL || *pos1 > *pos2) { printf("Elementi non validi.\n"); return lista; }

  while (i < *pos1) { tmp=tmp->next; i++; }
  tmp->next=elemento2->next;
  elemento2->prec = tmp;
  while(tmp -> next != elemento2->next) {
    canc = tmp->next;
    free(tmp->next); 
    tmp = canc;
  }
  return lista;
}
  
int main() {
  int i = 0;
  listaPtr tmp  = primo;
  listaPtr elemento1;
  listaPtr elemento2;
  int val1;
  int val2;
  int pos1;
  int pos2;

  for (i = 0; i < 10; i++) {
    listaPtr a = malloc(sizeof(elem_lista));
    a->val = i; 
    a->prec=NULL;
    a->next=NULL;
    if (tmp == NULL) primo = a;
    else {
      tmp->next = a;
      a->prec = tmp;
    }
    tmp = a;
  }

  printf("Primo valore da cercare: \n");
  scanf("%d", &val1);
  printf("Secondo valore da cercare: \n");
  scanf("%d", &val2);
  /*
   while (primo->next != NULL) {
     printf("valore: %d\n", primo->val);
     primo = primo->next;
  } 
   primo= primo->prec;
   while (primo -> prec != NULL) {
     printf("valore: %d\n", primo->val);
     primo = primo->prec;
   } 
  */

   cerca(primo, val1, &elemento1, &pos1);
   cerca(primo, val2, &elemento2, &pos2);

   primo=cancella(primo, elemento1, elemento2, &val1, &val2);
//   while(primo->prec != NULL) primo = primo->prec;

   while (primo != NULL) {
     printf("valore: %d\n", primo->val);
     primo = primo->next;
  } 

  return 0;
}
