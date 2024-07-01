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

// Adiciona o novo produto dentro da lista de produtos
static int addProduct(PRODUCT *newProduct) {
    PRODUCT *temp = realloc(products, (quantityProducts + 1) * sizeof(PRODUCT));
    if (temp == NULL) {
<<<<<<< HEAD
        printf("Falha na realocação de memória.\n");
        return 1; // Indica falha
=======
        printf("Falha na realocacao de memoria.\n");
        free(temp);
        return 1;
>>>>>>> 13618d94a4d5be30fffb6dbb996c0b4d74899df0
    }
    products = temp;
    products[quantityProducts] = *newProduct; // Copia novo produto para o array
    quantityProducts++; // Incrementa a quantidade de produtos

    FILE *file = fopen("productDatabase.bin", "ab");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return 1; // Indica falha
    }

    fwrite(newProduct, sizeof(PRODUCT), 1, file);
    fclose(file);
    return 0; // Sucesso
}

<<<<<<< HEAD

//funcao para deixa o input stream limpo
void clear() {
    while ( getchar() != '\n' );
}
=======
>>>>>>> 13618d94a4d5be30fffb6dbb996c0b4d74899df0
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
        newProduct.code = 1 + quantityProducts;
    }


    return addProduct(&newProduct);
}

int eliminateChosenProduct() {
    int foundIndex = -1;
    int codeOfProduct = 0;
    
    printf("Escreva o c�digo do produto a ser eliminado: ");
    scanf("%d", &codeOfProduct);

    for (int i = 0; i < quantityProducts; i++) {
        if (products[i].code == codeOfProduct) {
            foundIndex = i;
            break;
        }
    }

    if (foundIndex == -1) {
        printf("Produto com código %d não encontrado.\n", codeOfProduct);
        return 1; // Produto não encontrado
    }

    // Deslocar todos os produtos após o índice encontrado uma posição para trás
    for (int i = foundIndex; i < quantityProducts - 1; i++) {
        products[i] = products[i + 1];
    }

    // Realocar o array de produtos para o novo tamanho
    quantityProducts--;
    PRODUCT *temp = realloc(products, quantityProducts * sizeof(PRODUCT));
    if (temp == NULL && quantityProducts > 0) { // Falha na realocação, exceto quando o array é agora vazio
        printf("Falha ao realocar memória ao excluir produto.\n");
        return 1; // Falha na realocação
    }
    products = temp;

    printf("Produto excluído com sucesso.\n");
    return 0; // Sucesso
}
