#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Envio.h"

/** \brief genera un archivo de texto con los datos de la listaVentas
 *
 * \param listaventas LinkedList* Puntero a la lista
 * \param fileName char* puntero al nombre del archivo
 * \return int Retorna  (0) Error si no pudo escribir el archivo
                        ( 1) Si pudo escribir el archivo correctamente
 *
 */

int generarArchivos(char* fileName,LinkedList* listaEnvios)
{
    int retorno=0;
    int id_Envio;
    char nombre_producto[128];
    int id_Camion;
    char zona_Destino[128];
    int km_recorridos;
    int tipo_Entrega;
    int costo_Envio;
    int i;
    FILE*pFile;
    int len=ll_len(listaEnvios);
    pFile=fopen(fileName,"w");
    Envio*envio;

    if(pFile!=NULL && listaEnvios!=NULL && len>0)
    {
        for(i=0; i<len; i++)
        {
            envio=(Envio*)ll_get(listaEnvios,i);

            if(!Envio_getId_Envio(envio,&id_Envio)&&
                    !Envio_getNombre_producto(envio,nombre_producto)&&
                    !Envio_getId_Camion(envio,&id_Camion)&&
                    !Envio_getZona_Destino(envio,zona_Destino)&&
                    !Envio_getKm_recorridos(envio,&km_recorridos)&&
                    !Envio_getTipo_Entrega(envio,&tipo_Entrega)&&
                    !Envio_getCosto_Envio(envio,&costo_Envio))
            {
                fprintf(pFile,"%d %s %d %s %d %d %d\n",id_Envio,nombre_producto,id_Camion,zona_Destino,km_recorridos,tipo_Entrega,costo_Envio);
            }

        }

        retorno=1;
    }
    fclose(pFile);
    return retorno;
}
