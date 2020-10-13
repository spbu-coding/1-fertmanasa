#include <stdio.h>
#include<math.h>
#define array_length(x) (sizeof(x) / sizeof(x[0]))
struct interval
{
    double left, right;
} variable;
double rectangle_rule(double local_left, double local_right, int count)
{
    double step = (local_right - local_left)/count;
    double middle = (local_left + local_left + step)/2;
    double area = 0.0;
    for (int i = 1; i <= count; i++)
    {
        area += (sin(middle) * step);
        middle += step;
    }
    return area;
}
double simpson_rule(double local_left, double local_right, int count)
{
    double step = (local_right - local_left)/count;
    double area = 0.0;
    local_right = local_left + step;
    for (int i = 1; i <= count; i++)
    {
        area += (step/6 * (sin(local_left) + 4 * sin((local_left + local_right)/2) + sin(local_right)));
        local_right += step;
        local_left += step;
    }
    return area;
}
void interval_validation()
{
    printf("Insert the left and right interval borders consequently:\n");
    scanf("%lf", &variable.left);
    scanf("%lf", &variable.right);
    if (variable.left < 0 || variable.right > M_PI || variable.left>=variable.right)
    {
        while (variable.left < 0 || variable.right > M_PI || variable.left>=variable.right)
        {
            printf("Wrong interval borders. Insert once again.\n");
            scanf("%lf", &variable.left);
            scanf("%lf", &variable.right);
        }
    }
}
int main()
{
    interval_validation();
    printf("%.5lf %.5lf\n",variable.left, variable.right);
    int steps_amount[] = {6, 10, 20, 100, 500, 1000};
    for (int i = 0; i < array_length(steps_amount); i++)
    {
        double a = rectangle_rule(variable.left, variable.right, steps_amount[i]);
        double b = simpson_rule(variable.left, variable.right, steps_amount[i]);
        printf("%d %.5lf %.5lf\n", steps_amount[i], a, b);
    }
    return 0;
}