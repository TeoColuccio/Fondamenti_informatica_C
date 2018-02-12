#include <stdio.h>
#include <stdlib.h>

struct list_t{
  int valore;
  struct list_t *next;
};

struct list_t *lista=NULL;

/* FUNZIONI */
void stampa(struct list_t *l) {
  while (l != NULL) { 
    printf("%d \n", l->valore);
    l = l->next;
  }
}

void crea_lista_vuota(struct list_t **l, int valore) {
  struct list_t *elem = (struct list_t*) malloc(sizeof(struct list_t)); // creo elem
  elem->valore = valore; // popolo elem
  elem->next = NULL;
  *l = elem; // elem e' il primo elemento della lista
}

void crea_lista(struct list_t **l, int valore) {
  struct list_t *tmp = *l; // creo tmp che e' uguale ad l
  if (*l == NULL) crea_lista_vuota(l, valore); // se la lista e' vuota, usa la funzione apposita

  else {
    struct list_t *elem = (struct list_t*) malloc(sizeof(struct list_t)); // creo il nuovo elemento 
    if (elem == NULL) return; // nel caso la malloc fallisse

    elem->valore = valore; // popolo elem 
    elem->next = NULL;
    
    while (tmp->next != NULL) { // scorro la lista fino all'ultimo elemento 
      tmp=tmp->next;
    }
    tmp->next = elem; // ora l'ultimo elemento e' null
  }
}

int conta(struct list_t *l, int valore) {
  int i = 1, contatore =  0;
  
  if (l == NULL) return 0; // se la lista e' vuota, risultato sara' sempre 0

  while (l != NULL) { // finche' non arrivo all'ultimo elemento
    if ((i != 3) && (l->next != NULL) && (l->valore == valore)) contatore++; // se il valore dell'elemento corrente e' uguale al valore richiesto, e non siamo al terzo e nemmeno all'ultimo elemento, aggiorno il contatore
    l = l->next; // scorro la lista
    i++; // aggiorno la posizione corrente
  }
  return contatore; // ritorno il contatore
}

struct list_t * delel(struct list_t *l, struct list_t * C, struct list_t *P) {
  if (P != NULL) { // se NON ci troviamo sul primo elemento..
    P->next = C->next; // ora P punta all'elemento successivo di quello da eliminare
    free(C); // libero C
  } 
  else { // se C e' il primo elemento
    l = C->next; // la testa punta ora al secondo elemento 
    free(C); // libero C
  }
  return l;
}

int cancella(struct list_t **l, int valore, int limit) {
  int contatore = 0; // creo un contatore
  struct list_t *tmp = *l; // creo un tmp per non modificare l
  struct list_t *canc = NULL; // creo canc che sara' l'elemento precedente a quello da eliminare
  struct list_t *prec = NULL; // creo prec che cicla con tmp puntanto al suo precedente

  if (l == NULL) return 0; // se la lista e' nulla, ritorna 0
  
  while (tmp != NULL) { // finche' la non arrivo all'ultimo elemento
    if (tmp->valore == valore) { // confronto il valore dell'elemento corrente con quello richiesto
      contatore++; // nel caso, aggiorno il contatore...
      canc = prec; // ... ora canc e' uguale a prec, perche' prec vale il precedente dell'attuale tmp
    }
    prec = tmp; // scorro prec

    tmp = tmp->next; // scorro tmp
  }

  if (contatore < limit) { 
    /* COMMENTATA LA PARTE PRIMA DELLA CREAZIONE DI DELEL */
    // se devo cancellare...
    /*    if (canc==NULL) { // se ci troviamo sul primo elemento della lista...
          tmp = *l; // tmp diventa il primo elemento
     *l = tmp->next; // la testa punta ora al secondo
     free(tmp); // libero tmp
     } 
     else { // se e' un elemento diverso dal primo..
     tmp = canc->next; // tmp diventa l'elemento da cancellare
     canc -> next = tmp ->next; // canc punta ora al successivo di quello da eliminare
     free(tmp); // libera tmp
     } 
     return 1; // ritorno 1 se cancello...
     }
     return 0; // ...altrimenti ritorna 0
     */
    *l = delel(*l, canc->next, canc); 
    return 1;
  }
  return 0;
}


int main() {

/* Inserimento manuale:
  int i;
  struct list_t *tmp = lista;
  for (i = 0; i < 10; i++) {
    struct list_t *a = malloc(sizeof(struct list_t));
    a->valore = i;
    a->next = NULL;
    if (tmp == NULL) lista = a;
    else tmp->next = a;
  tmp = a;
  }
*/
  
  crea_lista(&lista, 1);
  crea_lista(&lista, 3);
  crea_lista(&lista, 4);
  crea_lista(&lista, 4);
   
  stampa(lista);
  printf("Eseguito: %d\n", cancella(&lista, 4, 3));
  stampa(lista);


  return 0;
}
