#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Funciones.h"

/** \brief valida precio
 *
 * \param precio char* puntero a precio
 * \return int* Retorna  (0) si los datos son correctos
                        ( -1) si los datos no son correctos
 *
 */
int isvalidPrecio(char* precio)
{
   int retorno=-1;
   float precioAux;
   if(!verificarArreglosoloFlotantes(precio))
   {
        precioAux=atof(precio);
        if(precioAux>=0)
        {
            retorno=0;
        }
   }
   return retorno;
}

/** \brief valida cuil
 *
 * \param cuil char* puntero a cuil
 * \return int* Retorna  (0) si los datos son correctos
                        ( -1) si los datos no son correctos
 *
 */
int isvalidCuil(char* cuil)
{
   int retorno=-1;
   if(!verificarCuitoCuil(cuil))
   {
        retorno=0;
   }
   return retorno;
}

/** \brief valida fecha
 *
 * \param fecha char* puntero a fecha
 * \return int* Retorna  (0) si los datos son correctos
                        ( -1) si los datos no son correctos
 *
 */
int isvalidFecha(char*fecha)
{
    int retorno=-1;
    if(!verificarfecha(fecha))
    {
        retorno=0;
    }
    return retorno;
}

/** \brief valida producto
 *
 * \param producto char* puntero a producto
 * \return int* Retorna  (0) si los datos son correctos
                        ( -1) si los datos no son correctos
 *
 */
int isvalidProducto(char*producto)
{
   int retorno;
    int i=0;
    int contadorguionBajo=0;
    char auxiliar=producto[i];
    while(auxiliar!='\0')
        {
            if(!((auxiliar>='A' && auxiliar<='Z')||(auxiliar>='0' && auxiliar<='9') || auxiliar=='_'))
            {
                retorno=-1;
                break;
            }
            if(auxiliar=='_')
            {
                contadorguionBajo++;
            }
                i++;
                auxiliar=producto[i];
            }
    if(contadorguionBajo==1)
    {
        retorno=0;
    }
    return retorno;
}

int isvalidID(char* id)
{
   int retorno=-1;
   int idaux;
   if(!verificarArregloSoloNumeros(id))
   {
        idaux=atoi(id);
        if(idaux>=0)
        {
            retorno=0;
        }
   }
   return retorno;
}

int isvalidCantidad(char*cantidad)
{
    int retorno=-1;
    int numero;
    if(cantidad!=NULL && !verificarArregloSoloNumeros(cantidad))
        {
            numero=atoi(cantidad);
            if(numero>=0)
                {
                    retorno=0;
                }
        }
        return retorno;
}

int isvalidMail(char*mail)
{
    int retorno=-1;
    if(mail!=NULL && !verificarMail(mail))
        {
            retorno=0;
        }
    return retorno;
}

int isvalidPassword(char*password)
{
    int retorno=-1;
    if(password!=NULL && !verificarArregloAlfanumerica(password))
        {
            retorno=0;
        }
    return retorno;
}

void imprimirObjeto(void*this)
{
    int idVenta;
    char fechaVenta[128];
    char codigoProducto[128];
    int cantidad;
    float precioUnitario;
    char cuitCliente[128];

        if(!Venta_getIdVenta(this,&idVenta)&&
           !Venta_getFechaVenta(this,fechaVenta)&&
           !Venta_getCodigoProducto(this,codigoProducto)&&
           !Venta_getCantidad(this,&cantidad)&&
           !Venta_getPrecioUnitario(this,&precioUnitario)&&
           !Venta_getCuitCliente(this,cuitCliente))
        {
            printf("%d %s %s %d %f %s\n",idVenta,fechaVenta,codigoProducto,cantidad,precioUnitario,cuitCliente);
        }
}
