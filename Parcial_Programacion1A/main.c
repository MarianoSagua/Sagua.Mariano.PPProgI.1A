#include <stdio.h>
#include <stdlib.h>
#define TAM 2
#define VACIO 0
#define OCUPADO 1

typedef struct{
    int id;
    char nombre[20];
    char tipo[20];
    float efectividad;
    int isEmpty;
}eVacuna;

int aplicarAumento(int precioProducto);
int ordenarPorTipo(eVacuna lista[], int tam);

int main()
{
    eVacuna lista[TAM] = {
            {2000, "A1", "tipoUno", 9.6, OCUPADO},
            {2001, "A2", "tipoDos", 6.4, OCUPADO},
    };

    aplicarAumento(200);

    ordenarPorTipo(lista, TAM);
    for(int i=0; i<TAM; i++){
        if(lista[i].isEmpty == OCUPADO){
            printf("%3d\t %3s\t %3s\t %3.2f\t\n",
                lista[i].id,
                lista[i].nombre,
                lista[i].tipo,
                lista[i].efectividad
            );

        }
    }



    return 0;
}

int aplicarAumento(int precioProducto){
    int todoOk = 0;
    float aumento;
    float precioConAumento;

    if(precioProducto > 0){

        aumento = precioProducto * 5/100;

        precioConAumento = precioProducto + aumento;

        printf("El precio con el aumento es: %.2f\n", precioConAumento);

        todoOk = 1;
    }

    return todoOk;
}

int ordenarPorTipo(eVacuna lista[], int tam){
    int todoOk = 0;
    eVacuna auxlista;

    if(lista != NULL && tam > 0){
        for(int i=0; i<tam-1; i++){
            for(int j=i+1; j<tam; j++){
                if(lista[i].tipo != lista[j].tipo){
                    if(strcmp(lista[i].tipo, lista[j].tipo) < 0){
                        auxlista = lista[i];
                        lista[i] = lista[j];
                        lista[j] = auxlista;
                    }
                }else{
                    if(lista[i].efectividad < lista[j].efectividad){
                        auxlista = lista[i];
                        lista[i] = lista[j];
                        lista[j] = auxlista;
                    }
                }
            }
        }

        todoOk = 1;
    }


    return todoOk;
}
