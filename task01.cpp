#include <iostream>
using namespace std;

double power(double base, double exponent) {
    double result = 1.0;
    for (int i = 0; i < exponent; ++i) {
        result *= base;
    }
    return result;
}

double factorial(double n) {
    double result = 1.0;
    for (int i = 1; i <= n; ++i) {
        result *= i;
    }
    return result;
}

double sine(double angle) {
    const int terms = 10; 
    double result = 0.0;
    for (int i = 0; i < terms; ++i) {
        result += power(-1, i) * power(angle, 2 * i + 1) / factorial(2 * i + 1);
    }
    return result;
}



int main()
 {
    double num1, num2;
    char operation;

    cout << "Enter first number: ";
    cin >> num1;

    cout << "Enter an operation (+, -, *, /, ^, s): ";
    cin >> operation;

    if (operation != 's') {
        cout << "Enter second number: ";
        cin >> num2;
    }

    double result;

    switch (operation) {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            result = num1 / num2;
            break;
        case '^':
            result = power(num1, num2);
            break;
        case 's':
            result = sine(num1 * (3.14159265359 / 180)); 
            break;
        default:
            cout << "Invalid operation." << endl;
            return 1;
    }

    cout << "Result: " << result << endl;

    return 0;
}