/*===========================================================================
 Name        : TP N°3
 Author      : Marcos Laporte
===========================================================================*/

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

int main()
{
	setbuf(stdout, NULL);
    int option;

    LinkedList* arrayEmployees = ll_newLinkedList();
    do{
    	option = printMenu();
        switch(option)
        {
            case 1:
                controller_loadFromText("data.csv", arrayEmployees);
                break;
            case 10:
            	printf("Ha salido del programa.\n");
            	break;
        }
    }while(option != 10);
    return 0;
}

