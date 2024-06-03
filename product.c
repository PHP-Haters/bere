#include "structHeader.h"

static PRODUCT *products;
static int quantityProducts = 3;

// retorna o punteiro relacionado a lista de produtos
static * getProducts() {
    return products;
}

// definicao de espaco de memoria
static void defineMemoryForProducts() {
    //definicao de memoria da lista de produtos
    products = malloc(quantityProducts * sizeof(PRODUCT));
    // SEM ESTE PRINTF NAO FUNCIONA NADA. NAO SEI PORQUE. VOU COMETER SUICIDIO. CARALHO.
    printf("sssss");
    if (products == NULL) {
       printf("Falha na aloca��o de mem�ria inicial.\n");
    }

    //definicao de valores default: 1 de cada loja.
    (products)->code = 1; strcpy(products[1].description, "Detergente"); products[1].category = 'L';
    (products)->price = 1.99;
    (products+1)->code = 2; strcpy(products[2].description, "Caf�"); products[2].category = 'A';
    (products+1)->price = 19.99;
    (products+2)->code = 3; strcpy(products[3].description, "Pao de Forma"); products[3].category = 'P';
    (products+2)->price = 9.5;

    for(int i = 0; i < 3; i++) {
        (products+i)->sellingPrice = 0; (products+i)->profitMargin = 0.1;
        (products+i)->stock = 20; (products+i)->minimumStock = 5;
    }
}

// adiciona o novo produto dentro da lista de produtos
static int addProduct(PRODUCT * newProduct) {
    quantityProducts++;

    PRODUCT *temp = realloc(products, quantityProducts * sizeof(PRODUCT));

    if (temp == NULL) {
       printf("Falha na realoca��o de mem�ria.\n");
       free(temp);
       return 1;
    }
    products = temp;
    (products+quantityProducts)->code = newProduct->code;
    (products+quantityProducts)->category = newProduct->category;
    strcpy(products[1].description, newProduct->description);
    (products+quantityProducts)->price = newProduct->price;
    (products+quantityProducts)->profitMargin = newProduct->profitMargin;
    (products+quantityProducts)->sellingPrice = newProduct->sellingPrice;
    (products+quantityProducts)->stock = newProduct->stock;
    (products+quantityProducts)->minimumStock = newProduct->minimumStock;
    return 0;
}

//funcao para deixa o input stream limpo
void clear() {
    while ( getchar() != '\n' );
}
// pergunta e gfuarda a informacao de um novo produto
static int askNewProduct() {
    PRODUCT newProduct;
    clear();

    printf("descri��o: ");
    fgets(newProduct.description, 100, stdin);
    printf("\n");

    printf("Pre�o: ");
    scanf("%f", &newProduct.price);
    printf("\n");
    clear();

    while(newProduct.category != 'L' && newProduct.category != 'P' && newProduct.category != 'A' ) {
        printf("Categoria (L - limpeza, P - Padaria, A - alimentos): ");
        scanf("%c", &newProduct.category);
        clear();
    }
    printf("\n");

    printf("Margem de lucro: ");
    scanf("%f", &newProduct.profitMargin);
    clear();
    printf("\n");

    printf("Estoque atual: ");
    scanf("%d", &newProduct.stock);
    printf("\n");

    printf("Estoque m�nimo: ");
    scanf("%d", &newProduct.minimumStock);
    printf("\n");

    newProduct.sellingPrice = 0;
    newProduct.code = 1 + (products+quantityProducts)->code;

    return addProduct(&newProduct);
}
// elimina o produto escolhido
static void eliminateChosenProduct() {
    int codeOfProduct = 0;
    printf("Escreva o c�digo do produto a ser eliminado:");
    scanf("%d", &codeOfProduct);

    int i = 0;
    while ((products + i)->code != codeOfProduct) {
        i++;
    }
    free((products+i));
}
