static int codigosPadaria[5] = {31, 32, 33, 34};
static char nomeProdutoPadaria[5][50] =
{
    {"Pao de Forma"},
    {"Pao Integral"},
    {"Pao Frances(Unid)"},
    {"Sonho"}
};
static float precoPadaria[5] = {9.5, 12.5, 1.9, 8.50};
static int repeticaoPadaria = 4;

//Funcao que recebe o codigo, reenvia para a funcao de pegar a quantidade, e retorna o preco correspodente
static float retornoPrecoPadaria(int codigoCompra)
{
    float preco = 0;
    int quantidade = 0;

    switch(codigoCompra){
        case 31:
            preco = precoPadaria[0];
            quantidade = pegarQuantidade(nomeProdutoPadaria[0], precoPadaria[0], codigosPadaria[0]);
            break;
        case 32:
            preco = precoPadaria[1];
            quantidade = pegarQuantidade(nomeProdutoPadaria[1], precoPadaria[1], codigosPadaria[1]);
            break;
        case 33:
            preco = precoPadaria[2];
            quantidade = pegarQuantidade(nomeProdutoPadaria[2], precoPadaria[2], codigosPadaria[2]);
            break;
        case 34:
            preco = precoPadaria[3];
            quantidade = pegarQuantidade(nomeProdutoPadaria[3], precoPadaria[3], codigosPadaria[3]);
            break;
        default:
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

