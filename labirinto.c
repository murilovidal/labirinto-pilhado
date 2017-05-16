#include <stdio.h>
#include <stdlib.h> // malloc
#include <locale.h>
#include <unistd.h>

//Define as cores
#define VERMELHO "\x1b[31m"
#define VERDE   "\x1b[32m"
#define AMARELO "\x1b[33m"
#define AZUL    "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN    "\x1b[36m"
#define RESET   "\x1b[0m"


//Estruturas
typedef struct Nodo_Pilha
{
         int coordenadas;
         struct Nodo_Pilha *prox;
}*NODOPTR;

void zera_Matriz(int Labirinto[30][30])
{
  int i,j;
  for(i=0; i<30; i++)
    for(j=0; j<30; j++)
      Labirinto[i][j] = 0;
}

//Recebe uma matriz 30x30 e configura as paredes, a entrada e a saída do labirinto
void Novo_Labirinto(int Labirinto[30][30])
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
  r = (rand()%28)+1;
  printf(" %d\n", r );
  Labirinto[r][29] = 0;
}

void Exibe_Labirinto(int Labirinto[30][30])//Desenha o labirinto na tela
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
        printf("☺");
      }
      else if (Labirinto[i][j] == 3)
      {
        printf("\033[%d;%dH", i, j);
        printf("░");
      }
    }
  }
  /*livre: será representada por um espaço em branco;
▪
parede: será representada por um bloco sólido (ASCII 219);
▪
visitada: será representada por um ponto;
▪
beco: será representada por um bloco pontilhado (ASCII 176);
▪
posição em que o rato se encontra no labirinto, no momento em que ele é exibido:
será representada pelo caracter -
ASCII 1  (carinha feliz)*/

}


//Funções da pilha
void size()//Retorna o tamanho da pilha
{

}
void push()//Inclui elemento na pilha
{

}

void pop()//Exclui elemento da pilha e retorna suas coordenadas
{

}

void stack_pop()//Retorna as coordenadas do elemento que está no topo da pilha sem desempilhar
{

}

void main()
{
  setlocale(LC_ALL, "Portuguese");//habilita a acentuação para o português
  //Variáveis
  int Labirinto[30][30];  /*0 - Livre
                            1 - Parede
                            2 - Visitada
                            3 - Beco*/
  zera_Matriz(Labirinto);
  Novo_Labirinto(Labirinto);
  Exibe_Labirinto(Labirinto);

}
