#include <stdio.h>
#include "Funcoes.h"


int main(){
    int opcao, contador;
    sugestoeseditar();
    
    printf("=============================\n");
    printf("Sistema de Cadastro de Filmes\n");
    printf("=============================\n\n");
    
    do{
        opcao = menu();
        switch(opcao){
            
            case 0:
            printf("O sistema foi finalizado");
            break;
            
            case 1:
            contador=adicionar(); //contador para adicionar vários filmes
            break;
            
            case 2:
            listar();
            break;
            
            case 3:
            editar();
            break;
            
            case 4:
            remover();
            break;
            
            case 5:
            sugestoes();
            break;
            
            default:
            printf("Número invalido");
            break;
            
        }
        printf("\n");
    } while(opcao != 0);
    
    return 0;
}
