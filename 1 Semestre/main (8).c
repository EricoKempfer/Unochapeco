#include <stdio.h>
#include <string.h>  

#define MAX_DESCRICAO 256 

int main() {
    FILE *arquivo; 
    char descricao[50];
    
    printf("Digite a descrição da transação financeira: ");
    fgets(descricao, sizeof(descricao), stdin);

    arquivo = fopen("transacoes.txt", "a");
    
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;  
    }
    
    fprintf(arquivo, "%s\n", descricao);
    fclose(arquivo);  

    arquivo = fopen("transacoes.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para leitura.\n");
        return 1;  
    }

    printf("Transações registradas:\n");
    while (fgets(descricao, sizeof(descricao), arquivo) != NULL) {
        printf("%s", descricao); 
    }
    fclose(arquivo);  

    return 0; 
}