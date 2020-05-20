#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define tam 8

typedef struct{
    int dado[tam];
    int ultimo;
}PILHA;

PILHA p1;
PILHA p2;
int op = 1;

int main(){
    setlocale(LC_ALL, "portuguese");
    while (op != 0){
        mostrar_menu();
        scanf("%i", &op);
        system("cls");

        switch(op){
            case 1: inserir(); inverter_pilha();
            break;
            case 0: system("cls"); printf("\nPROGRAMA FINALIZADO!\n\n");
            break;
        }
    }


return 0;
}

void mostrar_menu(){
    printf(" RA: ");
        mostrar_pilha(p1);
    printf("\n RA invertido: ");
        mostrar_pilha(p2);
    printf("\n--------------------------------------------\n");
    printf("\n1- Informar RA     0- Sair\n");
}

void inserir(){
    for (int i = 0; i<tam; i++){
        printf("Informe seu RA: ");
        if (i>0) mostrar_pilha(p1);
        scanf("%1i", &p1.dado[i]);
        p1.ultimo = i;
        system("cls");


    }
    system("cls");

}

void inverter_pilha(){
        if (p1.ultimo < tam-1)
            printf("RA incompleto!");

        else{
            for (int i = 0; i < tam; i++){
                p2.dado[i] = p1.dado[tam - 1 - i];
                p2.ultimo = i;
            }

        }
}

void mostrar_pilha(PILHA p){

    for (int i = 0; i<=p.ultimo; i++){
        printf("%i ", p.dado[i]);
    }
    printf("\n");
}


