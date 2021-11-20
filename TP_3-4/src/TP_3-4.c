/*
 ============================================================================
 Name        : TP_3 con LL de TP_4.c
 Author      : Marcos Laporte
 ============================================================================
 */

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/

#include "Controller.h"
#define DATA "data.csv"
#define DATA_BIN "data.bin"
#define ID_FILE "id.bin"

int main()
{
	setbuf(stdout, NULL);

	printf("\t\t#=======================================#\n"
		   "\t\t|\t    TP 3 - LinkedList\t\t|\n"
		   "\t\t|\t    --Marcos Laporte--\t\t|\n"
		   "\t\t#=======================================#\n");

    int option;
    int flagLoad;
    int r;
    flagLoad = 1;
//	controller_saveId(ID_FILE, 1001);

    LinkedList* arrayEmployees = ll_newLinkedList();
    do{
    	option = printMenu();
        switch(option)
        {
            case 1: //Cargar de texto
            	if(flagLoad){
					if(!controller_loadFromText(DATA, arrayEmployees)){
						printf("Hubo un problema con los punteros.\n");
					}else{
						printf("Se cargaron los %d empleados!\n", ll_len(arrayEmployees));
						flagLoad = 0;
					}
            	}else{
            		printf("Los empleados ya se cargaron anteriormente!\n");
            	}
                break;
            case 2: //Cargar de binario
            	if(flagLoad){
					if(!controller_loadFromBinary(DATA_BIN, arrayEmployees)){
						printf("Hubo un problema con los punteros.\n");
					}else{
						printf("Se cargaron los %d empleados del binario!\n", ll_len(arrayEmployees));
						flagLoad = 0;
					}
            	}else{
            		printf("Los empleados ya se cargaron anteriormente!\n");
            	}
            	break;
            case 3: //Alta
            	if(!ll_isEmpty(arrayEmployees)){
					if(controller_addEmployee(arrayEmployees, ID_FILE) > 0){
						printf("Se ha dado de alta el empleado!\n");
					}
            	}else{
            		printf("ERROR! No hay empleados cargados.\n");
            	}
            	break;
            case 4: //Modificar
            	if(!ll_isEmpty(arrayEmployees)){
            		r = controller_editEmployee(arrayEmployees);
					if(r > 0){
						printf("Se ha modificado el empleado!\n");
					}else{
						if(!r){
							printf("ERROR! No existe un empleado con ese ID.\n");
						}else{
							printf("Ha cancelado la acción.\n");
						}
					}
            	}else{
            		printf("ERROR! No hay empleados cargados.\n");
            	}
            	break;
            case 5: //Baja
            	if(!ll_isEmpty(arrayEmployees)){
					if(controller_removeEmployee(arrayEmployees)){
						printf("El empleado ha sido dado de baja!\n");
					}else{
						printf("ERROR! No existe un empleado con ese ID.\n");
					}
				}else{
					printf("ERROR! No hay empleados cargados.\n");
				}
            	break;
            case 6: //Lista
            	if(!ll_isEmpty(arrayEmployees)){
					controller_ListEmployee(arrayEmployees);
				}else{
					printf("ERROR! No hay empleados cargados.\n");
				}
            	break;
            case 7: //Ordenar
            	if(!ll_isEmpty(arrayEmployees)){
					if(controller_sortEmployee(arrayEmployees)){
						printf("Se han ordenado los empleados!\n");
					}
				}else{
					printf("ERROR! No hay empleados cargados.\n");
				}
            	break;
            case 8: //Guardar en texto
            	if(!ll_isEmpty(arrayEmployees)){
            		if(controller_saveAsText(DATA, arrayEmployees)){
            			printf("Los empleados fueron guardados con éxito!\n");
            		}else{
						printf("Hubo un problema con los punteros.\n");
            		}
            	}else{
					printf("ERROR! No hay empleados cargados.\n");
            	}
            	break;
            case 9: //Guardar en binario
            	if(!ll_isEmpty(arrayEmployees)){
            		if(controller_saveAsBinary(DATA_BIN, arrayEmployees)){
            			printf("Los empleados fueron guardados con éxito!\n");
            		}else{
						printf("Hubo un problema con los punteros.\n");
            		}
				}else{
					printf("ERROR! No hay empleados cargados.\n");
				}
            	break;
            case 10: //Salir
            	printf("Ha salido del programa.\n");
            	break;
        }
    }while(option != 10);

    return 0;
}

