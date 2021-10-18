/*
 * ArrayEmployees.c
 *      Author: Marcos
 */

#include "ArrayEmployees.h"
#include "Input.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int initEmployees(Employee* list, int len){
	int Return;
	Return = -1;

	for(int i = 0; i < len; i++){
		list[i].isEmpty = TRUE;
		Return = 0;
	}

	return Return;
}

Employee getEmployee(Employee* list, int length){
	Employee worker;

	getString("¬ Ingrese el nombre del empleado: ", worker.name, 51);
	while(checkAlphabetAndSpace(worker.name) == -1){
		getString("¬ ERROR! Ingrese un nombre SOLO con letras (sin tildes ni Ñ): ", worker.name, 51);
	}
	formatName(worker.name);

	getString("¬ Ingrese el apellido del empleado: ", worker.lastName, 51);
	while(checkAlphabetAndSpace(worker.lastName) == -1){
		getString("¬ ERROR! Ingrese un apellido SOLO con letras (sin tildes ni Ñ): ", worker.lastName, 51);
	}
	formatName(worker.lastName);

	getFinalFloat(&worker.salary, "¬ Ingrese el salario del empleado: ", "ERROR. El dato ingresado no es válido.\nIngrese un número entre 0 y 999.999: ", 0, 999999);

	getFinalInt(&worker.sector, "¬ Ingrese el sector del empleado: ", "ERROR. El dato ingresado no es válido.\nIngrese un entero entre 1 y 6: ", 1, 6);

	return worker;
}

int addEmployee(Employee* list, int len, int id, char name[], char lastName[], float salary, int sector){
	int Return;
	Return = -1;

	if(list != NULL && len > 0){
		for(int i = 0; i < len; i++){
			if(list[i].isEmpty == TRUE){
				Return = 0;
				list[i].id = id;
				strcpy(list[i].name, name);
				strcpy(list[i].lastName, lastName);
				list[i].salary = salary;
				list[i].sector = sector;
				list[i].isEmpty = FALSE;
				break;
			}
		}
	}

	return Return;
}

int findEmployeeById(Employee* list, int len, int id){
	int Return;
	Return = -1;

	if(list != NULL && len > 0){
		for(int i = 0; i < len; i++){
			if(list[i].isEmpty == FALSE && list[i].id == id){
				Return = i;
				break;
			}
		}
	}

	return Return;
}

int removeEmployee(Employee* list, int len, int id){
	int Return;
	Return = -1;
	int index;

	if(list != NULL && len > 0){
		index = findEmployeeById(list, len, id);
		if(index != -1){
			Return = 0;
			list[index].isEmpty = TRUE;
		}
	}

	return Return;
}

int modifyEmployee(Employee* list, int length, int id){
	int Return;
	int index;
//	int id;
	int modification;
	char auxName[51];
	Return = -1;

	if(list != NULL && length > 0){
//		id = getInt("Ingrese el ID del empleado que desea modificar: ");
		index = findEmployeeById(list, length, id);
		if(index != -1){
			if(list[index].isEmpty == FALSE){
				Return = 0;
				modification = getModificationMenu();
				switch(modification){
				case 0:
					printf("Canceló la modificación.\n");
					break;
				case 1:
					getString("¬ Ingrese el nuevo nombre del empleado: ", auxName, 51);
					strcpy(list[index].name, auxName);
					break;
				case 2:
					getString("¬ Ingrese el nuevo apellido del empleado: ", auxName, 51);
					strcpy(list[index].lastName, auxName);
					break;
				case 3:
					list[index].salary = getFloat("¬ Ingrese el nuevo salario del empleado: ");
					break;
				case 4:
					list[index].sector = getInt("¬ Ingrese el nuevo sector del empleado: ");
					break;
				}
			}
		}
	}

	return Return;
}

