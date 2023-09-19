#include <stdio.h>
const int linhas = 3; // Número de linhas da matriz
const int colunas = 3; // Número de colunas da matriz

// Função para calcular o tamanho do vetor com base no número de linhas e colunas.
int calcularTamanhoVetor(int linhas, int colunas) {
    return linhas * colunas;
}

// Função para zerar uma matriz representada como um vetor.
void zerarMatriz(int matriz[], int tamanho) {
	for (int i = 0; i < tamanho; i++) {
        matriz[i] = 0;
    }
}

void adicionarElemento(int matriz[],int colunasmatriz, int linha, int coluna,int elemento) {
    // Calcula o índice correspondente no vetor
    linha = linha - 1;
    coluna = coluna - 1;
    int indice = linha * colunasmatriz + coluna;
    
    // Verifica se o índice está dentro dos limites da matriz
    if (linha >= 0 && linha < colunas && coluna >= 0 && coluna < colunas) {
        matriz[indice] = elemento;
        printf("Elemento %d adicionado na posicao (%d, %d).\n", elemento, linha + 1, coluna + 1);
    } else {
        printf("Posicao inválida (%d, %d) para adicionar o elemento %d.\n", linha + 1, coluna + 1, elemento);
    }
}

void imprimirMatriz(int matriz[], int linhas, int colunas) {
	// Matriz resultante.
    printf("Matriz resultante:\n");
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            int indice = i * colunas + j;
            printf("%d ", matriz[indice]);
        }
        printf("\n");
    }
}

void buscarElemento(int matriz[],int linhaBusca, int colunaBusca) {
    if (linhaBusca >= 1 && linhaBusca <= linhas && colunaBusca >= 1 && colunaBusca <= colunas) {
        int indice = (linhaBusca - 1) * colunas + (colunaBusca - 1);
        int elemento = matriz[indice];
        printf("Elemento %d encontrado na posicao (%d, %d).\n", elemento, linhaBusca, colunaBusca);
    } else {
        printf("Posicao invalida (%d, %d) para buscar elemento na matriz.\n", linhaBusca, colunaBusca);
    }
}

// Função para somar duas matrizes representadas por vetores.
void somarMatrizes(int matrizA[], int matrizB[], int matrizResultado[],int linhatamanho,int colunatamanho) {
    int tamanho = calcularTamanhoVetor(linhatamanho, colunatamanho);

    for (int i = 0; i < tamanho; i++) {
        matrizResultado[i] = matrizA[i] + matrizB[i];
    }
}
//Função para calcular o produto de duas matriz.
void produto_Matriz(int *vet_1, int *vet_2, int matrizResultado[], int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < 2; k++) {
                matrizResultado[i * n + j] += vet_1[i * 2 + k] * vet_2[k * 3 + j];
            }
        }
    }
}
//Função para fazer a transposta da matriz.
void transposta_da_soma_Matriz(int *vet_soma, int *vet_transposta, int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            vet_transposta[j * m + i] = vet_soma[i * n + j];
        }
    }
}
//Função para verificar se a matriz é identidade.
int identidade_Matriz(int matriz[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int indice = i * n + j;
            if ((i == j && matriz[indice] != 1) || (i != j && matriz[indice] != 0)) {
                return 0; // Não é uma matriz identidade
            }
        }
    }
    return 1; // É uma matriz identidade
}
//Função para multiplicar as duas matriz.
//Função para multiplicar as duas matrizes e verificar a inversa.
int inversa_Matriz(int *vet_1, int *vet_2, int *matrizResultadoMulti, int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                matrizResultadoMulti[i * n + j] += vet_1[i * n + k] * vet_2[k * n + j];
            }
        }
    }
    int ResultadoDaFuncaoInversa = identidade_Matriz(matrizResultadoMulti, n);
    
    if (ResultadoDaFuncaoInversa) {
        return 1;
    } else {
        return 0;
    }
}


