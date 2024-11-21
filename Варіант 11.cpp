#include <iostream>
#include <vector>
#include <Windows.h>

class Matrix {
private:
    std::vector<std::vector<int>> data; // Приватне поле для зберігання матриці
    size_t rows, cols; // Розміри матриці

public:
    // Конструктор
    Matrix(size_t r, size_t c) : rows(r), cols(c), data(r, std::vector<int>(c)) {}

    // Сеттер для встановлення значення елемента
    void setElement(size_t row, size_t col, int value) {
        if (row < rows && col < cols) {
            data[row][col] = value;
        }
    }

    // Гетер для отримання значення елемента
    int getElement(size_t row, size_t col) const {
        if (row < rows && col < cols) {
            return data[row][col];
        }
        return 0; // Повертаємо 0, якщо індекс виходить за межі
    }

    // Метод для заповнення матриці
    void fillMatrix() {
        std::cout << "Введіть елементи матриці (" << rows << "x"
            << cols << "):\n";
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < cols; ++j) {
                std::cin >> data[i][j];
            }
        }
    }

    // Метод для виведення матриці
    void printMatrix() const {
        for (const auto& row : data) {
            for (int elem : row) {
                std::cout << elem << " ";
            }
            std::cout << std::endl;
        }
    }

    // Функція для транспонування матриці
    Matrix transpose() const {
        Matrix transposed(cols, rows);
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < cols; ++j) {
                transposed.setElement(j, i, data[i][j]);
            }
        }
        return transposed;
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    size_t rows, cols;
    std::cout << "Введіть кількість рядків і стовпців матриці: ";
    std::cin >> rows >> cols;

    Matrix matrix(rows, cols);
    matrix.fillMatrix();

    std::cout << "Початкова матриця:\n";
    matrix.printMatrix();

    Matrix transposed = matrix.transpose();

    std::cout << "Транспонована матриця:\n";
    transposed.printMatrix();

    return 0;
}
