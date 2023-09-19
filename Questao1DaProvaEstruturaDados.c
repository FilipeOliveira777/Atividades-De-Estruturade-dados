#include<stdio.h>


int linhasVet1 = 3;
int colunasVet1 = 2;

int linhasVet2 = 2;
int colunasVet2 = 3;



int dimensionaMatriz (int n1, int n2){
    return n1*n2;
}

void imprimeMatriz (int vet[], int linhas, int colunas){
    int k; 
    
    for (k=0; k < (linhas*colunas); k++){
        printf ("%4d ", vet[k]);
        if ((k+1) % colunas == 0 && k != 0){
            printf ("\n");
        }
    } 
    
    printf("\n");
}


void adicionaElemento (int vet[], int colunas, int valor, int i, int j){
    vet[((i-1) * colunas) + (j-1)] = valor;
}


void produtoMatriz (int vet1[], int vet2[], int M, int N) {
	int vetProd[linhasVet1 * colunasVet2];
	int r;
	int m, n;
	
	for (n=0; n<linhasVet1; n++){
		for (m=0; m < colunasVet2; m++){
			vetProd[n * colunasVet2 + m] = 0;
			for(r=0; r < N; r++){
				vetProd[n * colunasVet2 + m] = (vetProd[n * colunasVet2 + m]) + ((vet1[(n * (colunasVet1)) + r]) * (vet2[ (r * (colunasVet2)) + m]));
			}
		}
	}
	
	
	
	imprimeMatriz(vetProd, 3, 3);

}

// QUESTÃO  1  ---------------------------------------------------------------------------------------
//   3x2
void main () {
	int tamVet1 = dimensionaMatriz(linhasVet1, colunasVet1);
	int tamVet2 = dimensionaMatriz(linhasVet2, colunasVet2);
	
	int vet1[tamVet1];
	int vet2[tamVet2];


	adicionaElemento(vet1, colunasVet1, 1, 1, 1);
	adicionaElemento(vet1, colunasVet1, 2, 1, 2);

    adicionaElemento(vet1, colunasVet1, 3, 2, 1);
    adicionaElemento(vet1, colunasVet1, 4, 2, 2);
   
    adicionaElemento(vet1, colunasVet1, 5, 3, 1);
    adicionaElemento(vet1, colunasVet1, 6, 3, 2);


	adicionaElemento(vet2, colunasVet2, 1, 1, 1);
	adicionaElemento(vet2, colunasVet2, 2, 1, 2);
	adicionaElemento(vet2, colunasVet2, 3, 1, 3);

    adicionaElemento(vet2, colunasVet2, 4, 2, 1);
    adicionaElemento(vet2, colunasVet2, 5, 2, 2);
    adicionaElemento(vet2, colunasVet2, 6, 2, 3);
   
	printf("MATRIZ 1: \n");
	imprimeMatriz(vet1, 3, 2);
	
	printf("MATRIZ 2: \n");
	imprimeMatriz(vet2, 2, 3);
	
	int vetProd[linhasVet1];
	
	printf("MATRIZ 1 x MATRIZ 2: \n");
	produtoMatriz(vet1, vet2, linhasVet1, linhasVet2);


getch();


}
