#include "headerMain.h"
#include "structHeader.h"

// GLOBAL VARIABLES
float balance;
USER loggedUser;

// GLOBAL FUNCTION
void cleanChat() {
    system("cls || clear");
}

// CLEAR REMAINING CHARACTERS ON INPUT
void clearInputStream() {
    while ( getchar() != '\n' );
}

void updateLoggedUser(USER user){
    strcpy(loggedUser.login, user.login);
    strcpy(loggedUser.password, user.password);
    loggedUser.type = user.type;
}

void main(){
    setlocale(LC_ALL,"");

    // Setting standard memory definitions
    createOrFindFile();
    defineMemoryForClients();
    defineMemoryForUsers();

    mainLogin();

    initializeShop();
}

void initializeShop() {
    cleanChat();
    clearInputStream();
    mainMenu();
}

void mainMenu(){
    cleanChat();
    printf(".________- MERCEARIA DA BERE -_________.\n");
    printf("|                                      |\n");
    printf("| Usuario logado: %s           |\n", loggedUser.login);
    printf("|                                      |\n");
    printf("| 1 > Cadastro                         |\n");
    printf("| 2 > Vendas                           |\n");
    printf("| 3 > Abertura de Caixa                |\n");
    printf("| 4 > Fechamento do Caixa              |\n");
    printf("| 5 > Relatórios                       |\n");
    printf("| 6 > Sair                             |\n");
    printf("|______________________________________|");
    printf("\n");
    printf("Escreva sua escolha (Apenas o último número): ");
    redirectUser();
}

void redirectUser(){

    int choice = 0;
    scanf("%d", &choice);

    switch (choice){
    case 1:
        mainRegister();
        break;
    case 2:
        mainSales();
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

    initializeShop();
}

// SECCAO 3:
// ABERTURA DE CAIXA

void mainCashier(){
    cashierMenu();
}

void cashierMenu(){
    cleanChat();

    printf("._______- ABERTURA DE CAIXA -_______.\n");
    printf("|                                   |\n");
    printf("| 3.1 Abrir o caixa                 |\n");
    printf("| 3.2 Retornar ao Menu Principal    |\n");
    printf("|___________________________________|");
    printf("\n");
    printf("Escreva sua escolha (Apenas o último número): ");

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
    system("cls || clear");
    printf("Digite um saldo para o caixa: ");
    scanf("%d", &balance);

    system("cls || clear");
    printf("Caixa setado com sucesso!");
    sleep(3);

    system("cls || clear");

    initializeShop();
}
