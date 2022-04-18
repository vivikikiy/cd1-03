#include <stdio.h>
#include <ctype.h>
#include <math.h>

#define MAX 4096
int i=0;
int palabras=0;
int letras=0;
int oraciones=0;
float s=0;
float l=0;
float resultado=0;
int read_file(char *text, char *filename);

int main(int argc, char *argv[]) {

    if (argc != 2) {
        printf("Uso: ./readability file\n");
        return 1;
    }

    char text[MAX];

    if (read_file(text, argv[1])) {
        printf("Archivo no encontrado\n");
        return 1;
    }

    while (text[i]) {  

        if (isalpha(text[i])) { 
            letras++; 
        }

        if (text[i]==' ') { 
            palabras++; 
        } 

        if (text[i]=='.'||'?'||'!') { 
            oraciones++;
        }

        i++;
    }

    l = 100*letras/palabras;
    s = 100*oraciones/palabras;

    resultado = 0.0588*l-0.290*s-15.8;
    resultado = round(resultado);

    if (resultado < 1)
    { 
        printf("Before Grade 1\n");
    }
    else if ( resultado > 16)
    { 
        printf("Grade 16+\n");
    }
    else {
        printf("grado %d\n", resultado);
    }
     

    return 0;
}

int read_file(char *text, char *filename) {

    FILE *fp;
    char c;
    char full_name[30];
    
    sprintf(full_name, "texts/%s.txt", filename);
    fp = fopen(full_name, "r");
    
    if (!fp) {
        return 1;
    } 
    while ((c = getc(fp)) != EOF) {
        *text = c;
        text++;
    }
    return 0;
}
