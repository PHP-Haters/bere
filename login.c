#include "structHeader.h"

static USER *users;
static int usersQuantity = 2;

static void defineMemoryForUsers(){
    users = malloc(usersQuantity * sizeof(USER));

    if (users == NULL) {
        printf("Falha na alocacao de memoria dos usuarios iniciais.\n");
    }

    // Standard users definition:
    strcpy((users)->login, "berenice");
    strcpy((users)->password, "berenice");
    (users)->type = 1;

    strcpy((users+1)->login, "jorjao");
    strcpy((users+1)->password, "jorjao");
    (users+1)->type = 1;
}

static void mainLogin(){
    char hasAccount;

    printf("Vamos logar no sistema!\n");

    printf("Você já possui conta? (s/n)");
    scanf(" %c", &hasAccount);

    if(hasAccount == 'n'){
        createAccount();
    } else {
        login();
    }
}

static int login(){
    char userName[12], userPassword[8];

    system("cls || clear");

    printf("\nDigite seu nome de usuario: ");
    scanf("%s", userName);

    printf("\nDigite a sua senha: ");
    scanf("%s", userPassword);

    int credentialsChecked = checkCredentials(userName, userPassword);

    if(credentialsChecked == 1){
        return 1;
    } else {
        printf("Credenciais incorretas! Por favor tente novamente em alguns instantes.");
        sleep(3);
        login();
    }
}

static int checkCredentials(char name[12], char password[8]){
    int userPosition;

    // Find user with provided name
    for (int i = 0; i < usersQuantity; i++){
        if (strcmp((users+i)->login, name) == 0){
            userPosition = i;
        } else {
            printf("\nUsuário não encontrado!\n");
            return 0;
        }
    }

    // Check password
    if(strcmp((users+userPosition)->password, password) != 0){
        return 0;
    }

    return 1;
}
