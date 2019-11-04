#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CAPACIDADE 40;

typedef struct
{
  int peso;
  int valor;
  int quantidade;

} mochila;

void combinacoes(int elementos[], int vetTemp[], int inicio, int final, int index, int tamanhoCombinacao);

void imprimeCombinacoes(int elementos[], int tamanhoVetor, int tamanhoCombinacao)
{

  int vetTemp[tamanhoCombinacao];
  combinacoes(elementos, vetTemp, 0, tamanhoVetor - 1, 0, tamanhoCombinacao);
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

int insereVertor(mochila *itensMochila)
{
  FILE *arquivo;
  int tamanhoVetor, i = 0, cont = 0;
  char nome[30];
  mochila temporario;
  printf("Digite o nome do arquivo .txt");
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
      //add os items na lista
      if (cont == 0)
      {
        fscanf(arquivo, "%d", &tamanhoVetor);
        itensMochila = (mochila *)malloc(tamanhoVetor * sizeof(mochila));
        //itensMochila[i].quantidade=0;
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
    //itensMochila[0].quantidade=i;
  }

  return tamanhoVetor;
}
void main()
{
  int elementos[] = {1, 2, 3, 4, 5};
  int tamanhoCombinacao = 3;
  int tamanhoVetor = 5;
  imprimeCombinacoes(elementos, tamanhoVetor, tamanhoCombinacao);
}