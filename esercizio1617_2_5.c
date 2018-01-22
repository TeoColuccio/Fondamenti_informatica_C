#include <stdio.h>

int X[100] = {10, 2, 3, 13, 101}; // vettore principale
int last = 4; // indice dell'ultimo elemento utile
float MX[100]; // nuovo vettore per le medie

void media(int X[], int last, int n, float MX[]) {
  int i, k;
  float parziale;
  for (i = 0; i <= last; i++) { // per quati sono gli elementi di X 
    parziale = 0.0; // azzero ogni volta il parziale

    if (i >= (n-1)) { // se i e' maggiore/uguale n-1
      for (k = i-(n-1); k<=i; k++) parziale+= X[k]; // cosi' impostando il for, prenderemo sempre e solo 3 valori, quelli necessari 
      MX[i] = parziale / n; // esegue la normale media
    }
    else { // se i < n -1
      for (k = 0; k <= i; k++) parziale+= X[k];
      MX[i] = parziale / (i+1); // esegue una media con divisore pari al numero degli elementi sommati, senza badare ad n
    }
  }
}

int main() {
  int i;
  
  media(X, last, 3, MX);
  
  for(i = 0; i <= last; i++) printf("%.2f\n", MX[i]);
  
  return 0;
}

