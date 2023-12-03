#include <iostream>

using namespace std;

//Функция заполнения массива
void initArray(double* array, int arrayLength) {
    for (int i = 0; i < arrayLength; i++) {
        cout << "Enter the value of X[" << i << "]: ";
        cin >> array[i];
    }
}

//Функция заполнения "главного" массива на основе initArray
void inputMainArray(double** array, int arrayLength) {
    for (int i = 0; i < arrayLength; i++) {
        initArray(array[i], arrayLength);
    }
}

//Функция суммирования значений по главной диагонали
double sumArrayDiagonal(double** array, int arrayLength) {
    double sum = 0;
    for (int i = 0; i < arrayLength; i++) {
        sum += array[i][i];
    }
    return sum;
}

//Функция сравнения
bool compareArray(double* array, int arrayLength, double sum) {
    int errors = 0;
    for (int i = 0; i < arrayLength; i++) {
        if (sum < array[i]) errors += 1;
    }
    if (errors == arrayLength) return true; else return false;
}

//Функция увеличения и уменьшения значений
void editArray(double** array, int arrayLength, double sum) {
    for (int i = 0; i < arrayLength; i++) {
        for (int j = 0; j < arrayLength; j++) {
            if (array[i][j] < 0) array[i][j] -= sum;
            else if (array[i][j] >= 0) array[i][j] += sum;
        }
    }
}

void printArray(double* array, int arrayLength) {
    for (int i = 0; i < arrayLength; i++) {
        cout << array[i] << " ";
    }
}

int main()
{
    //Объявление безразмерных массивов arrA, arrC и переменных lenghtA, lenghtC, sum без значений
    double** arrA;
    double* arrC;
    int lengthA, lengthC;
    double sum;

    //Обозначение переменной lengthA и lengthC
    cout << "Enter the number of rows and columns in array A: ";
    cin >> lengthA;
    cout << "Enter the number of rows in array C: ";
    cin >> lengthC;

    //Задаем массиву arrA размер по lengthA
    arrA = new double*[lengthA];
    for (int i = 0; i < lengthA; i++) {
        arrA[i] = new double[lengthA];
    }

    //Задаем массиву arrC размер по lengthC
    arrC = new double[lengthC];

    //Вводим данные в массив arrA
    cout << "Array A:" << endl;
    inputMainArray(arrA, lengthA);

    //Вводим данные в массив arrC
    cout << "Array C:" << endl;
    initArray(arrC, lengthC);

    //Вывод массива arrA
    cout << "Array A:" << endl;
    for (int i = 0; i < lengthA; i++) {
        printArray(arrA[i], lengthA);
        cout << endl;
    }

    //Получение значения суммы sum
    sum = sumArrayDiagonal(arrA, lengthA);

    //Вывод суммы в консоль
    cout << "Sum: " << sum << endl;

    //Вывод массива arrC
    cout << "Array C:" << endl;
    printArray(arrC, lengthC);
    cout << endl;

    //Сравнивание суммы с элементами массива arrC и выполнение действия на результате сравнивания
    if (compareArray(arrC, lengthC, sum)) {
        //Увеличение и уменьшение элементов массива arrA на сумму sum
        editArray(arrA, lengthA, sum);
        cout << "Array was edited" << endl;

        //Вывод обновленного массива arrA
        cout << "New array A:" << endl;
        for (int i = 0; i < lengthA; i++) {
            printArray(arrA[i], lengthA);
            cout << endl;
        }
    } else {
        cout << "Array wasn't edited" << endl;
    }
}
