#include <stdio.h>
#define CAPACIDADE 40;

typedef struct
{
  int peso;
  int valor;

} mochila;

void combinacoes(int elementos[], int vetTemp[], int inicio, int final, int index, int tamanhoCombinacao);

void imprimeCombinacoes(int elementos[], int tamanhoElementos, int tamanhoCombinacao)
{

  int vetTemp[tamanhoCombinacao];
  combinacoes(elementos, vetTemp, 0, tamanhoElementos - 1, 0, tamanhoCombinacao);
}

void combinacoes(int elementos[], int vetTemp[], int inicio, int final, int index, int tamanhoCombinacao)
{

  if (index == tamanhoCombinacao)
  {
    for (int j = 0; j < tamanhoCombinacao; j++)
    {
      printf("%d", vetTemp[j]);
    }
    printf("\n");
    return;
  }

  for (int i = inicio; i <= final && final - i + 1 >= tamanhoCombinacao - index; i++)
  {
    vetTemp[index] = elementos[i];
    combinacoes(elementos, vetTemp, i + 1, final, index + 1, tamanhoCombinacao);
  }
}

void main()
{
  int elementos[] = {1, 2, 3, 4, 5};
  int tamanhoCombinacao = 3;
  int tamanhoElementos = 5;
  imprimeCombinacoes(elementos, tamanhoElementos, tamanhoCombinacao);
}