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
	//�������� ������
	Matrix PlusMatrix(Matrix& a);
	//��������� ������
	Matrix MinusMatrix(Matrix& a);
	//��������� ������
	Matrix MultiplyMatrix(Matrix& a);
	//��������� ������
	bool CompareMatrix(Matrix& a);
	//��������� ������� �� �����
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




