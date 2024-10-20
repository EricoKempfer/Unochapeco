#include <stdio.h>
int main() {
 
    int trocoreal[] = {10000, 5000, 2000, 1000, 500, 200};
    int trococent[] = {100, 50, 25, 10, 05, 01};
    int real, cent, i;
    int valor;
    
    scanf("%d.%d", &real, &cent);
    valor = (real*100)+cent;
    printf("NOTAS:\n");
    for(i=0;i<6;i++){
        printf("%d nota(s) de R$ %.2lf\n", valor/trocoreal[i], trocoreal[i]/100.0);
        valor %= trocoreal[i];
    }
    printf("MOEDAS:\n");
    for(i=0;i<6;i++){
        printf("%d moeda(s) de R$ %.2lf\n", valor/trococent[i], trococent[i]/100.0);
        valor %= trococent[i];
    }

    return 0;
}

