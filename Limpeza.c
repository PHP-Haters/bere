static int codigosLimpeza[5] = {11, 12, 13, 14};
static char nomeProdutoLimpeza[5][50] =
{
        {"Detergente"},
        {"Sabao em Po (1kg)"},
        {" Esponja"},
        {"Amaciante (1Lt)"}
};
static float precoLimpeza[5] = {9.5, 12.5, 1.9, 8.50};
static int repeticaoLimpeza = 4;

//Funcao que recebe o codigo, reenvia para a funcao de pegar a quantidade, e retorna o preco correspodente
static float retornoPrecoLimpeza(int codigoCompra)
{
    float preco = 0;
    int quantidade = 0;

    switch(codigoCompra){
        case 11:
            preco = precoLimpeza[0];
            quantidade = pegarQuantidade(nomeProdutoLimpeza[0], precoLimpeza[0], codigosLimpeza[0]);
            break;
        case 12:
            preco = precoLimpeza[1];
            quantidade = pegarQuantidade(nomeProdutoLimpeza[1], precoLimpeza[1], codigosLimpeza[1]);
            break;
        case 13:
            preco = precoLimpeza[2];
            quantidade = pegarQuantidade(nomeProdutoLimpeza[2], precoLimpeza[2], codigosLimpeza[2]);
            break;
        case 14:
            preco = precoLimpeza[3];
            quantidade = pegarQuantidade(nomeProdutoLimpeza[3], precoLimpeza[3], codigosLimpeza[3]);
            break;
        default:
            preco = 0.0;
            break;
    }

    preco = (float) preco * quantidade;

    return preco;
}

// envia os dados da Limpeza para o menu generico; depois recebe o codigo e retorna o valor retornado por retornoPreco
static float chamarMenuLimpeza()
{
    int codigoCompra = 0;
    float preco = 0;

    menuGenerico(codigosLimpeza, nomeProdutoLimpeza, precoLimpeza, repeticaoLimpeza);

    scanf("%d", &codigoCompra);

    preco = retornoPrecoLimpeza(codigoCompra);

    return preco;
}
