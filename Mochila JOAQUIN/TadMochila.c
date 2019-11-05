#include "TadMochila.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

mochila* insereVertor(int *meuTamanhoVetor)
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
        if (temporario.peso > 40)
        {
          continue;
        }
        else
        {
          itensMochila[i].peso = temporario.peso;
          itensMochila[i].valor = temporario.valor;
          i++;
        }
      }
      cont++;
    }
    fclose(arquivo);
  }
  *meuTamanhoVetor=tamanhoVetor;
  return itensMochila;
}


void imprimeCombinacoes(mochila elementos[], int tamanhoVetor, int tamanhoCombinacao,mochila* melhorCombinacao,int *melhorValor)
{

  mochila vetTemp[tamanhoCombinacao];
  combinacoes(elementos, vetTemp, 0, tamanhoVetor - 1, 0, tamanhoCombinacao, melhorCombinacao, melhorValor);
}
void combinacoes(mochila elementos[], mochila vetTemp[], int inicio, int Final, int index, int tamanhoCombinacao, mochila* melhorCombinacao,int *melhorValor)
{
    int j,i, somaPeso = 0, somaValor = 0;
    mochila combinacaoTemporaria[tamanhoCombinacao];
  if (index == tamanhoCombinacao)
  {
    for (j = 0; j < tamanhoCombinacao; j++)
    {
      printf("{%d %d} | ", vetTemp[j].peso,vetTemp[j].valor);
      somaPeso += vetTemp[j].peso;
      somaValor += vetTemp[j].valor;
      combinacaoTemporaria[j] = vetTemp[j];
    }
    if (somaPeso <= 40){
        if (somaValor > *melhorValor){
            *melhorValor = somaValor;
            for (j = 0; j < tamanhoCombinacao; j++){
                melhorCombinacao[j] = combinacaoTemporaria[j];
            }
        }
    }
    printf("\n");
    return;
  }

  for ( i = inicio; i <= Final && Final - i + 1 >= tamanhoCombinacao - index; i++)
  {
    vetTemp[index] = elementos[i];
    combinacoes(elementos, vetTemp, i + 1, Final, index + 1, tamanhoCombinacao, melhorCombinacao, melhorValor);
  }
}

