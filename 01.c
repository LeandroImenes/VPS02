#include <stdio.h>
#include <windows.h>

#define MAX_LETRAS 100
#define MAX_LINHAS 50

struct produto{
	char nome[50];
	int quantidade;
	float preco;
	float valor;
};

void main(){
	SetConsoleOutputCP(CP_UTF8);
	int qtdLinhas = 0;
	struct produto pro[MAX_LINHAS];
	FILE *arquivo = fopen("vendas.csv","r");
	if(arquivo == NULL){
		printf("Arquivo não encontrado.\n");
		getch();
		return 0;
	}
	char linha[MAX_LETRAS];
	while(fgets(linha,sizeof(linha),arquivo) != NULL && qtdLinhas < MAX_LINHAS){
		linha[strcspn(linha,"\n")] = '\0';
		qtdLinhas++;
		if(qtdLinhas > 1){
			sscanf(linha,"%49[^,],%d,%f\n,f\n]",
			pro[qtdLinhas - 2].nome,
			pro[qtdLinhas - 2].quantidade,
			&pro[qtdLinhas - 2].preco,
			&pro[qtdLinhas - 2].valor
			);
		}
	}
	fclose(arquivo);
	
	for(int i = 0; i < qtdLinhas - 1; i++){
		printf("Nome\tQuantidade\tPreço unitário\tValor total\n");
		printf("%s\t%d\t%f\t%f\n",pro[i].nome, pro[i].quantidade, pro[i].preco, pro[i].valor);
	}
	getch();
}