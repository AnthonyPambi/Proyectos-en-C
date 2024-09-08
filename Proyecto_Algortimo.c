#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#define MAX 3 

typedef struct {
    char ced[11];
    char n[20];
    int nninos;
    int r; 
} dat;

void ingdat(dat info[], int *c);
void entregar(dat info[], int c);
void reportfalta(dat info[], int c);
void reportentre(dat info[], int c);

int main() {
	system("Title Menu de entrega de regalos");
    dat info[MAX];
    int c=0; 
    int op;
    do {
    	
        system("cls");
        printf("*****ENTREGA*DE*REGALOS*****\n");
        printf("1) Ingresar datos de representante\n");
        printf("2) Ingresar entrega de regalo en particular\n");
        printf("3) Mostrar reporte de regalos faltantes\n");
        printf("4) Mostrar reporte de regalos entregados\n");
        printf("5) Salir\n");
        printf("Opcion: ");
        scanf("%d", &op);
        switch (op) {
            case 1:
            	system("cls");
                ingdat(info, &c);
                system("pause");
                break;
            case 2:
            	system("cls");
                entregar(info, c);
                system("pause");
                break;
            case 3:
            	system("cls");
                reportfalta(info, c);
                system("pause");
                break;
            case 4:
            	system("cls");
                reportentre(info, c);
                system("pause");
                break;
            case 5:
                printf("Saliendo....\nPresione cualquier tecla para cerrar el programa");
                break;
            default:
                printf("Digito no valido, ingrese nuevamente..\n");
                system("pause");
                break;
        }
    } while (op != 5);
    return 0;
}

void ingdat(dat info[], int *c) {
    if (*c >= MAX) {
        printf("No se pueden ingresar más representantes.\n");
        ;
    }
    printf("====INGRESAR DATOS====\n");
    printf("Ingrese su cedula:");
    scanf("%s",info[*c].ced);
    printf("Ingrese su nombre:");
    scanf("%s",info[*c].n);
    printf("Ingrese numero de hijos:");
    scanf("%d",&info[*c].nninos);
    info[*c].r = 0; 
    (*c)=(*c)+1;
    printf("Datos ingresados correctamente....\n");
}

void entregar(dat info[], int c) {
    char cedula[11];
    int i;
    printf("Ingrese numero de cedula del representante: ");
    scanf("%s", cedula);
    int encontrado = 0;
    for (i=0;i<c;i++) {
        if (strcmp(info[i].ced, cedula) == 0) {
            info[i].r = 1;
            printf("REGALO ENTREGADO\nPara la familia de %s.\n", info[i].n);
            encontrado = 1;
            break;
        }
    }
    if (!encontrado) {
        printf("No existe ese numero de cedula.\n");
    }
}

void reportfalta(dat info[], int c) {
	int i;
    printf("REPORTE DE REGALOS FALTANTES\n");
    printf("============================\n");
    for (i=0;i<c;i++){
        if (info[i].r==0){
            printf("Cedula: %s, Nombre: %s, Hijos: %d\n", info[i].ced, info[i].n, info[i].nninos);
        }
    }
}

void reportentre(dat info[], int c){
	int i;
    printf("REPORTE DE REGALOS ENTREGADOS\n");
    printf("=============================\n");
    for (i=0;i<c;i++) {
        if (info[i].r==1){
            printf("Cedula: %s, Nombre: %s, Hijos: %d\n", info[i].ced, info[i].n, info[i].nninos);
        }
    }
}
