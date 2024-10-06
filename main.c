#include "funcoes.c"


int main()
{
  srand(time(NULL));

    Quadro quadro = Criar_Quadro();

    Resposta_Usuario Resposta;

    Exibe_Menu(Resposta, quadro);

    Imprimir_Quadro(quadro);
    
    Liberar_Quadro(quadro);

    return 0;
}

