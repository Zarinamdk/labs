#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>
#include <cmath>
#include <ctype.h>
#include <Windows.h>
#include <string.h> 
#include <string>
#include <time.h>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <sstream>
#include <filesystem>
#include <vector>
#include <random>
#include <chrono>
#include <map>
#include <algorithm>
#include "Matrix.h"
using namespace std;

int main()
{
    setlocale(LC_ALL, "Rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    //std::cout << "Hello World!\n";
    Matrix a(2, 2);
    a.setEl(0, 0, 1);
    a.setEl(0, 1, 2);
    a.setEl(1, 0, 3);
    a.setEl(1, 1, 4);
    a.printMatrix();
    Matrix b;
    b.printMatrix();
    Matrix c(2, 2);
    c.setEl(0, 0, 5);
    c.setEl(0, 1, 6);
    c.setEl(1, 0, 7);
    c.setEl(1, 1, 8);
    c.printMatrix();
    cin >> b;
    cout << b;
    Matrix d(a);
    cout << d;
    d = b;
    int choice;
    cout << "Для получения инструкции введите '11'" << endl;
    cin >> choice;
    while (true)
    {
        cout << "Введите номер: " << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Сложение матриц" << endl;
            b = a.PlusMatrix(c);
            b.printMatrix();
            break;
        case 2:
            cout << "Вычитание матриц" << endl;
            b = a.MinusMatrix(c);
            b.printMatrix();
            break;
        case 3:
            cout << "Умножение матриц" << endl;
            b = a.MultiplyMatrix(c);
            b.printMatrix();
            break;
        case 4:
            cout << "Сравнение матриц" << endl;
            if (a.CompareMatrix(c) == 0)
                cout << "Матрицы не равные" << endl;
            else
                cout << "Матрицы равны" << endl;
            break;
        case 5:
            cout << "Умножение матрицы на число" << endl;
            b = a.MulCMatrix(2);
            b.printMatrix();
            break;
        case 6:
            cout << "Оператор 'Сложение матриц'" << endl;
            b = a + c;
            cout << b;
            break;
        case 7:
            cout << "Оператор 'Вычитание матриц'" << endl;
            b = a - c;
            cout << b;
            break;
        case 8:
            cout << "Оператор 'Сравнение матриц'" << endl;
            if(a==c)
                cout << "Матрицы равны" << endl;
            else
                cout << "Матрицы не равные" << endl;
            break;
        case 9:
            cout << "Оператор'Умножение матрицы на число'" << endl;
            b = a * 3;
            cout << b;
            break;
        case 10:
            cout << "Оператор'Умножение число на матрицу'" << endl;
            b = 4 * a;
            cout << b;
            break;
        case 11:
            cout << "Информация" << endl;
            cout << "1. Сложение матриц" << endl;
            cout << "2. Вычитание матриц" << endl;
            cout << "3. Умножение матриц" << endl;
            cout << "4. Сравнение матриц" << endl;
            cout << "5. Умножение матрицы на число" << endl;
            cout << "6. Оператор 'Сложение матриц'" << endl;
            cout << "7. Оператор 'Вычитание матриц'" << endl;
            cout << "8. Оператор 'Сравнение матриц'" << endl;
            cout << "9. Оператор'Умножение матрицы на число'" << endl;
            cout << "10. Оператор'Умножение число на матрицу'" << endl;
            break;
        case 12:

        default:
            return false;
            break;
        }
    }
}