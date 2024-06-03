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

typedef struct sale{
    int code;
    char description[40];
    char category[15];
    float rawPrice;
    float gain;
    float finalPrice;
    int quantityOnStock;
    int minimumStock;
} SALE;

#endif /* STRUCTHEADER_H */