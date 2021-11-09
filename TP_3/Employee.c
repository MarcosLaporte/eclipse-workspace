#include "Employee.h"

Employee* employee_new(){
	Employee* miEmpleado;

	miEmpleado = (Employee*)calloc(1, sizeof(Employee));

	return miEmpleado;
}

Employee* employee_newParametros(char* idStr, char* nombreStr, char* horasTrabajadasStr, char* sueldo){
	Employee* miEmpleado;

	miEmpleado = employee_new();
	if(idStr != NULL && nombreStr != NULL && horasTrabajadasStr != NULL && sueldo != NULL){
		/*if(!f_isInt(idStr, &auxId) && !f_getName(nombreStr, auxNombre) &&
				!f_isInt(horasTrabajadasStr, &auxHoras) && !f_isInt(sueldo, &auxSueldo)){ //Por fuera*/
			employee_setId(miEmpleado, atoi(idStr));
			camelStr(nombreStr);
			employee_setNombre(miEmpleado, nombreStr);
			employee_setHorasTrabajadas(miEmpleado, atoi(horasTrabajadasStr));
			employee_setSueldo(miEmpleado, atoi(sueldo));
//		}
	}

	return miEmpleado;
}

Employee* employee_newUsuario(int id){
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

void employee_delete(Employee* this){
	free(this);
	//Mucho código
}

int employee_setId(Employee* this, int id){
	int retorno;
	retorno = -1;

	if(this != NULL){
		this->id = id;
		retorno = 0;
	}

	return retorno;
}

int employee_getId(Employee* this, int* id){
	int retorno;
	retorno = -1;

	if(this != NULL && id != NULL){
		*id = this->id;
		retorno = 0;
	}

	return retorno;
}

int employee_setNombre(Employee* this, char* nombre){
	int retorno;
	retorno = -1;

	if(this != NULL && nombre != NULL){
		strcpy(this->nombre, nombre);
		retorno = 0;
	}

	return retorno;
}

int employee_getNombre(Employee* this, char* nombre){
	int retorno;
	retorno = -1;

	if(this != NULL && nombre != NULL){
		strcpy(nombre, this->nombre);
		retorno = 0;
	}

	return retorno;
}

int employee_setHorasTrabajadas(Employee* this, int horasTrabajadas){
	int retorno;
	retorno = -1;

	if(this != NULL){
		this->horasTrabajadas = horasTrabajadas;
		retorno = 0;
	}

	return retorno;
}

int employee_getHorasTrabajadas(Employee* this, int* horasTrabajadas){
	int retorno;
	retorno = -1;

	if(this != NULL && horasTrabajadas != NULL){
		*horasTrabajadas = this->horasTrabajadas;
		retorno = 0;
	}

	return retorno;
}

int employee_setSueldo(Employee* this, int sueldo){
	int retorno;
	retorno = -1;

	if(this != NULL){
		this->sueldo = sueldo;
		retorno = 0;
	}

	return retorno;
}

int employee_getSueldo(Employee* this, int* sueldo){
	int retorno;
	retorno = -1;

	if(this != NULL && sueldo != NULL){
		*sueldo = this->sueldo;
		retorno = 0;
	}

	return retorno;
}

int employee_printEmpleado(Employee* this){
	int retorno;
	int id;
	char nombre[MAX_CHAR];
	int horas;
	int sueldo;
	retorno = -1;

	if(this != NULL){
		employee_getId(this, &id);
		employee_getNombre(this, nombre);
		employee_getHorasTrabajadas(this, &horas);
		employee_getSueldo(this, &sueldo);

		printf("|%4d|%25s|%5d|%8d|\n", id, nombre, horas, sueldo);
	}

	return retorno;
}

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
