#ifndef tabuleiro_h
#define tabuleiro_h

void tabuleiro(char matjogo[3][3]) { //Imprime o tabuleiro do jogo atual
    printf("\n");

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            printf("[%c]", matjogo[i][j]);

        }

        printf("\n");

    }

    printf("\n");

}

void tab_cord() { //Imprime o tabuleiro com as coordenadas
    printf("\n");

    for(int i = 1; i <= 3; i++) {
        for(int j = 1; j <= 3; j++) {
            printf("[%i,%i]", i, j);

        }

        printf("\n");

    }

    printf("\n");

}

#endif //tabuleiro_h