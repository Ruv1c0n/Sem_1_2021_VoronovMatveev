#include <iostream>
#include <cstdio>
#include "matrix.hpp"
#include "chek_io.hpp"

// Функция создает нулевую матрицу размера str_count на column_count.
double **create_matrix(int str_count, int column_count) {
	double **result = new double *[str_count];
	for (int i = 0; i < str_count; i++) {
		result[i] = new double[column_count];
		for (int j = 0; j < column_count; j++)
			result[i][j] = 0.0;
	}
	return result;
}

// Функция создает нулевую или единичную квадратную матрицу размера size_matrix и возвращает указатель на нее.
// unit_matrix флаг содания единичной или нулевой матрицы: true - единичная, false - нулевая.
double **create_sqr_matrix(int size_matrix, bool unit_matrix) {
	double **result = new double *[size_matrix];
	for (int i = 0; i < size_matrix; i++) {
		result[i] = new double[size_matrix];
		for (int j = 0; j < size_matrix; j++)
			result[i][j] = (unit_matrix and i == j) ? 1.0 : 0.0;
	}
	return result;
}

// Функция очищает память занятую матрицей и стирает указатель на нее.
void free_matrix(double **matrix, int str_count, int column_count) {
	for (int i = 0; i < str_count; i++) {
		for (int j = 0; j < column_count; j++)
			matrix[i][j] = 0.0;
		delete[] matrix[i];
	}
	delete[] matrix;
	matrix = 0;
}

// Функция очищает память занятую квадратной матрицей и стирает указатель на нее.
void free_sqr_matrix(double **matrix, int size_matrix) {
	for (int i = 0; i < size_matrix; i++) {
		for (int j = 0; j < size_matrix; j++)
			matrix[i][j] = 0.0;
		delete[] matrix[i];
	}
	delete[] matrix;
	matrix = 0;
}

// Функция копирует матрицу 2 в матрицу 1 (размеры матриц должны совпадать).
void copy_matrix(double **matrix_src, double **matrix_dst, int str_count, int column_count) {
	for (int i = 0; i < str_count; i++)
		for (int j = 0; j < column_count; j++)
			matrix_src[i][j] = matrix_dst[i][j];
	return;
}

// Функция копирует матрицу 2 в матрицу 1 (матрицы должны быть квадратными и их размер совпадать!!!)
void copy_sqr_matrix(double **matrix_src, double **matrix_dst, int size_matrix) {
	for (int i = 0; i < size_matrix; i++)
		for (int j = 0; j < size_matrix; j++)
			matrix_src[i][j] = matrix_dst[i][j];
	return;
}

// Функция ввода вещественной матрицы размера str_count на column_count.
double **input_matrix(int &str_count, int &column_count) {
	printf("Введите количество строк матрицы: ");
	str_count = one_natur_num_input();
	printf("Введите количество столбцов матрицы: ");
	column_count = one_natur_num_input();
	double **matrix = create_matrix(str_count, column_count);
	for (int i = 0; i < str_count; i++)
		for (int j = 0; j < column_count; j++) {
			printf("matrix[%d][%d]: ", i + 1, j + 1);
			matrix[i][j] = one_double_input();
		}
	return matrix;
}

// Функция ввода вещественной квадратной матрицы.
double **input_sqr_matrix(int &size_matrix) {
	printf("Введите размер квадратной матрицы: ");
	size_matrix = one_natur_num_input();
	double **matr = create_sqr_matrix(size_matrix, false);
	printf("Введите элементы матрицы:\n");
	for (int i = 0; i < size_matrix; i++)
		for (int j = 0; j < size_matrix; j++) {
			printf("matrix[%d][%d]: ", i + 1, j + 1);
			matr[i][j] = one_double_input();
		}
	return matr;
}

// Функция вывода матрицы.
void output_matrix(double **matrix, int str_count, int column_count) {
	for (int i = 0; i < str_count; i++) {
		for (int j = 0; j < column_count; j++)
			printf("%.2lf\t", matrix[i][j]);
		printf("\n");
	}
}

