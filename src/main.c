#include <stdio.h>
#include<math.h>
#define array_length(x) (sizeof(x) / sizeof(x[0]))
void border(double *left, double *right)
{
    scanf("%lf", left);
    scanf("%lf", right);
}
double rectangle(double left1, double right1, int count)
{
    double step = (right1 - left1)/count;
    double middle = (left1 + left1 + step)/2;
    double area = 0.0;
    for (int i = 1; i <= count; i++)
    {
        area += (sin(middle) * step);
        middle += step;
    }
    return area;
}
double simpson(double left1, double right1, int count)
{
    double step = (right1 - left1)/count;
    double area = 0.0;
    right1 = left1 + step;
    for (int i = 1; i <= count; i++)
    {
        area += (step/6 * (sin(left1) + 4 * sin((left1 + right1)/2) + sin(right1)));
        right1 += step;
        left1 += step;
    }
    return area;
}
int main()
{
    double right = 0.0;
    double left = 0.0;
    border(&left, &right);
    int r[] = {6, 10, 20, 100, 500, 1000};
    for (int i = 0; i < array_length(r); i++)
    {
        double a = rectangle(left, right, r[i]);
        double b = simpson(left, right, r[i]);
        printf("%d %.5lf %.5lf\n", r[i], a, b);
    }
    return 0;
} 