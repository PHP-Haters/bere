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


#endif /* STRUCTHEADER_H */

