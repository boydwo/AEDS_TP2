#ifndef TADMOCHILA_H_INCLUDED
#define TADMOCHILA_H_INCLUDED



#endif // TADMOCHILA_H_INCLUDED

typedef struct
{
  int peso;
  int valor;
  /*int quantidade;*/

} mochila;

mochila* insereVertor(int *meuTamanhoVetor);
void imprimeCombinacoes(mochila elementos[], int tamanhoVetor, int tamanhoCombinacao,mochila* melhorCombinacao, int *melhorValor);
void combinacoes(mochila elementos[], mochila vetTemp[], int inicio, int Final, int index, int tamanhoCombinacao, mochila* melhorCombinacao,int *melhorValor);
