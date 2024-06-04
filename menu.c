#include "structHeader.h"
static void cleanChat() {
    system("cls");
}

static void mainMenu(){
    cleanChat();
    printf(".________- MERCEARIA DA BERE -_________.\n");
    printf("|                                      |\n");
    printf("| 1 > Cadastro                         |\n");
    printf("| 2 > Vendas                           |\n");
    printf("| 3 > Abertura de Caixa                |\n");
    printf("| 4 > Fechamento do Caixa              |\n");
    printf("| 5 > Relatórios                       |\n");
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

static void clientRegisterMenu(){
    cleanChat();

    printf("._______- CADASTRO DE CLIENTES -_______.\n");
    printf("|                                      |\n");
    printf("| 1.2.1 > Cadastrar cliente            |\n");
    printf("| 1.2.2 > Remover cliente              |\n");
    printf("| 1.2.3 > Retornar ao Menu Cadastros   |\n");
    printf("|______________________________________|");
    printf("\n");
    printf("Escreva sua escolha (Apenas o último número): ");
}
// SECAO 2:
// VENDA
void salesMenu(){
    cleanChat();
    printf(".__________- VENDAS -_______________.\n");
    printf("|                                   |\n");
    printf("| 2.1 > Nova Venda                  |\n");
    printf("| 2.2 > Retirada de Caixa (Sangria) |\n");
    printf("| 2.3 Pagamento                     |\n");
    printf("| 2.4 Retornar ao Menu Principal    |\n");
    printf("|___________________________________|");
    printf("\n");
    printf("Escreva sua escolha: ");
}

// SESSAO 3:
// ABERTURA DE CAIXA
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


// SECCAO 5:
// RELATORIOS
static void recordsMenu() {
    cleanChat();
    printf(".__________- RELAT�RIOS -__________.\n");
    printf("|                                  |\n");
    printf("| 5.1 > Listar Clientes            |\n");
    printf("| 5.2 > Listar Produtos            |\n");
    printf("| 5.3 > Listar Vendas              |\n");
    printf("| 5.4 > Retornar ao Menu Principal |\n");
    printf("|__________________________________|");
    printf("\n");
    printf("Escreva sua escolha: ");
}
//SECAO DE RELATORIOS:
// PRODUTO
static void productRecordsMenu(PRODUCT *productList, int quantityProducts) {
    cleanChat();
    printf("._____________________- PRODUTOS CADASTRADOS -______________________.\n");

    printf("\e[1m\033[0;36mcódigo");
    printf("\t");
    printf("categoria");
    printf("\t");
    printf("estoque");
    printf("\t");
    printf("pre�o");
    printf("\t");
    printf("Nome do produto \e[m \033[0m");
    printf("\n");

    for(int i = 0; i < quantityProducts; i++) {
        printf("%d", (productList+i)->code);
        printf("\t");
        printf("%c", (productList+i)->category);
        printf("\t");
        printf("\t");
        printf("%d", (productList+i)->stock);
        printf("\t");
        printf("%0.2f", (productList+i)->price);
        printf("\t");
        printf("%s", (productList+i)->description);
        printf("\n");
    }
}
//SECAO DE RELATORIOS:
// CLIENTE
static void clientsRecordsMenu(CLIENT *clientList, int clientQuantity) {
    cleanChat();
    printf("._____________________- CLIENTES CADASTRADOS -______________________.\n");

    printf("\e[1m\033[0;36mcódigo");
    printf("\t");
    printf("\t");
    printf("Nome Social");
    printf("\t");
    printf("\t");
    printf("celular");
    printf("\t");
    printf("\t");
    printf("Bairro \e[m \033[0m");
    printf("\n");

    for(int i = 0; i < clientQuantity; i++) {
        printf("%d", (clientList+i)->code);
        printf("\t");
        printf("\t");
        printf("%s", (clientList+i)->socialName);
        printf("\t");
        printf("\t");
        printf("%d", (clientList+i)->cellphone);
        printf("\t");
        printf("\t");
        printf("%s", (clientList+i)->neighborhood);
        printf("\t");
        printf("\n");
    }
}
