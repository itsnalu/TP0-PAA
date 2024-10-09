#include "TADs.h"

Quadro Criar_Quadro()
{
    Quadro quadro;
    quadro.linha = 20;
    quadro.coluna = 80;


    quadro.matriz = malloc(quadro.linha * sizeof(char *));
    for (int i = 0; i < quadro.linha; i++)
    {
        quadro.matriz[i] = malloc(quadro.coluna * sizeof(char));
    }


    for (int i = 0; i < quadro.linha; i++)
    {
        for (int j = 0; j < quadro.coluna; j++)
        {
            if (i == 0 || i == quadro.linha - 1)  
            {
                quadro.matriz[i][j] = '-';              
            }
            else if (j == 0 || j == quadro.coluna - 1)  
            {
                quadro.matriz[i][j] = '|';
            }
            else
            {
                quadro.matriz[i][j] = ' ';  
            }
        }
    }
    return quadro;
}

Cores Criar_Cores()
{
    Cores cor;
    cor.linha = 20;
    cor.coluna = 80;


    cor.matriz = malloc(cor.linha * sizeof(int *));
    for (int i = 0; i < cor.linha; i++)
    {
        cor.matriz[i] = malloc(cor.coluna * sizeof(int));
    }


    for (int i = 0; i < cor.linha; i++)
    {
        for (int j = 0; j < cor.coluna; j++)
        {
            if (i == 0 || i == cor.linha - 1)  
            {
                cor.matriz[i][j] = 9;              
            }
            else if (j == 0 || j == cor.coluna - 1)  
            {
                cor.matriz[i][j] = 9;
            }
            else
            {
                cor.matriz[i][j] = 9;  
            }
        }
    }
    return cor;
}
  

void AplicarCor(int cor, char caractere)
{
    switch (cor)
    {
        case 0:
            // Amarelo
            printf("\033[33m%c\033[0m", caractere);
            break;
        case 1:
            // Azul
            printf("\033[34m%c\033[0m", caractere);
            break;
        case 2:
            // Verde
            printf("\033[32m%c\033[0m", caractere);
            break;
        default:

            printf("%c", caractere);
            break;
    }
}




void Imprimir_Quadro(Quadro quadro, Cores cor, Resposta_Usuario *resposta)
{
    int corAleatoria = rand() % 3;
    for (int i = 0; i < quadro.linha; i++)
    {
        for (int j = 0; j < quadro.coluna; j++)
        {
            char caractere = quadro.matriz[i][j];

            if ((caractere == '(' || caractere == ')' || caractere == '/') && resposta->Tipo_Arte >= 6)
            {
                AplicarCor(cor.matriz[i][j], caractere); // Aplica uma cor aleatória em cada calopsita
            }
            else if ((caractere == '(' || caractere == ')' || caractere == '/') && resposta->Tipo_Arte == 5)
            {
                AplicarCor(corAleatoria, caractere); // Aplica uma cor aleatória em todas as calopsitas
            }
            else if (caractere == 'o')
            {
                // Branco
                printf("\033[37m%c\033[0m", caractere);
            }
            else if (caractere == '>')
            {
                // Laranja
                printf("\033[38;5;202m%c\033[0m", caractere);
            }
            else
            {
                printf("%c", caractere); 
            }
        }
        printf("\n");
    }
}
 


void Exibe_Menu(Resposta_Usuario *Resposta, Quadro *quadro, Cores *cor)
{
    printf("PROGRAMA GERADOR DE OBRA DE ARTE:\n");
    printf("=================================\n");
    printf("Escolha o tipo de figura basica a ser usada para criar a obra:\n");
    printf("1 - Asterisco simples.\n");
    printf("2 - Simbolo de soma com asteriscos.\n");
    printf("3 - Letra X com asteriscos.\n");
    printf("4 - Figuras aleatorias.\n");
    printf("5 - Calopsitas de uma cor (azul, amarelo e verde) aleatoria.\n");
    printf("6 ou qualquer outro numero - Calopsitas de uma cor (azul, amarelo e verde) aleatoria cada.\n");
    printf("=================================\n");


    printf("Digite o tipo de figura basica desejada: ");
    scanf("%d", &Resposta->Tipo_Arte);
    printf("Digite a quantidade de figuras (menor ou igual a zero para aleatorio): ");
    scanf("%d", &Resposta->Qtd_Figura);

    Escolhe_Arte(*Resposta, quadro, cor);

}


