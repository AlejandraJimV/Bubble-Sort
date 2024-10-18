/*Elaborado por Alejandra Jiménez Venegas 
Estructuras de Datos
Este programa es un ejemplo educativo que ilustra el uso de estructuras de datos y algoritmos de ordenamiento, 
así como la manipulación de la consola en C. Además, permite al usuario observar el proceso de ordenamiento
a medida que se realizan las comparaciones e intercambios.*/


#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#define MAX 37

void gotoxy(int x, int y);
int margen(int a, int b, int c, int d);
void generarAleatorios(int vector[], int n);
void ordenarBurbuja(int x, int y, int vector[], int n, int m);
void realizarIntercambio(int x, int y, int c, int a, int b, int m);
void datosVector(int x, int y, int n, int m);
void imprimirVector(int x, int y, int vector[], int n, int m);
void finalizar();

main() {
    int n;
    int Vector[MAX];
    margen(2, 1, 117, 25);
    margen(40, 2, 75, 4);
    gotoxy(40, 3);
    printf("METODO DE ORDENAMIENTO DE LA BURBUJA");

    do {
        gotoxy(40, 6);
        printf("Elementos (menor o igual que 37): ");
        gotoxy(74, 6);
        scanf("%d", &n);

        if (n > 37) {
            gotoxy(40, 7);
            printf("Por favor, ingrese un valor menor o igual a 37");
            Sleep(3000);
            gotoxy(40, 7);
            printf("                                               ");
            gotoxy(74, 6);
            printf("  ");
        }
    } while (n > 37);

    datosVector(5, 15, n, 2);
   	srand(time(NULL));
    generarAleatorios(Vector, n);

    gotoxy(5, 8);
    printf("Vector Original: ");
    imprimirVector(5, 8, Vector, n, 2); // Para imprimir el vector original

    ordenarBurbuja(5, 15, Vector, n, 2);
    finalizar();
}

void imprimirVector(int x, int y, int vector[], int n, int m) {
    int i;
    for (i = 0; i < n; i++) {
        gotoxy(x + ((m + 1) * i), y + 1);
        printf("%02d", vector[i]);
    }
}

void finalizar()
{
	gotoxy(5, 20);
    printf("Fin del ordenamiento");
    gotoxy(5, 23);
    printf("Presione una tecla para finalizar...");
    getch();
    system("cls");
}

void gotoxy(int x, int y) {
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hcon, dwPos);
}

void generarAleatorios(int vector[], int n ) {
   int i;
	
	for(i=0;i<n;i++){
		vector[i] = rand() % 90 + 10;
	}
}

void datosVector(int x, int y, int n, int m) {
    int i, j;

    gotoxy(x, y);
    printf("%c", 218);
    gotoxy(x, y + 2);
    printf("%c", 192);

    for (i = 0; i < n; i++) {
        for (j = 1; j <= m; j++) {
            gotoxy(x + ((m + 1) * i) + j, y);
            printf("%c", 196);
            gotoxy(x + ((m + 1) * i) + j, y + 2);
            printf("%c", 196);
        }
        gotoxy(x + ((m + 1) * i) + j, y);
        printf("%c", 194);
        gotoxy(x + ((m+ 1) * i) + j, y + 2);
        printf("%c", 193);
    }

    for (i = 0; i <= n; i++) {
        gotoxy(x + ((m + 1) * i), y + 1);
        printf("%c", 179);
    }
    gotoxy(x + ((m + 1) * i) - (m + 1), y);
    printf("%c", 191);
    gotoxy(x + ((m + 1) * i) - (m + 1), y + 2);
    printf("%c", 217);
}

