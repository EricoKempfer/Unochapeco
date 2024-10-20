#include <stdio.h>
int main()
{
    int v[5], i, numero,numeroatras;
    for(i=0;i<5;i++){
        scanf("%d", &v[i]);
        
    }
    
    for(i=1;i<5;i++){
        numero = v[i];
        numeroatras = i-1;
        while(numeroatras>=0 && v[numeroatras]>numero){
            v[numeroatras+1]=v[numeroatras];
            numeroatras=numeroatras-1;
        }
        v[numeroatras+1] = numero;
    }
    for(i=0;i<5;i++){
        printf("%d\n", v[i]);
    }
    
    return 0;
}
