#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUMERO_DE_TENTATIVAS 3

int main(){
    printf("          P  /_\\  P                              \n");
    printf("         /_\\_|_|_/_\\                             \n");
    printf("     n_n | ||. .|| | n_n         Bem vindo ao    \n");
    printf("     |_|_|nnnn nnnn|_|_|     Jogo de Adivinhação!\n");
    printf("    |" "  |  |_|  |"  " |                        \n");
    printf("    |_____| ' _ ' |_____|                        \n");
    printf("          \\__|_|__/                              \n\n");

    int segundos = time(0);
    srand(segundos);

    int numerogrande = rand();
	int numerosecreto = numerogrande % 100;

	int chute;
	int tentativas = 1;
    double pontos = 1000;
    int acertou = 0;

    int nivel;

    printf("Qual o nível de dificuldade?\n");
    printf("(1) Fácil (2) Médio (3) Difícil\n\n");
    printf("Escolha: ");
    scanf("%d", &nivel);

    int numerodetentativas;

    switch(nivel) {
        case 1:
            numerodetentativas = 20;
            break;
        case 2:
            numerodetentativas = 15;
            break;
        default:
            numerodetentativas = 6;
            break;
    }

	for(int i = 1; i <= numerodetentativas; i++) {
		printf("Tentativa %d de %d\n", tentativas, numerodetentativas);
		printf("Qual e o seu chute? ");

		scanf("%d", &chute);
		printf("\n\nSeu chute foi %d\n", chute);

		if(chute < 0) {
			printf("Voce nao pode chutar numeros negativos\n");
			continue;
		}

		acertou = (chute == numerosecreto);
		int maior = chute > numerosecreto;

		if(acertou) {
			break;
		} else if(maior) {
            printf("Seu chute foi maior que o numero secreto\n\n");
		} else {
			printf("Seu chute foi menor que o numero secreto\n\n");
		}

		tentativas++;

        double pontosperdidos = (chute - abs(numerosecreto)) / 2;
        pontos = pontos - pontosperdidos;
	}

	printf("Fim de jogo.\n\n");

    if( acertou ) {
        printf("             OOOOOOOOOOO               \n");
        printf("         OOOOOOOOOOOOOOOOOOO           \n");
        printf("      OOOOOO  OOOOOOOOO  OOOOOO        \n");
        printf("    OOOOOO      OOOOO      OOOOOO      \n");
        printf("  OOOOOOOO  #   OOOOO  #   OOOOOOOO    \n");
        printf(" OOOOOOOOOO    OOOOOOO    OOOOOOOOOO   \n");
        printf("OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO  \n");
        printf("OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO  \n");
        printf("OOOO  OOOOOOOOOOOOOOOOOOOOOOOOO  OOOO  \n");
        printf(" OOOO  OOOOOOOOOOOOOOOOOOOOOOO  OOOO   \n");
        printf("  OOOO   OOOOOOOOOOOOOOOOOOOO  OOOO    \n");
        printf("    OOOOO   OOOOOOOOOOOOOOO   OOOO     \n");
        printf("      OOOOOO   OOOOOOOOO   OOOOOO      \n");
        printf("         OOOOOO         OOOOOO         \n");
        printf("             OOOOOOOOOOOO              \n");
        printf("\n\n");

        printf("Você ganhou!\n");
        printf("Voce acertou em %d tentativas", tentativas);
        printf("\nTotal de pontos %.1f\n", pontos);
    } else {
        printf("Você perdeu! Tente de novo\n");
        printf("       \\|/ ____ \\|/    \n");
        printf("        @~/ ,. \\~@      \n");
        printf("       /_( \\__/ )_\\    \n");
        printf("          \\__U_/        \n");
    }
}