//Para representacion/animacion
void realizarIntercambio(int x, int y, int c, int a, int b, int m) {
    int i, j;
    // Recorrido hacia arriba
    for (i = 0; i < 4; i++) {
        if (i == 2) {
            gotoxy(c, (y + 1) - i + 1);
            printf("%c%c", 196, 196);
            gotoxy(c + (m + 1), (y + 1) + i - 1);
            printf("%c%c", 196, 196);
        }
        gotoxy(c, (y + 1) - i);
        printf("\033[1;32m%02d\033[0m", a);  // Impresión en verde
        gotoxy(c + (m + 1), (y + 1) + i);
        printf("\033[1;32m%02d\033[0m", b);  // Impresión en verde
        Sleep(200);
        for (j = 0; j < m; j++) {
            gotoxy(c + j, (y + 1) - i);
            printf(" ");
            gotoxy(c + j + (m + 1), (y + 1) + i);
            printf(" ");
        }
    }
    // Recorrer hacia los lados
    for (i = 0; i < 4; i++) {
        gotoxy(c + i, y - 2);
        printf("\033[1;32m%02d\033[0m", a);  // Impresión en verde
        gotoxy((c + (m + 1)) - i, y + 4);
        printf("\033[1;32m%02d\033[0m", b);  // Impresión en verde
        Sleep(200);
        for (j = 0; j <= m; j++) {
            gotoxy(c + i + j, y - 2);
            printf(" ");
            gotoxy(((c + (m + 1)) - i) + j, y + 4);
            printf(" ");
        }
    }
    // Recorrido/bajar
    for (i = 0; i < 4; i++) {
        if (i == 3) {
            gotoxy(c + (m + 1), (y - 2) + i - 1);
            printf("%c%c", 196, 196);
            gotoxy(c, (y + 4) - i + 1);
            printf("%c%c", 196, 196);
        }
        gotoxy(c + (m + 1), (y - 2) + i);
        printf("\033[1;32m%02d\033[0m", a);  // Impresión en verde
        gotoxy(c, (y + 4) - i);
        printf("\033[1;32m%02d\033[0m", b);  // Impresión en verde
        Sleep(200);
        for (j = 0; j < m; j++) {
            gotoxy(c + j + (m + 1), (y - 2) + i);
            printf(" ");
            gotoxy(c + j, (y + 4) - i);
            printf(" ");
        }
    }
}

void ordenarBurbuja(int x, int y, int vector[], int n, int m) {
    int i, j, valor, c;
    // Imprimir el vector antes de comenzar las comparaciones
    imprimirVector(x + 1, y, vector, n, m);
    Sleep(500); // Pausa 1/2
    for (i = 0; i < n - 1; i++) {
        c= x + 1;
        for (j = 0; j < n - i - 1; j++) {
            c = c + (j * 3);
            // Pintar la comparación en verde
            gotoxy(c, y + 1);
            printf("\033[1;32m%02d\033[0m", vector[j]);
            gotoxy(c+ (m + 1), y + 1);
            printf("\033[1;32m%02d\033[0m", vector[j + 1]);
            Sleep(500);
            // Revertir a color normal
            gotoxy(c, y + 1);
            printf("\033[0m%02d\033[0m", vector[j]);
            gotoxy(c + (m + 1), y + 1);
            printf("\033[0m%02d\033[0m", vector[j + 1]);
            if (vector[j] > vector[j + 1]) {
                realizarIntercambio(x, y, c, vector[j], vector[j + 1], m);
                valor = vector[j];
                vector[j] = vector[j + 1];
                vector[j + 1] = valor;
                imprimirVector(x + 1, y, vector, n, m);
            }
            c = x + 1;
        }
    }
}

int margen(int a, int b, int c, int d) {
    int j, k, i;
    j = a;
    gotoxy(a - 1, b);
    printf("%c", 201);
    gotoxy(a - 1, d);
    printf("%c", 200);
    for (a; a <= c; a++) {
        gotoxy(a, b);
        printf("%c", 205);
        gotoxy(a, d);
        printf("%c", 205);
    }
    gotoxy(a, b);
    printf("%c", 187);
    gotoxy(a, d);
    printf("%c", 188);
    k = b + 1;
    for (k; k <= (d - 1); k++) {
        gotoxy(j - 1, k);
        printf("%c", 186);
        gotoxy(a, k);
        printf("%c", 186);
    }
}

