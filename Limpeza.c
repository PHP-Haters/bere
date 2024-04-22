static int codigosLimpeza[9] = {11, 12, 13, 14, 15, 16, 17, 18, 19};
static char nomeProdutoLimpeza[9][50] =
{
    {"Detergente"},
    {"Sabao em Po (1kg)"},
    {"Esponja (sem estoque)"},
    {"Amaciante (1Lt)"},
    {"Bucha de Pia (kit c/3)"},
    {"Desinfetante (1Lt)"},
    {"Sabão em Barra(Un)"},
    {"Limpa Vidros"},
    {"Sabao Liquido"}
};
static float precoLimpeza[9] = {1.99, 8.99, 1.5, 15.0, 4.99, 7.99, 1.0, 6.5, 11.0};
static int repeticaoLimpeza = 9;
static int estoqueLimpeza[9] = {1, 1, 0, 1, 1, 1, 1, 1, 1};

//Funcao que recebe o codigo, reenvia para a funcao de pegar a quantidade, e retorna o preco correspodente
static float retornoPrecoLimpeza(int codigoCompra)
{
    float preco = 0;
    int quantidade = 0;

    switch(codigoCompra){
        case 11:
            if (estoqueLimpeza[0]){
            preco = precoLimpeza[0];
            quantidade = pegarQuantidade(nomeProdutoLimpeza[0], precoLimpeza[0], codigosLimpeza[0]);
            } else {
                printf("\n Produto indisponivel no estoque \n");
                sleep(5);
                preco = 0;
            }
            break;
        case 12:
            if (estoqueLimpeza[1]){
            preco = precoLimpeza[1];
            quantidade = pegarQuantidade(nomeProdutoLimpeza[1], precoLimpeza[1], codigosLimpeza[1]);
            } else {
                printf("\n Produto indisponivel no estoque \n");
                sleep(5);
                preco = 0;
            }
            break;
        case 13:
            if (estoqueLimpeza[2]){
                preco = precoLimpeza[2];
                quantidade = pegarQuantidade(nomeProdutoLimpeza[2], precoLimpeza[2], codigosLimpeza[2]);
            } else {
                printf(" \n Produto indisponivel no estoque \n");
                sleep(5);
                preco = 0;
            }
            break;
        case 14:
            if (estoqueLimpeza[3]){
            preco = precoLimpeza[3];
            quantidade = pegarQuantidade(nomeProdutoLimpeza[3], precoLimpeza[3], codigosLimpeza[3]);
            } else {
                printf("\n Produto indisponivel no estoque \n");
                sleep(5);
                preco = 0;
            }
            break;
        case 15:
            if (estoqueLimpeza[4]){
            preco = precoLimpeza[4];
            quantidade = pegarQuantidade(nomeProdutoLimpeza[4], precoLimpeza[4], codigosLimpeza[4]);
            } else{
                printf("\n Produto indisponivel no estoque \n");
                sleep(5);
                preco = 0;
            }
            break;
         case 16:
            if (estoqueLimpeza[5]){
            preco = precoLimpeza[5];
            quantidade = pegarQuantidade(nomeProdutoLimpeza[5], precoLimpeza[5], codigosLimpeza[5]);
            } else {
                printf("\n Produto indisponivel no estoque \n");
                sleep(5);
                preco = 0;
            }
            break;
         case 17:
            if (estoqueLimpeza[6]){
            preco = precoLimpeza[6];
            quantidade = pegarQuantidade(nomeProdutoLimpeza[6], precoLimpeza[6], codigosLimpeza[6]);
            } else{
                printf("\n Produto indisponivel no estoque \n");
                sleep(5);
                preco = 0;
            }
            break;
         case 18:
            if (estoqueLimpeza[7]){
            preco = precoLimpeza[7];
            quantidade = pegarQuantidade(nomeProdutoLimpeza[7], precoLimpeza[7], codigosLimpeza[7]);
            } else{
                printf("\n Produto indisponivel no estoque \n");
                sleep(5);
                preco = 0;
            }
            break;
         case 19:
            if (estoqueLimpeza[8]){
            preco = precoLimpeza[8];
            quantidade = pegarQuantidade(nomeProdutoLimpeza[8], precoLimpeza[8], codigosLimpeza[8]);
            } else{
                printf("\n Produto indisponivel no estoque \n");
                sleep(5);
                preco = 0;
            }
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
