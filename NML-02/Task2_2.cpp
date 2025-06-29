#include<bits/stdc++.h>
using namespace std;
double f(double x) {
    return 4 * x * x + 3 * x - 3;
}
const double TRUE_ROOT = (-3 + sqrt(57)) / 8;

double truePercentRelativeError(double approx) {
    return fabs((TRUE_ROOT - approx) / TRUE_ROOT) * 100.0;
}

void bisection(double a, double b, int iterations) {
    cout << "\n Bisection Method \n";
    for (int i = 1; i <= iterations; i++) {
        double c = (a + b) / 2.0;
        double fc = f(c);
        cout << i << "\t" << fixed << setprecision(6)
             << a << "\t" << b << "\t" << c << "\t"
             << fc << "\t" << truePercentRelativeError(c) << "%\n";

        if (f(a) * fc < 0)
            b=c;
        else
            a=c;
    }
}

void falsePosition(double a, double b, int iterations) {
    cout << "\n False Position Method \n";
    for (int i = 1; i <= iterations; ++i) {
        double fa = f(a);
        double fb = f(b);
        double c = b - (fb * (a - b)) / (fa - fb);
        double fc = f(c);
        cout << i << "\t" << fixed << setprecision(6)
             << a<< "\t" << b << "\t" << c << "\t"
             << fc << "\t" << truePercentRelativeError(c) << "%\n";

        if (fa * fc < 0)
            b = c;
        else
            a = c;
    }
}

int main() {
    double a = 0, b= 1;
    int iterations = 3;

    cout << "True Root = " << setprecision(10) << TRUE_ROOT << "\n";

    bisection(a, b, iterations);
    falsePosition(a, b, iterations);

    return 0;
}

