#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14

void calc_esfera (float r, float* area, float* volume) {
    *area =  4.0 * PI * (r*r);
    *volume = (4.0 * PI * (r*r*r))/3.0;
}   

int raizes (float a, float b, float c, float* x1, float* x2) {
    int delta = (b*b) - 4*a*c;
    int raizqdd = sqrt(delta);

    if (delta < 0) return -1;
    if (delta == 0) return 0;

    *x1 = (b * -1) + raizqdd/2*a;
    *x2 = (b * -1) - raizqdd/2*a;

    return 1;
}


int pares (int n, int* vet) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (vet[i] % 2 == 0) count++;
    }
    return count;
}

void inverte (int n, int* vet) {
    char temp = 'a';
    for (int i = 0, j = n-1; i < n/2; i++, j--) {
        temp = vet[i];
        vet[i] = vet[j];
        vet[j] = temp;
    }
}

double avalia (double* poli, int grau, double x) {
    int grauAux = grau;
    double ans = 0;
    for (int i = 0; i < grau+1; i++) {
        if (grauAux > 0) ans += poli[i] * pow(x, grauAux--);
        else ans += poli[i];
    }
    return ans;
}


/**
 * 2.1
*/
// int main () {
//     float r = 0;
//     float area, volume;

//     printf("Type a radius: ");          scanf("%f", &r);
//     calc_esfera(r, &area, &volume);

//     printf("area = %.2f\nvolume = %.2f\n", area, volume);

//     return 0;
// }


/**
 * 2.2
*/
// int main () {
//     float a = 1, b = 2, c = 3, x1 = 0, x2 = 0;
//     int ans = raizes(a, b, c, &x1, &x2);    
//     switch (ans) {
//         case -1:
//             printf("Nao ha raizes reais!");
//             break;        case 0:
//             printf("Ha apenas uma raiz! x' e x'' = %f\n", x1);
//             break;        case 1:
//             printf("Ha duas raizes reais: x' = %f e x'' = %f", x1, x2);
//             break;
//     }
// }

/**
 * 2.3
*/
// int main () {
//     int * vet = malloc(10 * sizeof(int));
//     for (int i = 0, j = 1; i < 10; i++, j++) {
//         vet[i] = j;
//     }
    
//     printf("O vetor possui %d numeros pares", pares(10, vet));
//     return 0;
// }

/**
 * 2.4
*/
// int main () {
//     int n = 10;
//     int * vet = malloc(n * sizeof(int));
//     for (int i = 0, j = 1; i < n; i++, j++) {
//         vet[i] = j;
//     }
    
//     printf("Sem inversao:\n");
//     for (int i = 0; i < n; i++) {
//         printf("%d ", vet[i]);
//     }
//     printf("\n\n");

//     printf("Com inversao\n");
//     inverte(n, vet);
//     for (int i = 0; i < n; i++) {
//         printf("%d ", vet[i]);
//     }
//     printf("\n");

//     return 0;
// }

/**
 * 2.5
*/
int main () {
    printf("Type the degree: ");
    int degree = 0;       scanf("%d", &degree);
    double *vet = malloc((degree + 1) * sizeof(double));

    double value = 0, x = 0;
    for (int i = 0; i < degree+1; i++) {
        printf("Type a value %d: ", i+1);
        scanf("%lf", &value);
        vet[i] = value;
    }

    printf("Type de x value: ");
    scanf("%lf", &x);

    double ans = avalia(vet, degree, x);
    printf("The polynom result is: %.2lf\n", ans);
    return 0;
}
