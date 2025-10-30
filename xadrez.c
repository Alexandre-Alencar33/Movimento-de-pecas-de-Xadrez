#include <stdio.h>

int main() {
    // variaveis 
    int casastorre = 5;
    int casasbispo = 5;
    int casasrainha = 8; 



    // === Movimento da Torre ===
    // A Torre move-se em linha reta, neste caso 5 casas para a direita.

    printf("Movimento da Torre:\n");
    for (int direita = 1; direita <= casastorre ; direita++) {// Estrutura for (variavel criada; condição; incremento)
        printf("Direita\n");// saida
    }

    // ESTRUTURA: usar estrutura for para mover 5 casas para a direita
    


    // === Movimento do Bispo ===
    // O Bispo move-se na diagonal, neste caso 5 casas para cima e para a direita.

    printf("\nMovimento do Bispo:\n");

    int Cima = 1; //variavel de incremento
    int direita = 1;// contador
    while (Cima <= casasbispo && direita <= casasbispo ) { //condição
        printf("Cima\n");// saida
        printf("Direita\n");// saida
        Cima++; // incremento
    }



         // === Movimento da Rainha ===
    // A Rainha move-se em todas as direções, neste caso 8 casas para a esquerda.

    printf("\nMovimento da Rainha:\n");
    // TODO: usar estrutura do-while para mover 8 casas
    // Exemplo do que vai imprimir: "Esquerda\n"

        int Esquerda = 1;
        do{ //entrada (1x pelo menos)
            printf("Esquerda\n"); // Saida
            Esquerda++; // incremento


        }   while (Esquerda <= casasrainha); //condição


    return 0;
    }