int sortEmployee(Employee* list, int len, int order){
	int Return;
	int flagSwap;
	Employee aux;
	Return = -1;
	flagSwap = 0;

	if(list != NULL && len > 0){
		do{
			flagSwap = -1;
			for(int i = 0; i < len-1; i++){
				if(list[i].isEmpty == FALSE && list[i+1].isEmpty == FALSE){
					Return = 0;
					if(order == 1){
						if(strcmp(list[i].lastName, list[i+1].lastName) > 0){
							flagSwap = 0;
							aux = list[i];
							list[i] = list[i+1];
							list[i+1] = aux;
						}else{
							if(strcmp(list[i].lastName, list[i+1].lastName) == 0){
								if(list[i].sector > list[i+1].sector){
									flagSwap = 0;
									aux = list[i];
									list[i] = list[i+1];
									list[i+1] = aux;
								}
							}
						}
					}else{
						if(strcmp(list[i].lastName, list[i+1].lastName) < 0){
							flagSwap = 0;
							aux = list[i];
							list[i] = list[i+1];
							list[i+1] = aux;
						}else{
							if(strcmp(list[i].lastName, list[i+1].lastName) == 0){
								if(list[i].sector < list[i+1].sector){
									flagSwap = 0;
									aux = list[i];
									list[i] = list[i+1];
									list[i+1] = aux;
								}
							}
						}
					}
				}
			}
		}while(flagSwap == 0);
	}

	return Return;
}

int printEmployees(Employee* list, int len){
	int Return;
	Return = -1;

	if(list != NULL && len > 0){
		for(int i = 0; i < len; i++){
			if(list[i].isEmpty == FALSE){
				Return = 0;
				printf("|%4d|%50s|%50s|$%10.2f|%7d|\n", list[i].id, list[i].name, list[i].lastName, list[i].salary, list[i].sector);
				printf("#----+--------------------------------------------------+--------------------------------------------------+-----------+-------#\n");
			}
		}
	}

	return Return;
}

void printList(Employee* list, int len){
	if(list != NULL && len > 0){
		printf("#------------------------------------------------------------------------------------------------------------------------------#\n");
		printf("|%-4s|\t\t\t %s\t\t\t\t|\t\t\t%s\t\t   |%-11s|%-7s|\n","ID","Nombre", "Apellido", "Salario", "Sector");
		printf("#----+--------------------------------------------------+--------------------------------------------------+-----------+-------#\n");
		if(printEmployees(list, len) == -1){
			printf("Ocurrió un error.\n");
		}
	}
}

int checkAnEmployee(Employee* list, int lenght){
	int Return;
	Return = -1;

	if(list != NULL && lenght > 0){
		for(int i = 0; i < lenght; i++){
			if(list[i].isEmpty == FALSE){
				Return = 0;
				break;
			}
		}
	}
	return Return;
}

int calcAverageSalary(Employee* list, int length, float* refAverage, float* refSum){
	int Return;
	float auxSum;
	int contEmp;
	Return = -1;
	auxSum = 0;
	contEmp = 0;

	if(list != NULL && length > 0){
		for(int i = 0; i < length; i++){
			if(list[i].isEmpty == FALSE){
				Return = 0;
				auxSum += list[i].salary;
				contEmp++;
			}
		}
	}
	*refAverage = auxSum/contEmp;
	*refSum = auxSum;

	return Return;
}

int calcEmployeesOverSalary(Employee* list, int length, float averageSalary){
	int Return;
	Return = 0;

	if(list != NULL && length > 0){
		for(int i = 0; i < length; i++){
			if(list[i].isEmpty == FALSE && list[i].salary > averageSalary){
				Return++;
			}
		}
	}

	return Return;
}

void printFinalSalaries(float salarySum, float averageSalary, int overSalaryEmp){
	printf("~La suma total de los salarios es: %.2f.\n", salarySum);
	printf("~El promedio de salario por empleado es: %.2f.\n", averageSalary);
	printf("~La cantidad de empleados que superan el salario promedio son: %d.\n", overSalaryEmp);
}
