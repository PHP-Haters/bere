
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
    char name[100];
    char socialName[100];
    int cpf;
    char address[100];
    char neighborhood[100];
    int cellphone;
} CLIENT;

typedef struct sale{
    int code;
    char description[40];
    char category[15];
    float rawPrice;
    float gain;
    float finalPrice;
    PRODUCT produtos[100];
    int quantity[100];
    CLIENT cliente;
} SALE;

void cleanChat();
#endif /* STRUCTHEADER_H */
