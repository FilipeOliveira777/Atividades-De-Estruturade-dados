#include <stdio.h>
#include <math.h>

int tamVet;
int linhas, colunas;

int dimensionaMatriz (int n1, int n2){
    return n1*n2;
}

void zeraMatriz (int vet[]) {

    int k;
    for (k=0; k < tamVet; k++){
        vet[k] = 0;
    }
}

void imprimeMatriz (int vet[], int linhas, int colunas){
    int k;
   
    for (k=0; k < tamVet; k++){
        printf ("%4d ", vet[k]);
   
        if ((k+1)%colunas == 0 && k != 0){
            printf ("\n");
        }
    }
   
    printf("\n");
}

int buscaElemento (int vet[], int n1, int n2) {

    return vet[((n1-1) * colunas) + (n2-1)];
}


void adicionaElemento (int vet[], int valor, int i, int j){

    vet[((i-1) * colunas) + (j-1)] = valor;
}


void somaMatriz(int vet1[], int vet2[]){

	int k;
	int vetSoma[tamVet];
	
	
	for (k = 0; k < tamVet; k++){
	
		vetSoma[k] = vet1[k] + vet2[k];
	
	}

	imprimeMatriz(vetSoma, linhas, colunas);
}

void produtoMatriz (int vet1[], int vet2[], int vetProd[], int M, int N) {
	int r;
	int m, n;
	
	for (n = 0; n < linhas; n++) {
		for (m = 0; m < colunas; m++){
			vetProd[n * colunas + m] = 0;
			for(r=0; r < N; r++){
				vetProd[n * colunas + m] = (vetProd[n * colunas + m]) + (  (vet1[(n * (colunas)) + r]) * (vet2[ (r * (colunas)) + m])  );
			}
		}
	}
}
// --- Questão 2 ----
void transpostaMatrizSoma(int vet1[], int vet2[]) {
	int M, N;
	int vetTransposta[tamVet];
	zeraMatriz(vetTransposta);
	
	for(M = 0; M<linhas; M++) {
		for(N = 0; N< colunas;N++) {
			vetTransposta[M+colunas * N] = vet1[M * colunas + N] + vet2[M * colunas + N];
		}
	}
	imprimeMatriz(vetTransposta, linhas, colunas);
}

// --- Questão 3 ---
int matrizIndentidade (int vet[], int colunas) {
	int m, n;
	int identidade = 1;
	
	for (m=0; m<colunas; m++){
		for (n=0; n<colunas; n++){
		
			if (m==n){
				if (vet[m * colunas + n] != 1){
					identidade = 0;
					break;
				}
			} else {
				if (vet[m * colunas + n] != 0) {
					identidade = 0;
					break;
				}
			}
		
		}
	}
	return identidade;
}

// Questão 4
int inversaMatriz(int vet1[], int vet2, int N) {
	int vetProd[tamVet];
	produtoMatriz(vet1, vet2, vetProd, linhas, colunas);
	
	int ehIdentidade = matrizIndentidade(vetProd, N);
	return ehIdentidade;
}

void main () {

    linhas = 3;
    colunas = 3;
   
    tamVet = dimensionaMatriz(linhas, colunas);
   
    int vet1[tamVet];
    int vet2[tamVet];
   
    printf("O tamanho dos vetores eh: %d \n\n", tamVet);
   
    zeraMatriz(vet1);
	zeraMatriz(vet2);
   
    printf("A matriz 1 zerada: \n");
    imprimeMatriz(vet1, linhas, colunas);
   
    printf("A matriz 2 zerada: \n");
    imprimeMatriz(vet2, linhas, colunas);
   

    adicionaElemento(vet1, 1, 1, 1);
    //                 valor, i, j
    adicionaElemento(vet1, 1, 2, 2);
    adicionaElemento(vet1, 1, 3, 3);
   
    printf("A matriz diagonal 1 completa: \n");
    imprimeMatriz(vet1, linhas, colunas);
   
   
    adicionaElemento(vet2, 10, 1, 1);
    //                   valor, i, j
    adicionaElemento(vet2, 20, 2, 2);
    adicionaElemento(vet2, 30, 3, 3);
   
    printf("A matriz diagonal 2 completa: \n");
    imprimeMatriz(vet2, linhas, colunas);
   
   
    printf("O elemento que esta na matriz 1 na linha 2 coluna 2 eh: %d \n\n", buscaElemento(vet1, 2, 2));


	printf("Soma de matrizes: \n\n");
	somaMatriz(vet1, vet2);
	
	int vetProd[tamVet];
	produtoMatriz(vet1, vet2, vetProd, linhas, colunas);
	printf("Produto de matrizes: \n");
	imprimeMatriz(vetProd, linhas, colunas);
	
	printf("A matriz transposta da matriz soma eh: \n");
	transpostaMatrizSoma(vet1, vet2);
	
	int ehIdentidade = matrizIndentidade(vet1, colunas);
	
	if(ehIdentidade) {
		printf("A matriz 1 eh uma matriz identidade.\n");	
	} else {
		printf("A matriz 1 nao eh uma matriz identidade.\n");
	}
	
	ehIdentidade = matrizIndentidade(vet2, colunas);
	if(ehIdentidade) {
		printf("A matriz 2 eh uma matriz identidade.\n");	
	} else {
		printf("A matriz 2 nao eh uma matriz identidade.\n");
	}
	
	printf("\n\n");
	
	int inversa = inversaMatriz(vet1, vet2, colunas);
	if(inversa) {
		printf("A matriz 1 é inversa da matriz 2.\n");	
	} else {
		printf("A matriz 1 nao eh inversa da matriz 2.\n");
	}
}
