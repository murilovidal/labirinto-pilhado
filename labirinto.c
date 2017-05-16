#include <stdio.h>
#include <stdlib.h> // malloc

//Estruturas
typedef struct Nodo_Pilha
{
         int coordenadas;
         struct Nodo_Pilha *prox;
}*NODOPTR;
//Variáveis
int Labirinto[30][30];  /*0 - Livre
                    1 - Parede
                    2 - Visitada
                    3 - Beco*/


//Recebe uma matriz 30x30 e configura as paredes, a entrada e a saída do labirinto
void Novo_Labirinto(int *Labirinto)
{

}

void Exibe_Labirinto()
{
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

void pop()//Exclui elemento da pilha
{

}

void stack_pop()//Retorna o elemento que está no topo da pilha sem desempilhar
{

}

void main()
{

}
