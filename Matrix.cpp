#include "Matrix.h"
using namespace std;

Matrix::Matrix(): n(0), m(0), matrix() 
{
	cout << "Конструктор по умолчанию" << endl;
}

Matrix::Matrix(int x, int y)
{
	cout << "Конструктор с параметрами" << endl;
	if (x < 0 || y < 0)
		cout << "Неправильные параметры";
	else
	{
		n = x;
		m = y;
		matrix.resize(n, vector<double>(m));
	}
}

Matrix::~Matrix()
{
	cout << "Деструктор" << endl;
}

Matrix::Matrix(Matrix& a)
{
	cout << "Конструктор копирования" << endl;
	n = a.n;
	m = a.m;
	matrix.resize(n, vector<double>(m));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			matrix[i][j] = a.matrix[i][j];
		}
	}
}


int Matrix::getX()
{
	return n;
}

int Matrix::getY()
{
	return m;
}

double Matrix::getEl(int x, int y)
{
	if (x < 0 || y < 0)
		cout << "Неправильные параметры";
	else
		return matrix[x][y];
}

double Matrix::setEl(int x, int y, double el)
{
	if (x < 0 || y < 0)
		cout << "Неправильные параметры";
	else
		return matrix[x][y] = el;
}

void Matrix::printMatrix()
{
	if (n == 0 || m == 0) {
		cout << "Пустая матрица" << endl;
		return;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}

Matrix Matrix::PlusMatrix(Matrix& a)
{
	if (n != a.n || m != a.m)
		cout << "Невозможно";
	else
	{
		Matrix result(n, m);
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				result.matrix[i][j] = matrix[i][j] + a.matrix[i][j];
			}
		}
		return result;
	}
}

Matrix Matrix::MinusMatrix(Matrix& a)
{
	if (n != a.n || m != a.m)
		cout << "Невозможно";
	else
	{
		Matrix result(n, m);
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				result.matrix[i][j] = matrix[i][j] - a.matrix[i][j];
			}
		}
		return result;
	}
}

Matrix Matrix::MultiplyMatrix(Matrix& a)
{
	if (m != a.n)
	{
		cout << "Невозможно" << endl;
	}
	else
	{
		Matrix result(n, a.m);
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < a.m; j++)
			{
				for (int k = 0; k < m; k++)
				{
					result.matrix[i][j] += matrix[i][k] * a.matrix[k][j];
				}
			}
		}
		return result;
	}
}

bool Matrix::CompareMatrix(Matrix& a)
{
	if (n != a.n || m != a.m)
		cout << "Невозможно";
	else
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (matrix[i][j] == a.matrix[i][j])
				{
					return true;
				}
				else
					return false;
			}
		}
	}
}

Matrix Matrix::MulCMatrix(double c)
{
	Matrix result(n, m);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			result.matrix[i][j] = matrix[i][j] * c;
		}
	}
	return result;
}
Matrix Matrix::operator+(Matrix& a)
{
	if (n != a.n || m != a.m)
		cout << "Невозможно";
	else
	{
		Matrix result(n, m);
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				result.matrix[i][j] = matrix[i][j] + a.matrix[i][j];
			}
		}
		return result;
	}
}
Matrix Matrix::operator-(Matrix& a)
{
	if (n != a.n || m != a.m)
		cout << "Невозможно";
	else
	{
		Matrix result(n, m);
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				result.matrix[i][j] = matrix[i][j] - a.matrix[i][j];
			}
		}
		return result;
	}
}
Matrix Matrix::operator*(double c)
{
	Matrix result(n, m);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			result.matrix[i][j] = matrix[i][j] * c;
		}
	}
	return result;
}
bool Matrix::operator==(Matrix& a)
{
	if (n != a.n || m != a.m)
		cout << "Невозможно";
	else
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (matrix[i][j] == a.matrix[i][j])
				{
					return true;
				}
				else
					return false;
			}
		}
	}
}

Matrix& Matrix::operator=(Matrix& a)
{
	cout << "Перегрузка оператора присваивания" << endl;
	if (this == &a)
		return *this;
	matrix.clear();
	n = a.n;
	m = a.m;
	matrix.resize(n, vector<double>(m));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			matrix[i][j] = a.matrix[i][j];
		}
	}
	return *this;
}


//дружественные
ostream& operator<<(ostream& print, Matrix& a)
{
	a.printMatrix();
	return print;
}

Matrix operator*(double c, Matrix& a)
{
	Matrix result(a.n, a.m);
	for (int i = 0; i < a.n; i++)
	{
		for (int j = 0; j < a.m; j++)
		{
			result.matrix[i][j] = a.matrix[i][j] * c;
		}
	}
	return result;
}

istream& operator>>(istream& scan, Matrix& a)
{
	int x, y;
	cout << "Введите кол-во строк" << endl;
	cin >> x;
	if (x < 0)
		cout << "Error" << endl;
	cout << "Введите кол-во столбцов" << endl;
	cin >> y;
	if (y < 0)
		cout << "Error" << endl;
	a.n = x;
	a.m = y;
	a.matrix.resize(a.n, vector<double>(a.m));
	cout << "Введите значения элементов матрицы" << endl;
	for (int i = 0; i < a.n; i++)
	{
		for (int j = 0; j < a.m; j++)
		{
			double value;
			cout << "Элемент [" << i << "][" << j << "]: ";
			if (scan >> value)
			{
				a.setEl(i, j, value);
			}
			else
				cout << "Error" << endl;
		}
	}
	return scan;
}
