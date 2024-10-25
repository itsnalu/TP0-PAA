//Ana Luísa Moreira Rodrigues 5389
#include "funcoes.c"


int main()
{
  srand(time(NULL));

  Quadro quadro = Criar_Quadro();
  Cores cor = Criar_Cores();
  Resposta_Usuario Resposta;

  Exibe_Menu(&Resposta, &quadro, &cor);
  Imprimir_Quadro(quadro, cor, &Resposta);

    Liberar_Quadro(&quadro);
    Liberar_Cores(&cor);

    return 0;
}

