/*
 * Nexus.h
 *      Author: Marcos
 */

#ifndef NEXUS_H_
#define NEXUS_H_

#include "Input.h"
#include "Products.h"
#include "ProductType.h"
#include "ProductNation.h"

int printProductsWithType(sProduct* prodList, int prodLen, sType* typeList, int typeLen, sNation* nationList, int natLen);
int printMadeInChina(sProduct* prodList, int prodLen, sType* typeList, int typeLen, sNation* nationList, int nationLen);
int printOnlyOne(sProduct prodList, sType* typeList, int typeLen, sNation* nationList, int natLen);


#endif /* NEXUS_H_ */
