#include "Controller.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	int retorno;
	FILE* pFile;
	retorno = 0;

	if(path != NULL && pArrayListEmployee != NULL){
		pFile = fopen(path, "r");
		if(!parser_EmployeeFromText(pFile, pArrayListEmployee)){
			retorno = 1;
		}
		fclose(pFile);
	}

    return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	int retorno;
	FILE* pFile;
	retorno = 0;

	if(path != NULL && pArrayListEmployee != NULL){
		pFile = fopen(path, "rb");
		if(!parser_EmployeeFromBinary(pFile, pArrayListEmployee)){
			retorno = 1;
		}
		fclose(pFile);
	}

    return retorno;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee, char* path)
{
	int retorno;
	Employee* miEmpleado;
	int id;
	retorno = 0;

	if(pArrayListEmployee != NULL && path != NULL){
		controller_readId(path, &id);
		miEmpleado = employee_newFromUser(id);
		employee_printEmpleado(miEmpleado);
		if(getConfirmation("Escriba 'SI' para confirmar: ", "SI", "NO", 3, 3) == 1){
			ll_add(pArrayListEmployee, miEmpleado);
			controller_saveId(path, id+1);
			retorno = 1;
		}else{
			printf("Se ha cancelado la acción!\n");
		}
	}

    return retorno;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
	int retorno;
	int id;
	int index;
	int opcion;
	Employee* miEmpleado;
	char auxNombre[MAX_CHAR];
	int auxHs;
	int auxSueldo;
	retorno = 0;

	if(pArrayListEmployee != NULL){
		controller_ListEmployee(pArrayListEmployee);
		getInt(&id, "Ingrese el ID que desea modificar: ", "ERROR! Ingrese un ID válido: ", 1, 99999);
		index = controller_findEmployeeById(pArrayListEmployee, id);
		if(index != -1){
			getInt(&opcion, "\t~ 0. Cancelar\n\t~ 1. Nombre\n\t~ 2. Horas trabajadas\n\t~ 3. Sueldo\nQué desea modificar?: ", "ERROR! Ingrese una opción válida: ", 0, 3);
			retorno = 1;
			miEmpleado = (Employee*)ll_get(pArrayListEmployee, index);
			switch(opcion){
			case 0:
				retorno = -1;
				break;
			case 1:
				myGetName(auxNombre, "Ingrese el nuevo nombre: ", "Ingrese un nombre válido: ", MAX_CHAR);
				employee_setNombre(miEmpleado, auxNombre);
				break;
			case 2:
				getInt(&auxHs, "Ingrese las nuevas horas de trabajo: ", "ERROR! Ingrese horas válidas: ", 0, 300);
				employee_setHorasTrabajadas(miEmpleado, auxHs);
				break;
			case 3:
				getInt(&auxSueldo, "Ingrese el nuevo sueldo: ", "ERROR! Ingrese sueldo válido: ", 0, 250000);
				employee_setSueldo(miEmpleado, auxSueldo);
				break;
			}
		}
	}

	return retorno;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
	int retorno;
	int id;
	int index;
	Employee* miEmpleado;
	retorno = 0;

	if(pArrayListEmployee != NULL){
		controller_ListEmployee(pArrayListEmployee);
		getInt(&id, "Ingrese el ID que desea dar de baja: ", "ERROR! Ingrese un ID válido: ", 1, 99999);
		index = controller_findEmployeeById(pArrayListEmployee, id);
		if(index != -1){
			if(getConfirmation("Esta acción no puede deshacerse. Escriba 'SI' para eliminar: ", "SI", "NO", 3, 3) == 1){
				ll_remove(pArrayListEmployee, index);
				miEmpleado = (Employee*)ll_get(pArrayListEmployee, index);
				employee_delete(miEmpleado);
				retorno = 1;
			}
		}
	}

    return retorno;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	int retorno;
	retorno = 0;

	if(pArrayListEmployee != NULL){
		printf("#====+=========================+=====+========#\n");
		printf("| ID |          Nombre         |Horas| Sueldo |\n");
		printf("#====+=========================+=====+========#\n");
		for(int i = 0; i < ll_len(pArrayListEmployee); i++){
			employee_printEmpleado((Employee*)ll_get(pArrayListEmployee, i));
		}
		printf("#=============================================#\n");
		retorno = 1;
	}

	return retorno;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
	int retorno;
	int opcion;
	int orden;
	retorno = 0;

	if(pArrayListEmployee != NULL){
		getInt(&opcion, "~1) Id\n~2) Nombre\n~3) Horas trabajadas\n~4) Sueldo\nPor qué campo desea ordenar?: ", "ERROR! Ingrese un campo válido (1-4): ", 1, 4);
		switch(opcion){
		case 1:
			getInt(&orden, "Mayor a menor: 0\tMenor a mayor: 1\nElija un orden: ", "ERROR! Ingrese un orden válido: ", 0, 1);
			ll_sort(pArrayListEmployee, employee_compareId, orden);
			break;
		case 2:
			getInt(&orden, "Z-A: 0\tA-Z: 1\nElija un orden: ", "ERROR! Ingrese un orden válido: ", 0, 1);
			ll_sort(pArrayListEmployee, employee_compareNombre, orden);
			break;
		case 3:
			getInt(&orden, "Mayor a menor: 0\tMenor a mayor: 1\nElija un orden: ", "ERROR! Ingrese un orden válido: ", 0, 1);
			ll_sort(pArrayListEmployee, employee_compareHoras, orden);
			break;
		case 4:
			getInt(&orden, "Mayor a menor: 0\tMenor a mayor: 1\nElija un orden: ", "ERROR! Ingrese un orden válido: ", 0, 1);
			ll_sort(pArrayListEmployee, employee_compareSueldo, orden);
			break;
		}
		retorno = 1;
	}

    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
	int retorno;
	FILE* pFile;
	retorno = 0;

	if(path != NULL && pArrayListEmployee != NULL){
		pFile = fopen(path, "w");
			parser_TextFromEmployee(pFile, pArrayListEmployee);
		fclose(pFile);
		retorno = 1;
	}

    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
	int retorno;
	FILE* pFile;
	retorno = 0;

	if(path != NULL && pArrayListEmployee != NULL){
		pFile = fopen(path, "wb");
			parser_BinaryFromEmployee(pFile, pArrayListEmployee);
		fclose(pFile);
		retorno = 1;
	}
    return retorno;
}

