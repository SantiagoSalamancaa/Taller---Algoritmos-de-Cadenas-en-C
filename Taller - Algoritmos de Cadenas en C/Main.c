#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//Main menu
void main()
{
	int op;
	do
	{
		printf("\n_____Menu_____\n1.Convertir en nombre Propio el contenido del a cadena.\n2.Contar el numero de veces que existe una palabra en una cadena.\n3.Enctriptar cadena.\n4.Desencriptar.\n5.Llenar caracteres por Izquierda o por derecha.\n6.Borrar caracteres de una cadena.\n7.Interseccion.\n8.Diferencia entre dos cadenas.\n9.Borrar caracteres Izquierda o Derecha.\n10.Validar correo electronico.\n11.Salir\n>>");
		scanf_s("%d", &op);

		switch (op)
		{
		case 1:
			//Convertir en nombre Propio el contenido de la cadena

			printf("Digite una palabra\n>>");
			
			char cadena[200];
			char* p;
			p = cadena;

			gets(cadena);
			gets(p);

			//printf("%s\n", p);
			
			int i=1;
			while (*p != '\0') {

				if (*p == ' ')
				{
					i = 1;
				}
				else if (*p >= 'A' && *p <= 'Z')
				{
					i = 0;
				}
				else if (*p >= 'a' && *p <= 'z' && i==1)
				{
					*p = *p - 'a' + 'A';
					i = 0;
				}
				//printf("%s\n", p);
				p++;
			}

			printf("La cadena queda: \"%s\" \n", cadena);
			
			break;
		case 2:
			//Contar el n�mero de veces que existe una palabra en una cadena

			printf("Ingrese un texto (Maximo 200 letras).\n>>");

			char text[200];
			char* tok;
			char* next_tok1;
			int cont = 0;
			char palabra[20];

			gets(text);
			gets(text);
			printf("Ingrese una palabra a buscar dentro del texto.\n>>");

			gets(palabra);

			tok = strtok_s(text, " \,\.\:\;", &next_tok1);
			
			while (tok != NULL)
			{
				if (_stricmp(tok, palabra)==0) 
				{
					cont++;
				}
				tok = strtok_s(NULL, " \,\.\:\;", &next_tok1);
			}

			printf("La palabra (%s) se encontro (%i) veces\n", palabra, cont);

			break;
		case 3:
			//Enctriptar cadena
			break;
		case 4:
			//Desencriptar
			break;
		case 5:
			//Llenar caracteres por Izquierda o por derecha
			break;
		case 6:
			//Borrar caracteres de una cadena
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
			break;
		}

	} while (op != 11);
}