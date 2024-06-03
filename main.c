#include "mainHeader.h"

// GLOBAL VARIABLES
float balance;
int comesFromRecords = 0;
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
        mainRecords();
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
    comesFromRecords = 0;
    callProductRecords();
    eliminateChosenProduct();
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

void mainRecords() {
    recordsMenu();
    redirectRecords();
}

void redirectRecords() {
    int choiceRecords = 0;

    scanf("%d", &choiceRecords);

    switch(choiceRecords){
    case 1:
        //relatorio de clientes
        break;
    case 2:
        comesFromRecords = 1;
        callProductRecords();
        break;
    case 3:
        mainRecords();
        break;
    default:
        initializeShop();
        break;
    }
}
void callProductRecords() {
    PRODUCT *list = getProducts();
    int products = getProductQuantity();
    productRecordsMenu(list, products);

    if(comesFromRecords == 1) {
        system("pause");
        mainRecords();
    }
}
