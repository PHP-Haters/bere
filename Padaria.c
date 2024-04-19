static int codigosPadaria[9] = {31, 32, 33, 34, 35, 36, 37, 38};
static char nomeProdutoPadaria[9][50] =
{
    {"Pao de Forma"},
    {"Pao Integral"},
    {"Pao Frances(Unid)"},
    {"Sonho"},
    {"Biscoito(kg)"},
    {"Pão Doce (Un)"},
    {"Salgado (Un)"},
    {"Torta de Limao"}
};
static float precoPadaria[9] = {9.5, 12.5, 1.9, 8.50, 12.50, 2.50, 17.50, 25.0};
static int repeticaoPadaria = 8;
static int estoquePadaria[9] = {1, 1, 1, 1, 0, 0, 1, 0};

//Funcao que recebe o codigo, reenvia para a funcao de pegar a quantidade, e retorna o preco correspodente
static float retornoPrecoPadaria(int codigoCompra)
{
    float preco = 0;
    int quantidade = 0;

    switch(codigoCompra){
    case 31:
        if (estoquePadaria[0]) {
            preco = precoPadaria[0];
            quantidade = pegarQuantidade(nomeProdutoPadaria[0], precoPadaria[0], codigosPadaria[0]);
        } else {
            printf("Produto %s nao esta disponivel.\n", nomeProdutoPadaria[0]);
            sleep(5);
            preco = 0.0;
        }
        break;
    case 32:
        if (estoquePadaria[1]) {
            preco = precoPadaria[1];
            quantidade = pegarQuantidade(nomeProdutoPadaria[1], precoPadaria[1], codigosPadaria[1]);
        } else {
            printf("Produto %s nao esta disponivel.\n", nomeProdutoPadaria[1]);
            sleep(5);
            preco = 0.0;
        }
        break;
    case 33:
        if (estoquePadaria[2]) {
            preco = precoPadaria[2];
            quantidade = pegarQuantidade(nomeProdutoPadaria[2], precoPadaria[2], codigosPadaria[2]);
        } else {
            printf("Produto %s nao esta disponivel.\n", nomeProdutoPadaria[2]);
            sleep(5);
            preco = 0.0;
        }
        break;
    case 34:
        if (estoquePadaria[3]) {
            preco = precoPadaria[3];
            quantidade = pegarQuantidade(nomeProdutoPadaria[3], precoPadaria[3], codigosPadaria[3]);
        } else {
            printf("Produto %s nao esta disponivel.\n", nomeProdutoPadaria[3]);
            sleep(5);
            preco = 0.0;
        }
        break;
    case 35:
        if (estoquePadaria[4]) {
            preco = precoPadaria[4];
            quantidade = pegarQuantidade(nomeProdutoPadaria[4], precoPadaria[4], codigosPadaria[4]);
        } else {
            printf("Produto %s nao esta disponivel.\n", nomeProdutoPadaria[4]);
            sleep(5);
            preco = 0.0;
        }
        break;
    case 36:
        if (estoquePadaria[5]) {
            preco = precoPadaria[5];
            quantidade = pegarQuantidade(nomeProdutoPadaria[5], precoPadaria[5], codigosPadaria[5]);
        } else {
            printf("Produto %s nao esta disponivel.\n", nomeProdutoPadaria[5]);
            sleep(5);
            preco = 0.0;
        }
        break;
    case 37:
        if (estoquePadaria[6]) {
            preco = precoPadaria[6];
            quantidade = pegarQuantidade(nomeProdutoPadaria[6], precoPadaria[6], codigosPadaria[6]);
        } else {
            printf("Produto %s nao esta disponivel.\n", nomeProdutoPadaria[6]);
            sleep(5);
            preco = 0.0;
        }
        break;
    case 38:
        if (estoquePadaria[7]) {
            preco = precoPadaria[7];
            quantidade = pegarQuantidade(nomeProdutoPadaria[7], precoPadaria[7], codigosPadaria[7]);
        } else {
            printf("Produto %s nao esta disponivel.\n", nomeProdutoPadaria[7]);
            sleep(5);
            preco = 0.0;
        }
        break;
    default:
        printf("Codigo de produto invalido.\n");
        preco = 0.0;
        break;
    }

    preco = (float) preco * quantidade;

    return preco;
}

// envia os dados da Padaria para o menu generico; depois recebe o codigo e retorna o valor retornado por retornoPreco
static float chamarMenuPadaria()
{
    int codigoCompra = 0;
    float preco = 0;

    menuGenerico(codigosPadaria, nomeProdutoPadaria, precoPadaria, repeticaoPadaria);

    scanf("%d", &codigoCompra);

    preco = retornoPrecoPadaria(codigoCompra);

    return preco;
}

