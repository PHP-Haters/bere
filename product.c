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
    // SEM ESTE PRINTF NAO FUNCIONA NADA. NAO SEI PORQUE. VOU COMETER SUICIDIO. CARALHO.
    // printf("sssss");
    if (products == NULL) {
       printf("Falha na aloca��o de mem�ria inicial.\n");
    }

    //definicao de valores default: 1 de cada loja.
    (products)->code = 1; strcpy((products)->description, "Detergente"); (products)->category = 'L';
    (products)->price = 1.99;
    (products+1)->code = 2; strcpy((products+1)->description, "Caf�"); (products+1)->category = 'A';
    (products+1)->price = 19.99;
    (products+2)->code = 3; strcpy((products+2)->description, "Pao de Forma"); (products+2)->category = 'P';
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
    FILE *file;

    file = fopen("products.dat", "ab");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    if (temp == NULL) {
        printf("Falha na realoca��o de mem�ria.\n");
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

    fwrite(&temp, sizeof(PRODUCT), 1, file);
    return 0;
}

static void listProducts() {
    PRODUCT p;
    FILE *file;

    file = fopen("products.dat", "rb");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    while (fread(&p, sizeof(PRODUCT), 1, file) == 1) {
        printf("Código: %d, Descrição: %s, Categoria: %c, Preço: R$ %.2f, Margem de Lucro: %.2f%%, Preço de Venda: R$ %.2f, Estoque: %d, Estoque Mínimo: %d\n",
               p.code, p.description, p.category, p.price, p.profitMargin, p.sellingPrice, p.stock, p.minimumStock);
    }

    fclose(file);
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
    newProduct.code = 1 + (products+(quantityProducts-1))->code;

    return addProduct(&newProduct);
}

// elimina o produto escolhido
static void eliminateChosenProduct() {
    int codeOfProduct = 0;
    printf("Escreva o c�digo do produto a ser eliminado: ");
    scanf("%d", &codeOfProduct);

    int found = 0;
    for(int i = 0; i < quantityProducts; i++) {
        if((products+i)->code == codeOfProduct) {
            found = 1;
            // Libera a mem�ria alocada dinamicamente para o produto a ser removido
            free(products + i);

            // Desloca os elementos � direita do elemento a ser removido uma posi��o para a esquerda
            for(int j = i; j < quantityProducts - 1; j++) {
                products[j] = products[j + 1];
            }
            // Reduz a quantidade de produtos no vetor
            quantityProducts--;
            printf("Produto eliminado corretamente!\n");
            break;
        }
    }

    if (!found) {
        printf("Produto n�o encontrado!\n");
    }
}

