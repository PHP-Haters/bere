#include "structHeader.h"

static SALE *sales;
static int quantitySales = 3;
static PRODUCT *productsListGlobal;
static int productsOnListGlobal = 0;


// retorna o punteiro relacionado a lista de vendas
static * getSales() {
    return sales;
}

static int getSalesQuantity() {
    return quantitySales;
}

// definicao de espaco de memoria
static void defineMemoryForSales() {
    //definicao de memoria da lista de vendas
    sales = malloc(quantitySales * sizeof(PRODUCT));
    // SEM ESTE PRINTF NAO FUNCIONA NADA. NAO SEI PORQUE. VOU COMETER SUICIDIO. CARALHO.
    printf("sssss");
    if (sales == NULL) {
       printf("Falha na alocação de memória inicial.\n");
    }
}


static int validateProduct(int productCode){
    for(int i = 0; i < productsOnListGlobal; i++){
        if((productsListGlobal+i)->code == productCode){
            return 0;
        }
    }

    return 1;
}

static int  checkStock(int productCode, int quantityAsked){
    for(int i = 0; i < productsOnListGlobal; i++){
        if((productsListGlobal+i)->code == productCode){
            if((productsListGlobal+i)->stock < (productsListGlobal+i)->minimumStock){
                printf("Atencao: Estoque minimo atingido!\n");
            }

            if((productsListGlobal+i)->stock == 0){
                printf("Atencao: Este produto esta zerado no estoque!\n");
                sleep(3);
                return 0;
            }

            if((productsListGlobal+i)->stock < quantityAsked){
                printf("Voce solicitou %d produtos, mas temos apenas %d no estoque!\n", quantityAsked, (productsListGlobal+i)->stock);
                sleep(3);
                return 0;
            }
        }
    }
}

static int askNewSale(PRODUCT *productList, int productsOnList) {
    int productCode = 0;
    int quantity = 0;
    productsListGlobal = productList;
    productsOnListGlobal = productsOnList;

    printf("Diga o código do produto: ");
    scanf("%d", &productCode);

    //Verify if product exists
    int verification = 0;
    verification = validateProduct(productCode);

    if(verification > 0){
        system("cls");
        printf("Produto nao encontrado!");
        sleep(3);
        return 0;
    }

    // Ask quantity of products
    printf("\nIndique a quantidade desejada: ");
    scanf("%d", &quantity);

    // Verify quantity of products availible
    int stockIsAvailible = 1;
    stockIsAvailible = checkStock(productCode, quantity);

    if(stockIsAvailible == 0){ // Error on stock
        return 0;
    }
}
