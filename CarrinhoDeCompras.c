static char nomeProdutos[50][50];
static float precoPorUnidade[50];
static int quantidadeProduto[50];
static int codigosProdutos[50];

static int itensNoCarrinho = 0;

//Adiciona nome, codigo, preco unitario e quantidade do item na lista de compras
static void addItemCarrinho(char nomeItem[50], float precoItem, int quantidadeItem, int codigoProduto){
    int booleanEstaDentroDaLista = 0;

    for(int i = 0; i < 50; i++) {
        if(codigosProdutos[i] == codigoProduto) {
            booleanEstaDentroDaLista = 1;
            break;
        }
    }

    if(itensNoCarrinho < 50 && booleanEstaDentroDaLista == 0){
        strcpy(nomeProdutos[itensNoCarrinho], nomeItem);
        precoPorUnidade[itensNoCarrinho] = precoItem;
        quantidadeProduto[itensNoCarrinho] = quantidadeItem;
        codigosProdutos[itensNoCarrinho] = codigoProduto;
        itensNoCarrinho++;
    } else {
        //sexo
    }
}

static void listarItensCarriho(){
    system("cls");
    printf("Carrinho de compras atual: \n\n");
    printf("Nome do Produto | Preco do Produto | Quantidade do Produto \n");

    for (int i = 0; i < itensNoCarrinho; i++){
        printf("%s | %.2f | %d\n", nomeProdutos[i], precoPorUnidade[i], quantidadeProduto[i]);
    }

    printf("\n");
}

static int pegarQuantidade(char nome[50], float preco,int codigo)
{
    int quantidade = 0;
    printf("\nQuantas unidades desse produto voce deseja: ");
    scanf("%d", &quantidade);

    addItemCarrinho(nome, preco, quantidade, codigo);

    return quantidade;
}