// Функция вывода квадратной матрицы.
void output_sqr_matrix(double **matrix, int size_matrix) {
	for (int i = 0; i < size_matrix; i++) {
		for (int j = 0; j < size_matrix; j++)
			printf("%.2lf\t", matrix[i][j]);
		printf("\n");
	}
}

// Функция умножает две квадратные матрицы размера size_matrix и записывает результат в matrix1.
void matrix_multip(double **matrix1, double **matrix2, int size_matrix) {
	double **matrix_res = create_sqr_matrix(size_matrix, false);
	// Пеереходим в элемент matrix_res[i][j].
	for (int i = 0; i < size_matrix; i++)
		for (int j = 0; j < size_matrix; j++)
			// Вычисляем элемент matrix_res[i][j].
			for (int l = 0; l < size_matrix; l++)
				matrix_res[i][j] += matrix1[i][l] * matrix2[l][j];
	// Копируем результат в matrix1 и удаляем matrix_res.
	copy_sqr_matrix(matrix1, matrix_res, size_matrix);
	free_sqr_matrix(matrix_res, size_matrix);
	return;
}

// Функция прибавляет к matrix1 matrix2 со знаком operand и записывает результат в matrix1.
void matrix_sum(double **matrix1, double **matrix2, int size_matrix, int operand) {
	// operand задает знак сложения: -1 - вычитание, 1 - сложение.
	// Блок для отладки.
	if (abs(operand) != 1) {
		printf("error in matrix_sum\n");
		return;
	}
	double **matrix_res = create_sqr_matrix(size_matrix, false);
	for (int i = 0; i < size_matrix; i++)
		for (int j = 0; j < size_matrix; j++)
			matrix_res[i][j] = matrix1[i][j] + static_cast<double>(operand) * matrix2[i][j];
	// Копируем результат в matrix1 и удаляем matrix_res.
	copy_sqr_matrix(matrix1, matrix_res, size_matrix);
	free_sqr_matrix(matrix_res, size_matrix);
	return;
}

// Функция умножает матрицу на число и записывает результат в matrix.
void matrix_multip_by_number(double **matrix, double number, int size_matrix) {
	double **matrix_res = create_sqr_matrix(size_matrix, false);
	for (int i = 0; i < size_matrix; i++)
		for (int j = 0; j < size_matrix; j++)
			matrix_res[i][j] = number * matrix[i][j];
	// Копируем результат в matrix1 и удаляем matrix_res.
	copy_sqr_matrix(matrix, matrix_res, size_matrix);
	free_sqr_matrix(matrix_res, size_matrix);
	return;
}

// Функция приведения матрицы к ступенчатому виду.
void to_stepped_matrix_type(double **matrix, int str_count, int column_count) {
	for (int i = 0; i < str_count - 1; i++)
		for (int j = 0; j < column_count; j++) {
			// Находим ненулевой элемент.
			if (matrix[i][j] == 0.0)
				continue;
			// Вычитаем верхнюю строку из нижней, зануляя первый элемент.
			for (int k = i + 1; k < str_count; k++) {
				for (int l = j + 1; l < column_count; l++)
					matrix[k][l] = matrix[i][j] * matrix[k][l] - matrix[k - 1][l] * matrix[i + 1][j];
				matrix[k][j] = 0.0;
			}
			break;
		}
	return;
}

// Функция считает ранг матрицы.
int rang_matrix(double **matrix, int str_count, int column_count) {
	double **matrix_src = create_matrix(str_count, column_count);
	copy_matrix(matrix_src, matrix, str_count, column_count);
	to_stepped_matrix_type(matrix_src, str_count, column_count);
	int count_nzero_str = 0;
	bool is_all_zero = true;
	for (int i = 0; i < str_count; i++) {
		is_all_zero = true;
		for (int j = 0; j < column_count and is_all_zero; j++)
			if (matrix_src[i][j] != 0.0)
				is_all_zero = false;
		if (not is_all_zero)
			count_nzero_str++;
	}
	return count_nzero_str;
}

