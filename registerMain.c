#include "registerHeader.h"
// Secao 1:
// CADASTRO
void mainRegister() {
    registerMenu();
}
void registerMenu(){
    cleanChat();

    printf(".__________- CADASTROS -___________.\n");
    printf("|                                  |\n");
    printf("| 1.1 > Cadastro de Usuario        |\n");
    printf("| 1.2 > Cadastro de Clientes       |\n");
    printf("| 1.3 > Cadastro de Produtos       |\n");
    printf("| 1.4 > Retornar ao Menu Principal |\n");
    printf("|__________________________________|");
    printf("\n");
    printf("Escreva sua escolha (Apenas o ultimo numero): ");

    redirectRegister();
}
void redirectRegister(){
    int choiceRegister = 0;

    scanf("%d", &choiceRegister);

    switch(choiceRegister){
    case 1:
        clearInputStream();
        createAccount();
        break;
    case 2:
        clientRegister();
        break;
    case 3:
        productRegister();
        break;
    case 4:
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
}
void clientRegisterMenu(){
    cleanChat();

    printf("._______- CADASTRO DE CLIENTES -_______.\n");
    printf("|                                      |\n");
    printf("| 1.2.1 > Cadastrar cliente            |\n");
    printf("| 1.2.2 > Remover cliente              |\n");
    printf("| 1.2.3 > Retornar ao Menu Cadastros   |\n");
    printf("|______________________________________|");
    printf("\n");
    printf("Escreva sua escolha (Apenas o ultimo numero): ");

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
        printf("Erro ao inserir novo cliente.");
        system("pause");
        mainRegister();
    }
    else {
        printf("Cliente adicionado corretamente!");
        sleep(2);
        mainRegister();
    }
}
void eliminateClient() {
   // callClientRecords();
    eliminateChosenClient();
    sleep(2);
    mainRegister();
}



// SECCAO DO CADASTRO:
// PRODUTOS
void productRegister() {
    productRegisterMenu();

}
void productRegisterMenu(){
    cleanChat();

    printf("._______- CADASTRO DE PRODUTOS -_______.\n");
    printf("|                                      |\n");
    printf("| 1.2.1 > Cadastrar produto no estoque |\n");
    printf("| 1.2.2 > Remover produto do estoque   |\n");
    printf("| 1.2.3 > Retornar ao Menu Cadastros   |\n");
    printf("|______________________________________|");
    printf("\n");
    printf("Escreva sua escolha (Apenas o ultimo numero): ");

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
        printf("Erro ao inserir novo produto.");
        system("pause");
        mainRegister();
    }
    else {
        printf("Produto adicionado corretamente!");
        sleep(2);
        mainRegister();
    }
}
void eliminateProduct() {
    eliminateChosenProduct();
    sleep(2);
    mainRegister();
}


