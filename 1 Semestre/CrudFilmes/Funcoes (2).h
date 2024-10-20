#define qtde 50

#include "Structs.h"
#include <string.h>

struct filmes filme[qtde]; // Filmes que o usuario digita
struct filmes sugestao[qtde];

int contador;
int contadorsugestao;

//opções do usuário
int menu(){
    int opcao;
    printf("1 - Adicionar filmes\n");
    printf("2 - Listar filmes cadastrados\n");
    printf("3 - Editar filmes\n");
    printf("4 - Remover filmes \n");
    printf("5 - Sugestões filmes\n");
    printf("\n0 - Finalizar o sistema\n");
    printf("\nSua opção = ");
    scanf("%d", &opcao);
    return opcao;
}
void leString(char stringLiga[], int max){
    int i = 0;
    char letra;

    for (i = 0; i < (max - 1); i++) {
        letra = fgetc(stdin);
        if ((letra == '\n') && (i == 0)) {
            i = i - 1;
            continue;
        }

        if (letra == '\n') break;
        
        stringLiga[i] = letra;
    }

    /* Finaliza a string */
    stringLiga[i] = '\0';
}

int adicionar(){
  
    printf("\nDigite o nome do filme: ");
    leString(filme[contador].nome,20);
    printf("Digite a categoria do filme: ");
    scanf("%s", filme[contador].categoria);
    printf("Digite a duração do filme (horas.minutos): ");
    scanf("%d.%d", &filme[contador].horas, &filme[contador].minutos);
    filme[contador].cod = contador; //cod recebe o cod anterior + 1
    contador++;
    return contador;
}

int listar(){
    printf("\nCódigo\t|\tNome\t|\tCategoria\t|\tDuração\n");
    printf("--------------------------------------------------------------------------\n");
    for(int i=0; i<contador;i++){ //Exibe todos as variáveis de todos os filmes
        if(filme[i].minutos != 999){
            printf("%d\t|\t%s\t|\t%s\t\t|\t%d:%d\n", filme[i].cod, filme[i].nome, filme[i].categoria, filme[i].horas, filme[i].minutos);
        }
    }
}

int editar(){
    int posicaoeditar;
    printf("Digite o código do filme que deseja editar: ");
    scanf("%d", &posicaoeditar);
    printf("\nDigite o novo nome do filme: ");
    leString(filme[posicaoeditar].nome,20);
    printf("Digite a categoria do filme: ");
    scanf("%s",filme[posicaoeditar].categoria);
    printf("Digite a duração do filme (horas.minutos): ");
    scanf("%d.%d", &filme[posicaoeditar].horas, &filme[posicaoeditar].minutos);
}

void remover(){
    int posicaoremover;
    printf("Digite o código do filme para remover: ");
    scanf("%d", &posicaoremover);
    filme[posicaoremover].minutos = 999; //Comando para não dar printf na lista
}

int sugestoeseditar(){ 
    
    contadorsugestao=3;
    
    strcpy(sugestao[0].nome,"Titanic    ");
    strcpy(sugestao[0].categoria,"Romance    ");
    sugestao[0].horas = 3;
    sugestao[0].minutos = 14;
    
    strcpy(sugestao[1].nome,"Jurassic World");
    strcpy(sugestao[1].categoria,"Ação      ");
    sugestao[1].horas = 2;
    sugestao[1].minutos = 10;
    
    strcpy(sugestao[2].nome,"Barbie       ");
    strcpy(sugestao[2].categoria,"Fantasia");
    sugestao[2].horas = 1;
    sugestao[2].minutos = 54;
}

int sugestoes(){
    printf("\nNome\t\t|\tCategoria\t|\tDuração\n");
    printf("--------------------------------------------------------------------------\n");
    for(int i=0; i<contadorsugestao; i++){ //Exibe todos as variáveis de todos os filmes
        printf("%s\t|\t%s\t|\t%d:%d\n", sugestao[i].nome, sugestao[i].categoria, sugestao[i].horas, sugestao[i].minutos);
    }
}
