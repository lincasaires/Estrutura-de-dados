#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define tam 8

typedef struct{
    int dado[tam];
    int topo;
}PILHA;

PILHA p1;
PILHA p2;

int ra[tam] = {1,9,8,6,3,5,8,5};
int op = 1;

int main(){
    setlocale(LC_ALL, "portuguese");
    iniciar_pilhas();
    while (op != 0){
        mostrar_menu();
        scanf("%i", &op);
        system("cls");

        switch(op){
            case 1: iniciar_pilhas();
            break;
            case 2: desempilhar();
            break;
            case 3: desempilhar_tudo();
            break;
            case 4: inserir();
            break;
            case 0: system("cls"); printf("\nPROGRAMA FINALIZADO!\n\n");
            break;
        }
    }

return 0;
}
void menu_select(int opt){

}

void mostrar_menu(){
    printf(" Pilha RA: ");
        mostrar_pilha(p1);
    printf("\n Pilha RA invertido: ");
        mostrar_pilha(p2);
    printf("\n--------------------------------------------\n");
    printf("\n1- Reiniciar RA     2- Desempilhar      3- Desempilhar Tudo    4- Novo RA    0- Sair\n");
}

void inserir(){
    for (int i = 0; i<tam; i++){
        printf("Informe seu RA: ");
        scanf("%1i", &p1.dado[i]);
        p1.topo = i;
        system("cls");
    }
    for (int i = 0; i < tam; i++){
        p2.dado[i] = 0;
    }
    p2.topo = 0;
    system("cls");
}

void desempilhar(){
    if (p1.topo < 0)
        printf("\n  Pilha Vazia!\n................\n");
    else{
    p2.dado[p2.topo] = p1.dado[p1.topo];
    p2.topo += 1;
    p1.dado[p1.topo] = 0;
    p1.topo -= 1;
    }
}
void desempilhar_tudo(){
    while (p1.topo >= 0)
        desempilhar();
}

void mostrar_pilha(PILHA p){
    for (int i = 0; i< tam; i++){
        printf("%i ", p.dado[i]);
    }
    printf("\n");
}

void iniciar_pilhas(){
    for (int i = 0; i < tam; i++){
        p1.dado[i] = ra[i];
        p2.dado[i] = 0;
    }
    p1.topo = tam -1;
    p2.topo = 0;
}
