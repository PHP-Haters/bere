// SECAO 2:
//VENDAS
void mainSales() {
    salesMenu();
}
void salesMenu(){
    cleanChat();
    printf(".__________- VENDAS -_______________.\n");
    printf("|                                   |\n");
    printf("| 2.1 > Nova Venda                  |\n");
    printf("| 2.2 > Retirada de Caixa (Sangria) |\n");
    printf("| 2.3 Pagamento                     |\n");
    printf("| 2.4 Retornar ao Menu Principal    |\n");
    printf("|___________________________________|");
    printf("\n");
    printf("Escreva sua escolha: ");

    redirectSales();
}

void redirectSales() {
    int saleChoice = 0;
    scanf("%d", &saleChoice);

    switch (saleChoice){
    case 1:
        startSale();
        break;
    case 2:
        //retirar no caixa
        break;
    case 3:
        //Realizar Pagamento
        break;
    case 4:
        break;
    default:
        mainSales();
        break;
    }
}

void startSale() {
    callProductRecords();
    int redirection = askNewSale(getProducts(), getProductQuantity());

    if(redirection < 1) {
        mainSales();
    } else {
        startSale();
    }
}
