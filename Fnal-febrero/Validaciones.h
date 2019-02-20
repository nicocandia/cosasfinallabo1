#ifndef VALIDACIONES_H_INCLUDED
#define VALIDACIONES_H_INCLUDED

int isvalidPrecio(char* precio);

/** \brief valida cuil
 *
 * \param cuil char* puntero a cuil
 * \return int* Retorna  (0) si los datos son correctos
                        ( -1) si los datos no son correctos
 *
 */
int isvalidCuil(char* cuil);


/** \brief valida fecha
 *
 * \param fecha char* puntero a fecha
 * \return int* Retorna  (0) si los datos son correctos
                        ( -1) si los datos no son correctos
 *
 */
int isvalidFecha(char*fecha);

/** \brief valida producto
 *
 * \param producto char* puntero a producto
 * \return int* Retorna  (0) si los datos son correctos
                        ( -1) si los datos no son correctos
 *
 */
int isvalidProducto(char*producto);

int isvalidID(char* id);

int isvalidCantidad(char*cantidad);

int isvalidMail(char*mail);

int isvalidPassword(char*password);

int isvalidNombre(char*palabra);

int isvalidKmrecorrido(char*numero);

int isvalidEntrega(char* entrega);


#endif // VALIDACIONES_H_INCLUDED
