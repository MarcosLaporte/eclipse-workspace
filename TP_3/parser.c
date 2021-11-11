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
		while(!feof(pFile)){
			if(fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, hs, sueldo) == 4){
				if(isAnInt(id, MAX_CHAR) && isAlphaSpace(nombre) &&
						isAnInt(hs, MAX_CHAR) && isAnInt(sueldo, MAX_CHAR)){
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
			miEmpleado = employee_new();
			if(fread(miEmpleado, sizeof(Employee), 1, pFile) == 1){
				ll_add(pArrayListEmployee, miEmpleado);
			}
		}
		retorno = 0;
	}

    return retorno;
}

int parser_TextFromEmployee(FILE* pFile, LinkedList* pArrayListEmployee){
	int retorno;
	Employee* miEmpleado;
	int id;
	char nombre[MAX_CHAR];
	int hs;
	int sueldo;
	retorno = -1;

	if(pFile != NULL && pArrayListEmployee != NULL){
		fprintf(pFile, "ID,Nombre,HorasTrabajadas,Sueldo\n");
		for(int i = 0; i < ll_len(pArrayListEmployee); i++){
			miEmpleado = (Employee*)ll_get(pArrayListEmployee, i);
			employee_getId(miEmpleado, &id);
			employee_getNombre(miEmpleado, nombre);
			employee_getHorasTrabajadas(miEmpleado, &hs);
			employee_getSueldo(miEmpleado, &sueldo);
			fprintf(pFile, "%d,%s,%d,%d\n", id, nombre, hs, sueldo);
		}
		retorno = 0;
	}

	return retorno;
}

int parser_BinaryFromEmployee(FILE* pFile, LinkedList* pArrayListEmployee){
	int retorno;
	Employee* miEmpleado;
	retorno = -1;

	if(pFile != NULL && pArrayListEmployee != NULL){
		for(int i = 0; i < ll_len(pArrayListEmployee); i++){
			miEmpleado = (Employee*)ll_get(pArrayListEmployee, i);
			fwrite(miEmpleado, sizeof(Employee), 1, pFile);
		}
	}

	return retorno;
}
