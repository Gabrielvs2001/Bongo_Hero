#include <stdio.h>
#include <stdlib.h> 
#include <time.h>

/*
*Imprime as instrucoes 
*/
void instrucoes(){
  printf("\nJogo criado por Gabrielvs2001\n");
  printf("\nInstrucoes:\n\n");
  printf("Para jogar, digite o numero da posicao desejada segundo o esquema abaixo:\n\n");
  printf(" 1 │ 2 │ 3 \n");
  printf("───┼───┼───\n");
  printf(" 4 │ 5 │ 6 \n");
  printf("───┼───┼───\n");
  printf(" 7 │ 8 │ 9 \n\n");
  printf("Voce joga com \"X\"\n");
  printf("E o computador joga com \"O\"\n\n");
}

/*
*Imprime a situacao atual da partida
*/
void imprimir(char matriz[3][3]){
  printf("\n");
  printf(" %c │ %c │ %c \n",matriz[0][0],matriz[0][1],matriz[0][2]);    //Imprime a primeira linha
  printf("───┼───┼───\n");                                              //Separador de linhas
  printf(" %c │ %c │ %c \n",matriz[1][0],matriz[1][1],matriz[1][2]);    //Imprime a segunda linha
  printf("───┼───┼───\n");                                              //Separador de linhas
  printf(" %c │ %c │ %c \n\n",matriz[2][0],matriz[2][1],matriz[2][2]);  //Imprime a terceira linha
}

/*
*Analisa se o jogo chegou no empate
*/
int empate(char matriz[3][3]){
  for (int i=0;i<3;i++){                                             //For para passar em todas as linhas
    for (int j=0;j<3;j++){                                           //For para passar em todas as colunas
      if (matriz[i][j]==' '){                                        //Analisa se a posicao em questao tem espaco
        return 0;                                                    //Se tiver espaco, retorna que o jogo nao empatou
      }
    }
  }
  return 1;                                                          //Se nao tiver nenhum espaco, retorna que o jogo esta empatado
}

/*
*Analisa se algum dos jogadores ganhou o jogo
*/
int vitoria(char matriz[3][3]){
  for (int i=0;i<3;i++){                                             //Analise de linhas
    if (matriz[i][0]==' ' || matriz[i][1]==' ' || matriz[i][2]==' '){//Se tiver algum espaco na linha, ja descarta a possibilidade
      continue;                                                      //Passa para a proxima linha
    }
    if (matriz[i][0]==matriz[i][1] && matriz[i][1]==matriz[i][2]){   //Analisa se todos os elemento da linha sao iguais
      return 1;                                                      //Em caso positivo, retorna que encontrou um ganhador
    }
  }
  for (int i=0;i<3;i++){                                             //Analise de colunas
    if (matriz[0][i]==' ' || matriz[1][i]==' ' || matriz[2][i]==' '){//Se tiver algum espaco na coluna, ja descarta a possibilidade
      continue;                                                      //Passa para a proxima coluna
    }
    if (matriz[0][i]==matriz[1][i] && matriz[1][i]==matriz[2][i]){   //Analisa se todos os elemento da coluna sao iguais
      return 1;                                                      //Em caso positivo, retorna que encontrou um ganhador
    }
  }
  for (int i=0;i<3;i+=2){                                            //Analise das diagonais
    if (matriz[i][0]==' ' || matriz[1][1]==' ' || matriz[2-i][2]==' '){ //Se tiver algum espaco na diagonal, ja descarta a possibilidade
      continue;                                                      //Passa para a proxima diagonal (principal para a secundaria)
    }
    if (matriz[i][0]==matriz[1][1] && matriz[1][1]==matriz[2-i][2]){ //Analisa se todos os elemento da diagonal sao iguais
      return 1;                                                      //Em caso positivo, retorna que encontrou um ganhador
    }
  }
  return 0;                                                          //Retorna que nao encontrou um vencedor
}