/// @brief Guarda el id pasado por parámetro en el archivo con la ruta pasada por parámetro.
///
/// @param path - Ruta del archivo.
/// @param id - ID a guardar en el archivo.
/// @return int - Retorna 0 si el puntero es inválido, o 1 si está todo bien.
int controller_saveId(char* path, int id){
	int retorno;
	FILE* pFile;
	retorno = 0;

	if(path != NULL){
		pFile = fopen(path, "wb");
			fwrite(&id, sizeof(int), 1, pFile);
		fclose(pFile);
		retorno = 1;
	}

	return retorno;
}

/// @brief Toma el id guardado en el archivo con la ruta pasada por parámetro, y lo pasa por el puntero.
///
/// @param path - Ruta del archivo.
/// @param id - Puntero para guardar el ID leido.
/// @return int - Retorna 0 si el puntero es inválido, o 1 si está todo bien.
int controller_readId(char* path, int* id){
	int retorno;
	FILE* pFile;
	retorno = 0;

	if(path != NULL && id != NULL){
		pFile = fopen(path, "rb");
			fread(id, sizeof(int), 1, pFile);
		fclose(pFile);
		retorno = 1;
	}

	return retorno;
}

/// @brief Busca por id la posición de LL ern la que se encuentra el empleado.
///
/// @param pArrayListEmployee - Puntero al array LL de empleados.
/// @param id - El ID a buscar.
/// @return int - Retorna la posición del empleado si la encuentra, o -1 si no.
int controller_findEmployeeById(LinkedList* pArrayListEmployee, int id){
	int retorno;
	int auxId;
	Employee* miEmpleado;
	retorno = -1;

	for(int i = 0; i < ll_len(pArrayListEmployee); i++){
		miEmpleado = (Employee*)ll_get(pArrayListEmployee, i);
		employee_getId(miEmpleado, &auxId);
		if(auxId == id){
			retorno = ll_indexOf(pArrayListEmployee, miEmpleado);
			break;
		}
	}

	return retorno;
}
