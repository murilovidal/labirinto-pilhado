#include <stdio.h>
#include <stdlib.h> // malloc
#include <time.h> // time

//Estruturas
typedef struct Nodo_Pilha
{
         int coordenadas;
         struct Nodo_Pilha *prox;
}Pilha;

void InicializaPilha(Pilha **N){*N = NULL;} // inserindo NULL no ponteiro externo

Pilha *Aloca()
{
  Pilha *p;

  p = (Pilha*)malloc(sizeof(Pilha));

  if(!p){
    printf("Problema de alocacao\n");
    exit(0);}

  return p;
}

void zera_Matriz(int Labirinto[30][30])
{
  int i,j;
  for(i=0; i<30; i++)
    for(j=0; j<30; j++)
      Labirinto[i][j] = 0;
}

void Novo_Labirinto(int Labirinto[30][30], int *coordenadas_rato, int *coordenadas_saida) //Recebe uma matriz 30x30 e configura as paredes, a entrada e a saída do labirinto
{
  int i, j, r;
  //Laterais
  srand(time(NULL));
  for (i = 0; i < 30; i++)
  {
    Labirinto[i][29] = 1;
    Labirinto[29][i] = 1;
    Labirinto[0][i] = 1;
    Labirinto[i][0] = 1;
  }
  for (i = 2; i < 29; i++) //gera as paredes internas aleatoriamente
  {
    for (j = 2; j < 29; j++)
    {
      r = rand()%5;
      if (r == 2)
      {
        Labirinto[i][j] = 1;
      }
    }
  }

  //definir entrada do labirinto ***TALVEZ COM PROBLEMA, ÀS VEZES NÃO EXIBE UMA ENTRADA OU SAÍDA, PODE SER PROBLEMA NO Exibe_Labirinto
  r = (rand()%28) + 2;
  Labirinto[r][0] = 0;
  while((Labirinto[r][1] != 0) || (Labirinto[r][2] != 0) || (Labirinto[r][3] != 0) || (r == 29))
  {
    Labirinto[r][0] = 1;
    r = (rand()%28) + 2;
    Labirinto[r][0] = 0;
  }
  printf(" %d\n", r );
  *coordenadas_rato = r*100+1; //atribui as coordenadas iniciais à variável coordenadas

  //definir saida do labirinto ***TALVEZ COM PROBLEMA, ÀS VEZES NÃO EXIBE UMA ENTRADA OU SAÍDA, PODE SER PROBLEMA NO Exibe_Labirinto
  r = (rand()%28)+2;
  Labirinto[r][29] = 0;
  while((Labirinto[r][28] != 0) || (Labirinto[r][27] != 0) || (Labirinto[r][26] != 0) || (r == 29))
  {
    Labirinto[r][29] = 1;
    r = (rand()%28) + 2;
    Labirinto[r][29] = 0;
  }

  *coordenadas_saida = r*100+29;
  printf(" %d\n", r);

}

void Exibe_Labirinto(int Labirinto[30][30], int coordenadas) //Desenha o labirinto na tela
{
  int i, j;
  system("clear");
  for (i = 0; i < 30; i++)
  {
    for (j = 0; j < 30; j++)
    {
      if (Labirinto[i][j] == 1)
      {
        printf("\033[%d;%dH", i, j);
        printf("█");
      }
      else if (Labirinto[i][j] == 2)
      {
        printf("\033[%d;%dH", i, j);
        printf("·");
      }
      else if (Labirinto[i][j] == 3)
      {
        printf("\033[%d;%dH", i, j);
        printf("░");
      }
    }
  }
  //imprimir a posição do personagem
  printf("\033[%d;%dH", div(coordenadas, 100), coordenadas%100);
  printf("☺");
}

void size() //Retorna o tamanho da pilha
{

}
void push(int coordenadas, Pilha **p) //Inclui elemento na pilha
{
  Pilha *novo;
  novo = Aloca(); // Alocacao do dado na lista que representa uma pilha
  novo->coordenadas = coordenadas;
  novo->prox = *p;
  *p = novo;
}

void pop(Pilha **P) //Exclui elemento da pilha
{
  if((*P) == NULL)
    printf("Ops! Pilha esta vazia.\n");

  Pilha *aux = (*P);
  *P = (*P)->prox;
  free(aux);
}

void stack_pop(Pilha **P) //Retorna as coordenadas do elemento que está no topo da pilha sem desempilhar
{

}

void Atualiza_Labirinto(int Labirinto[30][30], int i, int j, int situacao) //recebe o labirinto, coordenadas e situação para atualizar a célula
{

}

int onde_ir(int Labirinto[30][30], int onde_estou, Pilha **P)
{
  // Recebe o labirinto e a posição do objeto e retorna a coordenada que deve ser seguida
  // Essa função deve chamar Atualiza_Labirinto pra já atualizar onde encontrar paredes

  int i, j; // posicao i e j do rato

  i = onde_estou/100;
  j = onde_estou%100;

  if(Labirinto[i][j+1] == 0){
    printf("\033[%d;%dH", 30, 30);
    printf("entrou no primeiro\n");
    push((i*100)+(j+1), P);
    Labirinto[i][j+1] = 2;
  }
  else if(Labirinto[i-1][j] == 0){
    printf("\033[%d;%dH", 30, 30);
    printf("entrou no segundo\n");
    push(((i-1)*100)+j, P);
    Labirinto[i-1][j] = 2;
  }
  else if(Labirinto[i+1][j] == 0){
    printf("\033[%d;%dH", 30, 30);
    printf("entrou no terceiro\n");
    push(((i+1)*100)+j, P);
    Labirinto[i+1][j] = 2;
  }
  else if(Labirinto[i][j-1] == 0){
    printf("\033[%d;%dH", 30, 30);
    printf("entrou no quarto\n");
    push((i*100)+(j-1), P);
    Labirinto[i][j-1] = 2;
  }
  else{
    printf("\033[%d;%dH", 30, 30);
    printf("entrou no else\n");
    pop(P);
    Labirinto[i][j] = 3;
  }


  //printf("\033[%d;%dH", 30, 30);
  //printf("\ni: %d, j: %d\n", i,j);

  onde_estou = (*P)->coordenadas;


  i = onde_estou/100;
  j = onde_estou%100;

  //printf("\nonde_estou novo: %d\n", onde_estou);
  //printf("\nnovo i: %d, novo j: %d\n", i,j);

  return onde_estou;
}

void main()
{
  //Variáveis
  Pilha *pep; // pep = ponteiro externo para pilha
  int onde_estou, ondeir, saida, qq;
  int Labirinto[30][30];  /*0 - Livre
                            1 - Parede
                            2 - Visitada
                            3 - Beco*/
  InicializaPilha(&pep);
  zera_Matriz(Labirinto);
  Novo_Labirinto(Labirinto, &onde_estou, &saida);

  printf("onde_estou: %d, saida: %d\n", onde_estou, saida);

  Exibe_Labirinto(Labirinto, onde_estou);
  printf("\033[%d;%dH", 30, 30);

  while(onde_estou != saida){
    onde_estou = onde_ir(Labirinto, onde_estou, &pep);
    getchar();
    Exibe_Labirinto(Labirinto, onde_estou);
  }

  printf("\033[%d;%dH", 30, 30);
}
