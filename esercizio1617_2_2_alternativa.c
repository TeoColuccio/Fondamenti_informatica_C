/* codeptr.c */
/* Il programma presenta un'ampia descrizione nella descrizione
 * delle issue */

#include <stdio.h>
#include <stdlib.h>

/* Creazione della struct "cliente"*/
struct cliente {
  char CF[17];
  int priority;
  struct cliente *next;
};

typedef struct cliente Cliente; /* Rinomino struct cliente */
typedef struct  cliente * ClientePtr; /* Rinomino struct cliente* */

void print_cliente(ClientePtr p); /* Per la stampa, in questo caso, per verificare lo scorrimento */
ClientePtr insert_value(ClientePtr *p, char CF[], int priority); /* Aggiunge un elemento all'inizio */
void append_value(ClientePtr p, char CF[], int priority); /* Aggiunge un elemento alla coda */
void InsPriority1(ClientePtr p, char CF[], int priority); /* Aggiunge un elemento alla coda dei clienti con priorita' 1 */

int main()
{
  /* Codice nel main da implementare */
  ClientePtr l = NULL;

  print_cliente(l);
  insert_value(&l, "qbd", 1);
  insert_value(&l, "abd", 1);

  append_value(l, "abc", 1);
  append_value(l, "qbd", 1);
  append_value(l, "rdc", 0);
  append_value(l, "xzc", 0);
  append_value(l, "yyc", 0);
  

  print_cliente(l);

  return 0;
}

void print_cliente(ClientePtr p)
{
  if (p == NULL) {
    printf("NULL\n");
  } else {
    printf("CF (%s), p (%d), next (%p) ---> \n", p->CF, p->priority, p->next);
    print_cliente(p->next);
  }
}

ClientePtr insert_value(ClientePtr *p, char CF[], int priority) {
  int i = 0;
  ClientePtr n = (ClientePtr)malloc(sizeof(Cliente)); /* Creo una struct cliente e la popolo con i nuovi dati */
  while (CF[i] != '\0') {
    n->CF[i] = CF[i];
    i++;
  }
  n->CF[i] = '\0';
  n->priority = priority;
  n->next = *p; 

  *p = n; /* Punto al nuovo primo elemento */
  return n;
}

void append_value(ClientePtr p, char CF[], int priority) {
  int i = 0;
  if (p != NULL) { /* Controllo che mi trovo nell'ultimo elemento senza badare della priorita' */
    if (p->next != NULL) {
      append_value(p->next, CF, priority);
    } else {
      ClientePtr n = (ClientePtr) malloc(sizeof(Cliente)); /* Creo una struct clienti, la popolo ed infine la posiziono come ultima */
      while (CF[i] != '\0') {
        n->CF[i] = CF[i];
        i++;
      }
      n->CF[i] = '\0';
      n->priority = priority;
      n->next = NULL;
      p->next = n;
    }
  } else {
    insert_value(&p, CF, priority);
  }
}

void InsPriority1(ClientePtr p, char CF[], int priority) {
  int i = 0;
  if (priority != 1 || p->next != NULL) { /* Controllo che il volore della prorita' sia 1 e di trovarmi sull'ultimo elemento */
    append_value(p->next, CF, priority);
  }
  ClientePtr n = (ClientePtr)malloc(sizeof(ClientePtr)); /* Creo una struct clienti */
  while (CF[i] != '\0') {
    n->CF[i] = CF[i];
    i++;
  }
  n->CF[i] = '\0';
  n->next = NULL;
  n->priority = priority;
  p->next = n;
}

