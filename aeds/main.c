#include <stdio.h>
#include <stdlib.h>
#include "mochila.h"

int main(void)
{
  int n;
  mochila *itensMochila;
  itensMochila = insereVertor(&n);
  for (size_t i = 0; i < n; i++)
  {
    printCombination(itensMochila, n, (i + 1));
  }
  return 0;
  // printf("\ntamanho %d\n", n);
  // for (size_t i = 0; i < n; i++)
  // {
  //   printf("%d %d\n", itensMochila[i].peso, itensMochila[i].valor);
  // }
}
