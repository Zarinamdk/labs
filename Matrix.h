#include <vector>
#include <iostream>

using namespace std;


class Matrix
{
	int n, m;
	vector<vector<double>> matrix;
	
public:
	Matrix();
	Matrix(int x, int y);
	~Matrix();
	Matrix(Matrix& a);
	int getX();
	int getY();
	double getEl(int x, int y);
	double setEl(int x, int y, double el);
	void printMatrix();
	//сложение матриц
	Matrix PlusMatrix(Matrix& a);
	//вычитание матриц
	Matrix MinusMatrix(Matrix& a);
	//умножение матриц
	Matrix MultiplyMatrix(Matrix& a);
	//сравнение матриц
	bool CompareMatrix(Matrix& a);
	//умножение матрицы на число
	Matrix MulCMatrix(double c);
	friend ostream& operator<<(ostream& print, Matrix& a);
	Matrix operator +(Matrix& a);
	Matrix operator -(Matrix& a);
	Matrix operator *(double c);
	bool operator == (Matrix& a);
	friend Matrix operator *(double c, Matrix& a);
	friend istream& operator>>(istream& scan, Matrix& a);
	Matrix& operator =(Matrix& a);

};




