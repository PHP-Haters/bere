#include "mainHeader.h"

// GLOBAL VARIABLES
float balance;
int comesFromRecords = 0;

void main(){
    setlocale(LC_ALL,"");
    defineMemoryForProducts();
    defineMemoryForClients();
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

// Secao 1:
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
        clientRegister();
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
void clientRegister() {
    clientRegisterMenu();
    redirectClientRegister();
}
void redirectClientRegister(){
    int choiceClientRegister = 0;

    scanf("%d", &choiceClientRegister);

    switch(choiceClientRegister){

    case 1:
        addNewClient();
        break;
    case 2:
        eliminateClient();
        break;
    case 3:
        mainRegister();
        break;
    default:
        mainRegister();
        break;

    }
}
void addNewClient() {
    int returnedValue;
    returnedValue = askNewClient();

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
void eliminateClient() {
    comesFromRecords = 0;
    callClientRecords();
    eliminateChosenClient();
    sleep(2);
    initializeShop();
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


// SECAO 2:
//VENDAS


// SECCAO 3:
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

// SECCAO 4_
// FECHAMENTO DE CAIXA

// SECCAO 5:
// RELATORIOS

void mainRecords() {
    recordsMenu();
    redirectRecords();
}
void redirectRecords() {
    int choiceRecords = 0;

    scanf("%d", &choiceRecords);

    switch(choiceRecords){
    case 1:
        comesFromRecords = 1;
        callClientRecords();
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
void callClientRecords() {
    CLIENT *list = getClients();
    int clients = getClientQuantity();
    clientsRecordsMenu(list, clients);

    if(comesFromRecords == 1) {
        system("pause");
        mainRecords();
    }
}
