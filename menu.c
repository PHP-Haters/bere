#include "structHeader.h"
static void cleanChat() {
    system("cls");
}

static void mainMenu(){
    cleanChat();
    printf(".________- MERCEARIA DA BER� -_________.\n");
    printf("|                                      |\n");
    printf("| 1 > Cadastro                         |\n");
    printf("| 2 > Vendas                           |\n");
    printf("| 3 > Abertura de Caixa                |\n");
    printf("| 4 > Fechamento do Caixa              |\n");
    printf("| 5 > Relat�rios                       |\n");
    printf("| 6 > Sair                             |\n");
    printf("|______________________________________|");
    printf("\n");
    printf("Escreva sua escolha (Apenas o último número): ");
}

// SECCAO 1:
// CADASTRO
static void registerMenu(){
    cleanChat();

    printf(".__________- CADASTROS -___________.\n");
    printf("|                                  |\n");
    printf("| 1.1 > Cadastro de Clientes       |\n");
    printf("| 1.2 > Cadastro de Produtos       |\n");
    printf("| 1.3 > Retornar ao Menu Principal |\n");
    printf("|__________________________________|");
    printf("\n");
    printf("Escreva sua escolha (Apenas o último número): ");
}

// SECCAO DA SECCAO CADASTRO:
//PRODUTOS
static void productRegisterMenu(){
    cleanChat();

    printf("._______- CADASTRO DE PRODUTOS -_______.\n");
    printf("|                                      |\n");
    printf("| 1.2.1 > Cadastrar produto no estoque |\n");
    printf("| 1.2.2 > Remover produto do estoque   |\n");
    printf("| 1.2.3 > Retornar ao Menu Cadastros   |\n");
    printf("|______________________________________|");
    printf("\n");
    printf("Escreva sua escolha (Apenas o último número): ");
}

// SESSAO DA ABERTURA DE CAIXA
void cashierMenu(){
    cleanChat();

    printf("._______- ABERTURA DE CAIXA -_______.\n");
    printf("|                                   |\n");
    printf("| 3.1 Abrir o caixa                 |\n");
    printf("| 3.2 Retornar ao Menu Principal    |\n");
    printf("|___________________________________|");
    printf("\n");
    printf("Escreva sua escolha (Apenas o último número): ");
}


// SECCAO
// RELATORIOS

static void recordsMenu() {
    cleanChat();

    printf(".__________- CADASTROS -___________.\n");
    printf("|                                  |\n");
    printf("| 5.1 > Relat�rio de Clientes      |\n");
    printf("| 5.2 > Relat�rio de Produtos      |\n");
    printf("| 5.3 > Retornar ao Menu Principal |\n");
    printf("|__________________________________|");
    printf("\n");
    printf("Escreva sua escolha: ");
}

static void productRecordsMenu(PRODUCT *productList, int quantityProducts) {
    cleanChat();

    for(int i = 0; i < quantityProducts; i++) {
        printf("%d \n", (productList+i)->code);
    }
}