/*
*Permite ao jogador humano fazer sua jogada
*/
void vez_humano(char matriz[3][3]){
  int digitar;                                                       //Variavel que recebe a posicao escolhida pelo jogador
  while(1){
    printf("Sua vez: ");                                             //Mensagem para o jogador
    scanf("%d",&digitar);                                            //Leitura da posicao desejada pela jogador
    if (digitar <0 || digitar>9){                                    //Condicao para a variavel estar nos limites do tabuleiro
      printf("\nEntrada invalida, por favor tente novamente\n\n");   //Mensagem mostrando que a variavel nao esta nos limites do tabuleiro
      continue;                                                      //Volta no comeco do laco de repeticao para receber outro valor 
    }
    if (digitar==0){                                                 //Verifica se o jogador pediu o comando das instrucoes
      instrucoes();                                                  //Chama a funcao que vai passar as instrucoes
      printf("Situacao atual do jogo:\n");                           //Imprime uma mensagem para o jogador
      imprimir(matriz);                                              //Chama a funcao que vai imprimir
      printf("Sua vez: ");                                           //Imprime uma mensagem para o jogador
      continue;                                                      //Volta no comeco do laco de repeticao para receber outro valor 
    }
    int cont=0;                                                      //Variavel para analisar se a posicao escolhida esta vazia ou nao
    for (int i=0;i<3;i++){                                           //Passa por todas as linhas do tabuleiro
     for (int j=0;j<3;j++){                                          //Passa por todas as colunas do tabuleiro
       cont++;                                                       //Para cada posicao, incrementa a variavel de comparacao
       if(cont==digitar){                                            //Condicao para quando a posicao for igual a variavel de analise 
         if (matriz[i][j]==' '){                                     //Condicional se a posicao estiver vazia
           matriz[i][j]='X';                                         //Se estiver vazia, marca na posicao escolhida
           imprimir(matriz);                                         //Imprime o tabuleiro
           return;
         }else{
           printf("\nPosicao ja ocupada, por favor tente novamente\n\n"); //Mensagem mostrando que a posicao ja esta ocupada
         }
       }
     }
    }
  }
}

/*
*Faz o computador executar uma jogada
*/
void vez_computador(char matriz[3][3]){
  printf("Vez do computador:\n\a");
  int vazio=0;                                                        //Variavel que conta o numero de posicoes vazias
  for (int i=0;i<3;i++){                                              //Passa por todas as linhas do tabuleiro
    for (int j=0;j<3;j++){                                            //Passa por todas as colunas do tabuleiro
      if (matriz[i][j]==' '){                                         //Analisa se a posicao em questao esta vazia
        vazio++;                                                      //Em caso positivo, incrementa a variavel
      }                                                               //Que conta o numero de posicoes vazias
    }
  }
  int lower=1; //minimo de espacos
  int upper=vazio; //numero maximo de espacos
  int digitar = (rand() % (upper - lower + 1)) + lower;               //Sorteia um numero aletorio dentre o minimo e maximo de espacos
  int cont=0;                                                         //Variavel para 
  for (int i=0;i<3;i++){                                              //Passa por todas as linhas do tabuleiro
    for (int j=0;j<3;j++){                                            //Passa por todas as colunas do tabuleiro
      if (matriz[i][j]!=' '){                                         //Condicional se a posicao nao estiver vazia
        continue;                                                     //Se a posicao nao estiver vazia, avanca a posicao do tabuleiro
      }else{
        cont++;                                                       //Se a posicao estiver vazia, incrementa a variavel
      }
      if(cont==digitar){                                              //Condicional para alocar a posicao sorteada em um espaco vazio
        matriz[i][j]='O';                                             //Se estiver vazia, marca na posicao escolhida
        imprimir(matriz);                                             //Imprime o tabuleiro
        return;
      }
    }
  }
}

