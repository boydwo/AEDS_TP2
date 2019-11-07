#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CAPACIDADE 40;
#include "TadMochila.h"
//teste_basico.txt
void main()
{
  int i;
  int elementos[] = {1, 2, 3, 4, 5};
  int tamanhoCombinacao = 1;
  int tamanhoVetor;
  int n;
  mochila *ItensMochila;
  ItensMochila = insereVertor(&tamanhoVetor, &n);
  printf("\ntamanho %d\n", n);
  mochila melhorCombinacao[tamanhoVetor];
  int melhorValor = -1;

  imprimeCombinacoes(ItensMochila, tamanhoVetor, tamanhoCombinacao, melhorCombinacao, &melhorValor);
}
