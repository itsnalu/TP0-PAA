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


void Imprimir_Quadro(Quadro quadro)
{
    int corAleatoria = rand() % 3;
    for (int i = 0; i < quadro.linha; i++)
    {
        for (int j = 0; j < quadro.coluna; j++)
        {
            // Verifica cada caractere e aplica a cor correspondente
            // No caso das penas, eu decidi que a cor seria aleatória
            if (quadro.matriz[i][j] == '(' || quadro.matriz[i][j] == ')'|| quadro.matriz[i][j] == '/')
            {
                // Aplica a cor com base no número aleatório
                switch (corAleatoria)
                {
                    case 0:
                        // Amarelo
                        printf("\033[33m%c\033[0m", quadro.matriz[i][j]);
                        break;
                    case 1:
                        // Azul
                        printf("\033[34m%c\033[0m", quadro.matriz[i][j]);
                        break;
                    case 2:
                        // Verde
                        printf("\033[32m%c\033[0m", quadro.matriz[i][j]);
                        break;
                }
            }
            else if (quadro.matriz[i][j] == 'o')
            {
                // branco
                printf("\033[37m%c\033[0m", quadro.matriz[i][j]);
            }
            else if (quadro.matriz[i][j] == '>')
            {
                // laranja
                printf("\033[38;5;202m%c\033[0m", quadro.matriz[i][j]);
            }
            else
            {
                printf("%c", quadro.matriz[i][j]);
            }
        }
        printf("\n");
    }
}


void Liberar_Quadro(Quadro quadro)
{
    for (int i = 0; i < quadro.coluna; i++)
    {
        free(quadro.matriz[i]);
    }
    free(quadro.matriz);
}


//colocar para retornar void e chamar escolhe arte dentro dela
void Exibe_Menu(Resposta_Usuario Resposta, Quadro quadro)
{
    printf("PROGRAMA GERADOR DE OBRA DE ARTE:\n=================================\nEscolha o tipo de figura basica a ser usada para criar a obra:\n");
    printf("1 - asterisco simples.\n");
    printf("2 - simbolo de soma com asteriscos.\n");
    printf("3 - letra X com asteriscos.\n");
    printf("4 - figuras aleatorias\n");
    printf("5 ou qualquer outro numero - opcao de obra de arte criada pelo aluno\n=================================\n");

    printf("Digite o tipo de figura basica desejada: ");
    scanf("%d", &Resposta.Tipo_Arte);
    printf("Digite a quantidade de figuras (menor ou igual a zero para aleatorio): ");
    scanf("%d", &Resposta.Qtd_Figura);

    Escolhe_Arte(Resposta, quadro);

}

void Escolhe_Arte(Resposta_Usuario resposta, Quadro quadro)
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
    } else
    {
        Gerar_Calopsita(quadro, resposta);
    } 
    
}


void Gerar_Asterisco(Quadro quadro, Resposta_Usuario resposta)
{
    // Possíveis posições na coluna = 1 a 78
    // Possíveis posições na linha = 1 a 18 
    // Pois as primeiras já estão preenchidas com a borda do quadro
    int linha;
    int coluna;
    int posicoes_validas = 0;

    while (posicoes_validas != resposta.Qtd_Figura)
    {
        coluna = rand() % (quadro.coluna - 1);
        linha  = rand() % (quadro.linha - 1);

        if (quadro.matriz[linha][coluna] == ' ')
        {
            quadro.matriz[linha][coluna] = '*';
            posicoes_validas++;
        }

        if (resposta.Tipo_Arte == 4 && posicoes_validas == 1)
        {
            break;
        }
    }
    
}


