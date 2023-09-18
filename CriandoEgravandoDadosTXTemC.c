/*criando um arquivo txt e gravando dados*/
#include<stdio.h>
int main(){
	//criando a variavel do ponteiro para o arquivo.
	FILE*pont_arq;
	char palavra[50];
	//abrindo o arquivo variavel A para gravar varias palavras e W para substituir.
	pont_arq=fopen("arquivoGravando.txt","w");
	//testando se o arquivo foi criado.
	if(pont_arq==NULL){
		printf("Erro na abertura do arquivo");
	}
	else{
	printf("Escreva uma palavra para gravar no arquivo\n");
	gets( palavra );
	//armazenando a string no arquivo com fprintf.
	fprintf(pont_arq,"%s ",palavra);
	//fechando o arquivo.
	fclose(pont_arq);
	//printando o reultado.
	printf("Dados gravados com sucesso");
	}
	getch();
	return 0;
}
