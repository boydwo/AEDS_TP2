#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mochila.h"
int somaPesoFinal, somaValorFinal, somaValorFF, somaPesoFF;
void combinationUtil(mochila arr[], mochila data[], int start, int end,
                     int index, int r);

void printCombination(mochila arr[], int n, int r)
{

  mochila data[r];

  combinationUtil(arr, data, 0, n - 1, 0, r);
  // printf("\nPESO: %d  | VALOR: %d\n", somaPesoFinal, somaValorFinal);
  if (c == 0)
  {
    printf("\nmelhor de totos : PESO: %d  | VALOR: %d\n", somaPesoFF, somaValorFF);
  }
}

void combinationUtil(mochila arr[], mochila data[], int start, int end,
                     int index, int r)
{
  int somaPeso = 0, somaValor = 0, j;
  mochila combinacaoTemoraria[r];
  //printf("\nPESO: %d  | VALOR: %d", somaPeso, somaValor);
  if (index == r)
  {
    somaPeso = 0, somaValor = 0;
    for (j = 0; j < r; j++)
    {
      printf("{%d %d} | ", data[j].peso, data[j].valor);
      somaPeso += data[j].peso;
      somaValor += data[j].valor;
      if (somaPeso <= CAPACIDADE && somaValor >= somaValorFinal)
      {
        somaValorFinal = somaValor;
        somaPesoFinal = somaPeso;
        if (somaValorFinal > somaValorFF)
        {
          somaValorFF = somaValorFinal;
          somaPesoFF = somaPesoFinal;
        }

        //printf("PESO: %d  | VALOR: %d\n", somaPesoFinal, somaValorFinal);
      }
    }
    //printf("\nPESO: %d  | VALOR: %d", somaPeso, somaValor);
    // combinacaoTemoraria[j] = data[j];

    printf("\n");
    return;
  }

  for (int i = start; i <= end && end - i + 1 >= r - index; i++)
  {
    data[index] = arr[i];
    combinationUtil(arr, data, i + 1, end, index + 1, r);
  }
}

mochila *insereVertor(int *meuTamanhoVetor)
{
  FILE *arquivo;
  mochila *itensMochila;
  int tamanhoVetor, i = 0, cont = 0;
  char nome[30];
  mochila temporario;

  printf("Digite o nome do arquivo .txt: ");
  fgets(nome, 100, stdin);
  nome[strlen(nome) - 1] = '\0';
  arquivo = fopen(nome, "r");
  if (arquivo == NULL)
  {
    printf("arquivo invalido");
  }
  else
  {
    while (!feof(arquivo))
    {
      if (cont == 0)
      {
        fscanf(arquivo, "%d", &tamanhoVetor);
        itensMochila = (mochila *)malloc(tamanhoVetor * sizeof(mochila));
      }
      else
      {
        fscanf(arquivo, "%d %d", &temporario.peso, &temporario.valor);

        itensMochila[i].peso = temporario.peso;
        itensMochila[i].valor = temporario.valor;
        i++;
      }
      cont++;
    }
    fclose(arquivo);
  }

  *meuTamanhoVetor = tamanhoVetor;
  return itensMochila;
}