// SECAO 5:
//RELATORIOS
void mainRecords() {
    recordsMenu();
}
void recordsMenu() {
    cleanChat();
    printf(".__________- RELATORIOS -__________.\n");
    printf("|                                  |\n");
    printf("| 5.1 > Listar Usuarios            |\n");
    printf("| 5.2 > Listar Clientes            |\n");
    printf("| 5.3 > Listar Produtos            |\n");
    printf("| 5.4 > Listar Vendas              |\n");
    printf("| 5.5 > Retornar ao Menu Principal |\n");
    printf("|__________________________________|");
    printf("\n");
    printf("Escreva sua escolha: ");

    redirectRecords();
}
void redirectRecords() {
    int choiceRecords = 0;

    scanf("%d", &choiceRecords);

    switch(choiceRecords){
        case 1:
            listUsers();
            pausingRecordsMenu();
            break;
        case 2:
            callClientRecords();
            pausingRecordsMenu();
            break;
        case 3:
            callProductRecords();
            pausingRecordsMenu();
            break;
        case 4:
            break;
        case 5:
            break;
        default:
            mainRecords();
            break;
    }
}
void callProductRecords() {
    PRODUCT *list = getProducts();
    int products = getProductQuantity();
    productRecordsMenu(list, products);
}
void productRecordsMenu(PRODUCT *productList, int quantityProducts) {
    cleanChat();
    printf("._____________________- PRODUTOS CADASTRADOS -______________________.\n");
    printf("\e[1m\033[0;36mcódigo");
    printf("\t");
    printf("categoria");
    printf("\t");
    printf("estoque");
    printf("\t");
    printf("preco");
    printf("\t");
    printf("Nome do produto \e[m \033[0m");
    printf("\n");

    for(int i = 0; i < quantityProducts; i++) {
        printf("%d", (productList+i)->code);
        printf("\t");
        printf("%c", (productList+i)->category);
        printf("\t");
        printf("\t");
        printf("%d", (productList+i)->stock);
        printf("\t");
        printf("%0.2f", (productList+i)->price);
        printf("\t");
        printf("%s", (productList+i)->description);
        printf("\n");
    }
}

void callClientRecords() {
    CLIENT *list = getClients();
    int clients = getClientQuantity();
    clientsRecordsMenu(list, clients);
}
void clientsRecordsMenu(CLIENT *clientList, int clientQuantity) {
    cleanChat();
    printf("._____________________- CLIENTES CADASTRADOS -______________________.\n");

    printf("\e[1m\033[0;36mcodigo");
    printf("\t");
    printf("\t");
    printf("Nome Social");
    printf("\t");
    printf("\t");
    printf("celular");
    printf("\t");
    printf("\t");
    printf("Bairro \e[m \033[0m");
    printf("\n");

    for(int i = 0; i < clientQuantity; i++) {
        printf("%d", (clientList+i)->code);
        printf("\t");
        printf("%s", (clientList+i)->socialName);
        printf("\t");
        printf("%d", (clientList+i)->cellphone);
        printf("\t");
        printf("%s", (clientList+i)->neighborhood);
        printf("\t");
        printf("\n");
    }
}

void pausingRecordsMenu() {
    #if defined(_WIN32)
    system("pause");
    #elif defined(_WIN64)
    system("pause");
    #elif defined(__unix__) || defined(__unix)
        sleep(5);
    #elif defined(__linux__)
        sleep(5);
    #else
        printf("Unknown OS.\n");
    #endif
}

