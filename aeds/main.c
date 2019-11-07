#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "mochila.h"

int main(void)
{
  clock_t Ticks[2];
  Ticks[0] = clock();

  int n;
  mochila *itensMochila;
  itensMochila = insereVertor(&n);
  mochila *vetIndices;
  mochila melhorVetor[n];

  for (size_t i = 0; i < n; i++)
  {
    melhorVetor[i].peso = 0;
    melhorVetor[i].valor = 0;
  }

  for (size_t i = 0; i < n; i++)
  {
    printCombination(itensMochila, n, (i + 1));
  }

  Ticks[1] = clock();
  double Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
  printf("Tempo gasto: %g ms.", Tempo);
  getchar();
  return 0;

  // printf("\ntamanho %d\n", n);
  // for (size_t i = 0; i < n; i++)
  // {
  //   printf("%d %d\n", itensMochila[i].peso, itensMochila[i].valor);
  // }
}
