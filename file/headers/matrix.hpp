#ifndef MATRIX_HPP
#define MATRIX_HPP

// Функция создает нулевую матрицу размера str_count на column_count.
double **create_matrix(int str_count, int column_count);

// Функция создает пустую квадратную матрицу размера size_matrix и возвращает указатель на нее.
// unit_matrix флаг содания единичной или нулевой матрицы: true - единичная, false - нулевая.
double **create_sqr_matrix(int size_matrix, bool unit_matrix);

// Функция очищает память занятую матрицей и стирает указатель на нее.
void free_matrix(double **matrix, int str_count, int column_count);

// Функция очищает память занятую матрицей и стирает указатель на нее.
void free_sqr_matrix(double **matrix, int size_matrix);

// Функция копирует матрицу 2 в матрицу 1 (размеры матриц должны совпадать).
void copy_matrix(double **matrix_src, double **matrix_dst, int str_count, int column_count);

// Функция копирует матрицу 2 в матрицу 1 (матрицы должны быть квадратными и их размер совпадать!!!)
void copy_sqr_matrix(double **matrix_src, double **matrix_dst, int size_matrix);

// Функция ввода вещественной матрицы размера str_count на column_count.
double **input_matrix(int &str_count, int &column_count);

// Функция ввода вещественной квадратной матрицы.
double **input_sqr_matrix(int &size_matrix);

// Функция вывода матрицы.
void output_matrix(double **matrix, int str_count, int column_count);

// Функция вывода квадратной матрицы.
void output_sqr_matrix(double **matrix, int size_matrix);

// Операции сложения и умножения матриц определены только для квадратных матриц.
// Функция умножает две квадратные матрицы размера size_matrix и записывает результат в matrix1.
void matrix_multip(double **matrix1, double **matrix2, int size_matrix);

// Функция прибавляет к matrix1 matrix2 со знаком operand и записывает результат в matrix1.
void matrix_sum(double **matrix1, double **matrix2, int size_matrix, int operand);

// Операция умножения матрицы на число определна для квадратной матрицы.
// Функция умножает матрицу на число и записывает результат в matrix.
void matrix_multip_by_number(double **matrix, double number, int size_matrix);

// Функция приведения матрицы к ступенчатому виду.
void to_stepped_matrix_type(double **matrix, int str_count, int column_count);

// Функция считает ранг матрицы.
int rang_matrix(double **matrix, int str_count, int column_count);

// Функция возвращает подматрицу квадратной матрицы без i-го столбца и j-ой строки
double **matrix_minor(double **matrix, int size_matrix, int str_number, int column_number);

// Функция находит определитель матрицы.
double matrix_determinant(double **matrix, int size_matrix);

// Функция находит обратную для матрицы matrix матрицу и записывает ее в матрицу invr_matrix.
// Функция вернет true если обратная матрица была найденна и false в противном случае.
bool inverse_matrix(double **invr_matrix, double **matrix, int size_matrix);

// Функция считает значение выражения 2x^2 - x, где х - квадратная матрица.
double **function_f(double **matrix_A, int size_matrix);

// Функция считает значение выражения 2x^3 - x + 3, где х - квадратная матрица.
double **function_g(double **matrix_A, int size_matrix);

#endif // MATRIX_HPP