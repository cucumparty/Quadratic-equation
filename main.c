#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void input_function(double *a, double *b, double *c);

void solve(double a, double b, double c, double *x1, double *x2, int *number_roots);

void quadratic_solve(double a, double b, double c, double *x1, double *x2, int *number_roots);

void linear_solve(double b, double c, double *x1, int *number_roots);

void output_function(int number_roots, double x1, double x2);

int main() {
    system("chcp 65001");

    double a = 0, b = 0, c = 0, x1 = 0, x2 = 0;
    int number_roots = -2;

    input_function(&a, &b, &c);
    solve(a, b, c, &x1, &x2, &number_roots);
    output_function(number_roots, x1, x2);

    getchar();

    return 0;
}

void input_function(double *a, double *b, double *c) {
    int number_correctly_processed_characters = 0;

    printf("Привет! Данная программа поможет тебе с решением квадратных уравнений вида ax^2 + bx + c = 0 в действительных числах.\n"
           "Для получения ответа введи коэффициенты a, b, c через пробел соответственно\n");
    number_correctly_processed_characters = scanf("%lf%lf%lf", a, b, c);

    while (number_correctly_processed_characters != 3) {
        while ((getchar()) != '\n'); // очистка входного буфера
        printf("Возникла ошибка. Вновь введи коэффициенты уравнения:\n");
        number_correctly_processed_characters = scanf("%lf%lf%lf", a, b, c);
    }
}

void solve(double a, double b, double c, double *x1, double *x2, int *number_roots) {
    if (a != 0) {
        quadratic_solve(a, b, c, x1, x2, number_roots);
    } else if (a == 0 & b != 0) {
        linear_solve(b, c, x1, number_roots);
    }
}

void quadratic_solve(double a, double b, double c, double *x1, double *x2, int *number_roots) {
    double D = 0;

    D = pow(b, 2) - 4 * a * c;
    if (D > 0) {
        *x1 = (-b + sqrt(D)) / 2 * a;
        *x2 = (-b - sqrt(D)) / 2 * a;
        *number_roots = 2;
    } else if (D == 0) {
        *x1 = (-b + sqrt(D)) / 2 * a;
        *number_roots = 1;
    } else{
        *number_roots = 0;
    }
}

void linear_solve(double b, double c, double *x1, int *number_roots) {
    *x1 = -c / b;
    *number_roots = -1;
}

void output_function(int number_roots, double x1, double x2) {
    switch (number_roots) {
        case 2:
            printf("Корни уравнения равны %.3lf; %.3lf", x1, x2);
            break;
        case 1:
            printf("Корень уравнения равен %.3lf", x1);
            break;
        case 0:
            printf("Уравнение не имеет действительных корней");
            break;
        case -1:
            printf("Ты ввёл коэффициенты, определяющие линейное уравнение. Корень данного уравнениея равен %.3lf\n",
                   x1);
            break;
        default:
            printf("Ты ввёл коэффициенты, равные нулю, поэтому решением являеются все числа");
    }
}
