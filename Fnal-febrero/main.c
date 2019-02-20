#include <stdio.h>
#include <stdlib.h>
#include "Envio.h"
#include <string.h>
#include "LinkedList.h"
#include "Funciones.h"
#include "Parser.h"
#include "Generador.h"
int main()
{
   int opcion;
   char zona[128];
    LinkedList*listaEnvios=ll_newLinkedList();
    LinkedList*listaPorzona=ll_newLinkedList();

    printf("\n <<<<<<BIENVENIDO>>>>>>\n");
    do
        {
            if(utn_getInt(&opcion,"\n1-CARGAR ARCHIVO\n \n2-IMPRIMIR ENVIOS\n \n3-CALCULAR COSTOS\n \n4-GENERAR ARCHIVO\n \n5-IMPRIMIR LISTA CON ZONA\n\n6-SALIR\n\nOPCION:???\n","\nerror ingrese opcion valida",1,6,3)==0)
                {
                    switch(opcion)
                    {
                        case 1:
                            if(parser_parseEnvios("DATA_2F.csv",listaEnvios)==1)
                                {
                                    printf("\nse cargo el archivo correctamente\n");
                                }else{printf("no se pudo cargar el archivo");}

                            break;

                        case 2:
                            ll_map(listaEnvios,imprimirEnvio_sincosto);

                                break;

                        case 3:
                            printf("calculando costos....");
                            ll_map(listaEnvios,calcularCostoenvios);
                            printf("\nse han calculado los costos de envio");

                            break;

                        case 4:

                            if(!utn_getLetras(zona,128,3,"\ningrese zona\n","error\n"))
                                {
                                    listaPorzona=ll_filterVersion2(listaEnvios,verificar_Zona,zona);
                                    if(generarArchivos(zona,listaPorzona)==1)
                                        {
                                            printf("\nse genero el archivo correctamente\n");
                                        }else{printf("\nno se pudo generar el archivo\n");}
                                }
                            break;

                        case 5:
                            ll_map(listaPorzona,imprimirEnvio_Concosto);
                            break;

                    }
                }
        }while(opcion!=6);
    return 0;
}