void Gerar_Asterisco(Quadro *quadro, Resposta_Usuario resposta)
{
    // Possíveis posições na coluna = 1 a 78
    // Possíveis posições na linha = 1 a 18 
    // Pois as primeiras já estão preenchidas com a borda do quadro
    int linha;
    int coluna;
    int posicoes_validas = 0;

    while (posicoes_validas != resposta.Qtd_Figura)
    {
        coluna = rand() % (quadro->coluna - 1);
        linha  = rand() % (quadro->linha - 1);

        if (quadro->matriz[linha][coluna] == ' ')
        {
            quadro->matriz[linha][coluna] = '*';
            posicoes_validas++;
        }

        if (resposta.Tipo_Arte == 4 && posicoes_validas == 1)
        {
            break;
        }
    }
    
}


void Gerar_Soma(Quadro *quadro, Resposta_Usuario resposta)
{


    int linha;
    int coluna;
    int posicoes_validas = 0;

    while (posicoes_validas != resposta.Qtd_Figura)
    {
        coluna = rand() % (quadro->coluna - 1);
        linha  = rand() % (quadro->linha - 1);


        // Checada se todas as posições necessárias para fazer o símbolo de soma estão
        // vazias e verificando se a linha e coluna gerada são maiores que 0, por causa 
        // das operações de subtração de 1

        if (quadro->matriz[linha][coluna] == ' ' && quadro->matriz[linha+1][coluna] == ' ' 
        && quadro->matriz[linha-1][coluna] == ' ' && quadro->matriz[linha][coluna-1] == ' ' 
        && quadro->matriz[linha][coluna+1] == ' ' && coluna >= 0 && linha >= 0)
        {
            quadro->matriz[linha][coluna] = '*';
            quadro->matriz[linha+1][coluna] = '*';
            quadro->matriz[linha][coluna+1] = '*';
            quadro->matriz[linha-1][coluna] = '*';
            quadro->matriz[linha][coluna-1] = '*';
            posicoes_validas++;
        }

        if (resposta.Tipo_Arte == 4 && posicoes_validas == 1)
        {
            break;
        }
        
    }

}

void Gerar_X(Quadro *quadro, Resposta_Usuario resposta)
{
    int linha;
    int coluna;
    int posicoes_validas = 0;

    while (posicoes_validas != resposta.Qtd_Figura)
    {
        coluna = rand() % (quadro->coluna - 1);
        linha  = rand() % (quadro->linha - 1);


        if (quadro->matriz[linha][coluna] == ' ' && quadro->matriz[linha+1][coluna+1] == ' ' 
        && quadro->matriz[linha-1][coluna+1] == ' ' && quadro->matriz[linha-1][coluna-1] == ' ' 
        && quadro->matriz[linha+1][coluna-1] == ' ' && coluna >= 0 && linha >= 0)
        {
            quadro->matriz[linha][coluna] = '*';
            quadro->matriz[linha+1][coluna+1] = '*';
            quadro->matriz[linha-1][coluna+1] = '*';
            quadro->matriz[linha-1][coluna-1] = '*';
            quadro->matriz[linha+1][coluna-1] = '*';
            posicoes_validas++;
        }
        if (resposta.Tipo_Arte == 4 && posicoes_validas == 1)
        {
            break;
        }
    }
}

void Gerar_Aleatoriamente(Quadro *quadro, Resposta_Usuario resposta)
{
    for (int i = 0; i < resposta.Qtd_Figura; i++)
    {
        int arte = rand() % 3;

        if (arte == 0)
        {
            Gerar_Asterisco(quadro, resposta);
        } else if (arte == 1)
        {
            Gerar_Soma(quadro, resposta);
        } else if (arte == 2)
        {
            Gerar_X(quadro, resposta);
        }
    }

}

