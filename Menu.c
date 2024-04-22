static void menuPrincipal()
{
    printf("-- MENU PRINCIPAL --");
    printf("\n");
    printf("1. material de Limpeza");
    printf("\n");
    printf("2. Venda de Alimentos");
    printf("\n");
    printf("3. Padaria");
    printf("\n");
    printf("4. Pagamento");
    printf("\n");
    printf("5. Abertura de caixa");
    printf("\n");
    printf("6. Fechamento de caixa");
    printf("\n");
    printf("-- FIM MENU PRINCIPAL --");
    printf("\n");
}

static void menuGenerico(int codigos[5], char nomeProduto[5][50], float precos[5], int  referencia)
{
    printf("\n");
    printf("Item (codigo) - Nome do Item - Valor (Unidade)");
    printf("\n");

    for(int i = 0; i < referencia; i++)
    {
        printf("    %d     - %s -  R$ %0.2f", codigos[i], nomeProduto[i], precos[i]);
        printf("\n");
    }
    printf("-- Digite 0(zero) para voltar --");
    printf("\n");
}
