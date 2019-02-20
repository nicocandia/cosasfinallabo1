#ifndef ENVIO_H_INCLUDED
#define ENVIO_H_INCLUDED

typedef struct
{
    int id_Envio;
    char nombre_producto[128];
    int id_Camion;
    char zona_Destino[128];
    int km_recorridos;
    int tipo_Entrega;
    int costo_Envio;
}Envio;

Envio* Envio_new();
void Envio_delete();
Envio* Envio_newConParametros(char* id_Envio,char* nombre_producto,char* id_Camion,char* zona_Destino,char* km_recorridos,char* tipo_Entrega,int costo_Envio);

int Envio_setId_Envio(Envio* this,char* id_Envio);
int Envio_getId_Envio(Envio* this,int* id_Envio);

int Envio_setNombre_producto(Envio* this,char* nombre_producto);
int Envio_getNombre_producto(Envio* this,char* nombre_producto);

int Envio_setId_Camion(Envio* this,char* id_Camion);
int Envio_getId_Camion(Envio* this,int* id_Camion);

int Envio_setZona_Destino(Envio* this,char* zona_Destino);
int Envio_getZona_Destino(Envio* this,char* zona_Destino);

int Envio_setKm_recorridos(Envio* this,char* km_recorridos);
int Envio_getKm_recorridos(Envio* this,int* km_recorridos);

int Envio_setTipo_Entrega(Envio* this,char* tipo_Entrega);
int Envio_getTipo_Entrega(Envio* this,int* tipo_Entrega);

int Envio_setCosto_Envio(Envio* this,int costo_Envio);
int Envio_getCosto_Envio(Envio* this,int* costo_Envio);

void imprimirEnvio_sincosto(void*this);
void calcularCostoenvios(void*this);
void imprimirEnvio_Concosto(void*this);
int verificar_Zona(void*this,void*palabra);
#endif // ENVIO_H_INCLUDED
