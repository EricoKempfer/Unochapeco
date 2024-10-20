#include <stdio.h>
#include <string.h>

int main() {
    char op1[20], op2[20], op3[20];
    scanf("%s", op1);
    scanf("%s", op2);
    scanf("%s", op3);
    if(strcmp(op1, "vertebrado") == 0) {
        if(strcmp(op2, "ave") == 0) {
            if(strcmp(op3, "carnivoro") == 0) {
                printf("aguia\n");
                return 0;
            }
            else if(strcmp(op3, "onivoro") == 0) {
                printf("pomba\n");
                return 0;
            }
        }
        else if(strcmp(op2, "mamifero") == 0) {
            if(strcmp(op3, "onivoro") == 0) {
                printf("homem\n");
                return 0;
            }
            else if(strcmp(op3, "herbivoro") == 0) {
                printf("vaca\n");
                return 0;
            }
        }
    }
    if(strcmp(op1, "invertebrado") == 0) {
        if(strcmp(op2, "inseto") == 0) {
            if(strcmp(op3, "hematofago") == 0) {
                printf("pulga\n");
                return 0;
            }
            else if(strcmp(op3, "herbivoro") == 0) {
                printf("lagarta\n");
                return 0;
            }
        }
        else if(strcmp(op2, "anelideo") == 0) {
            if(strcmp(op3, "hematofago") == 0) {
                printf("sanguessuga\n");
                return 0;
            }
            else if(strcmp(op3, "onivoro") == 0) {
                printf("minhoca\n");
                return 0;
            }
        }
    }

    return 0;
}
