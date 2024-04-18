static int codigosAlimentos[5] = {21, 22, 23, 24, 25};
static char nomeProdutoAlimentos[5][50] =
{
    {"Cafe"},
    {"Leite (cx)"},
    {"Arroz (1kg)"},
    {"Feijao"},
    {"Acucar (1kg)"}
};
static float precoAlimentos[5] = {19.99, 5.99, 4.5, 8.00, 5.00};
static int repeticaoAlimentos = 5;

//Funcao que recebe o codigo, reenvia para a funcao de pegar a quantidade, e retorna o preco correspodente
static float retornoPrecoAlimentos(int codigoCompra)
{
    float preco = 0;
    int quantidade = 0;

    switch(codigoCompra)
    {
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

