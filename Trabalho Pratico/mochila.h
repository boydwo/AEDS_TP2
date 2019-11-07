#define CAPACIDADE 40

typedef struct
{
  int peso, valor;
} mochila;

mochila *insereVertor(int *meuTamanhoVetor);
void combinationUtil(mochila arr[], mochila data[], int start, int end,int index, int r);
void printCombination(mochila arr[], int n, int r,int stop);
