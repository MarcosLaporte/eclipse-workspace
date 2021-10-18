// nacionalidad
#define EEUU 1
#define CHINA 2
#define OTRO 3
// tipo
#define IPHONE 1
#define MAC 2
#define IPAD 3
#define ACCESORIOS 4
//estado
#define VACIO 0
#define CARGADO 1
// modificaciones
#define DESCR 1
#define NACION 2
#define TIPO 3
#define PRECIO 4

typedef struct{
	int idProducto;
	char descripcion[50];
	int nacionalidad;
	int tipo;
	float precio;
	int estado;
}eProducto;

eProducto PedirProducto();
int AltaProducto(eProducto listaProd[], int tam);
void MostrarProducto(eProducto unProducto);
void MostrarLista(eProducto listaProductos[], int tam);
void InicializarProductos(eProducto listaProductos[], int tam);
int BajaProducto(eProducto listaProd[], int tam);
int ModificarProducto(eProducto listaProd[], int tam);
int OrdenarArrayPrecio(eProducto listaProd[], int tam);
int OrdenarArrayDescripcion(eProducto listaProd[], int tam);
//int BuscarId(int idBuscado, eProducto idProducto[], int tam);

