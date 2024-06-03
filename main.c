#include "mainHeader.h"

void main(){
    inicializeShop();
}

void inicializeShop() {
    mainMenu();
    redirectUser();

}

void redirectUser(){

    int choice = 0;

    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        cadastro();
        break;
    case 2:
        //adicionar vendas
        break;
    case 3:
        //adicionar abertura de caixa
        break;
    case 4:
        //adicionar fechamento de caixas
        break;
    case 5:
        //adicionar relatorios
        break;
    case 6:
        //adicionar sair
        break;
    default:
        inicializeShop();
        break;
    }
}


void cadastro() {
    menuCadastros();
}

void redirectCadastro(){

    int choiceCadastro = 0;

    switch(choiceCadastro){

    case 1:
        //cadastro de clientes
        break;
    case 2:

        break;
    case 3:
        inicializeShop();
        break;
    default:
        cadastro();
        break;

    }

}
