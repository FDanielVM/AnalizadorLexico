#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <process.h>

int main()
{
    int estado=0;
    unsigned char entrada[50];
    char *p=entrada;


    printf(" Introuduce la cadena a analizar: \n"); gets(entrada);

    while (*p!= '\0')
    {
        switch(estado)
        {
            case 0:
                if(isalpha (*p) || *p=='_')
                    estado=1;
                else if(isdigit(*p))
                    estado=3;
                else estado =7;
                p++;
                break;
            case 1:
                if(isalpha (*p) || *p=='_' || isdigit(*p))
                    estado=1;
                else estado =2;
                p++;
                break;
            case 2:
                printf(" Identificador");
                estado=0;
                p--;
                break;
            case 3:
                if(isdigit(*p))
                    estado=3;
                else if(*p=='.')
                    estado=5;
                else estado=4;
                p++;
                break;
            case 4:
                printf(" Entero");
                estado=0;
                p--;
                break;
            case 5:
                if(isdigit(*p))
                    estado=4;
                else estado=6;
                p++;
                break;
            case 6:
                printf(" Real");
                estado=0;
                p--;
                break;
        }
    }
    switch(estado)
    {
        case 1: //ajuste de ultimo token
        case 2: printf(" Identificador"); break;
        case 3: printf(" Entero"); break;
        case 4: printf(" Real"); break;
        case 5: printf(" Bugeo4"); break;
        case 6: printf(" Bugeo4"); break;
        case 7: printf(" NO IDENTIFICADO"); break;
    }
}
