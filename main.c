#include "mainHeader.h"

// GLOBAL VARIABLES
float balance;

void main(){
    setlocale(LC_ALL,"");
    defineMemoryForProducts();
    initializeShop();
}

void initializeShop() {
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
        mainCashier();
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
        initializeShop();
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
        initializeShop();
        break;
    default:
        mainRegister();
        break;
    }
}


// SECCAO DO CADASTRO:
// CLIENTES



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
        eliminateProduct();
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
    int returnedValue;
    returnedValue = askNewProduct();

    if(returnedValue == 1) {
        printf("Aconteceu algum erro na hora de inserir o novo produto.");
        system("pause");
        initializeShop();
    }
    else {
        printf("Produto adicionado corretamente!");
        sleep(2);
        initializeShop();
    }
}
void eliminateProduct() {
    eliminateChosenProduct();
    printf("Produto eliminado corretamente!");
    sleep(2);
    initializeShop();
}


// SECCAO
//VENDAS


// SECCAO
// ABERTURA DE CAIXA

void mainCashier(){
    cashierMenu();
    redirectCashier();
}

void redirectCashier(){
    int choice = 0;

    scanf("%d", &choice);

    switch (choice){
    case 1:
        openCashier();
        break;
    case 2:
        initializeShop();
        break;
    default:
        printf("Digite uma opção válida!");
        sleep(2);
        mainCashier();
        break;
    }
}

void openCashier(){
    system("cls");
    printf("Digite um saldo para o caixa: ");
    scanf("%d", &balance);

    system("cls");
    printf("Caixa setado com sucesso!");
    sleep(3);

    system("cls");

    initializeShop();
}

// SECCAO
// FECHAMENTO DE CAIXA

//SECCAO
//RELATORIOS

void productRecords() {

}