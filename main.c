#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#include "Menu.c"
#include "CarrinhoDeCompras.c"
#include "Padaria.c"
#include "Limpeza.c"
#include "Alimentos.c"
#include "Pagamento.c"

// posicao 0 eh generico, 1 eh limpeza, 2 eh alimentos, 3 eh padaria
static float faturamento[4] = {0,0,0,0};
static float gastos[4] = {0,0,0,0};
static int vendas = 0;
static bool  saldoEstaSetado = false;
static float saldo_caixa = 0;

int main(void){
    verifica_saldo_caixa();
    mostrarAPagar();
    menuPrincipal();
    redirecionarUsuario();
    return 0;
}

void verifica_saldo_caixa(){
    if(saldoEstaSetado){
        return;
    }

    printf("Informe o saldo inicial do caixa:\n");
    scanf("%d", &saldo_caixa);

    saldoEstaSetado = true;

    return saldo_caixa >= 0 ? saldo_caixa : verifica_saldo_caixa();
}

// redireciona o usuario a funcao correspondente a sua escolha
void redirecionarUsuario()
{
    int entrada = 0;
    scanf("%d", &entrada);

    switch(entrada)
    {
        case 1:
            //chama material de limpeza
            chamarLimpeza();
            break;
        case 2:
            //chama Venda de alimentos
            chamarAlimentos();
            break;
        case 3:
            //chama Padaria
            chamarPadaria();
            break;
        case 4:
            //chama pagamento
            chamarPagamento();
            break;
        case 5:
            //chama pagamento
            terminarFaturamento();
            break;
        default:
            //avisa que o valor eh invalido e redireciona para o menu
            printf("Escreva um valor valido.");
            main();
            break;
    }
}

// chama a Limpeza, salva os valores selecionados e volta ao Menu principal se o Usuario decidir
void chamarLimpeza(){
    float preco = 0;
    mostrarAPagar();
    preco = chamarMenuLimpeza(); //Cria o menu de limpeza e retorna o valor a ser gasto

    if(preco != 0){
        gastos[0] += preco;
        gastos[1] += preco;
        chamarLimpeza();
    } else {
        main();
    }
}

// chama a Alimentos, salva os valores selecionados e volta ao Menu principal se o Usuario decidir
void chamarAlimentos(){
    float preco = 0;
    mostrarAPagar();
    preco = chamarMenuAlimentos();

    if(preco != 0){
        gastos[0] += preco;
        gastos[2] += preco;
        chamarAlimentos();
    } else {
        main();
    }
}

// chama a Padaria, salva os valores selecionados e volta ao Menu principal se o Usuario decidir
void chamarPadaria(){
    float preco = 0;
    mostrarAPagar();
    preco = chamarMenuPadaria();

    if(preco != 0){
        gastos[3] += preco;
        gastos[0] += preco;
        chamarPadaria();
    } else {
        main();
    }
}

// chama o pagamento, reinicia o sistema depois de terminado.
void chamarPagamento()
{
    int tipoPago = 0;
    int maquina = 0;

    tipoPago = tipoPagamento(gastos[0]);

    if(tipoPago == 1) {
        tratarCartao();
        maquina = maquinaDeCartao();

        if(maquina == 2) {
            mostrarAPagar();
            chamarPagamento();
        }
        else {
            tratarCartao();
        }
    }
    else if(tipoPago == 2){
        gastos[0] = tratarDinheiro();
    }
    else {
        main();
    }
    printf("\n Pagamento realizado!");

    faturamento[0] += gastos[0];
    faturamento[1] += gastos[1];
    faturamento[2] += gastos[2];
    faturamento[3] += gastos[3];
    vendas++;

    sleep(5);
    for(int i = 0; i < 4; i++)
    {
        gastos[i] = 0;
    }
    main();
}

// termina o faturamento, mostrando as vendas do dia.
void terminarFaturamento()
{
    system("cls");
    printf("--/--/--/--/--/--/");
    printf("\n");
    printf("Faturamento de limpeza: %.2f", faturamento[1]);
    printf("\n");
    printf("Faturamento de Alimentos: %.2f", faturamento[2]);
    printf("\n");
    printf("Faturamento da Padaria: %.2f", faturamento[3]);
    printf("\n");
    printf("Faturamento total do dia: %.2f", faturamento[0]);
    printf("\n");
    printf("Quantidade total de vendas hoje: %d", vendas);
    printf("\n");
    printf("--/--/--/--/--/--/");
    printf("\n \n \n");

}
// mostra os valores que tem que pagar
void mostrarAPagar()
{
    system("cls");
    printf("--/--/--/--/--/--/");
    printf("\n");
    printf("Valor da Limpeza a pagar: %.2f", gastos[1]);
    printf("\n");
    printf("Valor de Alimentos a pagar: %.2f", gastos[2]);
    printf("\n");
    printf("Valor da Padaria a pagar: %.2f", gastos[3]);
    printf("\n");
    printf("Valor a pagar: %.2f", gastos[0]);
    printf("\n");
    printf("--/--/--/--/--/--/");
    printf("\n \n");
}

