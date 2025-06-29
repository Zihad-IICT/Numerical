#include<bits/stdc++.h>
using namespace std;

double f(double x) {
    return log(3 * x) - 3;
}

double falsePosition(double a, double b, double tolerance) {
    if (f(a) * f(b) >= 0) {
        cout << "Invalid interval: f(a) and f(b) should have opposite signs." << endl;
        return NAN;
    }

    double y = a;
    int itr = 0;

    while (true) {
        y = (a * f(b) - b * f(a)) / (f(b) - f(a));
        double fy = f(y);
       itr++;

        if (fabs(a-b) < tolerance) {
            break;
        }

        if (f(a) * fy < 0)
            b = y;
        else
            a = y;

        if (itr > 1000) {
           cout << "Too many iterations!" << endl;
            break;
        }
    }

    cout << fixed << setprecision(6);
    cout << "Root = " << y << endl;
    cout << "f(Root) = " << f(y) << endl;
    cout << "Iterations: " <<itr << endl;

    return y;
}

int main() {
    double a = 6.0, b = 7.0;
    double tolerance = 1e-4;

    falsePosition(a, b, tolerance);

return 0;
}
