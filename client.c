#include "structHeader.h"

static CLIENT *clients;
static int quantityClients = 3;

// retorna o punteiro relacionado a lista de produtos
static * getClients() {
    return clients;
}

static int getClientQuantity() {
    return quantityClients;
}

// definicao de espaco de memoria
static void defineMemoryForClients() {
    //definicao de memoria da lista de produtos

    clients = malloc(quantityClients * sizeof(CLIENT));

    // SEM ESTE PRINTF NAO FUNCIONA NADA. NAO SEI PORQUE. VOU COMETER SUICIDIO. CARALHO.
    // printf("sssss");
    if (clients == 0 ) {
       printf("Falha na alocacao de memoria inicial.\n");
    }

    //definicao de valores default: 1 de cada loja.
    (clients)->code = 1;
    strcpy((clients)->name, "Caio Caleb Ramos");
    strcpy((clients)->socialName, "Betina");
    (clients)->cpf = 12332112;
    strcpy((clients)->address, "Rua Cinco, 112");
    strcpy((clients)->neighborhood, "Centro Politico Adm.");
    (clients)->cellphone = 0422400;

    (clients+1)->code = 2;
    strcpy((clients+1)->name, "Maite Evelyn Bernardes");
    strcpy((clients+1)->socialName, "Maimai");
    (clients+1)->cpf = 98636627;
    strcpy((clients+1)->address, "Alameda Mutum, 69");
    strcpy((clients+1)->neighborhood, "Coqueiro");
    (clients+1)->cellphone = 822275;

    (clients+2)->code = 3;
    strcpy((clients+2)->name, "Benjamin Claudio Assuncao");
    strcpy((clients+2)->socialName, "Ben 10");
    (clients+2)->cpf = 9607006;
    strcpy((clients+2)->address, "Rua Parime, 192");
    strcpy((clients+2)->neighborhood, "Sao Vicente");
    (clients+2)->cellphone = 8330752;
}

static void readFileClient(FILE *filePointer) {

    CLIENT *aux = malloc(1 * sizeof(CLIENT));

    filePointer = fopen("clientDatabase.bin", "rb");
    int i = 1;
    int quantityRead = 0;
    while(! feof(filePointer)) {

        quantityRead = fread(aux, sizeof(CLIENT), i, filePointer);
        i++;
        CLIENT *temp = realloc(aux, (i) * sizeof(CLIENT));
        aux = temp;
    }
    quantityClients = quantityRead;
    defineMemoryForClients();
    if(quantityRead > 0) {
        clients = aux;
    }

}
static void createOrFindFileClient() {

    FILE *filePointer = fopen("clientDatabase.bin", "ab");

    if(filePointer == 0) {
        printf("Arquivo nao encontrado; impossivel cria-lo (Produtos)");
    }
    fclose(filePointer);

    readFileClient(filePointer);
}

// adiciona o novo produto dentro da lista de produtos
static int addClient(CLIENT * newClient) {
    quantityClients++;

    CLIENT *temp = realloc(clients, quantityClients * sizeof(CLIENT));
    FILE *file;

    file = fopen("clientDatabase.bin", "ab");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    if (temp == 0) {
       printf("Falha na realocção de memoria.\n");
       free(temp);
       return 1;
    }

    clients = temp;

    strcpy((clients+(quantityClients-1))->name, newClient->name);
    strcpy((clients+(quantityClients-1))->socialName, newClient->socialName);
    strcpy((clients+(quantityClients-1))->address, newClient->address);
    strcpy((clients+(quantityClients-1))->neighborhood, newClient->neighborhood);
    (clients+(quantityClients-1))->cpf = newClient->cpf;
    (clients+(quantityClients-1))->cellphone = newClient->cellphone;

    fwrite(newClient, sizeof(CLIENT), 1, file);
    fclose(file);

    return 0;
}

// pergunta e gfuarda a informacao de um novo produto
static int askNewClient() {
    CLIENT newClient;
    clearInputStream();

    printf("Nome: ");
    fgets(newClient.name, 100, stdin);
    printf("\n");

    printf("Nome Social: ");
    fgets(newClient.socialName, 100, stdin);
    printf("\n");

    printf("Cpf: ");
    scanf("%d", &newClient.cpf);
    printf("\n");
    clearInputStream();

    printf("Celular: ");
    scanf("%d", &newClient.cellphone);
    printf("\n");
    clearInputStream();

    printf("Rua com numero: ");
    fgets(newClient.address, 100, stdin);
    printf("\n");


    printf("Bairro: ");
    fgets(newClient.neighborhood, 100, stdin);
    printf("\n");

    newClient.code = 1 + (clients+(quantityClients-1))->code;

    return addClient(&newClient);
}

// elimina o produto escolhido
static void eliminateChosenClient() {
    int codeOfClient = 0;
    printf("Escreva o codigo do produto a ser eliminado: ");
    scanf("%d", &codeOfClient);

    int found = 0;
    for(int i = 0; i < quantityClients; i++) {
        if((clients+i)->code == codeOfClient) {
            found = 1;
            // Libera a mem�ria alocada dinamicamente para o produto a ser removido
            free(clients + i);

            // Desloca os elementos � direita do elemento a ser removido uma posi��o para a esquerda
            for(int j = i; j < quantityClients - 1; j++) {
                clients[j] = clients[j + 1];
            }
            // Reduz a quantidade de produtos no vetor
            quantityClients--;
            printf("Produto eliminado corretamente!\n");
            break;
        }
    }
    if (!found) {
        printf("Produto nao encontrado!\n");
    }
}
