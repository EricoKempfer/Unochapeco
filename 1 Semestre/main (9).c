#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARQUIVO_DADOS "cadastro_pessoas.dat"

typedef struct {
    int cod;
    char nome[50];
    char sexo;
    int idade;
} Pessoa;

Pessoa pessoas[100]; // Vetor para armazenar as pessoas (máximo de 100 pessoas)
int contador = 0; // Contador para o número de pessoas cadastradas

int menu();
void carregar_dados();
void salvar_dados();
void cadastrar();
void editar();
void deletar();
void exibir();

int main() {
    int opcao;

    carregar_dados();  // Carrega dados do arquivo ao iniciar o programa
    
    printf("=============================\n");
    printf("Cadastro de Pessoas\n");
    printf("=============================\n\n");
    
    do {
        opcao = menu();
        switch(opcao) {
            case 0:
                printf("O sistema foi finalizado\n");
                salvar_dados();  // Salva os dados ao finalizar o programa
                break;
            
            case 1:
                cadastrar();
                salvar_dados();  // Salva os dados após cada cadastro
                break;
            
            case 2:
                editar();
                salvar_dados();  // Salva os dados após cada edição
                break;
            
            case 3:
                exibir();
                break;
            
            case 4:
                deletar();
                salvar_dados();  // Salva os dados após deletar uma pessoa
                break;
            
            default:
                printf("Número inválido\n");
                break;
        }
        printf("\n");
    } while (opcao != 0);
    
    return 0;
}

int menu() {
    int opcao;
    
    printf("1 - Cadastrar Pessoa\n");
    printf("2 - Editar Pessoa\n");
    printf("3 - Exibir Pessoas\n");
    printf("4 - Deletar Pessoa\n");
    printf("0 - Finalizar o sistema\n");
    printf("\nSua opção = ");
    scanf("%d", &opcao);
    return opcao;
}

void carregar_dados() {
    FILE *arquivo = fopen(ARQUIVO_DADOS, "rb");
    if (arquivo == NULL) {
        printf("Nenhum cadastro anterior encontrado.\n");
        return;
    }

    // Lê os dados do arquivo para a memória
    while (fread(&pessoas[contador], sizeof(Pessoa), 1, arquivo)) {
        contador++;
    }

    fclose(arquivo);
}

void salvar_dados() {
    FILE *arquivo = fopen(ARQUIVO_DADOS, "wb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para salvar os dados!\n");
        return;
    }

    // Escreve todas as pessoas cadastradas no arquivo
    for (int i = 0; i < contador; i++) {
        fwrite(&pessoas[i], sizeof(Pessoa), 1, arquivo);
    }

    fclose(arquivo);
}

void cadastrar() {
    Pessoa nova_pessoa;
    nova_pessoa.cod = contador + 1;  // Código da pessoa é baseado no contador

    printf("Nome: ");
    getchar(); // Limpar o buffer
    fgets(nova_pessoa.nome, 50, stdin);
    nova_pessoa.nome[strcspn(nova_pessoa.nome, "\n")] = 0; // Remover nova linha

    printf("Sexo (m/f): ");
    scanf("%c", &nova_pessoa.sexo);

    printf("Idade: ");
    scanf("%d", &nova_pessoa.idade);

    pessoas[contador] = nova_pessoa;
    contador++;
    printf("Pessoa cadastrada com sucesso!\n");
}

void exibir() {
    if (contador == 0) {
        printf("Nenhuma pessoa cadastrada.\n");
        return;
    }

    for (int i = 0; i < contador; i++) {
        printf("Código: %d\n", pessoas[i].cod);
        printf("Nome: %s\n", pessoas[i].nome);
        printf("Sexo: %c\n", pessoas[i].sexo);
        printf("Idade: %d\n", pessoas[i].idade);
        printf("------------------------\n");
    }
}

void editar() {
    int codigo, encontrado = -1;
    printf("Digite o código da pessoa que deseja editar: ");
    scanf("%d", &codigo);

    for (int i = 0; i < contador; i++) {
        if (pessoas[i].cod == codigo) {
            encontrado = i;
            break;
        }
    }

    if (encontrado == -1) {
        printf("Pessoa com código %d não encontrada.\n", codigo);
        return;
    }

    printf("Editando a pessoa de código %d:\n", codigo);

    printf("Novo nome: ");
    getchar(); // Limpar o buffer
    fgets(pessoas[encontrado].nome, 50, stdin);
    pessoas[encontrado].nome[strcspn(pessoas[encontrado].nome, "\n")] = 0; // Remover nova linha

    printf("Novo sexo (m/f): ");
    scanf("%c", &pessoas[encontrado].sexo);

    printf("Nova idade: ");
    scanf("%d", &pessoas[encontrado].idade);

    printf("Pessoa editada com sucesso!\n");
}

void deletar() {
    int codigo, encontrado = -1;
    printf("Digite o código da pessoa que deseja deletar: ");
    scanf("%d", &codigo);

    for (int i = 0; i < contador; i++) {
        if (pessoas[i].cod == codigo) {
            encontrado = i;
            break;
        }
    }

    if (encontrado == -1) {
        printf("Pessoa com código %d não encontrada.\n", codigo);
        return;
    }

    // Remover a pessoa do array, deslocando os elementos subsequentes
    for (int i = encontrado; i < contador - 1; i++) {
        pessoas[i] = pessoas[i + 1];
    }

    contador--; // Diminuir o número de pessoas cadastradas
    printf("Pessoa com código %d deletada com sucesso!\n", codigo);
}

