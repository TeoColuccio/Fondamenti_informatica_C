#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct el {
  char dato[10];
  struct el* next;
  struct el* prev;
};

struct sentinel {
  int quanti;
  struct el* next;
};

struct sentinel *lista; // lista e' un puntatore, in quanto punta al primo elemento

int trova (struct sentinel* l, char s[10], struct el** el) {
  struct el* temp = l->next; // temp sara' i vari elementi della lista

  if (temp == NULL) return 0; // nel caso la lista fosse vuota

  while (temp != NULL) {
    if (strcmp(s, temp-> dato) == 0) { // strcmp ritorna 0 solo se le 2 stringhe sono uguali
      *el = temp;
      return 1; // nel caso il valore venga trovato
    }
    temp = temp -> next; // scorre la lista
  }

  return 0; // nel caso il valore non venga trovato
}

void cancella (struct sentinel *l, struct el *del) {
  l->quanti--; // inizio decrementando un elemento del contatore
  
  if (del -> prev == NULL && del -> next == NULL) { // se l'elemento e' l'unico della lista
    l -> next = NULL;
  }

  else if (del -> prev == NULL) { // primo, ma con elementi successivi ad esso
    l -> next = del -> next;
    del -> next -> prev = NULL;
  }

  else { // elemento si trova nel mezzo della lista
    del -> prev -> next = del -> next;
    del -> next -> prev = del -> prev;
  }

  free(del); // libera la memoria
}
