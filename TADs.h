//Ana Luísa Moreira Rodrigues 5389
#include <stdlib.h>
#include <stdio.h>
#include <time.h>


typedef struct Resposta_Usuario
{
    int Tipo_Arte;
    int Qtd_Figura;

}Resposta_Usuario;

typedef struct Quadro
{
    int linha;
    int coluna;
    char **matriz;
}Quadro;


typedef struct Cores
{
    int linha;
    int coluna;
    int **matriz;
}Cores;


Quadro Criar_Quadro();
Cores Criar_Cores();
void Exibe_Menu(Resposta_Usuario *Resposta, Quadro *quadro, Cores *cor);

void Gerar_Asterisco(Quadro *quadro, Resposta_Usuario resposta);
void Gerar_Soma(Quadro *quadro, Resposta_Usuario resposta);
void Gerar_X(Quadro *quadro, Resposta_Usuario resposta);
void Gerar_Calopsita(Quadro *quadro, Resposta_Usuario resposta);
void Gerar_Aleatoriamente(Quadro *quadro, Resposta_Usuario resposta);
void Gerar_Calopsita_Cor_(Quadro *quadro, Resposta_Usuario resposta, Cores *cores);

void Imprimir_Quadro(Quadro quadro, Cores cor, Resposta_Usuario *resposta);
void Escolhe_Arte(Resposta_Usuario resposta, Quadro *quadro, Cores *cores);
void Liberar_Cores(Cores *cor);
void Liberar_Quadro(Quadro *quadro);
void AplicarCor(int cor, char caractere);