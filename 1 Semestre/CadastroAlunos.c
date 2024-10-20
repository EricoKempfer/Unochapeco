#include <stdio.h>

typedef struct{
        char nome[20];
        int idade;
        float nota;
    } infoPessoas;

int cadastrarPessoa(infoPessoas*a){
    printf("Nome: ");
    scanf("%19s", a->nome);
    printf("Idade: ");
    scanf("%d", &a->idade);
    printf("Nota: ");
    scanf("%f", &a->nota);
}
int exibirAlunos(infoPessoas a){
    printf("Nome: %s\n",a.nome);
    printf("Idade: %d\n",a.idade);
    printf("Nota: %f\n",a.nota);
}

int main()
{
    int tam=3;
    float somaNotas = 0.0;
    
    infoPessoas pessoas[tam];
    
    for(int i=0; i<tam;i++){
        cadastrarPessoa(&pessoas[i]);
        somaNotas += pessoas[i].nota;
        printf("\n");
    }
    for(int i=0;i<tam;i++){
        exibirAlunos(pessoas[i]);
        printf("\n");
    }
    printf("Média das notas: %f", somaNotas/3);

    return 0;
}
