/*
 * ArrayEmployees.h
 *      Author: Marcos
 */

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_

#define FALSE 0
#define TRUE 1
#define MAX_EMPLOYEES 1000

typedef struct{
	int id;
	char name[51];
	char lastName[51];
	float salary;
	int sector;
	int isEmpty;
}Employee;

/// @brief Inicializa todas las posiciones del array como vacias, declarando la bandera "isEmpty" en 1 (TRUE).
///
/// @param list - Puntero al array de empleados.
/// @param len - Indica el tamaño del array.
/// @return int - Retorna -1 si el puntero es nulo o el tamaño es inválido, o 0 si está todo bien.
int initEmployees(Employee* list, int len);

/// @brief Agrega a un array los valores pasados como parámetros en la primer posición vacía.
///
/// @param list - Puntero al array de empleados.
/// @param len - Indica el tamaño del array.
/// @param id - Valor del id a agregar.
/// @param name - Valor del nombre a agregar.
/// @param lastName - Valor del apellido a agregar.
/// @param salary - Valor del salario a agregar.
/// @param sector - Valor del sector a agregar.
/// @return int - Retorna -1 si el puntero es nulo o el tamaño es inválido, o 0 si está todo bien.
int addEmployee(Employee* list, int len, int id, char name[], char lastName[], float salary, int sector);

/// @brief Busca un empleado por el id que se pasa como parámetro.
///
/// @param list - Puntero al array de empleados donde hay que buscar el id.
/// @param len - Indica el tamaño del array.
/// @return int - Retorna la posición del id si lo encuentra, y -1 si no o si el puntero es nulo o el tamaño es inválido.
int findEmployeeById(Employee* list, int len, int id);

/// @brief Declara la bandera "isEmpty" del empleado en 1 (TRUE).
///
/// @param list - Puntero al array de empleados.
/// @param len - Indica el tamaño del array.
/// @param id - El id del empleado a remover.
/// @return int - Retorna -1 si el puntero es nulo o el tamaño es inválido, o 0 si está todo bien.
int removeEmployee(Employee* list, int len, int id);

/// @brief Ordena el array de empleados por apellido y sector de manera ascendente o descendente.
///
/// @param list - Puntero al array de empleados.
/// @param len - Indica el tamaño del array.
/// @param order - 1 indica Arriba - 0 indica Abajo.
/// @return int - Retorna -1 si el puntero es nulo o el tamaño es inválido, o 0 si está todo bien.
int sortEmployee(Employee* list, int len, int order);

/// @brief Imprime el array de empleados de forma encolumnada.
///
/// @param list - Puntero al array de empleados.
/// @param len - Indica el tamaño del array.
/// @return int - Retorna -1 si el puntero es nulo o el tamaño es inválido, o 0 si está todo bien.
int printEmployees(Employee* list, int len);

// FUNCIONES PROPIAS

/// @brief Pide los datos de un empleado.
///
/// @param list - Puntero al array de empleados.
/// @param length - Indica el tamaño del array.
/// @return Employee - Retorna un tipo de dato de estructura "Employee" con los datos pedidos.
Employee getEmployee(Employee* list, int length);

/// @brief Modifica el campo seleccionado de un empleado por su ID.
///
/// @param list - Puntero al array de empleados.
/// @param length - Indica el tamaño del array.
/// @param id - El ID del empleado a modificar.
/// @return int - Retorna -1 si el puntero es nulo, el tamaño es inválido o si no existe ese ID, o 0 si está todo bien.
int modifyEmployee(Employee* list, int length, int id);

/// @brief Muestra en pantalla la lista de empleados completa
///
/// @param list - Puntero al array de empleados.
/// @param length - Indica el tamaño del array.
void printList(Employee* list, int len);

/// @brief Revisa que haya al menos un empleado cargado.
///
/// @param list - Puntero al array de empleados.
/// @param length - Indica el tamaño del array.
/// @return int Retorna -1 si no hay empleados cargados, o 0 si hay al menos 1.
int checkAnEmployee(Employee* list, int lenght);

/// @brief Calcula el salario total y promedio con los datos de la estructura.
///
/// @param list - Puntero al array de empleados.
/// @param length - Indica el tamaño del array.
/// @param *refAverage - Puntero para pasar el promedio de salarios.
/// @param *refSum - Puntero para pasar la suma de salarios.
/// @return int - Retorna -1 si el puntero es nulo o el tamaño es inválido, o 0 si está todo bien.
int calcAverageSalary(Employee* list, int length, float* refAverage, float* refSum);

/// @brief Calcula cuántos empleados están por encima del salario promedio pasado como parámetro.
///
/// @param list - Puntero al array de empleados.
/// @param length - Indica el tamaño del array.
/// @param averageSalary - El promedio a fijarse si el empleado supera.
/// @return int - Retorna 0 el número de empleados que pasan el promedio.
int calcEmployeesOverSalary(Employee* list, int length, float averageSalary);

/// @brief Muestra en pantalla los últimos 3 mensajes con sus respectivos parámetros.
///
/// @param salarySum - La suma total de salarios.
/// @param averageSalary - EL promedio de los salarios.
/// @param overSalaryEmp - La cantidad de empleados que pasan el salario promedio.
void printFinalSalaries(float salarySum, float averageSalary, int overSalaryEmp);

#endif /* ARRAYEMPLOYEES_H_ */
