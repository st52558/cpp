#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>

template<typename T>
struct Matrix {
private:
	T** elements;
	int rowCount;
	int colCount;
public:
	Matrix(int rows, int cols);
	Matrix(const Matrix<T>& m);
	~Matrix();
	void Set(int row, int col, T value);
	void SetFrom(T* array);
	T& Give(int row, int col);
	const T& Give(int row, int col) const;
	template<typename R>
	Matrix<R> Cast() const;
	Matrix Transposition() const;
	Matrix Product(const Matrix& m) const;
	Matrix Product(T skalar) const;
	Matrix Sum(const Matrix& m) const;
	Matrix Sum(T skalar) const;
	bool isEqual(const Matrix& m) const;
	void WriteToConsole();
};

template<typename T>
Matrix<T>::Matrix(int rows, int cols) {
	rowCount = rows;
	colCount = cols;
	elements = new T*[rowCount];
	for (int i = 0; i < rowCount; i++)
	{
		elements[i] = new T[colCount];
		for (int j = 0; j < colCount; j++)
		{
			elements[i][j] = 0;
		}
	}
}

template<typename T>
Matrix<T>::Matrix(const Matrix<T>& m) {
	rowCount = m.rowCount;
	colCount = m.colCount;
	elements = new T * [rowCount];
	for (int i = 0; i < rowCount; i++)
	{
		elements[i] = new T[colCount];
		for (int j = 0; j < colCount; j++)
		{
			elements[i][j] = m.Give(i,j);
		}
	}
}

template<typename T>
Matrix<T>::~Matrix() {
	for (int i = 0; i < rowCount; i++)
	{
		delete[] elements[i];
	}
	delete[] elements;
}

template<typename T>
void Matrix<T>::Set(int row, int col, T value) {
	if (col >= colCount || col < 0 || row >= rowCount || row < 0) {
		throw "Neplatny index (Set)";
	}
	elements[row][col] = value;
}

template<typename T>
void Matrix<T>::SetFrom(T* array) {
	for (int i = 0; i < rowCount; i++)
	{
		for (int j = 0; j < colCount; j++)
		{
			elements[i][j] = array[i*colCount+j];

		}
	}
}

template<typename T>
T& Matrix<T>::Give(int row, int col) {
	if (col >= colCount || col < 0 || row >= rowCount || row < 0) {
		throw "Neplatny index (Give)";
	}
	return elements[row][col];
}

template<typename T>
const T& Matrix<T>::Give(int row, int col) const {
	if (col >= colCount || col < 0 || row >= rowCount || row < 0) {
		throw "Neplatny index (Give)";
	}
	return elements[row][col];
}
template<typename T>
template<typename R>
Matrix<R> Matrix<T>::Cast() const {
	Matrix<R> castedMatrix = Matrix<R>(rowCount,colCount);

	for (int i = 0; i < rowCount; i++)
	{
		for (int j = 0; j < colCount; j++)
		{
			castedMatrix.Set(i, j, (R)(elements[i][j]));

		}
	}
	
	return castedMatrix;
}
template<typename T>
Matrix<T> Matrix<T>::Transposition() const {
	Matrix<T> transposition = Matrix<T>(colCount, rowCount);

	for (int i = 0; i < colCount; i++)
	{
		for (int j = 0; j < rowCount; j++)
		{
			transposition.Set(i, j, elements[j][i]);
		}
	}

	return transposition;
}
template<typename T>
Matrix<T> Matrix<T>::Product(const Matrix& m) const {
	if (colCount != m.rowCount) {
		throw "Matice nelze nasobit";
	}
	Matrix<T> product = Matrix<T>(rowCount,m.colCount);
	for (int i = 0; i < rowCount; i++)
	{
		for (int j = 0; j < m.colCount; j++)
		{
			T sum = 0;
			for (int k = 0; k < m.rowCount; k++)
			{
				sum += elements[i][k] * m.Give(k, j);
			}
			product.Set(i, j, sum);
		}
	}
	return product;
}
template<typename T>
Matrix<T> Matrix<T>::Product(T skalar) const {
	Matrix<T> mat = Matrix<T>(rowCount,colCount);
	for (int i = 0; i < rowCount; i++)
	{
		for (int j = 0; j < colCount; j++)
		{
			mat.Set(i,j,Give(i,j) * skalar);
		}
	}
	return mat;
}
template<typename T>
Matrix<T> Matrix<T>::Sum(const Matrix& m) const {
	if (rowCount != m.rowCount || colCount != m.colCount) {
		throw "Spatny rozmer pro soucet matic (Sum)";
	}
	Matrix<T> sumMatrix = Matrix<T>(rowCount,colCount);

	for (int i = 0; i < rowCount; i++)
	{
		for (int j = 0; j < colCount; j++)
		{
			sumMatrix.Set(i, j, Give(i,j) + m.Give(i, j));
		}
	}
	return sumMatrix;
}
template<typename T>
Matrix<T> Matrix<T>::Sum(T skalar) const {
	Matrix<T> sumMatrix = Matrix<T>(rowCount, colCount);

	for (int i = 0; i < rowCount; i++)
	{
		for (int j = 0; j < colCount; j++)
		{
			sumMatrix.Set(i, j, Give(i,j) + skalar);
		}
	}
	return sumMatrix;
}
template<typename T>
bool Matrix<T>::isEqual(const Matrix& m) const {
	if (rowCount != m.rowCount || colCount != m.colCount) {
		return false;
	}
	for (int i = 0; i < rowCount; i++)
	{
		for (int j = 0; j < colCount; j++)
		{
			if (Give(i,j) != m.Give(i, j)) {
				return false;
			}
		}
	}
	return true;
}
template<typename T>
void Matrix<T>::WriteToConsole() {
	for (int i = 0; i < rowCount; i++)
	{
		for (int j = 0; j < colCount; j++)
		{
			std::cout << Give(i,j) << "\t";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

#endif // !MATRIX