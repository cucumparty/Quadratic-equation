#include <stdio.h>
#include <math.h>

int quadratic_solve(double a, double b, double c, double* x1, double* x2);
void linear_solve(double b, double c, double* x1);

int main()
{
    double a = 0, b = 0, c = 0, number_roots = 0, x1 = 0, x2 = 0;

    printf("Привет! Данная программа поможет тебе с решением квадратных уравнений вида ax^2 + bx + c = 0 в действительных числах.\n"
           "Для получения ответа введи коэффициенты a, b, c через пробел соответственно\n");
    scanf("%lf%lf%lf", &a, &b, &c);

    if(a != 0)
    {
        number_roots = quadratic_solve(a, b, c, &x1, &x2);
        if (number_roots == 2)
        {
            printf("Корни уравнения равны %.3lf; %.3lf", x1, x2);
        }
        else if (number_roots == 1)
        {
            printf("Корень уравнения равен %.3lf", x1);
        }
        else
        {
            printf("Уравнение не имеет действительных корней");
        }
    }
    else
    {
        linear_solve(b, c, &x1);
        printf("Ты ввёл коэффициенты, определяющие линейное уравнение. Корень данного уравнениея равен %.3lf", x1);
    }


    return 0;
}

int quadratic_solve(double a, double b, double c, double* x1, double* x2)
{
    double D = 0;

    D = pow(b, 2) - 4 * a * c;
    if (D > 0)
    {
        *x1 = (-b + sqrt(D)) / 2 * a;
        *x2 = (-b - sqrt(D)) / 2 * a;
        return 2;
    }
    else if (D == 0)
    {
        *x1 = (-b + sqrt(D)) / 2 * a;
        return 1;
    }
    return 0;
}

void linear_solve(double b, double c, double* x1)
{
    *x1 = -c / b;
}