/*
*Funcao que gera uma partida 
*/
void jogo(int first){
  if (first==1){                                                      //Condicional se o jogador que comeca for aleatorio
    srand(time(0));                                                   //Inicializador para gerar numeros aleatorios
    int lower=2;                                                      //Jogador humano joga primeiro
    int upper=3;                                                      //Computador joga primeiro
    first = (rand() % (upper - lower + 1)) + lower;                   //Sorteia um valor entre 2 e 3 para ver quem comeca
  }
  char velha[3][3]={{32,32,32},{32,32,32},{32,32,32}};                //Cria um tabuleiro inicial que contem espacos

  if (first==3){                                                      //Se o computador for jogar primeiro
    printf("\nO computador joga primeiro\n\n");                       //Mensagem indicando que o computador joga primeiro
    vez_computador(velha);                                            //Shama a funcao para fazer a jogada do computador
  }else{                                                              //Se o jogador humano joga primeiro
    printf("\nVoce joga primeiro\n\n");                               //Mensagem indicando que o jogador humano joga primeiro
    imprimir(velha);                                                  //Imprime o tabuleiro vazio para o jogador fazer a primeira jogada
  }
  while(1){                                                           //Entra em um loop infinito e apenas sai quando o jogo acaba
    vez_humano(velha);                                                //Chama a funcao para permitir o jogador humano fazer sua jogada
    if(vitoria(velha)==1){                                            //Analisa se o jogador humano ganhou
      printf("\"X\" ganhou! Parabens!!!\n\n");                        //Mensagem indicando que o jogador humano ganhou
      break;                                                          //Sai do loop infinito se o jogador humano ganhar
    }
    if(empate(velha)==1){                                             //Analisa se o jogo chegou no empate
      printf("Deu velha!\n\n");                                           //Mensagem indicando que o jogo chegou no empate
      break;                                                          //Sai do loop infinito se der empate
    }
    vez_computador(velha);                                            //Chama a funcao para fazer a jogada do computador
    if(vitoria(velha)==1){                                            //Analisa se o computador humano ganhou
      printf("\"O\" ganhou, tente novamente\n\n");                    //Mensagem indicando que o computador ganhou
      break;                                                          //Sai do loop infinito se o computador ganhar
    }
    if(empate(velha)==1){                                             //Analisa se o jogo chegou no empate
      printf("Deu velha!\n\n");                                           //Mensagem indicando que o jogo chegou no empate
      break;                                                          //Sai do loop infinito se der empate
    }
  }
}

/*
* Inicializacao do jogo e menu  
*/
int main(int argc, char*argv[]) {
  printf("Bem vindo ao Jogo da Velha Classico!\n");                   //Mensagem de quando o jogo comeca
  instrucoes();                                                       //Chama a funcao que imprime as instrucoes
  printf("E possivel acessar as instrucoes durante o jogo digitando \"0\"\n\n");  //Mensagem para chamar as instrucoes novamente
  int tempfirst=1,first=1;                                            //Variaveis que indicam quem joga primeiro
  while(1){
    printf("Digite: 1 para comecar o jogo\n");                        //Menu do jogo
    printf("        2 para escolher quem joga primeiro\n");           //que mostra mensagens sobre
    printf("        0 para sair\n");                                  //o que o jogador pode acessar
    int menu;
    scanf("%d",&menu);                                                //Faz a leitura do que o jogador quer acessar
    switch (menu){                                                    //Switchcase para o que o jogador querer acessar conforme o menu
      case 1:                                                         //Case 1: inicializa a partida
        jogo(first);                                                  //Chama a funcao que comeca a partida
        printf("Novo jogo\?\n");                                      //Mensagem perguntando se o jogador quer comecar um novo jogo
        break;                                                        //Break para sair do switcase
      case 2:                                                         //Case 2: altera quem vai jogar primeiro
        do {                                                          //Entra no while sem analisar a condicao
          if (tempfirst<1 || tempfirst>3){                            //Caso o valor digitado posterior nao esteja nas opcoes
            printf("\nEntrada invalida, por favor tente novamente\n\n");  //Mensagem indicando que a entrada foi invalida 
          }
          printf("Digite o numero da opcao para alterar quem joga primeiro:\n");  //Mensagem mostrando as opcoes de entrada
          printf("1 - Aleatorio\n");
          printf("2 - Voce joga primeiro\n");
          printf("3 - Computador joga primeiro\n");
          printf("Configuracao atual = %d\n",first);                  //Mensagem mostrando quem jogaria primeiro
          scanf("%d",&tempfirst);                                     //Faz a leitura do caracter para a mudanca de quem joga primeiro
        } while (tempfirst<1 || tempfirst>3);                         //Condicional para a variavel que escolhe quem joga primeiro
        first=tempfirst;                                              //Passa quem joga primeiro para a variavel nao temporaria
        printf("\nConfiguracao alterada para: %d\n\n",first);         //Mensagem mostrando qual jogador joga primeiro
        break;                                                        //Break para sair do switcase 
      case 0:                                                         //Case 0: fecha o programa
        printf("\nObrigado por jogar! ^_^\n");                          //Mensagem agradecendo por ter usado o programa
        return 0;                                                     //Retorna um valor para fechar o programa
        break;                                                        //Break para sair do switcase
      default:                                                        //Default para caso o jogador nao digitar um valor dos switchcase
        printf("\nEntrada invalida, por favor tente novamente\n\n");  //Mensagem indicando que a entrada e invalida
        break;                                                        //Break para sair do switcase
    }
  }
  return 0;                                                           //Retorna um valor para fechar o programa
}