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

    strcpy((users+1)->login, "jorjao01");
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
    sleep(1);
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
    char newName[12], newPassword[8], proceed;

    while (1){
        cleanChat();

        // Ask for new user name
        printf("\nDigite um nome de usuario (de 8 a 12 caracteres): ");
        fgets(newName, 12, stdin);
        strtok(newName, "\n");

        int nameLength = strlen(newName);
        int userExistence = userExists(newName);

        // Validate number of characters and if there is an user using this name
        if (nameLength >= 8 && userExistence == -1) {
            break;
        } else {
            printf("\nNome invalido, vamos tentar novamente\n");
            sleep(3);
        }
    }

    while (1){
        // Ask for a new password
        printf("Digite uma senha (de 6 a 8 caracteres): ");
        fgets(newPassword, 8, stdin);
        strtok(newPassword, "\n");

        // Validating password length
        int passwordLength = strlen(newPassword);

        if(passwordLength < 6){
            printf("\nNumero de caracteres invalido na senha, vamos tentar novamente\n");
            sleep(3);
        } else {
            break;
        }
    }

    // Add new credentials to the Users array
    usersQuantity++;

    USER *temp = realloc(users, usersQuantity * sizeof(USER)); // Realloc memory for new user

    // Catch errors during memory realocation
    if (temp == 0) {
        printf("Falha na realocção de memória do novo usuario.\n");
        free(temp);
    }

    users = temp; // Filling the clients array with new block of memory

    // Copying new user data to the last position of user's array
    strcpy((users+(usersQuantity-1))->login, newName);
    strcpy((users+(usersQuantity-1))->password, newPassword);
    (users+(usersQuantity-1))->type = 2;

    printf("\nNovo usuario criado com sucesso!");

    // Ask if user wants to log in right now
    clearInputStream();
    printf("\nDeseja fazer login no sistema (s/n)? ");
    scanf("%c", &proceed);

    if(proceed == 's'){
        clearInputStream();
        login();
    }
}

void listUsers(){
    for (int i = 0; i < usersQuantity; i++){
        printf("\nUser %d", i);
        printf("\nUsername (login): %s", (users+i)->login);
        printf("\nUser type (1:admin, 2:client): %d", (users+i)->type);
        printf("\n");
    }
}
