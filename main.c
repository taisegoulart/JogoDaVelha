#include <locale.h> // biblioteca para idioma
#include <stdio.h>
#include <stdlib.h>
#include <string.h> //biblioteca strings
#define JOGADOR1 'X'
#define JOGADOR2 'O'
#define CARACTERE_BRANCO '-'
#define EMPATE 'e'

int main(int argc, char *argv[]) {
  setlocale(LC_ALL, "Portuguese"); // atribui o idioma para Português
  int linha;
  int coluna;
  char tabuleiro[3][3];
  int posicao; // pois posição da cédula da matriz é um valor inteiro, vou usar
               // isso para percorrer a matriz
  int turno = 0;
  char ganhador = 'e';
  char jogadordoturno = JOGADOR1; // inicializa com o primeiro jogador
  int tamanhotabuleiro = 9;

  //imprime o tabuleirop e tpitulo do jogo com as regras
   printf("\t\t\t ## Jogo-da-Velha ##\n\n");
    printf("O jogo irá iniciar com o jogador X. Para jogar, escolha uma posição de 1 a 9 conformke mostrado abaixo. \n\n");
      
    printf("\t\t\t  1 | 2  | 3  \n");
    printf("\t\t\t--------------\n");
    printf("\t\t\t  4 | 5  | 6  \n");
    printf("\t\t\t--------------\n");
    printf("\t\t\t  7 | 8  | 9  \n\n");
      
    printf("-\t-\t-\t-\t-\t-\t-\t-\t-\t-\n\n");

  // Prenchimento inicial do tabuleiro com o valor "branco"
  for (linha = 0; linha < 3; linha++) // ou linha+=1
    for (coluna = 0; coluna < 3; coluna++)
      tabuleiro[linha][coluna] = '-'; // 

 
//início do laço que se manterá ativo até que o jogo acabe, por isso o 1
  while (1) {
    printf("\n\tTurno número: %d\n", turno+1);

    //impressão melhorada
   printf("\t\t\t  %c | %c  | %c  \n", tabuleiro[0][0], tabuleiro[0][1],
           tabuleiro[0][2]);
    printf("\t\t\t--------------\n");
    printf("\t\t\t  %c | %c  | %c  \n", tabuleiro[1][0], tabuleiro[1][1],
           tabuleiro[1][2]);
    printf("\t\t\t--------------\n");
    printf("\t\t\t  %c | %c  | %c  \n\n", tabuleiro[2][0], tabuleiro[2][1],
          tabuleiro[2][2]);
    

    printf("\n\tVez do jogador %c, faça sua jogada:\n", jogadordoturno);
    while(scanf("%d", &posicao) != 1)
    {
        printf("Por favor, escolha uma posição de 1-9: ");
        while(getchar() != '\n');
    }
        // scanf("%d", &posicao);

    if (!(posicao >= 1 && posicao <= 9)) {
      printf("\nPosição inválida, escolha uma posição de 1-9.");
      continue;
    }

    // trocar o a seguir por um switch-case
    // logia=valor da coluna=o que jogador digitou-1 -4 e -7 =agrupo as linhas
    // quando que inicializou esse posição?
    if (posicao >= 1 && posicao <= 3) {
      if (tabuleiro[0][posicao - 1] != CARACTERE_BRANCO) {
        printf("\nEssa posicao ja foi preenchida, escolha outra válida.\n");
        continue;
      }
      tabuleiro[0][posicao - 1] = jogadordoturno;
    }

    else if (posicao >= 4 && posicao <= 6) {
      if (tabuleiro[1][posicao - 4] != CARACTERE_BRANCO) {
        printf("\nEssa posicao ja foi preenchida, escolha outra válida.\n");
        continue;
      }
      tabuleiro[1][posicao - 4] = jogadordoturno;
    }

    else if (posicao >= 7 && posicao <= 9) {
      if (tabuleiro[2][posicao - 7] != CARACTERE_BRANCO) {
        printf("\nEssa posicao ja foi preenchida, escolha outra válida.\n");
        continue;
      }

      tabuleiro[2][posicao - 7] = jogadordoturno;
    }

    // verifica se jogador1 ganhou a partida pela linha
    for (linha = 0; linha < 3; linha++) {
      ganhador = jogadordoturno;
      for (coluna = 1; coluna < 3;
           coluna++) { // começa coluna com 1 porque não precisa comparar ela com
                       // ela mesma

        if (tabuleiro[linha][coluna] == CARACTERE_BRANCO ||
            tabuleiro[linha][coluna] != tabuleiro[linha][coluna - 1]) {
          ganhador = EMPATE;
          break;
        }
      }
      if (ganhador != EMPATE) // aqui já verifica se jogador ganhou a partida, senão, continua verificando pelos trechos de código a seguir
        break;
    }

    // abaixo tá fixando a coluna e percorrendo as linhas, verificando se ganhou
    // pela coluna

    if (ganhador == EMPATE)
    
    { 
      for (coluna = 0; coluna < 3; coluna++) {
        ganhador = jogadordoturno;
        for (linha = 1; linha < 3; linha++) {
          if (tabuleiro[linha][coluna] == CARACTERE_BRANCO ||
              tabuleiro[linha][coluna] != tabuleiro[linha - 1][coluna]) {
            ganhador = EMPATE;
            break;
          }
        }
        if (ganhador != EMPATE)
          break;
      }
    }

    if (ganhador == EMPATE) {
      // verficação das diagonais
      // diagonal primária
      ganhador = jogadordoturno;
      for (linha = 1; linha < 3; linha++) {
        if (tabuleiro[linha][linha] == CARACTERE_BRANCO ||
            tabuleiro[linha][linha] != tabuleiro[linha - 1][linha - 1]) {
          // verifico se cada posição da diagonal é formada por um caractere
          // vazio. Enquanto for, continua a condição de empate, ninguém ganhou
          // ainda. Também verifica se a posição da diagonal atual é diferente
          // da posição anterior, pois para ganhar diagonal 7-5-3 precisa
          // preencher as posições {0,0}, {1,1} {2,2}
          ganhador = EMPATE;
          break;
        }
      }
    }
    // verificação a seguir da diagonal secundária

    if (ganhador == EMPATE) {
      ganhador = jogadordoturno;
      coluna = 1; // precisamos começar em uma posição a mais do que se quer
                  // verificar, aqui ele começa verificando a cédula central,
                  // sem ela preenchida, não tem como ganahr por diagonal
      for (linha = 1; linha < 3 && coluna >= 0; linha++) {
        if (tabuleiro[linha][coluna] == CARACTERE_BRANCO ||
            tabuleiro[linha][coluna] != tabuleiro[linha - 1][coluna + 1]) {
          ganhador = EMPATE;
          break;
        }
        coluna--;
      }
    }

    // código para saber se alguém empatou:
    turno++;

    if (ganhador != EMPATE || turno == tamanhotabuleiro)
      break;
    // se ninguém empatou ou ganhou, continua a jogada, determinando o jogador
    // pelo número do turno, se par, jogador 1, se ímpar, jogador2

    if (turno % 2 == 0) {
      jogadordoturno = JOGADOR1;
    }

    else {
      jogadordoturno = JOGADOR2;
    }
  }
  if (ganhador != EMPATE)
    printf("\n\t=== O jogador %c ganhou! ===\n", ganhador);
  else
    printf("\nO jogo empatou!\n");
  
  // Impressão das posições do tabuleiro após a escolha do jogador respectivo e preenchimento de uma cédula
  printf("\t\t\t  %c | %c  | %c  \n", tabuleiro[0][0], tabuleiro[0][1],
           tabuleiro[0][2]);
    printf("\t\t\t--------------\n");
    printf("\t\t\t  %c | %c  | %c  \n", tabuleiro[1][0], tabuleiro[1][1],
           tabuleiro[1][2]);
    printf("\t\t\t--------------\n");
    printf("\t\t\t  %c | %c  | %c  \n\n", tabuleiro[2][0], tabuleiro[2][1],
          tabuleiro[2][2]);


}
