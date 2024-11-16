#include <iostream>
#include <Windows.h> // Підключення для роботи з кодовими сторінками
using namespace std;

// Структура для дробу
struct Fraction {
    int numerator;   // Чисельник
    int denominator; // Знаменник
};

// Функція для скорочення дробу
Fraction simplify(Fraction f) {
    int a = f.numerator;
    int b = f.denominator;
    while (a != b) {
        if (a > b) {
            a = a - b;
        }
        else {
            b = b - a;
        }
    }
    f.numerator = f.numerator / a;
    f.denominator = f.denominator / a;
    return f;
}

// Додавання дробів
Fraction add(Fraction f1, Fraction f2) {
    Fraction result;
    result.numerator = f1.numerator * f2.denominator + f2.numerator * f1.denominator;
    result.denominator = f1.denominator * f2.denominator;
    result = simplify(result);
    return result;
}

// Віднімання дробів
Fraction subtract(Fraction f1, Fraction f2) {
    Fraction result;
    result.numerator = f1.numerator * f2.denominator - f2.numerator * f1.denominator;
    result.denominator = f1.denominator * f2.denominator;
    result = simplify(result);
    return result;
}

// Множення дробів
Fraction multiply(Fraction f1, Fraction f2) {
    Fraction result;
    result.numerator = f1.numerator * f2.numerator;
    result.denominator = f1.denominator * f2.denominator;
    result = simplify(result);
    return result;
}

// Ділення дробів
Fraction divide(Fraction f1, Fraction f2) {
    Fraction result;
    result.numerator = f1.numerator * f2.denominator;
    result.denominator = f1.denominator * f2.numerator;
    result = simplify(result);
    return result;
}

// Виведення дробу
void printFraction(Fraction f) {
    cout << f.numerator << "/" << f.denominator << endl;
}

int main() {
    // Налаштування кодування для кирилиці
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Fraction f1, f2, result;

    // Введення дробів
    cout << "Введіть чисельник першого дробу: ";
    cin >> f1.numerator;
    cout << "Введіть знаменник першого дробу: ";
    cin >> f1.denominator;

    cout << "Введіть чисельник другого дробу: ";
    cin >> f2.numerator;
    cout << "Введіть знаменник другого дробу: ";
    cin >> f2.denominator;

    // Додавання
    result = add(f1, f2);
    cout << "Сума дробів: ";
    printFraction(result);

    // Віднімання
    result = subtract(f1, f2);
    cout << "Різниця дробів: ";
    printFraction(result);

    // Множення
    result = multiply(f1, f2);
    cout << "Добуток дробів: ";
    printFraction(result);

    // Ділення
    result = divide(f1, f2);
    cout << "Частка дробів: ";
    printFraction(result);

    return 0;
}
