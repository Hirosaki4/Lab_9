#include <iostream>
#include <Windows.h>
using namespace std;

struct Fraction {
    int numerator;   // Чисельник дробу
    int denominator;// Знаменник дробу 
};

Fraction simplify(Fraction f) {
    int a = f.numerator; // Копіюємо чисельник
    int b = f.denominator; // Копіюємо знаменник
    while (a != b) {
        if (a > b) {
            a = a - b; // Якщо чисельник більший, віднімаємо знаменник
        }
        else {
            b = b - a; // Якщо знаменник більший, віднімаємо чисельник
        }
    }
    f.numerator = f.numerator / a; // Ділимо чисельник на НСД
    f.denominator = f.denominator / a; // Ділимо знаменник на НСД
    return f; // Повертаємо спрощений дріб
}

Fraction add(Fraction f1, Fraction f2) {
    Fraction result;
    result.numerator = f1.numerator * f2.denominator + f2.numerator * f1.denominator;
    result.denominator = f1.denominator * f2.denominator;
    result = simplify(result);
    return result;
}

Fraction subtract(Fraction f1, Fraction f2) {
    Fraction result;
    result.numerator = f1.numerator * f2.denominator - f2.numerator * f1.denominator;
    result.denominator = f1.denominator * f2.denominator;
    result = simplify(result);
    return result;
}

Fraction multiply(Fraction f1, Fraction f2) {
    Fraction result;
    result.numerator = f1.numerator * f2.numerator;
    result.denominator = f1.denominator * f2.denominator;
    result = simplify(result);
    return result;
}

Fraction divide(Fraction f1, Fraction f2) {
    Fraction result;
    result.numerator = f1.numerator * f2.denominator;
    result.denominator = f1.denominator * f2.numerator;
    result = simplify(result);
    return result;
}

void printFraction(Fraction f) {
    cout << f.numerator << "/" << f.denominator << endl;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Fraction f1, f2, result;

    cout << "Введіть чисельник першого дробу: ";
    cin >> f1.numerator;
    cout << "Введіть знаменник першого дробу: ";
    cin >> f1.denominator;

    cout << "Введіть чисельник другого дробу: ";
    cin >> f2.numerator;
    cout << "Введіть знаменник другого дробу: ";
    cin >> f2.denominator;

    result = add(f1, f2);
    cout << "Сума дробів: ";
    printFraction(result);

    result = subtract(f1, f2);
    cout << "Різниця дробів: ";
    printFraction(result);

    result = multiply(f1, f2);
    cout << "Добуток дробів: ";
    printFraction(result);

    result = divide(f1, f2);
    cout << "Частка дробів: ";
    printFraction(result);

    return 0;
}
