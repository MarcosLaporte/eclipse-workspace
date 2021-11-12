#include "Employee.h"

/// @brief Construye espacio en memoria para un empleado.
///
/// @return Employee* - Retorna el puntero al empleado.
Employee* employee_new(){
	Employee* miEmpleado;

	miEmpleado = (Employee*)calloc(1, sizeof(Employee));

	return miEmpleado;
}

/// @brief Llama a employee_new() y guarda los datos pasados por parámetro (ya convertidos) al empleado del puntero.
///
/// @param idStr - Caracteres del ID a convertir.
/// @param nombreStr - Cadena de caracteres del nombre.
/// @param horasTrabajadasStr - Caracteres de las horas trabajadas a convertir
/// @param sueldoStr - Caracteres del sueldo a convertir
/// @return Employee* - Retorna el puntero al empleado.
Employee* employee_newParametros(char* idStr, char* nombreStr, char* horasTrabajadasStr, char* sueldoStr){
	Employee* miEmpleado;

	miEmpleado = employee_new();
	if(idStr != NULL && nombreStr != NULL && horasTrabajadasStr != NULL && sueldoStr != NULL){
		/*if(!f_isInt(idStr, &auxId) && !f_getName(nombreStr, auxNombre) &&
				!f_isInt(horasTrabajadasStr, &auxHoras) && !f_isInt(sueldoStr, &auxSueldo)){ //Por fuera*/
			employee_setId(miEmpleado, atoi(idStr));
			camelStr(nombreStr);
			employee_setNombre(miEmpleado, nombreStr);
			employee_setHorasTrabajadas(miEmpleado, atoi(horasTrabajadasStr));
			employee_setSueldo(miEmpleado, atoi(sueldoStr));
//		}
	}

	return miEmpleado;
}

/// @brief Crea un empleado con los datos pasados por teclado.
///
/// @param id
/// @return
Employee* employee_newFromUser(int id){
	Employee* miEmpleado;
	char auxNombre[MAX_CHAR];
	int auxHoras;
	int auxSueldo;

	miEmpleado = employee_new();
	if(myGetName(auxNombre, "Ingrese el nombre del empleado: ", "ERROR! Ingrese un nombre válido: ", MAX_CHAR) &&
			getInt(&auxHoras, "Ingrese las horas trabajadas: ", "ERROR! Ingrese horas válidas: ", 0, 300) &&
			getInt(&auxSueldo, "Ingrese el sueldo del empleado: ", "ERROR! Ingrese sueldo válido: ", 1, 250000)){
		employee_setId(miEmpleado, id);
		employee_setNombre(miEmpleado, auxNombre);
		employee_setHorasTrabajadas(miEmpleado, auxHoras);
		employee_setSueldo(miEmpleado, auxSueldo);
	}

	return miEmpleado;
}

/// @brief Utiliza la función free() para liberar el espacio donde se encuentra ese empleado.
///
/// @param this - Puntero al empleado a eliminar.
void employee_delete(Employee* this){
	free(this);
	//Mucho código
}

/// @brief Asigna el valor 'id' pasado por parámetro al campo id en la estructura Employee.
///
/// @param this - Puntero al empleado.
/// @param id - ID a asignar.
/// @return int - Retorna 0 si el puntero es nulo, o 1 si está todo bien.
int employee_setId(Employee* this, int id){
	int retorno;
	retorno = 0;

	if(this != NULL){
		this->id = id;
		retorno = 1;
	}

	return retorno;
}

/// @brief Toma el valor guardado en el campo id de la estructura Employee y lo guarda en el puntero 'id' del parámetro.
///
/// @param this - Puntero al empleado.
/// @param id - Puntero a dónde guardar el valor.
/// @return int - Retorna 0 si el puntero es nulo, o 1 si está todo bien.
int employee_getId(Employee* this, int* id){
	int retorno;
	retorno = 0;

	if(this != NULL && id != NULL){
		*id = this->id;
		retorno = 1;
	}

	return retorno;
}

