
#include "Envio.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Funciones.h"
#include "Validaciones.h"

Envio* Envio_new()
{
    Envio* this;
    this=malloc(sizeof(Envio));
    return this;
}

void Envio_delete(Envio* this)
{
    free(this);
}

Envio* Envio_newConParametros(char* id_Envio,char* nombre_producto,char* id_Camion,char* zona_Destino,char* km_recorridos,char* tipo_Entrega,int costo_Envio)
{
    Envio* this;
    this=Envio_new();

    if(
    !Envio_setId_Envio(this,id_Envio)&&
    !Envio_setNombre_producto(this,nombre_producto)&&
    !Envio_setId_Camion(this,id_Camion)&&
    !Envio_setZona_Destino(this,zona_Destino)&&
    !Envio_setKm_recorridos(this,km_recorridos)&&
    !Envio_setTipo_Entrega(this,tipo_Entrega)&&
    !Envio_setCosto_Envio(this,costo_Envio))
        return this;

    Envio_delete(this);
    return NULL;
}

int Envio_setId_Envio(Envio* this,char* id_Envio)
{
    int retorno=-1;
    int idAuxiliar;
    if(this!=NULL && !isvalidID(id_Envio))
    {
        idAuxiliar=atoi(id_Envio);
        this->id_Envio=idAuxiliar;
        retorno=0;
    }
    return retorno;
}

int Envio_getId_Envio(Envio* this,int* id_Envio)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *id_Envio=this->id_Envio;
        retorno=0;
    }
    return retorno;
}

int Envio_setNombre_producto(Envio* this,char* nombre_producto)
{
    int retorno=-1;
    if(this!=NULL && !isvalidNombre(nombre_producto))
    {
        strcpy(this->nombre_producto,nombre_producto);
        retorno=0;
    }
    return retorno;
}

int Envio_getNombre_producto(Envio* this,char* nombre_producto)
{
    int retorno=-1;
    if(this!=NULL && nombre_producto!=NULL)
    {
        strcpy(nombre_producto,this->nombre_producto);
        retorno=0;
    }
    return retorno;
}

int Envio_setId_Camion(Envio* this,char* id_Camion)
{
    int retorno=-1;
    int idAuxiliar;
    if(this!=NULL && !isvalidID(id_Camion))
    {
        idAuxiliar=atoi(id_Camion);
        this->id_Camion=idAuxiliar;
        retorno=0;
    }
    return retorno;
}

int Envio_getId_Camion(Envio* this,int* id_Camion)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *id_Camion=this->id_Camion;
        retorno=0;
    }
    return retorno;
}

int Envio_setZona_Destino(Envio* this,char* zona_Destino)
{
    int retorno=-1;
    if(this!=NULL && !isvalidNombre(zona_Destino))
    {
        strcpy(this->zona_Destino,zona_Destino);
        retorno=0;
    }
    return retorno;
}

int Envio_getZona_Destino(Envio* this,char* zona_Destino)
{
    int retorno=-1;
    if(this!=NULL && zona_Destino!=NULL)
    {
        strcpy(zona_Destino,this->zona_Destino);
        retorno=0;
    }
    return retorno;
}

int Envio_setKm_recorridos(Envio* this,char* km_recorridos)
{
    int retorno=-1;
    int kmAuxiliar;
    if(this!=NULL && !isvalidKmrecorrido(km_recorridos))
    {
        kmAuxiliar=atoi(km_recorridos);
        this->km_recorridos=kmAuxiliar;
        retorno=0;
    }
    return retorno;
}

int Envio_getKm_recorridos(Envio* this,int* km_recorridos)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *km_recorridos=this->km_recorridos;
        retorno=0;
    }
    return retorno;
}

int Envio_setTipo_Entrega(Envio* this,char* tipo_Entrega)
{
    int retorno=-1;
    int entregaAuxiliar;
    if(this!=NULL && !isvalidEntrega(tipo_Entrega))
    {
        entregaAuxiliar=atoi(tipo_Entrega);
        this->tipo_Entrega=entregaAuxiliar;
        retorno=0;
    }
    return retorno;
}

int Envio_getTipo_Entrega(Envio* this,int* tipo_Entrega)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *tipo_Entrega=this->tipo_Entrega;
        retorno=0;
    }
    return retorno;
}

int Envio_setCosto_Envio(Envio* this,int costo_Envio)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->costo_Envio=costo_Envio;
        retorno=0;
    }
    return retorno;
}

int Envio_getCosto_Envio(Envio* this,int* costo_Envio)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *costo_Envio=this->costo_Envio;
        retorno=0;
    }
    return retorno;
}

void imprimirEnvio_sincosto(void*this)
{
    int id_Envio;
    char nombre_producto[128];
    int id_Camion;
    char zona_Destino[128];
    int km_recorridos;
    int tipo_Entrega;

        if(!Envio_getId_Envio(this,&id_Envio)&&
           !Envio_getNombre_producto(this,nombre_producto)&&
           !Envio_getId_Camion(this,&id_Camion)&&
           !Envio_getZona_Destino(this,zona_Destino)&&
           !Envio_getKm_recorridos(this,&km_recorridos)&&
           !Envio_getTipo_Entrega(this,&tipo_Entrega))
        {
            printf("%d %s %d %s %d %d\n",id_Envio,nombre_producto,id_Camion,zona_Destino,km_recorridos,tipo_Entrega);
        }
}

void calcularCostoenvios(void*this)
{
    int km_Recorridos;
    int tipo_Entrega;
    int costo_envio=0;

    if(this!=NULL && !Envio_getKm_recorridos(this,&km_Recorridos) && !Envio_getTipo_Entrega(this,&tipo_Entrega))
    {
        if(km_Recorridos<50)
            {
                costo_envio= costo_envio+100*km_Recorridos;
            }
            else
                {
                    costo_envio=costo_envio+50*km_Recorridos;
                }

            switch(tipo_Entrega)
            {
                case 0:
                    costo_envio=costo_envio+250;
                    break;

                case 1:
                    costo_envio=costo_envio+420;
                    break;

                case 2:
                    costo_envio=costo_envio+75;
                    break;
            }
        }

        Envio_setCosto_Envio(this,costo_envio);
}

void imprimirEnvio_Concosto(void*this)
{
    int id_Envio;
    char nombre_producto[128];
    int id_Camion;
    char zona_Destino[128];
    int km_recorridos;
    int tipo_Entrega;
    int costo_Envio;

        if(!Envio_getId_Envio(this,&id_Envio)&&
           !Envio_getNombre_producto(this,nombre_producto)&&
           !Envio_getId_Camion(this,&id_Camion)&&
           !Envio_getZona_Destino(this,zona_Destino)&&
           !Envio_getKm_recorridos(this,&km_recorridos)&&
           !Envio_getTipo_Entrega(this,&tipo_Entrega)&&
           !Envio_getCosto_Envio(this,&costo_Envio))
        {
            printf("%d %s %d %s %d %d %d\n",id_Envio,nombre_producto,id_Camion,zona_Destino,km_recorridos,tipo_Entrega,costo_Envio);
        }
}

int verificar_Zona(void*this,void*palabra)
{
    int retorno=0;
    char zona [128];

    if(this!=NULL && !Envio_getZona_Destino(this,zona))
    {

        if(strcmp(zona,palabra)==0)
            {
                retorno=1;
            }
    }

return retorno;
}


