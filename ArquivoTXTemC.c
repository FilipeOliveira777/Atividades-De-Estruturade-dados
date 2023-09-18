/*criando um arquivo txt
*/
#include<stdio.h>
int main(){
	//criando a variavel do ponteiro para o arquivo.
	FILE*pont_arq;
	//abrrindo o arquivo.
	pont_arq=fopen("arquivo.txt","a");
	//fechando o arquivo.
	fclose(pont_arq);
	
	//printando o reultado.
	printf("O arquivo foi criado com sucesso");
	getch();
	return 0;
}
