#include "LinkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Envio.h"


/** \brief parsea un archivo de texto
 *
 * \param listaventas LinkedList* Puntero a la lista
 * \param fileName char* puntero al nombre del archivo
 * \return int Retorna  (0) Error si no pudo tomar los datos
                        ( 1) Si tomo los datos del archivo correctamente
 *
 */

int parser_parseEnvios(char* fileName, LinkedList* listaEnvios)
{
    FILE*pFile;
    int retorno=0;
    char buffer[2000];
    pFile=fopen(fileName,"r");
    char*tokenIdenvio;
    char*tokenNombreproducto;
    char*tokenIdcamion;
    char*tokenZonadestino;
    char*tokenKmrecorridos;
    char*tokenTipoentrega;
    Envio*envio;

    if(pFile!=NULL && listaEnvios!=NULL)
    {
        fgets(buffer,2000,pFile);
        do
        {
            fscanf(pFile,"%[^\n]\n",buffer);
            tokenIdenvio=strtok(buffer,",");
            tokenNombreproducto=strtok(NULL,",");
            tokenIdcamion=strtok(NULL,",");
            tokenZonadestino=strtok(NULL,",");
            tokenKmrecorridos=strtok(NULL,",");
            tokenTipoentrega=strtok(NULL,"\n");

            envio=Envio_newConParametros(tokenIdenvio,tokenNombreproducto,tokenIdcamion,tokenZonadestino,tokenKmrecorridos,tokenTipoentrega,0);

            if(envio!=NULL)
            {
                ll_add(listaEnvios,envio);
                retorno=1;
            }
        }while(!feof(pFile));
    }
    fclose(pFile);

    return retorno; // OK
}
