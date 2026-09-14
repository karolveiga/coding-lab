#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void mostrarMenu() {
    printf("\n========== TAROT DA KAROL ==========\n");
    printf("1 - Tirar uma carta\n");
    printf("2 - Tirar tres cartas\n");
    printf("3 - Consultar uma carta\n");
    printf("4 - Ver todos os Arcanos Maiores\n");
    printf("5 - Sair\n");
    printf("====================================\n");
}

void consultarCarta(int carta) {

    if (carta == 1) {
        printf("\nO LOUCO\n");
        printf("Novos começos, liberdade, espontaneidade e aventura.\n");
    }
    else if (carta == 2) {
        printf("\nO MAGO\n");
        printf("Criacao, iniciativa, habilidade e poder de manifestacao.\n");
    }
    else if (carta == 3) {
        printf("\nA SACERDOTISA\n");
        printf("Intuicao, misterio, conhecimento e sabedoria interior.\n");
    }
    else if (carta == 4) {
        printf("\nA IMPERATRIZ\n");
        printf("Criatividade, abundancia, fertilidade e crescimento.\n");
    }
    else if (carta == 5) {
        printf("\nO IMPERADOR\n");
        printf("Estrutura, autoridade, estabilidade e controle.\n");
    }
    else if (carta == 6) {
        printf("\nO HIEROFANTE\n");
        printf("Tradicao, ensinamentos, valores e conhecimento.\n");
    }
    else if (carta == 7) {
        printf("\nOS ENAMORADOS\n");
        printf("Escolhas, conexao, relacionamento e alinhamento.\n");
    }
    else if (carta == 8) {
        printf("\nO CARRO\n");
        printf("Determinacao, movimento, conquista e direcao.\n");
    }
    else if (carta == 9) {
        printf("\nA JUSTICA\n");
        printf("Equilibrio, verdade, responsabilidade e clareza.\n");
    }
    else if (carta == 10) {
        printf("\nO EREMITA\n");
        printf("Introspeccao, sabedoria, solidao e busca interior.\n");
    }
    else if (carta == 11) {
        printf("\nA RODA DA FORTUNA\n");
        printf("Mudancas, ciclos, movimento e novas possibilidades.\n");
    }
    else if (carta == 12) {
        printf("\nA FORCA\n");
        printf("Coragem, paciencia, autocontrole e confianca.\n");
    }
    else if (carta == 13) {
        printf("\nO ENFORCADO\n");
        printf("Pausa, perspectiva, entrega e mudanca de visao.\n");
    }
    else if (carta == 14) {
        printf("\nA MORTE\n");
        printf("Transformacao, encerramento e inicio de um novo ciclo.\n");
    }
    else if (carta == 15) {
        printf("\nA TEMPERANCA\n");
        printf("Equilibrio, harmonia, paciencia e integracao.\n");
    }
    else if (carta == 16) {
        printf("\nO DIABO\n");
        printf("Desejo, intensidade, apego e confrontacao com a propria sombra.\n");
    }
    else if (carta == 17) {
        printf("\nA TORRE\n");
        printf("Ruptura, revelacao, mudanca inesperada e libertacao.\n");
    }
    else if (carta == 18) {
        printf("\nA ESTRELA\n");
        printf("Esperanca, inspiracao, cura e renovacao.\n");
    }
    else if (carta == 19) {
        printf("\nA LUA\n");
        printf("Intuicao, inconsciente, misterio e imaginacao.\n");
    }
    else if (carta == 20) {
        printf("\nO SOL\n");
        printf("Alegria, clareza, sucesso, vitalidade e realizacao.\n");
    }
    else if (carta == 21) {
        printf("\nO JULGAMENTO\n");
        printf("Despertar, renovacao, consciencia e chamado interior.\n");
    }
    else if (carta == 22) {
        printf("\nO MUNDO\n");
        printf("Conclusao, realizacao, integracao e plenitude.\n");
    }
    else {
        printf("\nCarta invalida. Escolha um numero entre 1 e 22.\n");
    }
}

void mostrarArcanos() {

    printf("\n========== ARCANOS MAIORES ==========\n");

    printf("1  - O Louco\n");
    printf("2  - O Mago\n");
    printf("3  - A Sacerdotisa\n");
    printf("4  - A Imperatriz\n");
    printf("5  - O Imperador\n");
    printf("6  - O Hierofante\n");
    printf("7  - Os Enamorados\n");
    printf("8  - O Carro\n");
    printf("9  - A Justica\n");
    printf("10 - O Eremita\n");
    printf("11 - A Roda da Fortuna\n");
    printf("12 - A Forca\n");
    printf("13 - O Enforcado\n");
    printf("14 - A Morte\n");
    printf("15 - A Temperanca\n");
    printf("16 - O Diabo\n");
    printf("17 - A Torre\n");
    printf("18 - A Estrela\n");
    printf("19 - A Lua\n");
    printf("20 - O Sol\n");
    printf("21 - O Julgamento\n");
    printf("22 - O Mundo\n");
}

void tirarUmaCarta() {

    int carta;

    carta = rand() % 22 + 1;

    printf("\nSua carta foi:");

    consultarCarta(carta);
}

void tirarTresCartas() {

    int carta1;
    int carta2;
    int carta3;

    carta1 = rand() % 22 + 1;
    carta2 = rand() % 22 + 1;
    carta3 = rand() % 22 + 1;

    printf("\n========== SUA TIRAGEM ==========\n");

    printf("\nPASSADO:");
    consultarCarta(carta1);

    printf("\nPRESENTE:");
    consultarCarta(carta2);

    printf("\nFUTURO:");
    consultarCarta(carta3);
}

int main() {

    int opcao;
    int carta;

    srand(time(NULL));

    do {

        mostrarMenu();

        printf("\nEscolha uma opcao: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            tirarUmaCarta();
        }
        else if (opcao == 2) {
            tirarTresCartas();
        }
        else if (opcao == 3) {

            printf("\nDigite o numero da carta (1 a 22): ");
            scanf("%d", &carta);

            consultarCarta(carta);
        }
        else if (opcao == 4) {
            mostrarArcanos();
        }
        else if (opcao == 5) {
            printf("\nEncerrando a consulta...\n");
            printf("Que os Arcanos estejam ao seu favor. <3\n");
        }
        else {
            printf("\nOpcao invalida. Tente novamente.\n");
        }

    } while (opcao != 5);

    return 0;
}
