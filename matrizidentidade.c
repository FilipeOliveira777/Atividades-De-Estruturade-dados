/*4. Escreva uma Fun��o que, dadas duas matrizes quadradas, A e B, verifique se
B � a inversa de A (pesquisar este conceito caso tenham esquecido), isto �, se
B � igual a A? �. Se B for a inversa, a multiplica��o de A por B resulta numa matriz
identidade. A fun��o deve retorna 1 se B � a inversa de A e 0 caso contr�rio. A
fun��o deve seguir o seguinte prot�tipo: ( 2,5 Pontos)
void inversa_Matriz( int *vet_1, int *vet_2, int n)
*/
#include<stdio.h>
// Fun��o para verificar se uma matriz � uma matriz identidade.
int identidade_Matriz(int *vet_1, int n) {
    // Verifica se a matriz � quadrada (NxN).
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j && vet_1[i * n + j] != 1) {
                return 0; // Elemento da diagonal principal n�o � 1.
            } else if (i != j && vet_1[i * n + j] != 0) {
                return 0; // Elemento fora da diagonal principal n�o � 0.
            }
        }
    }
    return 1; // A matriz � uma matriz identidade.
}

int main() {
    int matriz_identidade[3][3] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
    int n = 3; // Dimens�o da matriz

    if (identidade_Matriz(&matriz_identidade[0][0], n)) {
        printf("A matriz � uma matriz identidade.\n");
    } else {
        printf("A matriz n�o � uma matriz identidade.\n");
    }

    return 0;
}
