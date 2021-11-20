/*
 * Nexus.c
 *      Author: Marcos
 */

#include "Nexus.h"

int addRequest(sClient* clientsList, int cliLen, sRequest* requestList, int reqLen, int requestId, sLocality* localList, int localLen){
	int Return;
	int index;
	int id;
	int tries;
	Return = -1;
	index = -1;
	tries = 2;

	if(clientsList != NULL && cliLen > 0 && requestList != NULL && reqLen > 0){
		index = findFreeSpaceRequest(requestList, reqLen);
		if(index != -1){
			printClientList(clientsList, MAX_CLIENT, localList, MAX_LOCAL);
			getFinalInt(&id, "Ingrese el ID del cliente a cargo del pedido: ", "ERROR! Ingrese un ID numérico mayor a 0: ", 1, 99999);
			while(findClientById(clientsList, cliLen, id) == -1 && tries > 0){
				printf("ERROR! El ID ingresado no existe. Le quedan %d intentos. ", tries);
				getFinalInt(&id, "Reingrese: ", "ERROR! Ingrese un ID numérico mayor a 0: ", 1, 99999);
				tries--;
			}
			if(findClientById(clientsList, cliLen, id) != -1){
				requestList[index].clientId = id;
				requestList[index].id = requestId;
				getFinalFloat(&requestList[index].kilosTotal, "Ingrese la cantidad de kilos de residuos a recolectar: ",
												"ERROR! Ingrese una cantidad numérica mayor a 0 y menor a 20000: ", 0, 20000);
				requestList[index].status = PENDING;
				requestList[index].isEmpty = FULL;
				Return = 1;
			}

			initPendingRequests(clientsList, cliLen);
			for(int i = 0; i < cliLen; i++){
				if(clientsList[i].status == FULL){
					countRequestsByClient(clientsList, cliLen, requestList, reqLen, clientsList[i].id);
				}
			}
		}else{
			Return = 0;
		}
	}

	return Return;
}

int printPendingRequestList(sClient* clientsList, int cliLen, sRequest* requestList, int reqLen){
	int Return;
	Return = -1;

	if(clientsList != NULL && cliLen > 0 && requestList != NULL && reqLen > 0){
		Return = 0;
		printf("#===================================================================#\n");
//		printf("|%-10s|%-15s|%-31s|%-8s|\n", "ID Pedido", "CUIT", "Dirección", "Kilos");
		printf("|ID Pedido |     CUIT      |           Dirección           | Kilos  |\n");
		printf("#==========+===============+===============================+========#\n");
		for(int i = 0; i < reqLen; i++){
			printPendingRequest(clientsList, cliLen, requestList[i]);
		}
		printf("#==========+===============+===============================+========#\n");
	}

	return Return;
}

int printPendingRequest(sClient* clientsList, int cliLen, sRequest request){
	int Return;
	int index;
	Return = -1;

	if(clientsList != NULL && cliLen > 0){
		if(request.isEmpty == FULL && request.status == PENDING){
			index = findClientById(clientsList, cliLen, request.clientId);
			if(clientsList[index].status == FULL && clientsList[index].id == request.clientId){
				printf("|%10d|%15s|%25s %5d|%8.2f|\n", request.id, clientsList[index].cuit,
						clientsList[index].direction.address, clientsList[index].direction.number,
						request.kilosTotal);
				Return = 0;
			}
		}
	}

	return Return;
}

int loadRequest(sClient* clientsList, int cliLen, sRequest* requestList, int reqLen){
	int Return;
	int index;
	int id;
	int tries;
	Return = -1;
	tries = 2;

	if(requestList != NULL && reqLen > 0 && clientsList != NULL && cliLen > 0){
		printPendingRequestList(clientsList, MAX_CLIENT, requestList, MAX_REQUEST);
		getFinalInt(&id, "Ingrese el ID del pedido a procesar: ", "ERROR! Ingrese un ID numérico mayor a 0: ", 1, 99999);
		index = findRequestById(requestList, reqLen, id);
		while(index == -1 && tries > 0){
			printf("ERROR! El ID ingresado no existe. Le quedan %d intentos. ", tries);
			getFinalInt(&id, "Reingrese: ", "ERROR! Ingrese un ID numérico mayor a 0: ", 1, 99999);
			index = findRequestById(requestList, reqLen, id);
			tries--;
		}
		if(index != -1){
			getPlasticTypes(requestList[index].kilosTotal, &requestList[index].kilosHDPE, &requestList[index].kilosLDPE, &requestList[index].kilosPP, &requestList[index].kilosWaste);
			requestList[index].status = COMPLETED;
			Return = 0;

			initPendingRequests(clientsList, cliLen);
			for(int i = 0; i < cliLen; i++){
				if(clientsList[i].status == FULL){
					countRequestsByClient(clientsList, cliLen, requestList, reqLen, clientsList[i].id);
				}
			}
		}

	}

	return Return;
}

int countRequestsByClient(sClient* clientsList, int cliLen, sRequest* requestList, int reqLen, int clientId){
	int Return;
	int index;
	Return = -1;

	if(clientsList != NULL && cliLen > 0 && requestList != NULL && reqLen > 0){
		for(int i = 0; i < reqLen; i++){
			if(requestList[i].isEmpty == FULL
					&& requestList[i].status == PENDING
					&& requestList[i].clientId == clientId){
				index = findClientById(clientsList, cliLen, clientId);
				clientsList[index].pendingRequests++;
				Return = 0;
			}
		}
	}

	return Return;
}

int countCompletedRequestsByClient(sClient* clientsList, int cliLen, sRequest* requestList, int reqLen, int clientId){
	int Return;
	int index;
	Return = -1;

	if(clientsList != NULL && cliLen > 0 && requestList != NULL && reqLen > 0){
		for(int i = 0; i < reqLen; i++){
			if(requestList[i].isEmpty == FULL
					&& requestList[i].status == COMPLETED
					&& requestList[i].clientId == clientId){
				index = findClientById(clientsList, cliLen, clientId);
				clientsList[index].completedRequests++;
				Return = 0;
			}
		}
	}

	return Return;
}

int printCompletedRequests(sClient* clientsList, int cliLen, sRequest* requestList, int reqLen){
	int Return;
	Return = -1;

	if(clientsList != NULL && cliLen > 0 && requestList != NULL && reqLen > 0){
		Return = 0;
		printf("#=====================================================================================#\n");
//		printf("|%-10s|%-15s|%-31s|%-8s|%-8s|%-8s|\n", "ID Pedido", "CUIT", "Dirección", "HDPE", "LDPE", "PP");
		printf("|ID Pedido |     CUIT      |           Dirección           |  HDPE  |  LDPE  |   PP   |\n");
		printf("#==========+===============+===============================+========+========+========#\n");
		for(int i = 0; i < cliLen; i++){
//			if(clientsList[i].status == FULL){
				printCompletedRequestByClientId(requestList, reqLen, clientsList, cliLen, clientsList[i].id);
//			}
		}
		printf("#=====================================================================================#\n");
	}

	return Return;
}
//Mostrar pedido completado por id de cliente
int printCompletedRequestByClientId(sRequest* requestList, int reqLen, sClient* clientsList, int cliLen, int clientId){
	int Return;
	sClient aux;
	Return = -1;

	if(requestList != NULL && reqLen > 0){
		for(int i = 0; i < reqLen; i++){
			if(requestList[i].isEmpty == FULL && requestList[i].status == COMPLETED && requestList[i].clientId == clientId){
				aux = searchClientById(clientsList, cliLen, requestList[i].clientId);
				printf("|%10d|%15s|%25s %5d|%8.2f|%8.2f|%8.2f|\n",
										requestList[i].id, aux.cuit,
										aux.direction.address,
										aux.direction.number,
										requestList[i].kilosHDPE, requestList[i].kilosLDPE,
										requestList[i].kilosPP);
				Return = 0;
			}
		}
	}

	return Return;
}

int countAveragePP(sClient* clientsList, int cliLen, sRequest* requestList, int reqLen, float* average){
	int Return;
	float accumPP;
	int count;
	Return = -1;
	accumPP = 0;
	count = 0;

	if(clientsList != NULL && cliLen > 0 && requestList != NULL && reqLen > 0){
		for(int i = 0; i < reqLen; i++){
			if(requestList[i].isEmpty == FULL && requestList[i].status == COMPLETED){
				accumPP += requestList[i].kilosPP;
				count++;
				Return = 0;
			}
		}
	}
	if(count != 0){
		*average = accumPP/count;
	}

	return Return;
}

int printClient(sClient client, sLocality* localList, int localLen){
	int Return;
	int index;
	Return = -1;

	if(client.status == FULL){
		Return = 0;
		index = findLocalityById(localList, localLen, client.direction.idLocal);
		printf("|%4d|%50s|%15s|%25s %5d|%20s|%7d|\n", client.id,
			client.companyName, client.cuit, client.direction.address, client.direction.number, localList[index].description, client.pendingRequests);
	}

	return Return;
}

int printClientList(sClient* list, int len, sLocality* localList, int localLen){
	int Return;
	Return = -1;

	if(list != NULL && len > 0){
		Return = 0;
		printf("#====================================================================================================================================#\n");
		printf("| ID |               Nombre de la empresa               |      CUIT     |           Dirección           |     Localidad      |Pedidos|\n");
		printf("#====+==================================================+===============+===============================+====================+=======#\n");
		for(int i = 0; i < len; i++){
			printClient(list[i], localList, localLen);
		}
		printf("#====================================================================================================================================#\n");
	}

	return Return;
}


