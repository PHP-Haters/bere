#include "mainHeader.h"

void main(){
    setlocale(LC_ALL,"");
    defineMemoryForProducts();
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
        mainRegister();
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

// Seccao:
// CADASTRO
void mainRegister() {
    registerMenu();
    redirectRegister();
}

void redirectRegister(){
    int choiceRegister = 0;

    scanf("%d", &choiceRegister);

    switch(choiceRegister){

    case 1:
        //cadastro de clientes
        break;
    case 2:
        productRegister();
        break;
    case 3:
        inicializeShop();
        break;
    default:
        mainRegister();
        break;

    }
}

// SECCAO DO CADASTRO:
// PRODUTOS
void productRegister() {
    productRegisterMenu();
    redirectProductRegister();
}
void redirectProductRegister(){
    int choiceProductRegister = 0;

    scanf("%d", &choiceProductRegister);

    switch(choiceProductRegister){

    case 1:
        addNewProduct();
        break;
    case 2:
        //eliminacao de produtos
        break;
    case 3:
        mainRegister();
        break;
    default:
        mainRegister();
        break;

    }
}
void addNewProduct() {
    askNewProduct();
}
void eliminateProduct() {
    askNewProduct();
}

