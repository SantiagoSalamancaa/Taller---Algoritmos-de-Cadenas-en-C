#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Main menu
void main() {
    char cadena[200];
    char *p;
    char *tok;
    char *next_tok1;
    int op, cont;
    do {
        printf("\n_____Menu_____\n1.Convertir en nombre Propio el contenido del a cadena.\n2.Contar el numero de veces que existe una palabra en una cadena.\n3.Enctriptar cadena.\n4.Desencriptar.\n5.Llenar caracteres por Izquierda o por derecha.\n6.Borrar caracteres de una cadena.\n7.Interseccion.\n8.Diferencia entre dos cadenas.\n9.Borrar caracteres Izquierda o Derecha.\n10.Validar correo electronico.\n11.Salir\n>>");
        scanf_s("%d", &op);

        switch (op) {
            case 1:
                //Convertir en nombre Propio el contenido de la cadena

                printf("Digite una palabra\n>>");

                //char cadena[200];
                //char* p;
                p = cadena;

                gets(cadena);
                gets(p);

                //printf("%s\n", p);

                int i = 1;
                while (*p != '\0') {

                    if (*p == ' ') {
                        i = 1;
                    } else if (*p >= 'A' && *p <= 'Z') {
                        i = 0;
                    } else if (*p >= 'a' && *p <= 'z' && i == 1) {
                        *p = *p - 'a' + 'A';
                        i = 0;
                    }
                    //printf("%s\n", p);
                    p++;
                }

                printf("La cadena queda: \"%s\" \n", cadena);

                break;
            case 2:
                //Contar el número de veces que existe una palabra en una cadena

                printf("Ingrese un texto (Maximo 200 letras).\n>>");

                //char* tok;
                //char* next_tok1;
                cont = 0;
                char palabra[20];

                gets(cadena);
                gets(cadena);
                printf("Ingrese una palabra a buscar dentro del texto.\n>>");

                gets(palabra);

                tok = strtok_s(cadena, " \,\.\:\;", &next_tok1);

                while (tok != NULL) {
                    if (_stricmp(tok, palabra) == 0) {
                        cont++;
                    }
                    tok = strtok_s(NULL, " \,\.\:\;", &next_tok1);
                }

                printf("La palabra (%s) se encontro (%i) veces\n", palabra, cont);

                break;
            case 3:
                //Enctriptar cadena usando código ascii

                printf("Ingrese el texto que quiere encriptar\n>>");

                gets(cadena);
                gets(cadena);

                for (int i = 0; i < 200; i++) {

                    if (cadena[i] == -52) {
                        i++;
                    } else {
                        //printf("%c\n", cripText[i]);
                        printf("%c", cadena[i] + 1);
                    }
                }

                break;
            case 4:
                //Desencriptar

                printf("Ingrese el texto que quiere desencriptar\n>>");

                gets(cadena);
                gets(cadena);

                for (int i = 0; i < 200; i++) {

                    if (cadena[i] == -52) {
                        i++;
                    } else {
                        //printf("%c\n", cripText[i]);
                        printf("%c", cadena[i] - 1);
                    }
                }

                break;
            case 5: {
                printf("Ingrese el texto\n>>");
                gets(cadena);
                gets(cadena);
                int numRepe;
                printf("ingrese la cantidad de veces\n>>");
                if (scanf_s("%i", &numRepe) != 1) {
                    printf("el valor debe ser un entero");
                } else if (numRepe < 0) {
                    printf("Error!!!, no puede ingresar cantidades negativas");
                } else {
                    char variableCaracter[numRepe];
                    printf("ingrese el caracter que quiere añadir\n>>");

                    gets(variableCaracter);
                    gets(variableCaracter);

                    printf("ingrese 1 para añadir por derecha\ningrese 2 para añadir por la izquierda\n>>");
                    int op;
                    scanf("%d", &op);

                    if (op != 1 && op != 2) {
                        printf("Error!!, Valor fuera de parámetro");
                    }

                    if (op == 1) {
                        for (int i = 0; i < numRepe; ++i) {
                            strcat(cadena, variableCaracter);
                        }
                        printf("La cadena queda:\n");
                        printf("%s.\n", cadena);

                    }
                    if (op == 2) {
                        printf("La cadena queda:\n");
                        for (int i = 0; i < numRepe; ++i) {
                            printf(variableCaracter);
                            //strcat(cadena, variableCaracter);
                        }
                        printf(cadena);
                    }
                }
            }
                break;
            case 6:
                printf("ingrese la cadena de texto\n>>");
                char newText[100];
                char borrar;
                gets(cadena);
                gets(cadena);
                int longText = strlen(cadena);
                printf("Ingrese el caracter que quiere borrar\n>>");
                scanf_s("%c", &borrar);
                int contador = 0;

                for (int i = 0; i < longText; ++i) {
                    if (cadena[i] != borrar) {
                        newText[contador] = cadena[i];
                        contador++;
                    }
                }
                newText[contador] = '\0';

                printf("%s\n", newText);
                //Borrar caracteres de una cadena- falta agregarle condicional a la variable borrar.
                break;
            case 7:

                //Interseccion
                break;
            case 8:
                //Diferencia entre dos cadenas
                break;
            case 9:
                //Borrar caracteres Izquierda o Derecha
                break;
            case 10:
                //Validar correo electronico

                printf("Ingrese su correo electronico\n>>");

                gets(cadena);
                gets(cadena);

                for (int i = 0; i < 40; i++) {
                    tok = strstr(cadena, "@");
                    if (tok != NULL) {
                        break;
                    }
                }
                for (int i = 0; i < 40; i++) {
                    next_tok1 = strstr(cadena, ".");
                    if (next_tok1 != NULL && &next_tok1 > &tok) {
                        break;
                    }
                }

                if (tok != NULL) {
                    if (next_tok1 != 0 && &next_tok1 > &tok) {
                        printf("Correo valido.");
                    } else {
                        printf("Su correo es invalido, por favor reviselo.");
                    }
                } else {
                    printf("Su correo es invalido, por favor reviselo.");
                }
        }

    } while (op != 11);
}