int calculateLocalityRequests(sClient* list, int len, int localityId, int* accum){
	int Return;
	Return = -1;
	*accum = 0;

	if(list != NULL && len > 0){
		for(int i = 0; i < len; i++){

//			if(strcmp(strlwr(list[i].direction.locality), strlwr(locality)) == 0){
			if(list[i].direction.idLocal == localityId){
				*accum += list[i].pendingRequests;
				Return = 0;
			}
		}
	}

	return Return;
}

int printLocalityRequests(sClient* list, int len, sLocality* localList, int localLen){
	int Return;
	int aux;
	int accum;
	int index;
	Return = -1;

	if(list != NULL && len > 0){
		printClientList(list, len, localList, localLen);
//		getString("Ingrese una localidad para ver la cantidad de pedidos pendientes: ", aux, MAX_CHARAC);
		getFinalInt(&aux, "¬ Elija la localidad de la empresa.\n\t1. Barracas\n\t2. Avellaneda\n\t3. MicroCentro\n\t4. Once\n\t5. Flores."
								"\n\tIngrese una opción para ver sus pedidos pendientes: ", "ERROR! Ingrese una localidad existente: ", 1, 5);
//		while(calculateLocalityRequests(list, len, aux, &accum) == -1){
//			getString("ERROR! Ingrese una localidad existente: ", aux, MAX_CHARAC);
//		}

		index = findLocalityById(localList, localLen, aux);
		if(calculateLocalityRequests(list, len, aux, &accum) == 0){
			printf("La cantidad de pedidos en la localidad '%s' es: %d.\n", localList[index].description, accum);
			Return = 0;
		}
	}

	return Return;
}

int calcMostPendingRequestsClient(sClient* cliList, int cliLen, sLocality* localList, int localLen, sClient* mostRequestClient){
	int Return;
	int maxRequests;
	Return = -1;
	maxRequests = 0;

	if(cliList != NULL && cliLen > 0 && localList != NULL && localLen > 0){
		for(int i = 0; i < cliLen; i++){
			if(cliList[i].status == FULL && cliList[i].pendingRequests > maxRequests){
				maxRequests = cliList[i].pendingRequests;
				*mostRequestClient = cliList[i];
				Return = 0;
			}
		}
	}

	return Return;
}

void printMostRequestsClient(sClient client, sLocality* localList, int localLen){

	printf("\nEl cliente con más pedidos pendientes es:\n");
	int index = findLocalityById(localList, localLen, client.direction.idLocal);
	printf("#====================================================================================================================================#\n");
	printf("| ID |               Nombre de la empresa               |      CUIT     |           Dirección           |     Localidad      |Pedidos|\n");
	printf("#====+==================================================+===============+===============================+====================+=======#\n");
	printf("|%4d|%50s|%15s|%25s %5d|%20s|%7d|\n", client.id,
		client.companyName, client.cuit, client.direction.address, client.direction.number, localList[index].description, client.pendingRequests);
	printf("#====================================================================================================================================#\n");
}

int calcMostCompletedRequestsClient(sClient* cliList, int cliLen, sLocality* localList, int localLen, sClient* mostRequestClient){
	int Return;
	int maxRequests;
	Return = -1;
	maxRequests = 0;

	if(cliList != NULL && cliLen > 0 && localList != NULL && localLen > 0){
		for(int i = 0; i < cliLen; i++){
			if(cliList[i].status == FULL && cliList[i].completedRequests > maxRequests){
				maxRequests = cliList[i].completedRequests;
				*mostRequestClient = cliList[i];
				Return = 0;
			}
		}
	}

	return Return;
}

int calcMostRequestsClient(sClient* cliList, int cliLen, sLocality* localList, int localLen, sClient* mostRequestClient){
	int Return;
	int maxRequests;
	Return = -1;
	maxRequests = 0;

	if(cliList != NULL && cliLen > 0 && localList != NULL && localLen > 0){
		for(int i = 0; i < cliLen; i++){
			if(cliList[i].status == FULL && (cliList[i].pendingRequests + cliList[i].completedRequests) > maxRequests){
				maxRequests = cliList[i].pendingRequests + cliList[i].completedRequests;
				*mostRequestClient = cliList[i];
				Return = 0;
			}
		}
	}

	return Return;
}



