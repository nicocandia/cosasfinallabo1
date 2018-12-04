#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int opcion;

    printf("\n <<<<<<BIENVENIDO>>>>>>\n");
    do
        {
            if(utn_getInt(&opcion,"\n1-ALTAS\n \n2-MODIFICAR\n \n3-BAJA\n \n4-INFORMAR\n \n5-SALIR\n\nOPCION:???\n","\nerror ingrese opcion valida",1,5,3)==0)
                {
                    switch(opcion)
                    {
                        case 1:
                            
                            break;

                        case 2:
                            
                                break;

                        case 3:
                            
                            break;

                        case 4:
                                  
                            break;

                    }
                }
        }while(opcion!=5);
    return 0;
}
