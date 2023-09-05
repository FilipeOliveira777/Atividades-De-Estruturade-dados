#include <stdio.h>

// Fun��o para calcular o tamanho do vetor com base no n�mero de linhas e colunas.
int calcularTamanhoVetor(int linhas, int colunas) {
    return linhas * colunas;
}

// Fun��o para zerar uma matriz representada como um vetor.
void zerarMatriz(int matriz[], int tamanho) {
    int i;
	for (i = 0; i < tamanho; i++) {
        matriz[i] = 0;
    }
}

void adicionarElemento(int matriz[], int linha, int coluna, int colunas, int elemento) {
    // Calcula o �ndice correspondente no vetor
    linha = linha - 1;
    coluna = coluna - 1;
    int indice = linha * colunas + coluna;
    
    // Verifica se o �ndice est� dentro dos limites da matriz
    if (linha >= 0 && linha < colunas && coluna >= 0 && coluna < colunas) {
        matriz[indice] = elemento;
        printf("Elemento %d adicionado na posicao (%d, %d).\n", elemento, linha + 1, coluna + 1);
    } else {
        printf("Posicao inv�lida (%d, %d) para adicionar o elemento %d.\n", linha + 1, coluna + 1, elemento);
    }
}

void imprimirMatriz(int matriz[], int linhas, int colunas) {
    int i,j;
	// Matriz resultante.
    printf("Matriz resultante:\n");
    for (i = 0; i < linhas; i++) {
        for (j = 0; j < colunas; j++) {
            int indice = i * colunas + j;
            printf("%d ", matriz[indice]);
        }
        printf("\n");
    }
}

void buscarElemento(int matriz[], int linhas, int colunas, int elemento) {
    int i,j;
	for (i = 0; i < linhas; i++) {
        for (j = 0; j < colunas; j++) {
            int indice = i * colunas + j;
            if (matriz[indice] == elemento) {
                printf("Elemento %d encontrado na posicao (%d, %d).\n", elemento, i + 1, j + 1);
                return; // Elemento encontrado, podemos sair da fun��o.
            }
        }
    }
    // Se chegarmos aqui, o elemento n�o foi encontrado.
    printf("Elemento %d n�o encontrado na matriz.\n", elemento);
}

int somarVetor(int vetor[], int tamanho) {
    int i,soma = 0;
    for (i = 0; i < tamanho; i++) {
        soma += vetor[i];
    }
    return soma;
}

int main() {
    int linhas = 3; // N�mero de linhas da matriz
    int colunas = 3; // N�mero de colunas da matriz

    // Calcula o tamanho do vetor necess�rio.
    int tamanhoVetor = calcularTamanhoVetor(linhas, colunas);
    int matriz[tamanhoVetor]; // Vetor para representar a matriz

    // Inicializa a matriz com zeros.
    zerarMatriz(matriz, tamanhoVetor);
    
    // Imprime a matriz antes da adi��o.
    imprimirMatriz(matriz, linhas, colunas);
    
    // Adicionar elementos � matriz.
    adicionarElemento(matriz, 1, 1, colunas, 10);
    adicionarElemento(matriz, 1, 2, colunas, 20);
    adicionarElemento(matriz, 1, 3, colunas, 30);
    adicionarElemento(matriz, 2, 1, colunas, 40);
    adicionarElemento(matriz, 2, 2, colunas, 50);
    adicionarElemento(matriz, 2, 3, colunas, 60);
    adicionarElemento(matriz, 3, 1, colunas, 70);
    adicionarElemento(matriz, 3, 2, colunas, 80);
    adicionarElemento(matriz, 3, 3, colunas, 90);
    
    // Imprime a matriz ap�s a edi��o.
    imprimirMatriz(matriz, linhas, colunas);
    
    // Busca elementos na matriz.
    buscarElemento(matriz, linhas, colunas, 30);
    int soma = somarVetor(matriz, tamanhoVetor);
    printf("Soma dos elementos da matriz: %d\n", soma);

    return 0;
}

