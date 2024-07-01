#include "structHeader.h"

static PRODUCT *products;
static int quantityProducts = 3;

// retorna o punteiro relacionado a lista de produtos
static * getProducts() {
    return products;
}

static int getProductQuantity() {
    return quantityProducts;
}

// definicao de espaco de memoria
static void defineMemoryForProducts() {
    //definicao de memoria da lista de produtos
    products = malloc(quantityProducts * sizeof(PRODUCT));
    if (products == NULL) {
       printf("Falha na alocacao de memoria inicial.\n");
    }
}
static void readFile(FILE *filePointer) {

    PRODUCT *aux = malloc(1 * sizeof(PRODUCT));

    filePointer = fopen("productDatabase.bin", "rb");

    int i = 1;
    int quantityRead = 0;
    int auxQuantity = 0;

    while(! feof(filePointer)) {

        quantityRead = fread(aux, sizeof(PRODUCT), i, filePointer);
        if(quantityRead == 0) {
            quantityRead = auxQuantity;
            break;
        }
        auxQuantity = quantityRead;

        i++;
        PRODUCT *temp = realloc(aux, (i) * sizeof(PRODUCT));
        aux = temp;
    }
    quantityProducts = (quantityRead);

    defineMemoryForProducts();
    if(quantityRead > 0) {
        products = aux;
    }

}
static void createOrFindFile() {

    FILE *filePointer = fopen("productDatabase.bin", "ab");

    if(filePointer == 0) {
        printf("Arquivo não encontrado; impossivel criar ele (Produtos)");
    }
    fclose(filePointer);

    readFile(filePointer);
}

// adiciona o novo produto dentro da lista de produtos
static int addProduct(PRODUCT * newProduct) {

    PRODUCT *temp = realloc(products, quantityProducts * sizeof(PRODUCT));
    FILE *file;

    file = fopen("productDatabase.bin", "ab");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    if (temp == NULL) {
        printf("Falha na realocacao de memoria.\n");
        free(temp);
        return 1;
    }
    products = temp;
    (products+(quantityProducts-1))->code = newProduct->code;
    (products+(quantityProducts-1))->category = newProduct->category;
    strcpy((products+(quantityProducts-1))->description, newProduct->description);
    (products+(quantityProducts-1))->price = newProduct->price;
    (products+(quantityProducts-1))->profitMargin = newProduct->profitMargin;
    (products+(quantityProducts-1))->sellingPrice = newProduct->sellingPrice;
    (products+(quantityProducts-1))->stock = newProduct->stock;
    (products+(quantityProducts-1))->minimumStock = newProduct->minimumStock;

    fwrite(newProduct, sizeof(PRODUCT), 1, file);
    fclose(file);
    return 0;
}

// pergunta e gfuarda a informacao de um novo produto
static int askNewProduct() {
    PRODUCT newProduct;
    clearInputStream();

    printf("descricao: ");
    fgets(newProduct.description, 100, stdin);
    printf("\n");

    printf("Preco: ");
    scanf("%f", &newProduct.price);
    printf("\n");
    clearInputStream();

    while(newProduct.category != 'L' && newProduct.category != 'P' && newProduct.category != 'A' ) {
        printf("Categoria (L - limpeza, P - Padaria, A - alimentos): ");
        scanf("%c", &newProduct.category);
        clearInputStream();
    }
    printf("\n");

    printf("Margem de lucro: ");
    scanf("%f", &newProduct.profitMargin);
    clearInputStream();
    printf("\n");

    printf("Estoque atual: ");
    scanf("%d", &newProduct.stock);
    printf("\n");

    printf("Estoque minimo: ");
    scanf("%d", &newProduct.minimumStock);
    printf("\n");

    quantityProducts++;

    newProduct.sellingPrice = 0;
    if(quantityProducts == 0) {
        newProduct.code = 1;
    }
    else {
        newProduct.code = 1 + (products+(quantityProducts-1))->code;
    }


    return addProduct(&newProduct);
}

// elimina o produto escolhido
static void eliminateChosenProduct() {
    int codeOfProduct = 0;
    FILE * file = fopen("productDatabase.bin", "wb");

    if(file == 0) {
        printf("Arquivo nao encontrado; impossivel cria-lo (Produtos)");
    }
    fclose(file);

    printf("Escreva o codigo do produto a ser eliminado: ");
    scanf("%d", &codeOfProduct);

    int found = 0;
    for(int i = 0; i < quantityProducts; i++) {
        if((products+i)->code == codeOfProduct) {
            found = 1;
            quantityProducts--;
            // Libera a mem�ria alocada dinamicamente para o produto a ser removido
            free(products + i);
            fwrite((products), sizeof(PRODUCT), quantityProducts, file);
            // Desloca os elementos � direita do elemento a ser removido uma posi��o para a esquerda
            for(int j = i; j < quantityProducts; j++) {
                products[j] = products[j + 1];
            }
            // Reduz a quantidade de produtos no vetor
            printf("Produto eliminado corretamente!\n");
            break;
        }
    }

    file = fopen("productDatabase.bin", "ab");
    for(int j = 0; j < quantityProducts; j++) {
        fwrite((products+j), sizeof(PRODUCT), 1, file);
    }
    fclose(file);
    if (!found) {
        printf("Produto nao encontrado!\n");
    }
}
