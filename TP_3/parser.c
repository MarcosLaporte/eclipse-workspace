#include "parser.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int retorno;
	char id[MAX_CHAR];
	char nombre[MAX_CHAR];
	char hs[MAX_CHAR];
	char sueldo[MAX_CHAR];
	Employee* aux;
	retorno = -1;

	if(pFile != NULL && pArrayListEmployee != NULL){
		fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, hs, sueldo);
			//Si y solo si el archivo tiene encabezado
		while(!feof(pFile)){
			if(fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, hs, sueldo) == 4){
				if(!isAnInt(id, MAX_CHAR) && checkAlphabetAndSpace(nombre) &&
						!isAnInt(hs, MAX_CHAR) && !isAnInt(sueldo, MAX_CHAR)){
					aux = employee_newParametros(id, nombre, hs, sueldo);
					ll_add(pArrayListEmployee, aux);
				}
			}
		}
		retorno = 0;
	}

	return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int retorno;
	Employee* miEmpleado;
	retorno = -1;

	if(pFile != NULL && pArrayListEmployee != NULL){
		while(!feof(pFile)){
			if(fread((Employee*)&miEmpleado, sizeof(Employee), 1, pFile) == 4){
				miEmpleado = employee_new();
				ll_add(pArrayListEmployee, miEmpleado);
			}
		}
		retorno = 0;
	}

    return retorno;
}