void hardcodeClients(sClient* clientsList, sRequest* requestList, int maxClients, int* ids, int maxRequests, int* reqIds){

	char names[MAX_CLIENT][MAX_CHARAC] = { "Apple Inc.",
			"Microsoft Corporation", "Saudi Arabian Oil Co", "Alphabet Inc",
			"Amazon.com, Inc.", "Facebook Incorporation", "Tesla Inc",
			"Berkshire Hathaway Inc.", "Tencent Holdings Limited",
			"Taiwan Semiconductor Manufacturing Company Limited",
			"NVIDIA Corporation", "JPMorgan Chase & Co.", "Visa Incorporation",
			"Alibaba Group Holding Ltd", "Johnson & Johnson",
			"UnitedHealth Group Incorporated",
			"Samsung Electronics Company Limited", "Walmart Inc",
			"LVMH Moet Hennessy Louis Vuitton SE",
			"Bank of America Corporation", "Kweichow Moutai Co., Ltd.",
			"Home Depot Inc", "Mastercard, Inc.", "Procter & Gamble Co",
			"Nestle S.A.", "Roche Holding Aktiengesellschaft",
			"ASML Holding NV", "Paypal Holdings Inc", "Walt Disney Co",
			"Adobe Inc", "Salesforce.Com, Inc.", "Netflix Inc",
			"Exxon Mobil Corporation",
			"Industrial and Commercial Bank of China Ltd", "Oracle Corporation",
			"Nike Inc.", "Comcast Corporation", "Toyota Motor Corporation",
			"L'Oreal", "Coca-Cola Co", "China Construction Bank Corp",
			"Novo Nordisk As", "Cisco Systems Incorporated", "Pfizer Inc.",
			"Thermo Fisher Scientific Inc.", "Reliance Industries Limited",
			"Eli Lilly and Company", "Intel Corporation", "Meituan",
			"Pepsico Inc.", "Verizon Communications", "Accenture Plc",
			"Danaher Corporation", "Chevron Corporation",
			"China Merchants Bank Co Ltd", "Abbott Laboratories",
			"Broadcom Inc", "Contemporary Amperex Technology Co Ltd",
			"Costco Wholesale Corporation", "Merck & Co. , Inc.",
			"Wells Fargo & Company", "Abbvie Inc", "Royal Dutch Shell Plc",
			"Novartis AG", "Morgan Stanley", "AT&T Inc.", "Mcdonald's Corp",
			"Texas Instruments Incorporated", "Tata Consultancy Services Ltd",
			"Shopify Inc", "SAP SE", "Medtronic PLC", "PetroChina Co Ltd",
			"United Parcel Service, Inc.", "Agricultural Bank Of China Limited",
			"NextEra Energy Inc", "Linde PLC", "AstraZeneca PLC",
			"Hermes International SCA",
			"Philip Morris International Incorporation",
			"Lowe's Companies Inc.", "Charles Schwab Corp",
			"Honeywell International Incorporated", "Intuit Inc.",
			"Royal Bank of Canada", "Union Pacific Corporation",
			"Qualcomm Incorporated", "T-Mobile Us Inc", "BHP Group Ltd",
			"Ping An Insurance (Group) Company Of China Ltd",
			"Keyence Corporation", "Citigroup Inc.",
			"Wuliangye Yibin Company Limited", "American Express Company",
			"Bank of China Ltd", "Sony Group Corp", "Prosus NV",
			"Christian Dior SE", "Blackrock, Incorporation",
			"China Life Insurance Co Ltd" };

	char cuit[MAX_CLIENT][14] = { "30-80251517-2", "30-86351003-9",
			"30-72931789-4", "30-57894355-4", "30-23227006-4", "30-52922074-3",
			"30-43001844-7", "30-72825602-1", "30-29460519-3", "30-71281721-9",
			"30-15544861-1", "30-89736585-4", "30-67351621-7", "30-61565485-8",
			"30-88601117-7", "30-36506239-2", "30-55611694-5", "30-11327544-4",
			"30-94987285-8", "30-22147534-2", "30-68783988-5", "30-59461624-7",
			"30-58743023-7", "30-63287089-4", "30-36910541-8", "30-21009551-2",
			"30-22020476-2", "30-14135436-6", "30-64333249-3", "30-36642059-5",
			"30-66230972-9", "30-34180573-1", "30-35278090-9", "30-27399416-6",
			"30-49690568-7", "30-72741301-1", "30-51914385-7", "30-51453370-5",
			"30-33933400-8", "30-16181126-5", "30-24058870-7", "30-86430920-7",
			"30-62818577-6", "30-27408010-5", "30-55415045-3", "30-36657640-2",
			"30-87866138-6", "30-83987760-3", "30-14073746-5", "30-76242792-9",
			"30-67492053-5", "30-88413379-4", "30-64766087-5", "30-22919652-8",
			"30-45021622-2", "30-37645383-2", "30-91014837-1", "30-61016619-5",
			"30-80741246-3", "30-50174396-2", "30-62868392-2", "30-77526167-7",
			"30-81004560-8", "30-72951843-2", "30-96257602-2", "30-87716586-1",
			"30-64956913-5", "30-75742053-1", "30-38073677-1", "30-18656585-1",
			"30-29767716-2", "30-23951583-8", "30-51623384-6", "30-66907576-9",
			"30-96657782-7", "30-92904078-3", "30-22711305-9", "30-58012903-8",
			"30-54199045-7", "30-57204642-1", "30-24463366-7", "30-61734331-7",
			"30-61110792-8", "30-16916772-1", "30-92033857-0", "30-89986246-2",
			"30-62178130-7", "30-19845811-1", "30-78849644-2", "30-60908155-4",
			"30-10626200-6", "30-31948238-4", "30-79768249-3", "30-92663322-7",
			"30-71474015-4", "30-35654525-9", "30-26250248-1", "30-52578875-5",
			"30-32039914-6", "30-95098737-4"};

	char address[MAX_CLIENT][MAX_CHARAC] = {"a", "b", "c", "d", "e", "f", "g", "h", "i",
			"j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v",
			"w", "x", "y", "z", "aa", "ab", "ac", "ad", "ae", "af", "ag", "ah",
			"ai", "aj", "ak", "al", "am", "an", "ao", "ap", "aq", "ar", "as",
			"at", "au", "av", "aw", "ax", "ay", "az", "ba", "bb", "bc", "bd",
			"be", "bf", "bg", "bh", "bi", "bj", "bk", "bl", "bm", "bn", "bo",
			"bp", "bq", "br", "bs", "bt", "bu", "bv", "bw", "bx", "by", "bz",
			"ca", "cb", "cc", "cd", "ce", "cf", "cg", "ch", "ci", "cj", "ck",
			"cl", "cm", "cn", "co", "cp", "cq", "cr", "cs", "ct", "cu", "cv"};

	int number[MAX_CLIENT] = { 2351, 2322, 2019, 2301, 1824, 1020,
			1923, 2536, 2719, 2721, 1701, 1440, 1035, 2338,
			2339, 1749, 1524, 1453, 1462, 1905, 1844, 1247,
			2760, 2747, 1537, 1864, 1532, 1060, 1364, 1201,
			2360, 2169, 2767, 1970, 2771, 1119, 1566, 2777,
			1876, 2081, 1082, 2538, 10901, 12205, 14411, 14228,
			12010, 13021, 14020, 14420, 13031, 14424, 12414,
			11720, 13036, 14225, 13039, 14031, 13041, 12043,
			11725, 13045, 12061, 11554, 13057, 13637, 11735,
			12524, 14063, 13069, 14454, 14456, 12077, 12302,
			14626, 12065, 14075, 13350, 14843, 14845, 14850,
			13790, 12095, 12401, 14750, 14086, 12110, 14094,
			13367, 14502, 12953, 11758, 13662, 11953, 10940,
			10547, 10950, 12701, 13413, 12550};

/*	char locality[MAX_CLIENT][MAX_CHARAC] = {"Hornell", "Johnson City",
			"Leicester", "Orange", "Tewksbury", "Leominster", "East Falmouth",
			"Sturbridge", "Canandaigua", "Hanover", "CABA", "Auburn",
			"Kingston", "Lancaster", "Monroe", "East Greenbush", "Salem",
			"Catskill", "Glenville", "Halfmoon", "CABA", "Ithaca",
			"Chicopee", "Plymouth", "CABA", "Albany", "Commack", "Fishkill",
			"Fulton", "Hamburg", "Malone", "Abington", "Northhampton",
			"East Syracuse", "Brockport", "Hudson", "Monticello",
			"Mohegan Lake", "Lowville", "Lockport", "North Oxford", "Swansea",
			"Cheektowaga", "East Meadow", "Herkimer", "Raynham", "Farmingdale",
			"Macedon", "Springfield", "Geneva", "Central Square", "Halifax",
			"Danvers", "North Adams", "Framingham", "Walpole", "Clay",
			"Amsterdam", "CABA", "Lakewood", "Wareham", "Massena",
			"North Attleboro", "Airmont", "Evans Mills", "Middle Island",
			"Ware", "Lunenburg", "Gardner", "CABA", "Geneseo",
			"Clarence", "Newburgh", "Pittsfield", "Fairhaven", "Glenmont",
			"Hadley", "Fall River", "North Dartmouth", "Centereach", "Avon",
			"Amherst", "Greece", "Chelmsford", "CABA", "Seekonk",
			"Methuen", "Albion", "CABA", "Fredonia", "Quincy", "Lynn",
			"New Hartford", "Johnstown", "Bellingham", "Cobleskill", "Cicero",
			"Massapequa", "Latham", "Batavia"};*/
	int locality[MAX_CLIENT] = {2, 1, 4, 5, 2, 4, 1, 2, 2, 5, 2, 1, 2, 2, 3, 1, 4, 5, 1, 2, 2, 3, 3, 4, 1, 1, 2, 2, 3, 5, 3, 1, 5, 5, 1, 1, 5, 2, 1, 4, 3, 5, 3, 2, 4, 5, 3, 3, 1, 4, 5, 3, 4, 4, 4, 2, 3, 1, 5, 1, 4, 4, 2, 5, 4, 1, 2, 5, 4, 3, 1, 5, 2, 2, 3, 4, 5, 3, 5, 3, 3, 4, 2, 5, 4, 3, 3, 4, 3, 5, 2, 1, 1, 5, 3, 4, 1, 1, 4, 5};

	float totalK[MAX_REQUEST] = {19663, 770, 17815, 17286, 15390, 1074, 2065, 7211, 8499, 2812, 9206, 6893, 11377, 1405, 15725, 15196, 2303, 2224, 7201, 17843, 2769, 6919, 3193, 7881, 7494, 11062, 14482, 18079, 10560, 7535, 17766, 12614, 1111, 15943, 8865, 10903, 17565, 6879, 5942, 13533, 7058, 5030, 15770, 8068, 3497, 5624, 10797, 6274, 19805, 11508, 12048, 18308, 604, 7064, 3776, 6446, 11887, 17501, 7428, 7888, 6989, 16551, 11168, 12705, 740, 10460, 17716, 891, 8060, 961, 7394, 14441, 14777, 763, 3828, 15535, 8037, 11548, 8498, 18974, 7789, 7967, 9145, 18652, 7060, 15984, 6558, 13755, 19613, 17813, 10205, 17233, 10984, 8268, 10643, 10492, 4496, 4563, 5614, 13645, 15140, 521, 13287, 19817, 6158, 15120, 9445, 4520, 1706, 13502, 14689, 10259, 6130, 1637, 4982, 3022, 17282, 6404, 19184, 15753, 7751, 3343, 4267, 10095, 7100, 9303, 9195, 5867, 4565, 19158, 6646, 19096, 16869, 16077, 18240, 12318, 3811, 4068, 18316, 9355, 2349, 645, 7817, 15408, 2180, 11910, 12445, 8845, 17029, 7333, 2968, 3370, 3180, 19352, 3161, 9764, 1565, 18013, 14382, 10058, 17470, 2424, 3309, 9940, 12213, 5077, 4611, 903, 15416, 2903, 2433, 7254, 13674, 12859, 12954, 17308, 5464, 14816, 1277, 19889, 10939, 14775, 14794, 12175, 1931, 19487, 14631, 3543, 9788, 3653, 5071, 973, 4603, 17075, 12821, 18182, 4080, 3523, 1879, 13274, 8404, 9075, 12959, 17839, 15192, 15953, 16666, 7976, 10203, 7527, 18676, 18125, 6277, 10059, 14773, 1835, 8102, 13223, 18772, 7702, 19950, 12943, 4175, 5612, 5398, 388, 18829, 4695, 10670, 3103, 19377, 2379, 18196, 17730, 14603, 4510, 6271, 5996, 5028, 12983, 6731, 5533, 13468, 10870, 1292, 17619, 11423, 4734, 8099, 14644, 13785, 4908, 15079, 2505, 15286, 19664, 11510, 8919, 271, 15223, 17896, 10624, 15406, 5603, 2997, 10731, 8424, 12908, 8357, 17352, 6653, 14246, 14629, 14683, 15538, 5047, 12972, 19330, 11687, 18323, 6763, 6371, 4940, 10361, 7847, 3441, 5160, 5091, 16576, 1622, 17189, 9772, 11354, 6176, 1388, 19608, 3440, 16229, 4047, 14846, 6123, 11340, 7288, 12285, 17487, 19245, 10775, 541, 11755, 14937, 15459, 9812, 8495, 6060, 2467, 7822, 13088, 10197, 3218, 5430, 12015, 14095, 11204, 14295, 13770, 16816, 8848, 19980, 10616, 2427, 4828, 123, 2668, 15972, 15881, 7101, 9662, 3111, 4884, 16651, 180, 12977, 3930, 11279, 16339, 1817, 4969, 7167, 5294, 17215, 2485, 13331, 17605, 17627, 8588, 19722, 8935, 15998, 18577, 6364, 13613, 16178, 5248, 14326, 9271, 5393, 6968, 3120, 14266, 15176, 14955, 7339, 19917, 8204, 17335, 13908, 18661, 4420, 1446, 7691, 14505, 1065, 13716, 17744, 5565, 14726, 19856, 10130, 3091, 5638, 11361, 8702, 12228, 12854, 8567, 18316, 19890, 4658, 12124, 145, 9552, 1191, 6433, 1336, 8373, 3086, 7001, 19518, 14654, 16728, 4014, 3561, 8901, 87, 6829, 6856, 12538, 12618, 14196, 8940, 19554, 7825, 17253, 4942, 12374, 2935, 18395, 5742, 18772, 17427, 8221, 2817, 13369, 503, 2751, 784, 9639, 18268, 18721, 8810, 16796, 1039, 13610, 5607, 5467, 258, 16161, 3974, 3661, 18644, 9133, 1137, 7335, 19884, 3737, 11270, 8311, 5812, 19564, 7618, 1391, 1468, 11593, 19184, 17241, 17283, 8911, 15833, 12629, 14893, 1778, 5025, 5298, 4287, 13556, 9010, 9725, 19977, 8805, 8229, 1316, 11269, 10854, 12203, 372, 4759, 6724, 11569, 19281, 10185, 3407, 19552, 7215, 19766, 13660, 16139, 4670, 10468, 9755, 15644, 11901, 6613, 4859, 17938, 14699, 352, 3801, 907, 5943, 4825, 3054, 192, 16692, 6639, 7500, 15180, 12499, 17544, 13147, 5273, 370, 9926, 9538, 4734, 17583, 9811, 17239, 8977, 19108, 8762, 6303, 9122, 6938, 15881, 14860, 4807, 15669, 7228, 857, 4636, 19163, 8626, 14943, 8067, 17536, 7746, 7322, 4536, 6511, 9941, 17529, 4034, 2011, 4689, 9825, 15168, 13722, 9, 17217, 12076, 12728, 5641, 1906, 2990, 16052, 9121, 282, 18241, 13192, 1128, 13258, 4401, 12750, 19084, 19596, 1078, 1772, 7804, 5707, 6740, 8157, 3131, 10606, 9128, 5102, 12976, 2568, 2464, 11096, 5358, 13448, 1959, 12524, 16937, 16890, 4080, 9320, 9102, 17513, 17471, 6133, 3893, 3473, 12102, 11331, 15261, 10929, 10918, 15224, 16253, 12006, 3826, 12154, 17634, 2887, 17320, 19951, 12764, 11368, 538, 2182, 4991, 18358, 292, 4994, 11078, 8835, 2368, 4123, 1063, 7133, 14029, 13384, 9069, 15327, 3117, 876, 9200, 18543, 10448, 10934, 7, 13282, 11862, 9669, 12541, 1460, 16415, 3115, 18457, 16415, 8252, 5389, 673, 3314, 184, 8758, 17657, 2816, 14629, 14541, 7637, 11257, 6988, 19391, 12643, 6570, 12453, 6956, 1052, 2049, 6127, 5841, 12269, 10028, 10437, 12771, 7631, 10464, 11452, 8813, 14403, 14597, 11340, 14855, 9038, 1247, 15042, 10336, 19026, 13982, 11471, 13917, 11798, 12145, 2906, 10785, 11795, 16048, 7705, 11271, 2565, 18468, 3257, 15943, 14284, 469, 9631, 10061, 404, 2408, 9014, 6855, 13348, 364, 2561, 17015, 10749, 4677, 9380, 2992, 6145, 8869, 18829, 4594, 14691, 8743, 19912, 14973, 3024, 4624, 13275, 7153, 14539, 13179, 6166, 16544, 15199, 4904, 3751, 1359, 11938, 9319, 14470, 16062, 1101, 10712, 13665, 2688, 18884, 18216, 9087, 1608, 12641, 3754, 6, 17446, 2295, 2446, 18061, 15325, 8144, 2971, 3957, 11067, 11571, 6199, 2084, 6944, 199, 12478, 4930, 8287, 17772, 11902, 3087, 15633, 12981, 15831, 1303, 3725, 4118, 5822, 12938, 11823, 4318, 9773, 16643, 497, 15812, 14816, 12747, 9523, 708, 14581, 11414, 19593, 1500, 10559, 13023, 17340, 13157, 13444, 7437, 3015, 3630, 12513, 5958, 18023, 8934, 5239, 18241, 15776, 7390, 10771, 14798, 11712, 10929, 19865, 13776, 18743, 49, 772, 6356, 15499, 8818, 10980, 3433, 18376, 7380, 13773, 11924, 5295, 15095, 14818, 19056, 6765, 8499, 4962, 1996, 11397, 6394, 14940, 16304, 17989, 11395, 1389, 17862, 15834, 2184, 646, 18651, 17517, 4716, 1760, 2685, 2577, 13628, 19711, 4861, 10069, 5811, 15982, 3215, 7962, 19641, 7121, 14907, 16908, 11571, 1342, 1120, 136, 10623, 17243, 6963, 15506, 1338, 10117, 9839, 18139, 17564, 5449, 10028, 19634, 12420, 6646, 5319, 15899, 6096, 12387, 14236, 14531, 5417, 2427, 12371, 6710, 16551, 9367, 14696, 2811, 12473, 244, 5268, 19979, 9904, 8657, 19357, 3292, 3290, 19843, 15647, 18255, 14447, 15273, 17610, 775, 7578, 9214, 18853, 18135, 7465, 2638, 3378, 2767, 11406, 4068, 1961, 11968, 15740, 8652, 12238, 12280, 5696, 1555, 3452, 10254, 8911, 11104, 16541, 7031, 4409, 11668, 9058, 1327, 6961, 8148, 16972, 13760, 1545, 16421, 473, 9139, 7406, 10990, 16782, 5213, 11647, 3881, 10443, 4479, 1571, 589, 8113, 11648, 4624, 1693, 6336, 16672, 14990, 4105, 18403, 19219, 2060, 8087, 18330, 3900, 11652, 10899, 3079, 19270, 704, 15555, 4596, 7968, 7295, 7033, 1481, 18171, 5657, 7613, 164, 15249, 1035, 12045, 10185, 853, 11952, 1543, 5355};

	float totalHDPE[MAX_REQUEST] = {6711, 256, 14019, 9334, 5500, 635, 239, 6552, 5374, 1507, 449, 1768, 5914, 692, 607, 11835, 611, 731, 6076, 11588, 632, 4611, 971, 4501, 4169, 484, 5574, 6404, 2801, 5681, 1050, 10682, 527, 2843, 3378, 10045, 141, 356, 5135, 4079, 5752, 4083, 6270, 5757, 3089, 4589, 5613, 3626, 7739, 8637, 2157, 1086, 45, 2018, 2067, 3312, 4960, 7287, 5112, 4040, 1418, 5283, 8417, 9523, 697, 3129, 1616, 639, 6459, 581, 7213, 4819, 6094, 373, 2248, 12090, 5705, 8936, 6349, 7916, 535, 1733, 6476, 13127, 2578, 3665, 243, 13455, 8701, 8694, 2261, 7279, 9129, 4861, 8874, 1855, 4247, 373, 2312, 10011, 3156, 192, 8045, 5140, 2354, 11770, 8896, 365, 778, 7388, 3616, 1027, 8, 395, 168, 811, 10308, 2609, 6058, 7655, 5877, 2135, 2578, 4818, 1240, 3419, 316, 3904, 915, 14025, 861, 1281, 1213, 4884, 18178, 1171, 316, 3867, 7132, 7913, 158, 333, 6264, 10083, 815, 10881, 12368, 4896, 7832, 4060, 611, 3265, 1494, 17086, 2443, 4015, 97, 15740, 4366, 6365, 14339, 2039, 2220, 8491, 8175, 3761, 3240, 161, 8163, 671, 1235, 2856, 11446, 2412, 10649, 4266, 3127, 9396, 804, 5206, 7205, 12025, 10805, 3545, 636, 18748, 7791, 2624, 579, 2185, 70, 374, 2825, 7593, 2780, 15977, 3861, 11, 1853, 5219, 6689, 3498, 7522, 8954, 806, 6660, 10806, 53, 9728, 4228, 6404, 14305, 4589, 3122, 9845, 1435, 1811, 12899, 1322, 929, 3740, 579, 1538, 4169, 3513, 15, 17145, 1146, 8900, 1143, 1831, 805, 16468, 10658, 8871, 4376, 2896, 3785, 3474, 6463, 2882, 4098, 11949, 7948, 407, 7678, 9199, 3234, 4968, 10707, 3171, 3014, 11862, 2376, 4651, 848, 7577, 1890, 11, 4746, 5725, 2173, 4708, 1148, 396, 9228, 1386, 7844, 2595, 11720, 3251, 4112, 1102, 5463, 10042, 4369, 8446, 9783, 3506, 15576, 6557, 5142, 1458, 1257, 5482, 986, 709, 22, 6647, 875, 13212, 3875, 10821, 1987, 361, 2434, 2520, 280, 3725, 2438, 4577, 9373, 2145, 10413, 15969, 12302, 9685, 507, 11350, 4614, 14013, 954, 5520, 3358, 1157, 5826, 1419, 3962, 331, 2458, 3683, 161, 509, 3226, 2449, 6415, 2781, 3790, 2516, 210, 572, 42, 2024, 10993, 10636, 994, 8726, 1058, 3209, 7579, 97, 10564, 1308, 933, 565, 1483, 4426, 6697, 3748, 15753, 1685, 10500, 2351, 6713, 5510, 1642, 5329, 11938, 9175, 5818, 12297, 489, 1200, 7980, 1485, 4413, 708, 2631, 5866, 8979, 10505, 4745, 15811, 2097, 16099, 8215, 1781, 1188, 1249, 1189, 10829, 658, 1670, 16261, 2394, 11603, 4169, 6823, 2808, 4652, 6811, 6914, 7870, 4451, 6396, 6867, 14795, 224, 10787, 144, 6380, 67, 5437, 659, 3047, 382, 4969, 18069, 7683, 3566, 1100, 2119, 5790, 53, 447, 5205, 11174, 984, 12830, 927, 19391, 5786, 6508, 2814, 5540, 2210, 6719, 1486, 17176, 2784, 2602, 809, 9352, 116, 472, 77, 8219, 7087, 7372, 747, 15392, 833, 1830, 2891, 197, 231, 5757, 1995, 3531, 8060, 6199, 599, 6565, 621, 3142, 974, 3144, 5724, 4620, 2126, 1095, 1117, 2164, 5124, 1284, 12452, 2004, 12123, 7646, 2494, 469, 4590, 3485, 43, 13341, 3851, 654, 6536, 5743, 6044, 364, 6526, 9898, 3797, 219, 2923, 4660, 1434, 4509, 906, 3134, 19172, 1526, 2401, 8623, 9623, 4246, 10453, 1455, 8866, 5794, 4710, 1949, 14598, 5045, 328, 3267, 838, 5361, 3847, 846, 105, 10541, 2092, 3727, 4474, 2195, 10636, 7521, 1079, 341, 3417, 3763, 731, 10338, 2407, 8606, 3333, 7205, 1863, 2965, 4309, 67, 12826, 6520, 2969, 11611, 1571, 422, 2413, 7334, 2282, 9131, 2344, 6327, 1601, 5976, 3092, 3425, 2088, 10953, 2379, 1941, 925, 8035, 2023, 4518, 7, 11501, 365, 3860, 16, 480, 500, 7805, 2263, 71, 8250, 8902, 531, 3918, 1948, 10912, 5055, 12326, 991, 474, 636, 4959, 215, 3133, 2242, 157, 8468, 4260, 5850, 50, 307, 4703, 5356, 2639, 759, 4377, 2100, 1253, 493, 5862, 1280, 1973, 14543, 4199, 2949, 2576, 5770, 3478, 2776, 3762, 2989, 5581, 5586, 10879, 1158, 956, 3368, 1706, 15030, 18491, 8421, 9177, 19, 108, 2178, 149, 168, 884, 2335, 5109, 840, 1978, 834, 4285, 5062, 9706, 7412, 7134, 268, 533, 1991, 18044, 8411, 10351, 7, 8687, 1237, 2614, 322, 228, 8236, 1124, 3247, 5447, 7325, 1303, 286, 2976, 38, 5432, 10935, 1070, 5616, 11934, 4723, 3141, 1054, 3832, 9151, 3727, 2390, 6878, 867, 904, 2387, 1356, 8849, 1895, 3319, 7063, 5904, 3762, 1287, 6357, 10455, 7030, 10610, 12105, 6088, 407, 2398, 5542, 3279, 4433, 7048, 9413, 11172, 4007, 2040, 1578, 9731, 10129, 6296, 11152, 618, 1510, 759, 4784, 12095, 176, 8428, 7696, 183, 1577, 8553, 1752, 12986, 100, 2059, 12305, 9319, 2941, 9065, 2777, 4378, 1677, 18743, 2572, 8301, 5205, 14769, 9801, 1088, 3259, 591, 1707, 7820, 27, 5857, 13399, 13261, 2293, 2640, 789, 3750, 269, 1165, 9427, 535, 7312, 387, 1074, 2189, 3723, 1953, 810, 6950, 3666, 6, 11654, 673, 1073, 10080, 5671, 4270, 1827, 3259, 8508, 1055, 6038, 1248, 2890, 14, 2877, 2434, 534, 2837, 3828, 1905, 1434, 7979, 13362, 328, 1854, 1655, 1672, 3903, 5392, 3356, 2720, 6503, 373, 15082, 12093, 3006, 3828, 559, 2760, 2024, 8505, 977, 2217, 4608, 16380, 233, 1739, 6550, 491, 3387, 5963, 4322, 4753, 485, 67, 16126, 14082, 5126, 7630, 3311, 719, 7729, 9444, 7422, 6397, 7, 124, 4851, 3423, 601, 9297, 2374, 14747, 5108, 13762, 7928, 2196, 9827, 13627, 3420, 2477, 8431, 2166, 1552, 8803, 5922, 5076, 15506, 692, 9118, 1172, 14774, 15646, 1544, 135, 1677, 13739, 2166, 919, 2339, 711, 13064, 3885, 134, 9266, 2309, 5183, 2297, 2608, 18780, 3569, 8573, 9264, 5675, 498, 810, 35, 8322, 262, 2548, 2478, 502, 8458, 2388, 795, 386, 4876, 2558, 9156, 8438, 53, 719, 3540, 1087, 6566, 7348, 4903, 1200, 641, 948, 2866, 1951, 3450, 7428, 1752, 8022, 219, 2492, 1587, 6416, 3870, 12021, 99, 1176, 14042, 2243, 10949, 7978, 1845, 9593, 448, 7172, 4716, 8432, 8288, 6410, 2086, 1654, 1899, 4749, 1132, 396, 1825, 3616, 7773, 8800, 6906, 4826, 880, 2743, 6920, 3739, 5820, 3143, 2836, 1633, 1872, 307, 1034, 1550, 3091, 3532, 7249, 846, 4334, 392, 6854, 6863, 8577, 15723, 4186, 603, 1095, 1746, 3812, 625, 425, 68, 8770, 3272, 1503, 5577, 7971, 5491, 1159, 11218, 8704, 1387, 2273, 8690, 1860, 5916, 1773, 1014, 1985, 524, 9972, 3330, 5125, 2254, 81, 206, 2934, 4944, 6825, 94, 2534, 583, 5925, 6276, 478, 3374, 957, 4919};

	float totalLDPE[MAX_REQUEST] = {3032, 112, 3607, 5256, 5274, 254, 1633, 307, 2808, 1240, 4268, 1147, 2058, 615, 7733, 1862, 101, 605, 20, 2618, 1229, 805, 1440, 733, 1047, 5319, 2488, 10745, 51, 1638, 9035, 1246, 441, 8541, 2083, 246, 11119, 315, 603, 405, 101, 602, 394, 904, 236, 605, 4034, 1783, 3697, 1616, 4077, 3987, 104, 4790, 624, 2671, 4216, 6320, 49, 3291, 1695, 3238, 379, 1112, 41, 1778, 7501, 248, 614, 271, 163, 7042, 1707, 21, 613, 2739, 1083, 1578, 2000, 7092, 4351, 4197, 1476, 2493, 364, 6559, 3883, 24, 2770, 1671, 5959, 9442, 5, 1451, 1355, 813, 196, 2434, 2694, 1248, 8811, 43, 370, 13442, 2862, 2521, 533, 2873, 306, 3871, 8608, 6367, 4365, 1145, 2231, 1454, 4617, 527, 12712, 1603, 1852, 801, 601, 3011, 2733, 2202, 5773, 225, 2214, 4200, 1929, 7361, 11192, 7468, 53, 4017, 1466, 66, 8537, 736, 2142, 292, 238, 297, 767, 937, 46, 3445, 870, 577, 603, 18, 586, 2235, 277, 5352, 1074, 1385, 7967, 165, 2156, 36, 218, 1419, 3230, 998, 317, 252, 6785, 973, 391, 3493, 1652, 70, 517, 6406, 1163, 270, 240, 10847, 3724, 2267, 455, 5647, 854, 420, 5554, 558, 3772, 221, 609, 375, 1305, 3892, 560, 1702, 208, 1122, 5, 2101, 1171, 1771, 2228, 7490, 1141, 1895, 966, 3937, 430, 475, 10666, 2293, 401, 3426, 882, 87, 83, 140, 9792, 5163, 855, 1257, 13, 1409, 558, 259, 680, 1647, 1287, 1250, 16349, 641, 1542, 55, 4201, 31, 2389, 1252, 1371, 5444, 599, 498, 1117, 1275, 73, 7906, 1939, 134, 829, 598, 6765, 1051, 1905, 2, 9486, 10794, 1481, 6363, 115, 9494, 11459, 3578, 3681, 4174, 163, 1232, 2639, 2264, 5490, 1069, 828, 2433, 10783, 5287, 1219, 602, 787, 5950, 8055, 684, 200, 129, 1122, 6999, 1513, 594, 1683, 4710, 3415, 145, 11, 5326, 506, 1259, 265, 5860, 116, 148, 283, 700, 397, 207, 2826, 689, 1029, 2028, 191, 25, 221, 1949, 57, 864, 1649, 1353, 695, 1331, 390, 5457, 2632, 940, 4597, 8748, 3526, 8522, 6309, 271, 394, 5847, 4513, 2198, 163, 60, 60, 4168, 4820, 349, 894, 449, 1126, 891, 75, 561, 131, 4229, 3041, 30, 268, 368, 1422, 1285, 760, 2451, 1148, 9937, 946, 16859, 3417, 3706, 8235, 221, 921, 13707, 1684, 2063, 6583, 576, 1579, 142, 6688, 5016, 2452, 1248, 576, 3716, 135, 284, 12746, 2601, 122, 3906, 1563, 105, 10043, 1394, 245, 978, 13691, 655, 192, 508, 1142, 776, 2075, 1520, 377, 1715, 2773, 1192, 89, 1, 2125, 520, 939, 399, 1788, 1737, 18, 904, 3674, 8117, 787, 394, 1344, 32, 1442, 1588, 1275, 4542, 1281, 1618, 14, 1165, 10517, 1129, 4313, 292, 732, 3776, 656, 13409, 4873, 1409, 1356, 146, 1439, 151, 487, 7496, 6925, 6788, 191, 99, 4874, 959, 891, 26, 753, 1017, 52, 4723, 1435, 315, 602, 13342, 396, 6872, 5069, 25, 3079, 2598, 103, 251, 8921, 2853, 6640, 1432, 3157, 2652, 1515, 11340, 263, 13, 1421, 2399, 183, 1551, 5096, 11293, 703, 1136, 393, 1589, 163, 6222, 54, 1652, 285, 5104, 7285, 6945, 219, 197, 4870, 10187, 4178, 4064, 225, 2, 6805, 5969, 5953, 17, 2271, 1595, 5644, 14, 415, 8, 475, 431, 129, 61, 703, 3617, 128, 4298, 7314, 2830, 3657, 1899, 14, 699, 1963, 3811, 6396, 6468, 7404, 2906, 2570, 3490, 1454, 4751, 3798, 117, 5581, 1404, 3151, 707, 168, 886, 11607, 6200, 3099, 1312, 10220, 3664, 248, 789, 235, 6157, 5602, 556, 53, 1888, 413, 8093, 1724, 1, 4022, 5891, 8645, 1532, 1066, 1428, 1555, 1435, 205, 6531, 2411, 208, 8765, 731, 1015, 3852, 2943, 76, 867, 2219, 112, 3972, 246, 104, 7423, 253, 104, 3034, 1838, 1972, 5595, 1, 4216, 126, 2371, 4543, 5530, 2521, 1470, 2394, 15046, 426, 120, 539, 608, 2339, 7702, 1668, 5873, 3919, 4160, 1766, 272, 15, 6919, 13055, 768, 951, 1075, 3891, 36, 17, 493, 34, 4014, 51, 809, 7158, 2853, 299, 908, 185, 1119, 4055, 91, 1147, 3100, 1748, 307, 6346, 204, 1581, 116, 0, 2682, 8004, 1822, 7206, 932, 2869, 689, 9250, 2668, 284, 3250, 330, 172, 137, 63, 1238, 640, 3778, 835, 344, 3125, 3033, 14108, 2084, 1059, 8653, 70, 63, 378, 440, 1539, 1838, 7949, 7018, 5592, 1407, 2630, 1725, 1336, 3030, 5668, 135, 1879, 2083, 631, 8906, 4748, 7591, 6436, 3836, 4470, 257, 5245, 554, 180, 1224, 1818, 1210, 20, 175, 8954, 2374, 3621, 1531, 234, 219, 231, 95, 339, 18, 208, 190, 8, 118, 2560, 149, 336, 114, 97, 862, 1540, 39, 924, 2040, 1100, 145, 3549, 678, 542, 4057, 2720, 6182, 1418, 274, 1058, 16, 982, 769, 181, 3438, 4853, 10925, 1353, 564, 1259, 372, 309, 2704, 5935, 2569, 703, 2402, 64, 0, 463, 1230, 1019, 2312, 883, 3774, 973, 356, 269, 2243, 123, 267, 2807, 32, 1824, 252, 7421, 10944, 5206, 336, 696, 2350, 577, 601, 1750, 1912, 2546, 7371, 6356, 940, 6814, 8842, 94, 332, 1555, 1461, 3516, 125, 3457, 5485, 2488, 260, 6039, 2145, 862, 597, 10498, 425, 733, 52, 3784, 861, 3354, 2284, 3018, 1086, 1611, 63, 2463, 7992, 970, 122, 1247, 3925, 599, 26, 36, 361, 2611, 268, 763, 840, 102, 1544, 10, 1233, 3076, 3037, 812, 9584, 2503, 52, 420, 122, 2499, 169, 4927, 366, 12878, 1205, 112, 2771, 79, 9, 188, 6464, 3205, 704, 251, 326, 890, 474, 2465, 3131, 801, 1035, 3677, 595, 3947, 487, 2813, 396, 5036, 1514, 553, 97, 36, 572, 11008, 740, 10253, 165, 695, 450, 10023, 16806, 463, 1764, 7547, 972, 3283, 2932, 5038, 3791, 450, 1385, 5753, 3668, 444, 6630, 269, 11002, 846, 6655, 482, 3087, 23, 1215, 13700, 2174, 844, 3264, 2883, 697, 2491, 374, 4779, 1966, 12208, 7258, 174, 228, 3004, 9629, 296, 906, 408, 336, 559, 3872, 462, 959, 7934, 3437, 342, 2098, 1085, 770, 350, 193, 2148, 1382, 2624, 10165, 2794, 615, 8666, 1818, 204, 511, 4006, 12122, 3559, 38, 6495, 64, 1567, 356, 647, 957, 657, 6522, 1349, 5592, 282, 779, 4, 6731, 2857, 905, 144, 569, 7815, 7578, 963, 332, 10243, 26, 1451, 5703, 342, 1459, 117, 412, 9726, 93, 4038, 127, 46, 3028, 98, 938, 12415, 605, 285, 6, 5853, 30, 4969, 3200, 286, 5325, 378, 160};

	float totalPP[MAX_REQUEST] = {5380, 370, 53, 370, 2271, 40, 36, 31, 166, 29, 2523, 3139, 905, 6, 390, 1245, 290, 803, 632, 585, 427, 1075, 407, 366, 1327, 2716, 4797, 278, 3566, 163, 6917, 66, 128, 2046, 2115, 335, 5393, 5624, 183, 1369, 1135, 104, 6177, 1107, 20, 423, 294, 169, 6455, 729, 3985, 183, 195, 6, 789, 342, 1515, 3399, 1510, 163, 1564, 1009, 1583, 1542, 1, 2986, 7399, 3, 715, 11, 18, 2295, 5130, 273, 528, 114, 782, 971, 6, 3488, 980, 1265, 960, 897, 3583, 716, 2192, 219, 7542, 3869, 869, 388, 864, 516, 27, 2189, 12, 521, 105, 1861, 1935, 164, 584, 27, 69, 371, 4, 284, 324, 627, 1782, 35, 1004, 34, 1935, 315, 1909, 219, 48, 3033, 7, 194, 949, 1645, 1914, 748, 1533, 614, 725, 308, 2757, 6527, 3736, 738, 5, 7019, 1221, 115, 543, 527, 35, 5, 771, 3320, 178, 4, 27, 79, 6279, 2487, 1675, 66, 596, 17, 95, 104, 260, 186, 1368, 2911, 689, 18, 580, 29, 88, 143, 419, 105, 169, 12, 314, 282, 62, 5032, 1319, 3073, 566, 2319, 171, 2384, 5, 94, 1953, 1954, 254, 60, 397, 296, 2956, 316, 2218, 208, 157, 2562, 349, 204, 1, 743, 21, 3993, 201, 3701, 1896, 780, 11126, 2659, 4373, 3323, 44, 2497, 1449, 1155, 302, 620, 1630, 108, 3993, 164, 2630, 871, 10441, 6947, 873, 25, 463, 93, 229, 1275, 331, 432, 236, 372, 8, 5207, 907, 102, 218, 412, 175, 44, 159, 98, 308, 875, 464, 1266, 243, 102, 254, 1347, 1181, 746, 176, 15, 850, 1422, 1485, 592, 0, 495, 229, 3874, 3412, 205, 1082, 52, 2069, 539, 32, 3272, 1114, 2384, 2734, 1900, 2981, 71, 2946, 2111, 69, 1300, 1, 84, 1697, 659, 48, 614, 1608, 66, 4202, 101, 3788, 334, 10, 1986, 260, 2744, 161, 288, 22, 1555, 78, 806, 128, 538, 456, 527, 179, 1, 30, 1220, 612, 806, 1274, 886, 466, 477, 1346, 623, 73, 1367, 2031, 342, 3889, 1292, 48, 9582, 4012, 512, 2629, 1, 310, 14, 426, 785, 345, 1809, 40, 862, 103, 7297, 2, 870, 914, 797, 8286, 298, 159, 22, 58, 161, 37, 369, 4026, 592, 1640, 1023, 53, 42, 518, 191, 382, 257, 2235, 503, 118, 215, 3144, 254, 610, 243, 120, 495, 1216, 2354, 198, 2792, 963, 18, 51, 1978, 823, 14, 447, 17, 476, 982, 1623, 2071, 82, 366, 553, 844, 217, 4757, 1049, 5303, 2115, 1238, 1191, 0, 973, 315, 8, 174, 735, 791, 1549, 483, 1771, 4670, 1379, 446, 1410, 2, 1342, 17, 23, 5250, 37, 1093, 7, 541, 107, 35, 1380, 188, 10430, 185, 666, 1166, 140, 531, 716, 129, 152, 249, 610, 3639, 1936, 774, 1123, 4, 4038, 174, 2398, 0, 2027, 57, 30, 2484, 1008, 137, 75, 3795, 79, 3112, 36, 8, 1651, 101, 65, 16, 137, 396, 5189, 1552, 1881, 195, 498, 147, 646, 210, 72, 56, 6, 2676, 1790, 563, 1347, 174, 314, 1747, 47, 2165, 91, 50, 139, 2348, 5231, 783, 49, 179, 705, 2796, 855, 1472, 10, 11, 483, 480, 44, 90, 34, 1063, 3055, 8, 78, 43, 47, 297, 162, 22, 536, 837, 3146, 63, 124, 330, 1484, 1739, 11, 1069, 3634, 1, 509, 804, 490, 671, 7264, 2608, 1408, 24, 1957, 2527, 860, 105, 26, 329, 188, 376, 154, 31, 1057, 2146, 457, 994, 1063, 472, 152, 1053, 38, 453, 1, 1453, 174, 2044, 6690, 0, 1544, 1046, 109, 3120, 291, 540, 2965, 4331, 2, 3353, 480, 284, 436, 1104, 358, 1505, 2816, 3, 196, 4851, 344, 1508, 2108, 330, 252, 138, 610, 3828, 18, 172, 321, 0, 1984, 688, 798, 6972, 1556, 22, 1533, 3413, 293, 873, 759, 89, 43, 1403, 148, 3777, 519, 1303, 4049, 7431, 586, 2264, 3326, 726, 161, 1226, 67, 316, 828, 31, 958, 1751, 4848, 3, 2470, 1055, 177, 178, 919, 1, 1008, 3726, 1309, 486, 805, 1031, 21, 302, 119, 438, 166, 0, 335, 1093, 4808, 2527, 86, 12, 234, 2265, 1056, 45, 569, 15, 10, 5, 1970, 4097, 1051, 4248, 242, 2223, 1668, 1656, 247, 357, 229, 303, 6, 47, 538, 718, 2883, 532, 45, 10, 103, 278, 2385, 7839, 933, 848, 1224, 264, 331, 66, 162, 201, 24, 7584, 539, 22, 14, 101, 473, 27, 4853, 42, 2288, 90, 28, 1202, 7900, 26, 675, 283, 15, 683, 277, 16, 151, 423, 2148, 63, 27, 337, 1392, 20, 54, 145, 108, 324, 3861, 28, 54, 4293, 2274, 4913, 96, 653, 18, 6201, 1173, 241, 11557, 7, 1840, 1160, 1366, 156, 334, 2824, 866, 10, 1627, 2, 1072, 6185, 605, 3220, 2851, 1523, 53, 2747, 20, 0, 2948, 48, 190, 863, 1149, 27, 153, 242, 780, 718, 25, 95, 889, 107, 7384, 174, 234, 1974, 2521, 519, 1238, 1346, 630, 240, 16, 414, 1427, 397, 60, 19, 208, 363, 21, 325, 840, 3928, 963, 9, 4682, 1183, 5579, 154, 536, 4194, 54, 7471, 186, 330, 975, 144, 1763, 315, 9235, 2419, 1013, 3, 0, 2168, 234, 521, 6014, 793, 1728, 1192, 2307, 16, 174, 570, 6680, 7754, 899, 182, 1108, 475, 0, 271, 23, 280, 224, 2970, 1163, 9, 1938, 157, 29, 191, 4928, 105, 220, 4, 1, 272, 12, 483, 83, 8968, 442, 377, 491, 13, 933, 0, 12971, 725, 2, 2327, 3588, 279, 925, 288, 317, 3762, 398, 3102, 10, 90, 53, 7, 3755, 270, 2495, 113, 342, 3155, 3105, 338, 59, 5189, 2876, 944, 1136, 614, 3951, 25, 3036, 1762, 3846, 84, 654, 699, 1208, 631, 3169, 26, 248, 311, 1, 326, 3762, 189, 1451, 1327, 302, 238, 1766, 2106, 1163, 3998, 1016, 592, 56, 47, 821, 201, 4026, 24, 51, 989, 301, 27, 253, 395, 487, 7133, 329, 767, 590, 16, 172, 385, 640, 952, 2545, 685, 966, 1391, 16, 6370, 86, 2380, 1020, 338, 2502, 641, 3911, 7, 386, 29, 1679, 34, 286, 1575, 1437, 2868, 273, 126, 111, 1281, 5, 91, 42, 27, 342, 1577, 1828, 1586, 238, 441, 2139, 2580, 1305, 2142, 8053, 647, 305, 85, 679, 84, 2335, 1999, 3620, 294, 2698, 14, 485, 47, 1144, 139, 387, 487, 36, 2806, 73, 164};

	float totalWaste[MAX_REQUEST] = {4540, 32, 136, 2326, 2345, 145, 157, 321, 151, 36, 1966, 839, 2500, 92, 6995, 254, 1301, 85, 473, 3052, 481, 428, 375, 2281, 951, 2543, 1623, 652, 4142, 53, 764, 620, 15, 2513, 1289, 277, 912, 584, 21, 7680, 70, 241, 2929, 300, 152, 7, 856, 696, 1914, 526, 1829, 13052, 260, 250, 296, 121, 1196, 495, 757, 394, 2312, 7021, 789, 528, 1, 2567, 1200, 1, 272, 98, 0, 285, 1846, 96, 439, 592, 467, 63, 143, 478, 1923, 772, 233, 2135, 535, 5044, 240, 57, 600, 3579, 1116, 124, 986, 1440, 387, 5635, 41, 1235, 503, 525, 1238, 122, 4288, 1208, 873, 458, 12, 998, 298, 1616, 683, 2830, 753, 63, 648, 442, 448, 3049, 366, 3462, 15, 213, 139, 621, 1213, 2934, 1573, 1124, 711, 625, 1099, 3927, 728, 2987, 4, 111, 808, 20, 2104, 179, 14, 15, 544, 1708, 420, 88, 4, 425, 2048, 209, 79, 21, 504, 14, 346, 293, 134, 702, 681, 617, 286, 331, 291, 1, 720, 175, 635, 385, 299, 1247, 493, 623, 514, 5345, 469, 3563, 608, 2831, 62, 1452, 5, 389, 1581, 1029, 187, 259, 889, 65, 2481, 931, 2174, 16, 316, 3028, 9132, 299, 10, 1647, 0, 1961, 343, 105, 1313, 615, 2119, 4739, 521, 663, 1, 327, 157, 372, 985, 2891, 2416, 205, 2215, 20, 5028, 739, 4914, 4160, 1751, 9, 864, 21, 775, 627, 152, 278, 961, 561, 178, 1810, 624, 1, 768, 547, 8, 1032, 3091, 839, 94, 772, 348, 769, 42, 1264, 2048, 1992, 2668, 97, 1136, 112, 299, 6600, 967, 74, 145, 488, 483, 999, 3605, 76, 1356, 219, 2330, 2261, 240, 1291, 1460, 5317, 10, 2033, 1296, 5, 793, 1486, 57, 763, 5, 1016, 663, 1446, 804, 1247, 1160, 293, 2312, 501, 178, 237, 17, 944, 502, 8570, 643, 15513, 17, 10153, 1071, 954, 2189, 645, 33, 4388, 720, 8, 154, 7154, 777, 7188, 52, 463, 149, 188, 9933, 155, 182, 665, 1704, 4844, 3280, 1255, 4964, 548, 1661, 9831, 958, 18, 3783, 7, 158, 26, 80, 3949, 2, 742, 446, 884, 6, 982, 1577, 5320, 4447, 6, 116, 80, 66, 16, 3, 11, 10080, 385, 492, 198, 136, 312, 649, 134, 13, 1725, 129, 3780, 1085, 189, 1537, 93, 1102, 938, 1878, 851, 2314, 37, 903, 2617, 3171, 613, 24, 618, 1290, 288, 1556, 72, 2450, 1163, 373, 581, 9, 112, 2855, 168, 2066, 2126, 745, 4431, 207, 2004, 57, 0, 74, 289, 49, 104, 2803, 176, 465, 62, 1526, 375, 748, 602, 357, 0, 3598, 46, 66, 1842, 48, 5302, 142, 333, 121, 964, 1141, 245, 514, 295, 274, 68, 606, 68, 1945, 112, 688, 307, 323, 46, 2488, 501, 90, 103, 2868, 1583, 1981, 1, 7624, 905, 48, 3377, 491, 86, 93, 2126, 120, 312, 62, 55, 10214, 2793, 128, 84, 371, 10811, 4128, 1847, 1869, 863, 2970, 912, 400, 212, 320, 1789, 26, 932, 2185, 1585, 1012, 875, 245, 1407, 746, 19, 8, 134, 1640, 2683, 2256, 1551, 5, 4, 114, 4382, 4, 980, 189, 2, 1012, 329, 110, 1796, 605, 682, 955, 2, 41, 18, 60, 250, 1917, 4, 4912, 93, 499, 6345, 2866, 3748, 485, 556, 4, 4741, 178, 191, 340, 132, 739, 2067, 2069, 801, 476, 38, 1116, 411, 1899, 329, 881, 4621, 79, 961, 68, 113, 1656, 2265, 532, 1487, 35, 183, 2699, 643, 936, 646, 16, 423, 1203, 3008, 790, 1, 150, 4774, 114, 973, 69, 522, 3727, 1092, 4, 107, 1399, 105, 139, 618, 465, 8672, 1511, 8, 235, 98, 292, 1045, 2670, 455, 2774, 269, 128, 264, 662, 13, 477, 1, 4609, 386, 4978, 3322, 8551, 1044, 455, 2015, 201, 1629, 1055, 316, 246, 2590, 3, 7040, 775, 2707, 1434, 1470, 269, 389, 953, 485, 252, 113, 318, 136, 1327, 471, 623, 1028, 9347, 70, 831, 530, 696, 1051, 318, 43, 721, 1186, 2278, 24, 4288, 70, 15, 561, 176, 18, 301, 0, 1578, 1528, 425, 2486, 214, 5298, 1068, 3695, 7244, 598, 267, 42, 156, 4, 1293, 1387, 55, 987, 1530, 347, 3323, 1245, 1204, 1051, 1555, 1107, 2, 75, 229, 2582, 63, 1050, 139, 90, 13, 42, 1687, 601, 187, 70, 675, 331, 540, 801, 47, 3537, 22, 572, 2574, 565, 20, 268, 2420, 285, 4174, 798, 1813, 109, 71, 570, 104, 98, 6863, 375, 44, 301, 1857, 110, 341, 20, 2747, 109, 229, 47, 758, 1261, 1346, 56, 10, 581, 1791, 19, 1044, 57, 164, 85, 1527, 605, 805, 2426, 1553, 296, 177, 28, 247, 762, 263, 186, 55, 1926, 3331, 2370, 3655, 0, 1069, 6721, 700, 10771, 5707, 3042, 42, 542, 4, 0, 2381, 344, 164, 4806, 7622, 73, 18, 100, 1510, 7555, 13, 474, 358, 46, 393, 2070, 98, 2017, 347, 327, 12265, 1306, 1262, 134, 105, 137, 177, 1267, 15, 3, 31, 935, 9, 73, 328, 4352, 1216, 15, 3682, 2722, 3021, 109, 1767, 2076, 44, 4856, 1021, 132, 816, 47, 1003, 460, 681, 3746, 1141, 1026, 83, 33, 444, 2974, 4009, 2285, 7446, 1237, 9440, 0, 438, 574, 2785, 195, 21, 37, 2419, 253, 1, 2492, 0, 1951, 155, 3082, 622, 7, 438, 165, 66, 112, 9, 327, 4199, 1068, 104, 45, 97, 148, 240, 1542, 131, 1469, 99, 7, 43, 90, 390, 871, 0, 140, 3534, 44, 482, 86, 422, 2176, 2210, 1280, 281, 123, 12, 1722, 2218, 3405, 280, 558, 622, 3846, 4216, 34, 51, 517, 55, 2066, 2174, 1054, 3370, 1193, 2335, 3741, 29, 465, 688, 4094, 2367, 2967, 1902, 587, 329, 1053, 1, 1235, 930, 1125, 2492, 2745, 8, 1179, 1544, 10924, 1364, 505, 204, 167, 97, 131, 673, 591, 5525, 125, 93, 399, 8, 2758, 2221, 211, 1722, 1554, 208, 573, 3699, 84, 153, 131, 546, 2838, 115, 2548, 435, 770, 1114, 563, 3, 2520, 31, 980, 450, 20, 1681, 10, 332, 158, 87, 68, 84, 2947, 0, 237, 112, 41, 49, 33, 16, 356, 4, 163, 544, 344, 155, 5267, 34, 206, 2224, 1357, 393, 2135, 956, 1006, 7254, 2, 866, 1055, 462, 14, 3234, 43, 124, 94, 18, 17, 5718, 283, 764, 222, 53, 447, 135, 112};

	int idCli[MAX_REQUEST] = {33, 68, 28, 35, 53, 87, 47, 95, 10, 62, 46, 23, 37, 35, 71, 50, 44, 5, 21, 88, 100, 49, 63, 69, 71, 84, 80, 11, 55, 59, 40, 63, 33, 89, 81, 71, 43, 14, 23, 65, 16, 3, 10, 44, 71, 78, 66, 77, 4, 79, 82, 84, 53, 89, 85, 63, 19, 48, 24, 19, 15, 2, 28, 83, 66, 13, 17, 15, 35, 28, 33, 57, 48, 22, 14, 82, 21, 53, 19, 43, 42, 41, 54, 17, 55, 19, 43, 17, 50, 92, 83, 78, 78, 79, 72, 33, 24, 32, 33, 67, 28, 84, 54, 13, 86, 95, 51, 49, 84, 80, 23, 29, 20, 96, 74, 67, 8, 23, 73, 14, 92, 53, 4, 76, 75, 48, 7, 88, 70, 96, 59, 69, 60, 46, 47, 88, 74, 84, 57, 3, 86, 4, 43, 77, 97, 37, 81, 92, 16, 98, 93, 92, 76, 42, 6, 49, 25, 27, 16, 28, 91, 17, 70, 42, 56, 37, 66, 57, 79, 99, 21, 33, 83, 92, 66, 34, 30, 2, 77, 42, 84, 20, 84, 34, 89, 86, 31, 46, 26, 72, 74, 71, 45, 47, 5, 20, 27, 33, 36, 100, 71, 21, 6, 25, 38, 65, 3, 14, 84, 69, 45, 45, 18, 38, 50, 50, 83, 34, 31, 32, 66, 70, 67, 45, 63, 42, 9, 95, 61, 54, 42, 49, 27, 100, 46, 34, 93, 70, 100, 73, 54, 3, 46, 75, 90, 98, 14, 50, 61, 45, 96, 46, 7, 96, 80, 22, 78, 54, 40, 87, 8, 93, 22, 93, 11, 92, 83, 66, 89, 24, 5, 28, 73, 91, 63, 24, 18, 9, 56, 86, 83, 40, 32, 4, 29, 48, 76, 32, 32, 74, 85, 61, 15, 7, 57, 39, 13, 18, 28, 26, 7, 54, 73, 36, 72, 66, 65, 69, 57, 9, 29, 18, 1, 7, 70, 50, 64, 46, 94, 11, 99, 4, 33, 68, 100, 4, 7, 76, 66, 2, 16, 54, 1, 9, 25, 31, 3, 62, 11, 41, 83, 87, 24, 69, 24, 42, 4, 10, 66, 56, 75, 70, 97, 24, 9, 34, 91, 96, 41, 70, 33, 88, 57, 76, 78, 26, 1, 22, 21, 61, 65, 92, 22, 75, 100, 4, 46, 64, 36, 86, 3, 70, 88, 12, 95, 39, 31, 71, 36, 86, 40, 68, 57, 1, 72, 57, 13, 43, 58, 19, 59, 92, 35, 74, 19, 14, 35, 7, 87, 18, 70, 16, 1, 77, 95, 24, 60, 55, 72, 24, 2, 66, 20, 66, 43, 38, 77, 43, 54, 89, 89, 89, 77, 34, 79, 73, 49, 87, 39, 14, 34, 6, 37, 55, 39, 30, 18, 15, 57, 91, 27, 58, 87, 4, 5, 94, 27, 67, 39, 64, 63, 3, 100, 81, 50, 12, 68, 43, 17, 5, 70, 8, 53, 19, 59, 96, 12, 31, 68, 64, 26, 39, 51, 21, 34, 15, 67, 40, 29, 29, 38, 57, 97, 10, 29, 42, 81, 25, 67, 36, 66, 96, 53, 38, 84, 28, 52, 15, 16, 81, 89, 49, 73, 72, 72, 42, 56, 37, 49, 84, 79, 37, 43, 100, 88, 17, 17, 50, 28, 21, 98, 70, 63, 48, 20, 15, 97, 85, 8, 64, 47, 88, 5, 94, 56, 64, 68, 14, 23, 59, 8, 73, 19, 99, 34, 85, 1, 40, 72, 39, 45, 65, 31, 100, 14, 38, 60, 56, 28, 51, 20, 39, 23, 34, 24, 65, 78, 85, 29, 47, 16, 39, 1, 54, 77, 90, 47, 83, 80, 81, 47, 78, 26, 3, 38, 16, 93, 40, 80, 74, 74, 31, 45, 83, 43, 61, 34, 26, 28, 17, 97, 70, 33, 63, 58, 94, 66, 71, 43, 20, 13, 93, 2, 9, 95, 95, 63, 40, 50, 1, 50, 15, 20, 11, 93, 87, 21, 2, 85, 54, 13, 68, 75, 5, 69, 50, 83, 18, 5, 12, 85, 44, 53, 76, 2, 7, 83, 11, 22, 51, 51, 54, 64, 38, 42, 56, 91, 48, 72, 100, 97, 27, 16, 31, 15, 1, 76, 100, 55, 99, 44, 32, 43, 16, 64, 10, 4, 90, 47, 98, 67, 33, 10, 76, 28, 51, 77, 19, 38, 58, 65, 89, 12, 19, 48, 61, 33, 66, 14, 3, 1, 65, 15, 45, 1, 34, 3, 73, 5, 25, 80, 17, 53, 48, 80, 47, 8, 55, 53, 32, 39, 99, 40, 57, 98, 29, 4, 29, 27, 89, 68, 26, 19, 91, 4, 11, 65, 81, 5, 75, 70, 95, 4, 46, 79, 14, 57, 89, 11, 16, 34, 15, 80, 11, 98, 28, 5, 50, 80, 18, 35, 82, 38, 43, 57, 75, 64, 63, 43, 71, 36, 59, 13, 4, 56, 94, 76, 42, 24, 3, 71, 36, 83, 30, 12, 90, 60, 10, 70, 8, 72, 50, 84, 67, 28, 48, 40, 42, 16, 5, 77, 1, 98, 24, 29, 90, 37, 11, 45, 42, 12, 69, 59, 10, 73, 77, 47, 81, 36, 78, 39, 39, 19, 79, 4, 69, 10, 17, 6, 85, 77, 26, 24, 7, 16, 8, 28, 72, 44, 10, 52, 28, 43, 31, 97, 59, 66, 1, 57, 72, 18, 47, 65, 77, 36, 38, 39, 65, 85, 59, 95, 5, 29, 78, 74, 1, 62, 18, 58, 54, 91, 3, 6, 93, 95, 37, 3, 84, 27, 50, 10, 56, 87, 26, 25, 3, 2, 42, 28, 32, 29, 10, 96, 1, 53, 23, 45, 7, 37, 96, 49, 34, 52, 55, 72, 65, 24, 60, 70, 78, 51, 30, 64, 62, 43, 8, 76, 32, 9, 17, 28, 91, 23, 11, 96, 35, 3, 20, 17, 90, 67, 63, 9, 94, 69, 62, 84, 72, 91, 23, 13, 7, 58, 83, 2, 78, 93, 63, 95, 10, 41, 75, 20, 20, 27, 20, 1, 11, 61, 56, 31, 54, 93, 67, 72, 3, 81, 67, 58, 99, 18, 13, 57, 58, 14, 73, 2, 60, 59, 25, 44, 96, 60, 12, 97, 74, 75, 91, 23, 72};

	for(int i = 0; i < maxClients; i++){
		clientsList[i].id = i+1;
		*ids = clientsList[i].id+1;
		strcpy(clientsList[i].companyName, names[i]);
		strcpy(clientsList[i].cuit, cuit[i]);
		strcpy(clientsList[i].direction.address, address[i]);
		clientsList[i].direction.number = number[i];
		clientsList[i].direction.idLocal = locality[i];
//		strcpy(clientsList[i].direction.locality, locality[i]);
		clientsList[i].pendingRequests = 0;
		clientsList[i].completedRequests = 0;
		clientsList[i].status = FULL;
	}

	for(int i = 0; i < maxRequests; i++){
		requestList[i].id = i+1;
		*reqIds = requestList[i].id+1;
		requestList[i].kilosTotal = totalK[i];
		requestList[i].kilosHDPE = totalHDPE[i];
		requestList[i].kilosLDPE = totalLDPE[i];
		requestList[i].kilosPP = totalPP[i];
		requestList[i].kilosWaste = totalWaste[i];
		requestList[i].clientId = idCli[i];
		requestList[i].status = PENDING;
		requestList[i].isEmpty = FULL;
	}

	for(int i = 0; i < maxClients; i++){
		if(clientsList[i].status == FULL){
			countRequestsByClient(clientsList, maxClients, requestList, maxRequests, clientsList[i].id);
		}
	}
}