int main() {
    // Calcula o tamanho do vetor necessário.
    int matriz3x2= calcularTamanhoVetor(3,2);
    int matriz2x3= calcularTamanhoVetor(2,3);
    int matrizA[matriz3x2]; // Vetor para representar a primeira matriz.
    int matrizB[matriz2x3]; // Vetor para representar a segunda matriz.
    int matrizC[matriz3x2]; // Vetor para representar a primeira matriz de soma.
    int matrizD[matriz3x2]; // Vetor para representar a segunda matriz de soma.
    int matrizResultadoSoma[matriz3x2]; // Vetor para guardar a soma das matriz C e D.
    int matrizResultadoTranspostaSoma[matriz2x3]; // Vetor para representar a transposta da soma.
	int tamanho_vetor_resultante = calcularTamanhoVetor(linhas, colunas);
    int matrizResultado[tamanho_vetor_resultante]; // Vetor para representar a matriz resultante.
    int matriz_identidade[tamanho_vetor_resultante];
    // Inicializa as matriz com zeros.
    zerarMatriz(matrizA, matriz3x2);
    zerarMatriz(matrizB, matriz2x3);
    zerarMatriz(matrizResultado,tamanho_vetor_resultante);
    // Imprime a matriz antes da adição.
    printf("Matriz A zerada:\n");
    imprimirMatriz(matrizA, 3, 2);
    printf("Matriz B zerada:\n");
    imprimirMatriz(matrizB, 2, 3);
    //adicionando elementos a matriz A.
    adicionarElemento(matrizA, 2, 1, 1,5);
    adicionarElemento(matrizA, 2, 1, 2,5);
    adicionarElemento(matrizA, 2, 2, 1,5);
    adicionarElemento(matrizA, 2, 2, 2,5);
    adicionarElemento(matrizA, 2, 3, 1,5);
    adicionarElemento(matrizA, 2, 3, 2,5);
    //adicionando elementos a matriz B.
    adicionarElemento(matrizB, 3, 1, 1,1);
    adicionarElemento(matrizB, 3, 1, 2,2);
    adicionarElemento(matrizB, 3, 1, 3,3);
    adicionarElemento(matrizB, 3, 2, 1,4);
    adicionarElemento(matrizB, 3, 2, 2,5);
    adicionarElemento(matrizB, 3, 2, 3,6);
    // Imprime a matriz após a edição.
    printf("Matriz A apos a adicao\n");
    imprimirMatriz(matrizA, 3, 2);
    printf("Matriz B apos a adicao\n");
    imprimirMatriz(matrizB, 2, 3);
    //chamando a função para buscar um elemento na matriz A.
    printf("MatrizA ");
	buscarElemento(matrizA,1,1);
    //chamando a função para buscar um elemento na matriz B.
    printf("MatrizB ");
	buscarElemento(matrizB,1,1);
    //chamando a função para calcular o produto da matriz.
    produto_Matriz(matrizA,matrizB,matrizResultado,linhas,colunas);
    //imprimindo a matriz produto.
    printf("A matriz produto\n");
    imprimirMatriz(matrizResultado,linhas,colunas);
    //iniciando as matriz de soma zeradas.
    zerarMatriz(matrizC, matriz3x2);
    zerarMatriz(matrizD, matriz3x2);
    zerarMatriz(matrizResultadoSoma,matriz3x2);
    zerarMatriz(matrizResultadoTranspostaSoma,matriz2x3);
     //adicionando elementos a matriz C para soma.
    adicionarElemento(matrizC, 2, 1, 1,5);
    adicionarElemento(matrizC, 2, 1, 2,5);
    adicionarElemento(matrizC, 2, 2, 1,5);
    adicionarElemento(matrizC, 2, 2, 2,5);
    adicionarElemento(matrizC, 2, 3, 1,5);
    adicionarElemento(matrizC, 2, 3, 2,5);
    //adicionando elementos a matriz D para soma.
    adicionarElemento(matrizD, 2, 1, 1,1);
    adicionarElemento(matrizD, 2, 1, 2,2);
    adicionarElemento(matrizD, 2, 2, 1,3);
    adicionarElemento(matrizD, 2, 2, 2,4);
    adicionarElemento(matrizD, 2, 3, 1,5);
    adicionarElemento(matrizD, 2, 3, 2,6);
     // Chama a função para somar as matrizes C e D e armazenar o resultado em matrizResultado.
    somarMatrizes(matrizC, matrizD, matrizResultadoSoma,3,2);
    //imprimindo matriz C antes da soma.
	printf("matriz C antes da soma\n");
    imprimirMatriz(matrizC,3,2);
    //imprimindo matriz D antes da soma.
	printf("matriz D antes da soma\n");
    imprimirMatriz(matrizD,3,2);
	// Imprime a matriz resultante.
    printf("\nResultado da soma:\n");
    imprimirMatriz(matrizResultadoSoma, 3, 2);
    //chama a função para a transposta da soma.
   transposta_da_soma_Matriz(matrizResultadoSoma,matrizResultadoTranspostaSoma,3,2);
    //imprimindo a matriz transposta.
    printf("\nResultado da transposta:\n");
    imprimirMatriz(matrizResultadoTranspostaSoma, 2, 3);
    //adicionando elementos a matriz identidade.
     //adicionando elementos a matriz A.
    adicionarElemento(matriz_identidade, 3, 1, 1,1);
    adicionarElemento(matriz_identidade, 3, 1, 2,0);
    adicionarElemento(matriz_identidade, 3, 1, 3,0);
    adicionarElemento(matriz_identidade, 3, 2, 1,0);
    adicionarElemento(matriz_identidade, 3, 2, 2,1);
    adicionarElemento(matriz_identidade, 3, 2, 3,0);
    adicionarElemento(matriz_identidade, 3, 3, 1,0);
    adicionarElemento(matriz_identidade, 3, 3, 2,0);
    adicionarElemento(matriz_identidade, 3, 3, 3,1);
    //chamando a função para verificar se a matriz é identidade.
     int eh_identidade = identidade_Matriz(matriz_identidade, 3);
    if(eh_identidade){
    	printf("A matriz eh identidade\n");
	}
	else{
		printf("A matriz nao eh identidade\n");
	}	
    //imprimindo a matriz identidade.
    imprimirMatriz(matriz_identidade,3,3);
    //matriz para realizar a multiplicação.
    int MatrizAMulti[tamanho_vetor_resultante];//Matriz A 3x3 para multiplicação.
    int MatrizBMulti[tamanho_vetor_resultante];//Matriz A 3x3 para multiplicação.
    int MatrizResultadoMulti[tamanho_vetor_resultante];//Matriz A 3x3 para armazenar o resultado.
     //zerando as matrizes.
    zerarMatriz(MatrizAMulti, tamanho_vetor_resultante);
    zerarMatriz(MatrizBMulti, tamanho_vetor_resultante);
    zerarMatriz(MatrizResultadoMulti,tamanho_vetor_resultante);
	 //adicionando elementos a matriz A de multiplicação.
    adicionarElemento(MatrizAMulti, 3, 1, 1,1);
    adicionarElemento(MatrizAMulti, 3, 1, 2,0);
    adicionarElemento(MatrizAMulti, 3, 1, 3,0);
    adicionarElemento(MatrizAMulti, 3, 2, 1,0);
    adicionarElemento(MatrizAMulti, 3, 2, 2,1);
    adicionarElemento(MatrizAMulti, 3, 2, 3,0);
    adicionarElemento(MatrizAMulti, 3, 3, 1,0);
    adicionarElemento(MatrizAMulti, 3, 3, 2,0);
    adicionarElemento(MatrizAMulti, 3, 3, 3,1);
    //adicionando elementos a matriz B de multiplicação.
    adicionarElemento(MatrizBMulti, 3, 1, 1,1);
    adicionarElemento(MatrizBMulti, 3, 1, 2,0);
    adicionarElemento(MatrizBMulti, 3, 1, 3,0);
    adicionarElemento(MatrizBMulti, 3, 2, 1,0);
    adicionarElemento(MatrizBMulti, 3, 2, 2,1);
    adicionarElemento(MatrizBMulti, 3, 2, 3,0);
    adicionarElemento(MatrizBMulti, 3, 3, 1,0);
    adicionarElemento(MatrizBMulti, 3, 3, 2,0);
    adicionarElemento(MatrizBMulti, 3, 3, 3,1);
    //imprimindo a matriz A antes da multiplicação.
    printf("Matriz A antes da multiplicacao\n");
    imprimirMatriz(MatrizAMulti,3,3);
    //imprimindo a matriz B antes da multiplicação.
    printf("Matriz B antes da multiplicacao\n");
    imprimirMatriz(MatrizBMulti,3,3);
	//chamando a função para multiplicar e verificar a inversa.
    int verificar_iversa= inversa_Matriz( MatrizAMulti, MatrizBMulti,MatrizResultadoMulti, 3,3);
    //verificando o resultado da inversa da matriz.
    if(verificar_iversa){
    	printf("A matriz B eh a inversa da A\n");
	}
	else{
	printf("A matriz B nao eh a inversa da A\n");
	}
	//imprimindo o resultado da multiplicação das matrizes.
	imprimirMatriz(MatrizResultadoMulti,3,3);
    return 0;
}