void Gerar_Calopsita(Quadro *quadro, Resposta_Usuario resposta)
{

    int linha;
    int coluna;
    int posicoes_validas = 0;

    while (posicoes_validas != resposta.Qtd_Figura)
    {
        coluna = rand() % (quadro->coluna - 1);
        linha  = rand() % (quadro->linha - 1);
        
/* 

 (     
(o>   
(/)

*/

    if (quadro->matriz[linha][coluna] == ' ' && quadro->matriz[linha][coluna+1] == ' ' && quadro->matriz[linha][coluna-1] == ' ' 
        && quadro->matriz[linha+1][coluna-1] == ' ' && quadro->matriz[linha+1][coluna] == ' ' && quadro->matriz[linha-1][coluna] == ' ' 
        && quadro->matriz[linha-1][coluna-1] == ' ' && quadro->matriz[linha-1][coluna+1] == ' ' && quadro->matriz[linha+1][coluna+1] == ' ' 
        && coluna >= 0 && linha >= 0)
    {

        quadro->matriz[linha][coluna] = 'o';     
        quadro->matriz[linha][coluna+1] = '>';    
        quadro->matriz[linha][coluna-1] = '(';    
        quadro->matriz[linha-1][coluna-1] = ' ';  
        quadro->matriz[linha-1][coluna] = '(';    
        quadro->matriz[linha+1][coluna] = '/';    
        quadro->matriz[linha+1][coluna-1] = '(';  
        quadro->matriz[linha+1][coluna+1] = ')';  
        quadro->matriz[linha-1][coluna+1] = ' ';
            
            posicoes_validas++;
    }
        if (resposta.Tipo_Arte == 4 && posicoes_validas == 1)
        {
            break;
        }
    }
}



void Gerar_Calopsita_Cor_Individual(Quadro *quadro, Resposta_Usuario resposta, Cores *cores)
{

    int linha;
    int coluna;
    int posicoes_validas = 0;

    while (posicoes_validas != resposta.Qtd_Figura)
    {
        coluna = rand() % (quadro->coluna - 1);
        linha  = rand() % (quadro->linha - 1);
/* 

 (     
(o>   
(/)


 */

    int arte = rand() % 3;

    if (quadro->matriz[linha][coluna] == ' ' && quadro->matriz[linha][coluna+1] == ' ' && quadro->matriz[linha][coluna-1] == ' ' 
        && quadro->matriz[linha+1][coluna-1] == ' ' && quadro->matriz[linha+1][coluna] == ' ' && quadro->matriz[linha-1][coluna] == ' ' 
        && quadro->matriz[linha-1][coluna-1] == ' ' && quadro->matriz[linha-1][coluna+1] == ' ' && quadro->matriz[linha+1][coluna+1] == ' ' 
        && coluna >= 0 && linha >= 0)
        {

        quadro->matriz[linha][coluna] = 'o';     
        quadro->matriz[linha][coluna+1] = '>';    
        quadro->matriz[linha][coluna-1] = '(';    
        quadro->matriz[linha-1][coluna-1] = ' ';  
        quadro->matriz[linha-1][coluna] = '(';    
        quadro->matriz[linha+1][coluna] = '/';    
        quadro->matriz[linha+1][coluna-1] = '(';  
        quadro->matriz[linha+1][coluna+1] = ')';  
        quadro->matriz[linha-1][coluna+1] = ' ';


        //Preenche a matriz de cores para identificar onde está cada figura
        cores->matriz[linha][coluna-1] = arte;     
        cores->matriz[linha-1][coluna] = arte;    
        cores->matriz[linha+1][coluna] = arte;    
        cores->matriz[linha+1][coluna-1] = arte;  
        cores->matriz[linha+1][coluna+1] = arte;  

            
            posicoes_validas++;
        }
        if (resposta.Tipo_Arte == 4 && posicoes_validas == 1)
        {
            break;
        }
    }
}

void Liberar_Quadro(Quadro *quadro)
{
    for (int i = 0; i < quadro->linha; i++)
    {
        free(quadro->matriz[i]);
    }
    free(quadro->matriz);
}

void Liberar_Cores(Cores *cor)
{
    for (int i = 0; i < cor->linha; i++)
    {
        free(cor->matriz[i]);
    }
    free(cor->matriz);
}

void Escolhe_Arte(Resposta_Usuario resposta, Quadro *quadro, Cores *cores)
{
    if (resposta.Qtd_Figura <= 0)
    {
        resposta.Qtd_Figura = 1 + (rand() % 100);
    }
    
    if (resposta.Qtd_Figura > 100)
    {
        resposta.Qtd_Figura = 100;
    }


    if (resposta.Tipo_Arte == 1)
    {
        Gerar_Asterisco(quadro, resposta);
    } else if (resposta.Tipo_Arte == 2)
    {
        Gerar_Soma(quadro, resposta);
    }else if (resposta.Tipo_Arte == 3)
    {
        Gerar_X(quadro, resposta);
    } else if (resposta.Tipo_Arte == 4)
    {
        Gerar_Aleatoriamente(quadro, resposta);
    } else if (resposta.Tipo_Arte == 5)
    {
        Gerar_Calopsita(quadro, resposta);
    } else
    {
        Gerar_Calopsita_Cor_Individual(quadro, resposta, cores);
    }
    
    
}