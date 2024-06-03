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
    printf("sssss");
    if (clients == NULL) {
       printf("Falha na aloca��o de mem�ria inicial.\n");
    }

    //definicao de valores default: 1 de cada loja.
    (clients)->code = 1; strcpy((clients)->description, "Detergente"); (clients)->category = 'L';
    (clients)->price = 1.99;
    (clients+1)->code = 2; strcpy((clients+1)->description, "Caf�"); (clients+1)->category = 'A';
    (clients+1)->price = 19.99;
    (clients+2)->code = 3; strcpy((clients+2)->description, "Pao de Forma"); (clients+2)->category = 'P';
    (clients+2)->price = 9.5;

    for(int i = 0; i < 3; i++) {
        (clients+i)->sellingPrice = 0; (clients+i)->profitMargin = 0.1;
        (clients+i)->stock = 20; (clients+i)->minimumStock = 5;
    }
}

// adiciona o novo produto dentro da lista de produtos
static int addClient(CLIENT * newClient) {
    quantityClients++;

    CLIENT *temp = realloc(clients, quantityClients * sizeof(CLIENT));

    if (temp == NULL) {
       printf("Falha na realoca��o de mem�ria.\n");
       free(temp);
       return 1;
    }
    clients = temp;
    (clients+(quantityClients-1))->code = newClient->code;
    (clients+(quantityClients-1))->category = newClient->category;
    strcpy((clients+(quantityClients-1))->description, newClient->description);
    (clients+(quantityClients-1))->price = newClient->price;
    (clients+(quantityClients-1))->profitMargin = newClient->profitMargin;
    (clients+(quantityClients-1))->sellingPrice = newClient->sellingPrice;
    (clients+(quantityClients-1))->stock = newClient->stock;
    (clients+(quantityClients-1))->minimumStock = newClient->minimumStock;
    return 0;
}

//funcao para deixa o input stream limpo
void clear() {
    while ( getchar() != '\n' );
}
// pergunta e gfuarda a informacao de um novo produto
static int askNewClient() {
    CLIENT newClient;
    clear();

    printf("descri��o: ");
    fgets(newClient.description, 100, stdin);
    printf("\n");

    printf("Pre�o: ");
    scanf("%f", &newClient.price);
    printf("\n");
    clear();

    while(newClient.category != 'L' && newClient.category != 'P' && newClient.category != 'A' ) {
        printf("Categoria (L - limpeza, P - Padaria, A - alimentos): ");
        scanf("%c", &newClient.category);
        clear();
    }
    printf("\n");

    printf("Margem de lucro: ");
    scanf("%f", &newClient.profitMargin);
    clear();
    printf("\n");

    printf("Estoque atual: ");
    scanf("%d", &newClient.stock);
    printf("\n");

    printf("Estoque m�nimo: ");
    scanf("%d", &newClient.minimumStock);
    printf("\n");

    newClient.sellingPrice = 0;
    newClient.code = 1 + (clients+(quantityClients-1))->code;

    return addClient(&newClient);
}

// elimina o produto escolhido
static void eliminateChosenClient() {
    int codeOfClient = 0;
    printf("Escreva o c�digo do produto a ser eliminado: ");
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
        printf("Produto n�o encontrado!\n");
    }
}
