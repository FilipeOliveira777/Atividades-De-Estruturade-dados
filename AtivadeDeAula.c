#include <stdio.h>

// Função para adicionar um elemento a uma matriz (representada como um vetor).
void zerarmatriz(int matriz[],int tamanho){
	int i;
	// Inicializa a matriz ja com valores.
    for (i = 0; i < tamanho * tamanho; i++) {
        matriz[i] = 0;
    }
	
}

void adicionarElemento(int matriz[], int linha, int coluna, int tamanho, int elemento) {
    // Calcula o índice correspondente no vetor
    linha=linha-1;
    coluna=coluna-1;
    int indice = linha * tamanho + coluna;
    
    // Verifica se o índice está dentro dos limites da matriz
    if (linha >= 0 && linha < tamanho && coluna >= 0 && coluna < tamanho) {
        matriz[indice] = elemento;
        printf("Elemento %d adicionado na posicao (%d, %d).\n", elemento, linha+1, coluna+1);
    } else {
        printf("Posicao inválida (%d, %d) para adicionar o elemento %d.\n", linha+1, coluna+1, elemento);
    }
}
void imprimirmatriz(int matriz[],int tamanho){
	 int i,j;
	 //matriz resultante.
    printf("Matriz resultante:\n");
    for (i = 0; i < tamanho; i++) {
        for (j = 0; j < tamanho; j++) {
            int indice = i * tamanho + j;
            printf("%d ", matriz[indice]);
        }
        printf("\n");
    }
    
}
void buscarelemento(int matriz[],int tamanho, int elemento){
	int i,j;
	for (i = 0; i < tamanho; i++) {
        for (j = 0; j < tamanho; j++) {
        	
        }
	}
}

int main() {
    int tamanho = 3; // tamanho da matriz
    int matriz[tamanho * tamanho]; // Vetor para representar a matriz
    int i, j;
    
    // Inicializa a matriz ja com valores.
    zerarmatriz(matriz,tamanho);
    //imprimir a matriz antes da adicao.
    imprimirmatriz(matriz,tamanho);
    
    // Adicionar um elemento à matriz.
    adicionarElemento(matriz, 1,1, tamanho, 10);
    adicionarElemento(matriz, 1,2, tamanho, 20);
    adicionarElemento(matriz, 1,3, tamanho, 30);
    adicionarElemento(matriz, 2,1, tamanho, 40);
    adicionarElemento(matriz, 2,2, tamanho, 50);
    adicionarElemento(matriz, 2,3, tamanho, 60);
    adicionarElemento(matriz, 3,1, tamanho, 70);
    adicionarElemento(matriz, 3,2, tamanho, 80);
    adicionarElemento(matriz, 3,3, tamanho, 90);
   //imprimir a matriz apos a edicao.
   imprimirmatriz(matriz,tamanho);
   buscarelemento(matriz,tamanho,40);
    return 0;
}