/// @brief Asigna la cadena 'nombre' pasada por parámetro al campo nombre en la estructura Employee.
///
/// @param this - Puntero al empleado.
/// @param nombre - Cadena de caracteres a asignar.
/// @return int - Retorna 0 si el puntero es nulo, o 1 si está todo bien.
int employee_setNombre(Employee* this, char* nombre){
	int retorno;
	retorno = 0;

	if(this != NULL && nombre != NULL){
		strcpy(this->nombre, nombre);
		retorno = 1;
	}

	return retorno;
}

/// @brief Toma la cadena guardada en el campo nombre de la estructura Employee y la guarda en el puntero 'nombre' del parámetro.
///
/// @param this - Puntero al empleado.
/// @param nombre - Puntero a dónde guardar la cadena.
/// @return int - Retorna 0 si el puntero es nulo, o 1 si está todo bien.
int employee_getNombre(Employee* this, char* nombre){
	int retorno;
	retorno = 0;

	if(this != NULL && nombre != NULL){
		strcpy(nombre, this->nombre);
		retorno = 1;
	}

	return retorno;
}

/// @brief Asigna el valor 'horasTrabajadas' pasado por parámetro al campo horasTrabajadas en la estructura Employee.
///
/// @param this - Puntero al empleado.
/// @param horasTrabajadas - Horas a asignar.
/// @return int - Retorna 0 si el puntero es nulo, o 1 si está todo bien.
int employee_setHorasTrabajadas(Employee* this, int horasTrabajadas){
	int retorno;
	retorno = 0;

	if(this != NULL){
		this->horasTrabajadas = horasTrabajadas;
		retorno = 1;
	}

	return retorno;
}

/// @brief Toma el valor guardado en el campo horasTrabajadas de la estructura Employee y lo guarda en el puntero 'horasTrabajadas' del parámetro.
///
/// @param this - Puntero al empleado.
/// @param horasTrabajadas - Puntero a dónde guardar el valor.
/// @return int - Retorna 0 si el puntero es nulo, o 1 si está todo bien.
int employee_getHorasTrabajadas(Employee* this, int* horasTrabajadas){
	int retorno;
	retorno = 0;

	if(this != NULL && horasTrabajadas != NULL){
		*horasTrabajadas = this->horasTrabajadas;
		retorno = 1;
	}

	return retorno;
}

/// @brief Asigna el valor 'sueldo' pasado por parámetro al campo sueldo en la estructura Employee.
///
/// @param this - Puntero al empleado.
/// @param sueldo - Sueldo a asignar.
/// @return int - Retorna 0 si el puntero es nulo, o 1 si está todo bien.
int employee_setSueldo(Employee* this, int sueldo){
	int retorno;
	retorno = 0;

	if(this != NULL){
		this->sueldo = sueldo;
		retorno = 1;
	}

	return retorno;
}

/// @brief Toma el valor guardado en el campo sueldo de la estructura Employee y lo guarda en el puntero 'sueldo' del parámetro.
///
/// @param this - Puntero al empleado.
/// @param sueldo - Puntero a dónde guardar el valor.
/// @return int - Retorna 0 si el puntero es nulo, o 1 si está todo bien.
int employee_getSueldo(Employee* this, int* sueldo){
	int retorno;
	retorno = 0;

	if(this != NULL && sueldo != NULL){
		*sueldo = this->sueldo;
		retorno = 1;
	}

	return retorno;
}

/// @brief Imprime el empleado pasado por parámetro.
///
/// @param this - El punteor del empleado a imprimir.
/// @return Retorna 0 si el puntero es nulo o 1 si pudo imprimir.
int employee_printEmpleado(Employee* this){
	int retorno;
	int id;
	char nombre[MAX_CHAR];
	int horas;
	int sueldo;
	retorno = 0;

	if(this != NULL){
		employee_getId(this, &id);
		employee_getNombre(this, nombre);
		employee_getHorasTrabajadas(this, &horas);
		employee_getSueldo(this, &sueldo);

		printf("|%4d|%25s|%5d|%8d|\n", id, nombre, horas, sueldo);
		retorno = 1;
	}

	return retorno;
}

