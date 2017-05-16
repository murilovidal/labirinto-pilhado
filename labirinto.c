#include <stdio.h>
#include <stdlib.h> // malloc


//Estruturas
typedef struct Nodo_Pilha
{
         int coordenadas;
         struct Nodo_Pilha *prox;
         int tamanho;
}Pilha;

void InicializaPilha(Pilha **N)
{
  *N = NULL;
} // inserindo NULL no ponteiro externo

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

//Recebe uma matriz 30x30 e configura as paredes, a entrada e a saída do labirinto
void Novo_Labirinto(int Labirinto[30][30], int *coordenadas)
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
  for (i = 2; i < 29; i++)//gera as paredes internas aleatoriamente
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

  //definir entrada e saída do labirinto***COM PROBLEMA, ÀS VEZES NÃO EXIBE UMA ENTRADA OU SAÍDA, PODE SER PROBLEMA NO Exibe_Labirinto
  r = (rand()%28)+1;
  Labirinto[r][0] = 0;
  printf(" %d\n", r );

  *coordenadas = r*100+1;//atribui as coordenadas iniciais à variável coordenadas
  r = (rand()%28)+1;
  printf(" %d\n", r );
  Labirinto[r][29] = 0;
}

void Exibe_Labirinto(int Labirinto[30][30], int coordenadas)//Desenha o labirinto na tela
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
    //imprimir a posição do personagem
    printf("\033[%d;%dH", div(coordenadas, 100), coordenadas%100);
    printf("☺");
  }
}


//Funções da pilha
void size()//Retorna o tamanho da pilha
{

}
void push(int coordenadas, Pilha ***ppp)//Inclui elemento na pilha
{
  Pilha *novo;
  novo = Aloca();
  // Alocacao do dado na lista que representa uma pilha
  novo->coordenadas = coordenadas;
  novo->prox = **ppp;
  // Atualizando endereco do ponteiro externo que esta lá na main
  **ppp = novo; // mais uma vez a indireção
}

void pop(Pilha **P, int *coordenadas)//Exclui elemento da pilha e retorna suas coordenadas
{

}

void stack_pop()//Retorna as coordenadas do elemento que está no topo da pilha sem desempilhar
{

}

int onde_ir(int Labirinto[30][30], int onde_estou)
{
    return 0;
}

void main()
{
  //Variáveis
  int Labirinto[30][30];  /*0 - Livre
                            1 - Parede
                            2 - Visitada
                            3 - Beco*/
  int onde_estou, onde_ir;
  Pilha *pep; // pep = ponteiro externo para pilha

  InicializaPilha(&pep);

  zera_Matriz(Labirinto);
  Novo_Labirinto(Labirinto, &onde_estou);
  onde_ir = onde_ir(Labirinto, onde_estou);

  Exibe_Labirinto(Labirinto, onde_estou);





  printf("\033[%d;%dH", 30, 30);
}
