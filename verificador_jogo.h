#ifndef verificador_jogo_h
#define verificador_jogo_h

#include <locale.h>

int verificador(char matjogo[3][3],char ganhador) {
    setlocale(LC_ALL,"Portuguese");
    int final;
    for (int i = 0; i < 3; i++) {
        if ((matjogo[i][0] == matjogo[i][1]) && (matjogo[i][1] == matjogo[i][2]) && (matjogo[i][0] != ' ')) { //Verifica as linhas
            wprintf(L"O jogador \"%c\" ganhou! Parabéns!\n\n", ganhador);
            final = 1;
            return final;

        }

        if ((matjogo[0][i] == matjogo[1][i]) && (matjogo[1][i] == matjogo[2][i]) && (matjogo[1][i] != ' ')) { //Verifica as colunas
            wprintf(L"O jogador \"%c\" ganhou! Parabéns!\n\n", ganhador);
            final = 1;
            return final;

        }

        if ((matjogo[0][0] == matjogo[1][1]) && (matjogo[1][1] == matjogo[2][2]) && (matjogo[1][1] != ' ')) { //Verifica a diagonal 1
            wprintf(L"O jogador \"%c\" ganhou! Parabéns!\n\n", ganhador);
            final = 1;
            return final;

        }

        if ((matjogo[2][0] == matjogo[1][1]) && (matjogo[1][1] == matjogo[0][2]) && (matjogo[1][1] != ' ')) { //Verifica a diagonal 2
            wprintf(L"O jogador \"%c\" ganhou! Parabéns!\n\n", ganhador);
            final = 1;
            return final;

        }

    }

}

#endif //verificador_jogo_h