void Gerar_Soma(Quadro quadro, Resposta_Usuario resposta)
{


    int linha;
    int coluna;
    int posicoes_validas = 0;

    while (posicoes_validas != resposta.Qtd_Figura)
    {
        coluna = rand() % (quadro.coluna - 1);
        linha  = rand() % (quadro.linha - 1);


        // Checada se todas as posições necessárias para fazer o símbolo de soma estão
        // vazias e verificando se a linha e coluna gerada são maiores que 0, por causa 
        // das operações de subtração de 1

        if (quadro.matriz[linha][coluna] == ' ' && quadro.matriz[linha+1][coluna] == ' ' 
        && quadro.matriz[linha-1][coluna] == ' ' && quadro.matriz[linha][coluna-1] == ' ' 
        && quadro.matriz[linha][coluna+1] == ' ' && coluna >= 0 && linha >= 0)
        {
            quadro.matriz[linha][coluna] = '*';
            quadro.matriz[linha+1][coluna] = '*';
            quadro.matriz[linha][coluna+1] = '*';
            quadro.matriz[linha-1][coluna] = '*';
            quadro.matriz[linha][coluna-1] = '*';
            posicoes_validas++;
        }

        if (resposta.Tipo_Arte == 4 && posicoes_validas == 1)
        {
            break;
        }
        
    }

}

void Gerar_X(Quadro quadro, Resposta_Usuario resposta)
{
    int linha;
    int coluna;
    int posicoes_validas = 0;

    while (posicoes_validas != resposta.Qtd_Figura)
    {
        coluna = rand() % (quadro.coluna - 1);
        linha  = rand() % (quadro.linha - 1);


        if (quadro.matriz[linha][coluna] == ' ' && quadro.matriz[linha+1][coluna+1] == ' ' 
        && quadro.matriz[linha-1][coluna+1] == ' ' && quadro.matriz[linha-1][coluna-1] == ' ' 
        && quadro.matriz[linha+1][coluna-1] == ' ' && coluna >= 0 && linha >= 0)
        {
            quadro.matriz[linha][coluna] = '*';
            quadro.matriz[linha+1][coluna+1] = '*';
            quadro.matriz[linha-1][coluna+1] = '*';
            quadro.matriz[linha-1][coluna-1] = '*';
            quadro.matriz[linha+1][coluna-1] = '*';
            posicoes_validas++;
        }
        if (resposta.Tipo_Arte == 4 && posicoes_validas == 1)
        {
            break;
        }
    }
}

void Gerar_Calopsita(Quadro quadro, Resposta_Usuario resposta)
{

    int linha;
    int coluna;
    int posicoes_validas = 0;

    while (posicoes_validas != resposta.Qtd_Figura)
    {
        coluna = rand() % (quadro.coluna - 1);
        linha  = rand() % (quadro.linha - 1);
/* 

 (     
(o>   
(/)

 */

    if (quadro.matriz[linha][coluna] == ' ' && quadro.matriz[linha][coluna+1] == ' ' && quadro.matriz[linha][coluna-1] == ' ' 
        && quadro.matriz[linha+1][coluna-1] == ' ' && quadro.matriz[linha+1][coluna] == ' ' && quadro.matriz[linha-1][coluna] == ' ' 
        && quadro.matriz[linha-1][coluna-1] == ' ' && quadro.matriz[linha-1][coluna+1] == ' ' && quadro.matriz[linha+1][coluna+1] == ' ' 
        && coluna >= 0 && linha >= 0)
        {

        quadro.matriz[linha][coluna] = 'o';     
        quadro.matriz[linha][coluna+1] = '>';    
        quadro.matriz[linha][coluna-1] = '(';    
        quadro.matriz[linha-1][coluna-1] = ' ';  
        quadro.matriz[linha-1][coluna] = '(';    
        quadro.matriz[linha+1][coluna] = '/';    
        quadro.matriz[linha+1][coluna-1] = '(';  
        quadro.matriz[linha+1][coluna+1] = ')';  
        quadro.matriz[linha-1][coluna+1] = ' ';
            
            posicoes_validas++;
        }
        if (resposta.Tipo_Arte == 4 && posicoes_validas == 1)
        {
            break;
        }
    }
}

void Gerar_Aleatoriamente(Quadro quadro, Resposta_Usuario resposta)
{
    for (int i = 0; i < resposta.Qtd_Figura; i++)
    {
        int arte = rand() % 4;

        if (arte == 0)
        {
            Gerar_Asterisco(quadro, resposta);
        } else if (arte == 1)
        {
            Gerar_Soma(quadro, resposta);
        } else if (arte == 2)
        {
            Gerar_X(quadro, resposta);
        } else if (arte == 3)
        {
            Gerar_Calopsita(quadro, resposta);
        }
    }

}

