#include <stdio.h>
#include <string.h>

struct el {
  double val;
  struct el *next;
  struct el *prec;
};

int (struct *el lista, FILE *f, int *numericaricati) {
  char str[50*20];
  int i = 0;
  
  printf("Inserisci il nome di un file: \n");
  scanf("%s", &f);

  fopen(f, "r"); 

  fgets(str[], 50*20, f);
  if (lista != NULL) {
    lista -> next = el;
    el -> prec = lista;
  while (str[i] != '\0') {
    if (str[i] != '\n') {
      el = (struct *el) malloc(sizeof(struct el));
      el -> val = atoi(str[i]);
      el = el -> next;
      el -> prec = el;
    }
    i++;
  }
  el -> next = NULL;
}


int main () {
  struct el *primo = NULL;


  return 0;
}
