static int codigosAlimentos[9] = {21, 22, 23, 24, 25, 26, 27, 28, 29};
static char nomeProdutoAlimentos[9][50] =
{
    {"Cafe"},
    {"Leite (cx)"},
    {"Arroz (1kg)"},
    {"Feijao"},
    {"Acucar (1kg)"},
    {"Sal"},
    {"Farinha de Trigo (1kg)"},
    {"Azeite"},
    {"Farinha (1kg)"}
};
static float precoAlimentos[9] = {19.99, 5.90, 4.5, 8.00, 5.00, 2.00, 5.00, 15.00, 3.50};
static int repeticaoAlimentos = 9;

//Funcao que recebe o codigo, reenvia para a funcao de pegar a quantidade, e retorna o preco correspodente
static float retornoPrecoAlimentos(int codigoCompra)
{
    float preco = 0;
    int quantidade = 0;

    switch(codigoCompra){
        case 21:
            preco = precoAlimentos[0];
            quantidade = pegarQuantidade(nomeProdutoAlimentos[0], precoAlimentos[0], codigosAlimentos[0]);
            break;
        case 22:
            preco = precoAlimentos[1];
            quantidade = pegarQuantidade(nomeProdutoAlimentos[1], precoAlimentos[1], codigosAlimentos[1]);
            break;
        case 23:
            preco = precoAlimentos[2];
            quantidade = pegarQuantidade(nomeProdutoAlimentos[2], precoAlimentos[2], codigosAlimentos[2]);
            break;
        case 24:
            preco = precoAlimentos[3];
            quantidade = pegarQuantidade(nomeProdutoAlimentos[3], precoAlimentos[3], codigosAlimentos[3]);
            break;
        case 25:
            preco = precoAlimentos[4];
            quantidade = pegarQuantidade(nomeProdutoAlimentos[4], precoAlimentos[4], codigosAlimentos[4]);
            break;
        case 26:
            preco = precoAlimentos[5];
            quantidade = pegarQuantidade(nomeProdutoAlimentos[5], precoAlimentos[5], codigosAlimentos[5]);
            break;
        case 27:
            preco = precoAlimentos[6];
            quantidade = pegarQuantidade(nomeProdutoAlimentos[6], precoAlimentos[6], codigosAlimentos[6]);
            break;
        case 28:
            preco = precoAlimentos[7];
            quantidade = pegarQuantidade(nomeProdutoAlimentos[7], precoAlimentos[7], codigosAlimentos[7]);
            break;
        case 29:
            preco = precoAlimentos[8];
            quantidade = pegarQuantidade(nomeProdutoAlimentos[8], precoAlimentos[8], codigosAlimentos[8]);
            break;
        default:
            preco = 0.0;
            break;
    }

    preco = (float) preco * quantidade;

    return preco;
}

// envia os dados da Alimentos para o menu generico; depois recebe o codigo e retorna o valor retornado por retornoPreco
static float chamarMenuAlimentos()
{
    int codigoCompra = 0;
    float preco = 0;

    menuGenerico(codigosAlimentos, nomeProdutoAlimentos, precoAlimentos, repeticaoAlimentos);

    scanf("%d", &codigoCompra);

    preco = retornoPrecoAlimentos(codigoCompra);

    return preco;
}