/// @brief Compara los ids conseguidos a través de employee_get() de los empleados pasados por parámetro.
///
/// @param this - Puntero a void donde se pasa el empleado.
/// @param that - Puntero a void donde se pasa el empleado.
/// @return int - Retorna 0 si los elementos comparados son iguales, 1 si el primero es mayor, y -1 si el segundo lo es.
int employee_compareId(void* this, void* that){
	int retorno;
	Employee* empleado1;
	Employee* empleado2;
	int id1;
	int id2;
	retorno = 0;

	if(this != NULL && that != NULL){
		empleado1 = (Employee*)this;
		empleado2 = (Employee*)that;

		employee_getId(empleado1, &id1);
		employee_getId(empleado2, &id2);

		if(id1 > id2){
			retorno = 1;
		}else{
			if(id1 < id2){
				retorno = -1;
			}
		}
	}

	return retorno;
}

/// @brief Compara los nombres conseguidos a través de employee_get() de los empleados pasados por parámetro.
///
/// @param this - Puntero a void donde se pasa el empleado.
/// @param that - Puntero a void donde se pasa el empleado.
/// @return int - Retorna 0 si los elementos comparados son iguales, 1 si el primero es mayor, y -1 si el segundo lo es.
int employee_compareNombre(void* this, void* that){
	int retorno;
	Employee* empleado1;
	Employee* empleado2;
	char nombre1[MAX_CHAR];
	char nombre2[MAX_CHAR];

	if(this != NULL && that != NULL){
		empleado1 = (Employee*)this;
		empleado2 = (Employee*)that;

		employee_getNombre(empleado1, nombre1);
		employee_getNombre(empleado2, nombre2);

		retorno = strcmpi(nombre1, nombre2);
	}

	return retorno;
}

/// @brief Compara las horas trabajadas conseguidas a través de employee_get() de los empleados pasados por parámetro.
///
/// @param this - Puntero a void donde se pasa el empleado.
/// @param that - Puntero a void donde se pasa el empleado.
/// @return int - Retorna 0 si los elementos comparados son iguales, 1 si el primero es mayor, y -1 si el segundo lo es.
int employee_compareHoras(void* this, void* that){
	int retorno;
	Employee* empleado1;
	Employee* empleado2;
	int horas1;
	int horas2;
	retorno = 0;

	if(this != NULL && that != NULL){
		empleado1 = (Employee*)this;
		empleado2 = (Employee*)that;

		employee_getHorasTrabajadas(empleado1, &horas1);
		employee_getHorasTrabajadas(empleado2, &horas2);

		if(horas1 > horas2){
			retorno = 1;
		}else{
			if(horas1 < horas2){
				retorno = -1;
			}
		}
	}

	return retorno;
}

/// @brief Compara los sueldos conseguidos a través de employee_get() de los empleados pasados por parámetro.
///
/// @param this - Puntero a void donde se pasa el empleado.
/// @param that - Puntero a void donde se pasa el empleado.
/// @return int - Retorna 0 si los elementos comparados son iguales, 1 si el primero es mayor, y -1 si el segundo lo es.
int employee_compareSueldo(void* this, void* that){
	int retorno;
	Employee* empleado1;
	Employee* empleado2;
	int sueldo1;
	int sueldo2;
	retorno = 0;

	if(this != NULL && that != NULL){
		empleado1 = (Employee*)this;
		empleado2 = (Employee*)that;

		employee_getSueldo(empleado1, &sueldo1);
		employee_getSueldo(empleado2, &sueldo2);

		if(sueldo1 > sueldo2){
			retorno = 1;
		}else{
			if(sueldo1 < sueldo2){
				retorno = -1;
			}
		}
	}

	return retorno;
}
