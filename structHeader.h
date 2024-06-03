#ifndef AVO_H
#define AVO_H
extern struct produto{

    int codigo;
    char descricao[100];
    int categoria;
    float preco;
    float margemDeLucro;
    float precoDeVenda;
    int estoque;
    int estoqueMinimo;

};

#endif /* AVO_H */

