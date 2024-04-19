static int codigosLimpeza[9] = {11, 12, 13, 14, 15, 16, 17, 18, 19};
static char nomeProdutoLimpeza[9][50] =
{
    {"Detergente"},
    {"Sabao em Po (1kg)"},
    {"Esponja"},
    {"Amaciante (1Lt)"},
    {"Bucha de Pia (kit c/3)"},
    {"Desinfetante (1Lt)"},
    {"Sabão em Barra(Un)"},
    {"Limpa Vidros"},
    {"Sabao Liquido"}
};
static float precoLimpeza[9] = {1.99, 8.99, 1.5, 15.0, 4.99, 7.99, 1.0, 6.5, 11.0};
static int repeticaoLimpeza = 9;

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
        case 15:
            preco = precoLimpeza[4];
            quantidade = pegarQuantidade(nomeProdutoLimpeza[4], precoLimpeza[4], codigosLimpeza[4]);
            break;
         case 16:
            preco = precoLimpeza[5];
            quantidade = pegarQuantidade(nomeProdutoLimpeza[5], precoLimpeza[5], codigosLimpeza[5]);
            break;
         case 17:
            preco = precoLimpeza[6];
            quantidade = pegarQuantidade(nomeProdutoLimpeza[6], precoLimpeza[6], codigosLimpeza[6]);
            break;
         case 18:
            preco = precoLimpeza[7];
            quantidade = pegarQuantidade(nomeProdutoLimpeza[7], precoLimpeza[7], codigosLimpeza[7]);
            break;
         case 19:
            preco = precoLimpeza[8];
            quantidade = pegarQuantidade(nomeProdutoLimpeza[8], precoLimpeza[8], codigosLimpeza[8]);
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
