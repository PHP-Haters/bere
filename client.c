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
    if (clients == 0 ) {
       printf("Falha na aloca��o de mem�ria inicial.\n");
    }
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
        printf("Arquivo não encontrado; impossivel criar ele (Produtos)");
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
       printf("Falha na realocção de memória.\n");
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
int eliminateChosenClient() {
    int foundIndex = -1;
    int codeOfClient = 0;
    printf("Escreva o c�digo do produto a ser eliminado: ");
    scanf("%d", &codeOfClient);
    for (int i = 0; i < quantityClients; i++) {
        if (clients[i].code == codeOfClient) {
            foundIndex = i;
            break;
        }
    }

    if (foundIndex == -1) {
        printf("Cliente com código %d não encontrado.\n", codeOfClient);
        return 1; // Cliente não encontrado
    }

    // Deslocar todos os clientes após o índice encontrado uma posição para trás
    for (int i = foundIndex; i < quantityClients - 1; i++) {
        clients[i] = clients[i + 1];
    }

    // Realocar o array de clientes para o novo tamanho
    quantityClients--;
    CLIENT *temp = realloc(clients, quantityClients * sizeof(CLIENT));
    if (temp == NULL && quantityClients > 0) { // Falha na realocação, exceto quando o array é agora vazio
        printf("Falha ao realocar memória ao excluir cliente.\n");
        return 1; // Falha na realocação
    }
    clients = temp;

    printf("Cliente excluído com sucesso.\n");
    return 0; // Sucesso
}