#ifndef STRUCTHEADER_H
#define STRUCTHEADER_H

typedef struct product{
    int code;
    char description[100];
    char category;
    float price;
    float profitMargin;
    float sellingPrice;
    int stock;
    int minimumStock;

} PRODUCT;

typedef struct client{
    int code;
    char name[50];
    char socialName[50];
    int cpf;
    char rua[20];
    char bairro[20];
    int telefone;
    
} CLIENT;

#endif /* STRUCTHEADER_H */