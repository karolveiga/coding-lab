#include <stdio.h>

#define LARGURA 32
#define ALTURA 32

typedef struct {
    int vermelho;
    int verde;
    int azul;
} Cor;

void preencherImagem(Cor imagem[ALTURA][LARGURA], Cor cor) {

    int i;
    int j;

    for (i = 0; i < ALTURA; i++) {
        for (j = 0; j < LARGURA; j++) {
            imagem[i][j] = cor;
        }
    }
}

void desenharPixel(Cor imagem[ALTURA][LARGURA], int x, int y, Cor cor) {

    if (x >= 0 && x < LARGURA && y >= 0 && y < ALTURA) {
        imagem[y][x] = cor;
    }
}

void desenharCereja(Cor imagem[ALTURA][LARGURA]) {

    Cor vermelhoEscuro = {120, 0, 20};
    Cor vermelho = {220, 20, 50};
    Cor vermelhoClaro = {255, 60, 80};

    Cor verdeEscuro = {20, 80, 35};
    Cor verde = {40, 130, 50};

    int x;
    int y;

    /*
        Cereja da esquerda
    */

    for (y = 14; y <= 24; y++) {

        for (x = 5; x <= 15; x++) {

            if ((x - 10) * (x - 10) +
                (y - 19) * (y - 19) <= 30) {

                desenharPixel(imagem, x, y, vermelho);
            }
        }
    }

    /*
        Cereja da direita
    */

    for (y = 13; y <= 23; y++) {

        for (x = 14; x <= 25; x++) {

            if ((x - 20) * (x - 20) +
                (y - 18) * (y - 18) <= 30) {

                desenharPixel(imagem, x, y, vermelho);
            }
        }
    }

    /*
        Sombras das cerejas
    */

    for (y = 19; y <= 24; y++) {

        for (x = 6; x <= 14; x++) {

            if ((x - 10) * (x - 10) +
                (y - 19) * (y - 19) <= 28) {

                desenharPixel(imagem, x, y, vermelhoEscuro);
            }
        }
    }

    for (y = 18; y <= 23; y++) {

        for (x = 16; x <= 24; x++) {

            if ((x - 20) * (x - 20) +
                (y - 18) * (y - 18) <= 28) {

                desenharPixel(imagem, x, y, vermelhoEscuro);
            }
        }
    }

    /*
        Brilhos
    */

    desenharPixel(imagem, 8, 16, vermelhoClaro);
    desenharPixel(imagem, 9, 16, vermelhoClaro);
    desenharPixel(imagem, 8, 17, vermelhoClaro);

    desenharPixel(imagem, 18, 15, vermelhoClaro);
    desenharPixel(imagem, 19, 15, vermelhoClaro);
    desenharPixel(imagem, 18, 16, vermelhoClaro);

    /*
        Cabos
    */

    for (y = 3; y <= 15; y++) {

        x = 13 - (y / 3);

        desenharPixel(imagem, x, y, verdeEscuro);
        desenharPixel(imagem, x + 1, y, verdeEscuro);

        x = 18 + (y / 4);

        desenharPixel(imagem, x, y, verdeEscuro);
    }

    /*
        Folha
    */

    desenharPixel(imagem, 14, 5, verde);
    desenharPixel(imagem, 15, 5, verde);
    desenharPixel(imagem, 16, 5, verde);

    desenharPixel(imagem, 13, 6, verde);
    desenharPixel(imagem, 14, 6, verde);
    desenharPixel(imagem, 15, 6, verde);
    desenharPixel(imagem, 16, 6, verde);
    desenharPixel(imagem, 17, 6, verde);

    desenharPixel(imagem, 13, 7, verde);
    desenharPixel(imagem, 14, 7, verde);
    desenharPixel(imagem, 15, 7, verde);
    desenharPixel(imagem, 16, 7, verde);

    desenharPixel(imagem, 14, 8, verdeEscuro);
    desenharPixel(imagem, 15, 8, verdeEscuro);

    /*
        Pontinho decorativo
    */

    desenharPixel(imagem, 10, 27, vermelho);
    desenharPixel(imagem, 11, 27, vermelho);
    desenharPixel(imagem, 10, 28, vermelho);
    desenharPixel(imagem, 11, 28, vermelho);
}

void salvarImagem(Cor imagem[ALTURA][LARGURA]) {

    FILE *arquivo;

    int i;
    int j;

    arquivo = fopen("cereja.ppm", "w");

    if (arquivo == NULL) {
        printf("Erro ao criar a imagem.\n");
        return;
    }

    fprintf(arquivo, "P3\n");
    fprintf(arquivo, "%d %d\n", LARGURA, ALTURA);
    fprintf(arquivo, "255\n");

    for (i = 0; i < ALTURA; i++) {

        for (j = 0; j < LARGURA; j++) {

            fprintf(arquivo, "%d %d %d ",
                    imagem[i][j].vermelho,
                    imagem[i][j].verde,
                    imagem[i][j].azul);
        }

        fprintf(arquivo, "\n");
    }

    fclose(arquivo);

    printf("\nImagem criada com sucesso!\n");
    printf("Arquivo: cereja.ppm\n");
}

int main() {

    Cor imagem[ALTURA][LARGURA];

    Cor fundo = {255, 240, 245};

    preencherImagem(imagem, fundo);

    desenharCereja(imagem);

    salvarImagem(imagem);

    return 0;
}
