static float gastosTotais;

// Mostra o valor a ser pago em cartao
static void tratarCartao()
{
    system("cls");
    printf("Valor total: %.2f \n", gastosTotais);
}
// Verifica se o cartao conseguiu ser usado na maquina de cartao
static int maquinaDeCartao()
{
    int estadoCartao = 0;
    printf("\n O cartao passou corretamente na maquininha? \n");

    printf("1. sim \n");
    printf("2. nao \n");

    scanf("%d", &estadoCartao);

    if(estadoCartao == 1)
    {
        return 0;
    }
    else
    {
        return 2;
    }
}

// Cria o desconto correspodente, e mostra o valor a ser pago em dinheiro
static float tratarDinheiro()
{
    system("cls");

    float porcentagem = 0.0;
    float desconto = 0;
    float valorComDesconto = 0;
    float valorRecebido = 0;
    float troco = 0;

    printf("Informe o valor total da compra: ");
    scanf("%f", &gastosTotais);

    printf("Informe o percentual de desconto (em porcentagem): ");
    scanf("%f", &porcentagem);
    porcentagem /= 100; // Convertendo para decimal

    desconto = (porcentagem * gastosTotais);
    valorComDesconto = (gastosTotais - desconto);

    printf("Valor total da compra: %.2f \n", gastosTotais);
    printf("Valor descontado: %.2f \n", desconto);
    printf("Valor final com desconto: %.2f \n", valorComDesconto);

    printf("\nInforme o valor recebido pelo cliente: ");
    scanf("%f", &valorRecebido);

    if (valorRecebido < valorComDesconto) {
        printf("Pagamento recusado! Valor recebido menor que o valor da compra.\n");
        return 0; // Retorna 0 indicando pagamento recusado
    }

    troco = valorRecebido - valorComDesconto;
    printf("Troco: %.2f \n", troco);

    return valorComDesconto;
     }

// Pede o tipo de pagamento
static int tipoPagamento(float gastos)
{
    gastosTotais = gastos;

    int formaPagamento;

    mostrarAPagar();
    listarItensCarriho();

    printf("Escolha a forma de pagamento: \n");

    printf("1. cartao \n");
    printf("2. dinheiro (tem desconto)\n");
    printf("3. voltar \n");
    scanf("%d", &formaPagamento);

    return formaPagamento;
}
