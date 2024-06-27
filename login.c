#include "structHeader.h"

USER *users;
int usersQuantity = 3;

void defineMemoryForUsers(){
    users = malloc(usersQuantity * sizeof(USER));

    if (users == 0) {
        printf("Falha na alocacao de memoria dos usuarios iniciais.\n");
    }

    // Standard users definition:
    strcpy((users)->login, "berenice");
    strcpy((users)->password, "bere123");
    (users)->type = 1;

    strcpy((users+1)->login, "jorjao");
    strcpy((users+1)->password, "jorje69");
    (users+1)->type = 2;

    strcpy((users+2)->login, "foster");
    strcpy((users+2)->password, "jp1604");
    (users+2)->type = 1;
}

void mainLogin(){
    char hasAccount;

    printf("Vamos logar no sistema!\n");
    printf("Voce ja possui conta (s/n)? ");
    scanf(" %c", &hasAccount);
    clearInputStream();

    if(hasAccount == 'n'){
        createAccount();
    } else {
        login();
    }
}

void login(){
    char userName[12], userPassword[8];

    cleanChat();

    printf("\nDigite seu nome de usuario: ");
    fgets(userName, 12, stdin);
    strtok(userName, "\n");

    printf("Digite a sua senha: ");
    fgets(userPassword, 8, stdin);
    strtok(userPassword, "\n");

    int userPosition = userExists(userName);

    if(userPosition == -1){
        printf("\n usuario nao encontrado, tente novamente!\n");
        sleep(3);
        login();
    }

    int correctPassword = validatePassword(userPassword, userPosition);

    if(correctPassword != 1){
        printf("senha incorreta, tente novamente em alguns instantes!");
        sleep(3);
        login();
    }

    printf("\nLogin realizado com sucesso!\n");
    sleep(3);
}

int userExists(char name[12]){
    // Checks if user exists and return its position
    int userPosition = -1;

    for (int i = 0; i < usersQuantity; i++){
        int comparison = strcmp((users+i)->login, name);

        if (comparison == 0){
            userPosition = i;
            break;
        }
    }
    
    return userPosition;
}

int validatePassword(char password[8], int userPosition){
    if(strcmp((users+userPosition)->password, password) != 0){
        return 0;
    }

    return 1;
}


void createAccount(){
    char newName[12], newPassword[8];

    cleanChat();

    printf("\nDigite um nome de usuario (minimo de 8 caracteres): ");
    fgets(newName, 12, stdin);

    int nameLength = strlen(newName);

    // Validate number of characters
    if ((nameLength - 1) < 8) {
        printf("Menos de 8 caracteres, vamos tentar novamente...");
        sleep(3);
        createAccount();
    }

    // Validate if user already exists
    int userExistence = userExists(newName);

    if(userExistence != -1){
        printf("O usuario ja existe em nosso sistema, por favor, use outro nome");
        sleep(3);
        createAccount();
    }
}