// Функция возвращает подматрицу квадратной матрицы без i-го столбца и j-ой строки
double **matrix_minor(double **matrix, int size_matrix, int str_number, int column_number) {
	double **minor = create_sqr_matrix(size_matrix - 1, false);
	int minor_str = 0, minor_column = 0;
	for (int i = 0; i < size_matrix; i++) {
		if (i == str_number)
			continue;
		for (int j = 0; j < size_matrix; j++) {
			if (j == column_number)
				continue;
			minor[minor_str][minor_column++] = matrix[i][j];
			if (minor_column == size_matrix - 1) {
				minor_str++;
				minor_column = 0;
			}
		}
	}
	return minor;
}

// Функция находит определитель матрицы.
double matrix_determinant(double **matrix, int size_matrix) {
	double answer = 0.0;
	if (size_matrix == 1)
		return matrix[0][0];
	if (size_matrix == 2) {
		 answer = matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
		 return answer;
	}
	// Используется разложение по первой строке матрицы.
	for (int i = 0; i < size_matrix; i++) {
		double **minor = matrix_minor(matrix, size_matrix, 0, i);
		double sign = (i % 2 == 0) ? 1.0 : -1.0;
		answer += sign * matrix[0][i] * matrix_determinant(minor, size_matrix - 1);
		free_sqr_matrix(minor, size_matrix - 1);
	}
	return answer;
}

// Функция находит обратную для матрицы matrix матрицу и записывает ее в матрицу invr_matrix.
// Функция вернет true если обратная матрица была найденна и false в противном случае.
bool inverse_matrix(double **invr_matrix, double **matrix, int size_matrix) {
	double determinant = matrix_determinant(matrix, size_matrix);
	if (determinant == 0.0)
		return false;
	double **answer = create_sqr_matrix(size_matrix, false);
	for (int i = 0; i < size_matrix; i++)
		for (int j = 0; j < size_matrix; j++){
			double **minor = matrix_minor(matrix, size_matrix, j, i);
			double sign = ((i + j) % 2 == 0) ? 1.0 : -1.0;
			invr_matrix[i][j] = sign * matrix_determinant(minor, size_matrix - 1) / determinant;
			if (abs(invr_matrix[i][j]) < 0.00000000001)
				invr_matrix[i][j] = 0.0;
			free_sqr_matrix(minor, size_matrix - 1);
		}
	return true;
}

// Функция считает значение выражения 2x^2 - x, где х - квадратная матрица.
double **function_f(double **matrix_A, int size_matrix) {
	double **answer = create_sqr_matrix(size_matrix, false);
	copy_sqr_matrix(answer, matrix_A, size_matrix);
	// 2x^2
	matrix_multip(answer, matrix_A, size_matrix);
	matrix_multip_by_number(answer, 2.0, size_matrix);
	printf("Значение 2*x^2:\n");
	output_sqr_matrix(answer, size_matrix);
	printf("Значение х\n");
	output_sqr_matrix(matrix_A, size_matrix);
	matrix_sum(answer, matrix_A, size_matrix, -1);
	return answer;
}

// Функция считает значение выражения 2x^3 - x + 3, где х - квадратная матрица.
double **function_g(double **matrix_A, int size_matrix) {
	double **answer = create_sqr_matrix(size_matrix, false);
	copy_sqr_matrix(answer, matrix_A, size_matrix);
	matrix_multip(answer, matrix_A, size_matrix);
	matrix_multip(answer, matrix_A, size_matrix);
	matrix_multip_by_number(answer, 2.0, size_matrix);
	// 2x^3
	printf("Значение 2*x^3:\n");
	output_sqr_matrix(answer, size_matrix);
	printf("Значение х\n");
	output_sqr_matrix(matrix_A, size_matrix);
	matrix_sum(answer, matrix_A, size_matrix, -1);
	printf("Значение 2*x^3 - x:\n");
	output_sqr_matrix(answer, size_matrix);
	double **matrix_number = create_sqr_matrix(size_matrix, true);
	matrix_multip_by_number(matrix_number, 3.0, size_matrix);
	printf("Значение 3*E\n");
	output_sqr_matrix(matrix_number, size_matrix);
	matrix_sum(answer, matrix_number, size_matrix, 1);
	free_sqr_matrix(matrix_number, size_matrix);
	return answer;
}
