#include <stdio.h>

#define R 3
#define C 4

int maxanello (int M[R][C], int i, int j, int *imax, int *jmax) {
  int riga = i; int col = j;
/* dopo */  *imax = i; *jmax = j;
  for (riga = i-1; riga <= i+1; riga++) {
    if (riga>=0 && riga < R) {
      for (col = j-1; col <= j+1; col++) {
        if (col >= 0 && col <= C) {
         /* prima if (M[riga][col] > M[i][j]) { */
         /* dopo */ if (M[riga][col] > M[*imax][*jmax]) {
            *imax = riga; *jmax = col;
          }
        }
      }
    }
  }
  if (M[i][j] != M[*imax][*jmax]) return 1;
  return 0;
}

void grande(int M[R][C],int i, int j) {
  int imax = i; int jmax = j;
  
  do {
    printf("%d, %d\n", imax, jmax);
    // } while (maxanello(M, i, j, &imax, &jmax) == 1);
  /* dopo */ } while (maxanello(M, imax, jmax, &imax, &jmax) == 1);
}

int main(int argc, char* argv[]) {
  int i = 1, j = 3;
  int imax = 0; 
  int jmax = 0;


  int M[R][C] = {
   10, 3, 4, 5,
   8, 4, 2, 4,
   3, 23, 12, 11,
 };

 for (i = 0; i<R;i++) {
   for(j=0; j<C; j++) {
     printf("%d ", M[i][j]);
    }
  printf("\n");
 }
//  maxanello(M, 1, 0, &imax, &jmax);

//  grande(M, 1, 0); 
  maxanello(M, (int)argv[1],(int)argv[2], &imax, &jmax);
// printf("%d, %d\n", imax, jmax);

 return 0;
}
