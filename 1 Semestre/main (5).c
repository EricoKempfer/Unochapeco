#include <stdio.h>
char v[3][3] = {'1','2','3','4','5','6','7','8','9'};
int i, j, jogadorX, jogadorO, posicao;
char valor;

int imprimirTabuleiro(){
    printf("%c | %c | %c\n", v[0][0],v[0][1],v[0][2]);
    printf("--+---+---\n");
    printf("%c | %c | %c\n", v[1][0],v[1][1],v[1][2]);
    printf("--+---+---\n");
    printf("%c | %c | %c\n\n", v[2][0],v[2][1],v[2][2]);
    return 0;
}

int mudarPosicao(int posicao){
    switch (posicao){
    
    case 1 :
    v[0][0] = valor;
    break;
    
    case 2 :
    v[0][1] = valor;
    break;
    
    case 3 :
    v[0][2] = valor;
    break;
    
    case 4 :
    v[1][0] = valor;
    break;
    
    case 5 :
    v[1][1] = valor;
    break;
    
    case 6 :
    v[1][2] = valor;
    break;
    
    case 7 :
    v[2][0] = valor;
    break;
    
    case 8 :
    v[2][1] = valor;
    break;

    case 9 :
    v[2][2] = valor;
    break;
    
    default :
    printf ("Valor invalido!\n");
    return 0;
  }
}
int main()
{
    imprimirTabuleiro();
    for(i=0;i<9;i++){
        if(i%2==0){
        valor = 'X';
        printf("Vez do Jogador X: \n");
        scanf("%d", &posicao);
        mudarPosicao(posicao);
        imprimirTabuleiro();
        } else {
        valor = 'O';
        printf("Vez do Jogador Y: \n");
        scanf("%d", &posicao);
        mudarPosicao(posicao);
        imprimirTabuleiro();
        }
    }

    return 0;
}

