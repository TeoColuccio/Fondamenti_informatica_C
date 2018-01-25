#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct el {
    double val;
    struct el *next;
    struct el *prec;
};

int leggi(struct el *lista, int *numericaricati) {
    struct el *nuovo;
    char *str, nome_file[100];
    int res = 0;
    FILE *f;

    printf("Inserisci il nome di un file: \n");
    scanf("%s", nome_file);

    while (lista != NULL && lista->next != NULL) lista = lista-> next;

    f = fopen(nome_file, "r");

    if (f == NULL){
        perror("Errore");
    }

    *numericaricati = 0;
    str = (char*) malloc(sizeof(char)*20);
    while(f != NULL && !feof(f)){
        nuovo = (struct el*) malloc(sizeof(struct el));
        str = fgets(str, 20, f);

        if (nuovo == NULL || str == NULL){
            res = -2;
            break;
        }

        nuovo -> val = atof(str);
        nuovo->prec = lista;
        nuovo->next = NULL;

        if (lista != NULL){
            lista->next = nuovo;
        }

        lista = nuovo;

        (*numericaricati)++;
    }

    fclose(f);

    return res;
}


int main () {
    struct el *primo = NULL;
    int letti;

    leggi(primo, &letti);

    printf("\n\n%d", letti);

  return 0;
}
