#include <stdio.h>
#include <windows.h>
#include<conio.h>

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
		return;
	}
	char linha[MAX_LETRAS];
	while(fgets(linha,sizeof(linha),arquivo) != NULL && qtdLinhas < MAX_LINHAS){
		linha[strcspn(linha,"\n")] = '\0';
		if(qtdLinhas > 0){
			sscanf(linha,"%49[^,],%d,%f",
			pro[qtdLinhas - 1].nome,
			&pro[qtdLinhas - 1].quantidade,
			&pro[qtdLinhas - 1].preco
			);
		}
				qtdLinhas++;
	}
	fclose(arquivo);
	
	printf("%-15s %-12s %-15s %-15s\n", "Nome", "Quantidade", "Preço", "Valor total");
	for(int i = 0; i < qtdLinhas - 1; i++){
		pro[i].valor = pro[i].quantidade * pro[i].preco;
		printf("%-15s %-12d %-15.2f %-15.2f\n",pro[i].nome, pro[i].quantidade, pro[i].preco, pro[i].valor);
	}
	getch();
}