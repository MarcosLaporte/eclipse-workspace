/*
 * Productos.h
 *      Author: Marcos
 */

#ifndef PRODUCTS_H_
#define PRODUCTS_H_
#include "Input.h"

#define EMPTY 0
#define FULL 1
// nationality
#define EEUU 1
#define CHINA 2
#define OTRO 3
// type
#define IPHONE 1
#define MAC 2
#define IPAD 3
#define ACCESORIOS 4

typedef struct {
	int idProduct; //PK
	char description[51];
	int nationality; //FK
	int type; //FK
	float price;
	int status;
} sProduct;

int initProduct(sProduct *list, int len);
sProduct getProduct();
int addProduct(sProduct *list, int len);
void printOneProduct(sProduct aProduct);
int printAllProducts(sProduct *list, int len);
int findProductById(sProduct *list, int len, int id);
int checkAnyProduct(sProduct *list, int len);
int removeProduct(sProduct *list, int len);
int modifyProduct(sProduct *list, int len);
void sortProductPrice(sProduct *list, int len);
void sortProductDescr(sProduct *list, int len);
float highestPrice(sProduct *list, int len);
int printByPrice(sProduct *list, int len, float searchedPrice);
int highestPriceProducts(sProduct *list, int len);
int averagePrice(sProduct *list, int len, float averagePrices[]);
int printAveragePerType(sProduct *list, int len, float prices[]);
float lowestPrice(sProduct *list, int len);
int lowestPriceProducts(sProduct *list, int len);
int findActiveId(sProduct* list, int len, int id);

#endif /* PRODUCTS_H_ */
