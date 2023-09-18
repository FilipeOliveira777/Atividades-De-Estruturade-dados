/*4. Escreva uma Função que, dadas duas matrizes quadradas, A e B, verifique se
B é a inversa de A (pesquisar este conceito caso tenham esquecido), isto é, se
B é igual a A? ¹. Se B for a inversa, a multiplicação de A por B resulta numa matriz
identidade. A função deve retorna 1 se B é a inversa de A e 0 caso contrário. A
função deve seguir o seguinte protótipo: ( 2,5 Pontos)
void inversa_Matriz( int *vet_1, int *vet_2, int n)
*/
#include<stdio.h>
// Função para verificar se uma matriz é uma matriz identidade.
int identidade_Matriz(int *vet_1, int n) {
    // Verifica se a matriz é quadrada (NxN).
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j && vet_1[i * n + j] != 1) {
                return 0; // Elemento da diagonal principal não é 1.
            } else if (i != j && vet_1[i * n + j] != 0) {
                return 0; // Elemento fora da diagonal principal não é 0.
            }
        }
    }
    return 1; // A matriz é uma matriz identidade.
}

int main() {
    int matriz_identidade[3][3] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
    int n = 3; // Dimensão da matriz

    if (identidade_Matriz(&matriz_identidade[0][0], n)) {
        printf("A matriz é uma matriz identidade.\n");
    } else {
        printf("A matriz não é uma matriz identidade.\n");
    }

    return 0;
}
