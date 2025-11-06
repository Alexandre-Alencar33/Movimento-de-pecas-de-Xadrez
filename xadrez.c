#include <stdio.h>

/*
 Desafio: nível mestre - Movimentos Complexos (C)
 - Torre, Bispo e Rainha: implementados com recursividade.
 - Bispo: recursividade + loops aninhados (outer = vertical, inner = horizontal).
 - Cavalo: loops complexos aninhados simulando "L" (2x Cima, 1x Direita) com uso de continue/break.
 - Todas as direções imprimem usando printf("Cima\n"), printf("Baixo\n"), printf("Esquerda\n"), printf("Direita\n").
 - Variáveis de número de casas definidas diretamente no código.
 - Comentários explicam a lógica e cuidados com recursão.
*/

/* =======================
   Protótipos das funções
   =======================*/
void torre_recursive(int steps);
void bispo_recursive_with_nested_loops(int steps);
void rainha_recursive(int steps);
void cavalo_loops_complexos(int l_moves, int up_per_L, int right_per_L);

int main() {
    /* ---------------------------------------------------
       Configuração: números de casas/iterações definidos
       diretamente no código conforme solicitado.
       (Usar apenas inteiros para contadores / limites)
       ---------------------------------------------------*/
    int casastorre = 5;            // Torre: 5 casas para a direita
    int casasbispo = 5;            // Bispo: 5 passos diagonais (cada passo = 1 Cima + 1 Direita)
    int casasrainha = 8;           // Rainha: 8 casas para a esquerda
    int cavalo_L_moves = 3;        // Quantos "L" o cavalo fará
    int cavalo_up_per_L = 2;       // Cavalo: 2 casas para cima por 'L'
    int cavalo_right_per_L = 1;    // Cavalo: 1 casa para a direita por 'L'

    /* ===== Movimento da Torre (recursivo) ===== */
    printf("Movimento da Torre:\n");
    torre_recursive(casastorre);  // chama recursivamente 'casastorre' vezes
    printf("\n");

    /* ===== Movimento do Bispo (recursivo + loops aninhados) =====
       Implementação: cada chamada recursiva realiza um "passo diagonal".
       Dentro da chamada usamos um loop externo (vertical) e um loop interno (horizontal).
       Observação: para cumprir o requisito de loops aninhados + recursão,
       cada passo usa loops (mesmo que cada loop execute 1 iteração lógica por passo).
    */
    printf("Movimento do Bispo:\n");
    bispo_recursive_with_nested_loops(casasbispo);
    printf("\n");

    /* ===== Movimento da Rainha (recursivo) ===== */
    printf("Movimento da Rainha:\n");
    rainha_recursive(casasrainha);
    printf("\n");

    /* ===== Movimento do Cavalo (loops complexos aninhados) =====
       Objetivo: simular 'L' para cima-direita: duas casas 'Cima' e uma 'Direita'.
       Uso de loops aninhados, múltiplas variáveis, continue e break para controle.
    */
    printf("Movimento do Cavalo (L: 2 Cima + 1 Direita):\n");
    cavalo_loops_complexos(cavalo_L_moves, cavalo_up_per_L, cavalo_right_per_L);
    printf("\n");

    return 0;
}

/* ---------------------------
   Função recursiva: Torre
   - Imprime "Direita" uma vez por passo e chama recursivamente com steps-1.
   - Termina quando steps <= 0.
   --------------------------- */
void torre_recursive(int steps) {
    if (steps <= 0) {
        return; // condição de parada da recursão
    }
    printf("Direita\n");         // imprime a casa atual
    torre_recursive(steps - 1);  // chamada recursiva para a próxima casa
}

/* --------------------------------------------------------------
   Bispo: recursividade combinada com loops aninhados.
   - Cada chamada recursiva representa 1 passo diagonal (Cima + Direita).
   - Dentro da chamada usamos:
   - O uso de loops aninhados é demonstrado mesmo que, logicamente,
     para uma diagonal simples cada loop execute uma iteração por passo.
   - Essa estrutura atende ao requisito "loop externo vertical, loop interno horizontal"
   -------------------------------------------------------------- */
void bispo_recursive_with_nested_loops(int steps) {
    if (steps <= 0) return;

    /* (simula "Cima" por passo) */
    for (int v = 0; v < 1; v++) { // v iterará uma vez por chamada recursiva
        /* (simula "Direita" por passo) */
        for (int h = 0; h < 1; h++) { // h iterará uma vez por passo
            printf("Cima\n");
            printf("Direita\n");
        }
    }

    /* Chamada recursiva para o próximo passo diagonal */
    bispo_recursive_with_nested_loops(steps - 1);
}

/* ---------------------------
   Função recursiva: Rainha
   - Neste exercício a Rainha se move somente para a esquerda (como pedido).
   - Imprime "Esquerda" em cada passo recursivo.
   --------------------------- */
void rainha_recursive(int steps) {
    if (steps <= 0) return;
    printf("Esquerda\n");
    rainha_recursive(steps - 1);
}

/* ------------------------------------------------------------
   Cavalo: Loops complexos aninhados
   - Simula N movimentos em 'L' (cada 'L' = up_per_L vezes "Cima" + right_per_L vezes "Direita").
   - Usa for externo para controlar quantos 'L' serão executados.
   - Dentro, usa um while para o movimento para cima que demonstra controle
     fino com continue/break (mostrando formas de controlar fluxo).
   - Depois do movimento para cima, executa o movimento para a direita.
   - O uso de continue é mostrado para pular ações (aqui apenas ilustrativo),
     e break para sair do loop quando a condição é satisfeita.
   ------------------------------------------------------------ */
void cavalo_loops_complexos(int l_moves, int up_per_L, int right_per_L) {
  
    if (l_moves <= 0 || up_per_L <= 0 || right_per_L <= 0) return;

    for (int move = 1; move <= l_moves; move++) {
        /* contador de 'Cima' realizado neste L */
        int up_count = 0;

        /* Loop que sobe até atingir up_per_L.
           Demonstra o uso de continue e break:
           - usamos continue quando queremos pular código extra (ilustrativo),
           - usamos break para sair imediatamente ao completar o número desejado. */
        while (1) {
            if (up_count >= up_per_L) {
                /* já subimos o necessário: sair do while */
                break;
            }

            /* Realiza uma unidade de 'Cima' */
            printf("Cima\n");
            up_count++;

           
            if (up_count < up_per_L) {
                continue; // volta ao topo do while para subir outra vez
            }

     
        }

        /* Agora faz o movimento horizontal correspondente (direita) */
        for (int r = 0; r < right_per_L; r++) {
            printf("Direita\n");
        }

    
    }
}