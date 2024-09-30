#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#include "tabuleiro.h"
#include "verificador_jogo.h"

int main(void) {
    setlocale(LC_ALL, "Portuguese");

    char matjogo[3][3], vez = 'X';
    int linha, coluna, validez, final = 0;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            matjogo[i][j] = ' ';

        }

    }

    wprintf(L"Jogo da Velha em C v1.6 (Windows) - Gslherme \n");
    wprintf(L"\nRegras: \n\n - O primeiro jogador sempre será o \"X\"; \n - Após o inicio do jogo, digite primeiro a linha e depois a coluna que deseja fazer a sua jogada; \n - Os números inseridos devem ser de 1 a 3, de acordo com as coordenadas; \n - Ao final do jogo, o programa dirá quem foi o vencedor. ");
    wprintf(L"\n\nEste é o nosso tabuleiro e suas coordenadas: \n");

    tab_cord();

    wprintf(L"Vamos iniciar o nosso jogo da velha! \n\n");
    system("pause");

    for(int i = 0; i < 9; i++) {
        validez = 0; //Reseta a validez para 0 ao inicio de toda repetição caso ocorra uma jogada inválida do tipo 2

        system("cls");

        if(vez == 'X' && i != 0) { //Altera a vez
            vez = 'O';

        }

        else {
            vez = 'X';

        }

        while(validez == 0) {
            validez = 0; //Reseta a validez para 0 ao inicio deste while caso ocorra uma jogada inválida do tipo 1

            system("cls");

            wprintf(L"Coordenadas: \n");
            tab_cord();

            wprintf(L"Jogo atual: \n");
            tabuleiro(matjogo);


            wprintf(L"Vez do jogador \"%c\". Digite a linha que deseja: ", vez);
            if((scanf("%i", &linha) != 1) || (linha > 3) || (linha < 1)) { //If para jogada inválida do tipo 1 caso o jogador inserir uma resposta diferente de 0, 1 e 2
                fflush(stdin);
                wprintf(L"\nJogada inválida! Digite apenas números do 0 ao 2! Tente novamente. \n\n");
                system("pause");
                continue;

            }


            wprintf(L"\nDigite a coluna que deseja: ");
            if((scanf("%i", &coluna) != 1) || (coluna > 3) || (coluna < 1)) { //Jogada inválida do tipo 1
                fflush(stdin);
                wprintf(L"\nJogada inválida! Digite apenas números do 0 ao 2! Tente novamente. \n\n");
                system("pause");
                continue;

            }

            linha = linha - 1;
            coluna = coluna - 1;

            if(matjogo[linha][coluna] == ' ') { //If para verificar se a casa selecionada pelo jogador estava desocupada (referente a jogada inválida do tipo 2)
                matjogo[linha][coluna] = vez;
                validez = 1;

            }

            else {
                wprintf(L"\nJogada inválida! Esta coordenada já está ocupada! Tente novamente. \n\n"); //Jogada inválida do tipo 2
                system("pause");

            }

        }

        wprintf(L"\nSua jogada foi: \n");
        tabuleiro(matjogo);

        final = verificador(matjogo, vez); //Verifica se alguém ganhou o jogo
        if(final == 1) {
            system("pause");
            return 0;

        }

        if((i == 8) && (final == 0)) { //Verifica se o jogo deu velha
            wprintf(L"O jogo deu velha!\n\n");
            system("pause");
            return 0;

        }

        system("pause");

    }

    return 0;

}