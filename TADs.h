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


Quadro Criar_Quadro();
void Imprimir_Quadro(Quadro quadro);
void Liberar_Quadro(Quadro quadro);
void Exibe_Menu(Resposta_Usuario Resposta, Quadro quadro);
void Escolhe_Arte(Resposta_Usuario resposta, Quadro quadro);
void Gerar_Asterisco(Quadro quadro, Resposta_Usuario resposta);
void Gerar_Soma(Quadro quadro, Resposta_Usuario resposta);
void Gerar_X(Quadro quadro, Resposta_Usuario resposta);
void Gerar_Calopsita(Quadro quadro, Resposta_Usuario resposta);
void Gerar_Aleatoriamente(Quadro quadro, Resposta_Usuario resposta);
