
#include <iostream>
#include <math.h>
using namespace std;

class complexClass
{
private:
	int a, b;
	double Module;
	int* result = new int[2];    // 0 ������� - ��������� ��� ������������ �����, 1 ������� - ��������� ��� ������ �����                    

	friend void scan(complexClass& scan, char ch);            // ������������� �������
	friend void print(complexClass& print, char ch);        // ������������� �������
	friend void ModuleVect(complexClass& valAB);    // ������������� �������
	friend void PrModVect(complexClass& valAB, char ch);    // ������������� �������

public:
	complexClass()                                // ����������� �� ���������
	{
		cout << "����� ������������ ��� ���������� " << endl;
	}
	complexClass(int a)                            // ����������� � �����������
	{
		cout << "����� ������������ � ����������� " << endl;

		this->a = a;
	}
	complexClass(int a, int b)                    // ����������� � �����������
	{
		cout << "����� ������������ � ����������� " << endl;

		this->a = a;
		this->b = b;
	}
	complexClass(const complexClass& other)        // ����������� �����������
	{
		cout << "����� ������������ ����������� " << endl;

		a = other.a;
		b = other.b;
		result[0] = other.result[0];
		result[1] = other.result[1];
	}




	void Set_a(int value_a)        // ������ a
	{
		a = value_a;
	}
	void Set_b(int value_b)        // ������ b
	{
		b = value_b;
	}
	int Get_a()                    // ������ a 
	{
		return a;
	}
	int Get_b()                    // ������ b
	{
		return b;
	}




	bool operator == (const complexClass& other)    // ����� �� �����, ��������� �������� ==
	{		
		if (Module == other.Module)
		{
			cout << "����� �����" << endl;
			return true;
		}
		else return false;
	}
	bool operator != (const complexClass& other)    // ����� �� �����, ��������� �������� !=
	{
		if (Module != other.Module)
		{
			cout << "����� �� �����" << endl;
			return true;
		}
		else  return false;
	}
	bool operator < (const complexClass& other)    // ������� ���������, ���� ������ ����� ������/������ �������
	{
		if (Module < other.Module)
		{
			cout << "����� A < ����� B" << endl;
			return true;
		}
		else return false;
	}
	bool operator > (const complexClass& other)    // ������� ���������, ���� ������ ����� ������/������ �������
	{
		if (Module > other.Module)
		{
			cout << "����� A > ����� B" << endl;
			return true;
		}
		else return false;
	}

	void operator = (const complexClass& other)    // ����� ��������� �����
	{
		cout << "����� ��������� (=) " << endl;

		a = other.a;
		b = other.b;
	}
	int operator + (const complexClass& other)    // ����� ��������� ��������
	{
		cout << "����� ��������� (+) " << endl;

		result[0] = a + other.a;

		return result[0];
	}
	int* operator * (const complexClass& other)    // ����� ��������� ���������
	{
		cout << "����� ��������� (*) " << endl;

		result[0] = a * other.a + b * other.b * (-1);    // ��������� ��������� ������ ��� ��� �����
		result[1] = a * other.b + b * other.a;            // ��������� ��������� ������ ��� ������ �����

		return result;
	}
	int operator - (const complexClass& other)    // ����� ��������� ���������
	{
		cout << "����� ��������� (-) " << endl;

		result[0] = a - other.a;

		return result[0];
	}




	~complexClass()                            // ����� ���������, ���� ���-�� ����� ������������ �� ������, � ��� ������
	{
		cout << "����� ����������� " << endl;
	}
};

void scan(complexClass& scan, char ch)        // ��� ����� �����, �������� ������������� ��������
{
	cout << "���� ������������� ����� " << ch << ":\t"; cin >> scan.a;
	cout << "���� ������ �����:\t\t"; cin >> scan.b;
}
void print(complexClass& print, char ch)    // ��� ������ �����, �������� ������������� ��������
{
	if (print.b > 0) cout << "����� ����� " << ch << ": " << print.a << " + " << print.b << "*i" << endl;
	else if (print.b == 0) cout << "����� ����� " << ch << ": " << print.a << endl;
	else cout << "����� ����� " << ch << ": " << print.a << print.b << "*i" << endl;
}
void printFirstResult(int res)                // ����� ������� ����������
{
	cout << "���������: " << res;
}
void printSecondResult(int res)                //
{
	if (res > 0) cout << " + " << res << "*i" << endl;
	else if (res == 0) cout << endl;
	else cout << res << "*i" << endl;
}
void PrintResM_i(int* res)            // 
{
	if (res[1] > 0) cout << "���������: " << res[0] << " + " << res[1] << "*i" << endl;
	else if (res[1] == 0) cout << "���������: " << res[0] << endl;
	else cout << "���������: " << res[0] << res[1] << "*i" << endl;

}
void printResOperation(complexClass& valA, complexClass& valB, char& _A, char& _B)    // ����� �������� 
{
	int* result1 = new int[2];                    // ��������� �������� + * - =
	char _C = _A;

	result1[0] = valA.operator+(valB);
	cout << _A << " + " << _B << endl;
	printFirstResult(result1[0]);
	result1[1] = valA.Get_b() + valB.Get_b();
	printSecondResult(result1[1]);

	cout << endl;

	result1 = valA.operator*(valB);
	cout << _A << " * " << _B << endl;
	/*result2 = (valA.Get_b() * valB.Get_b()) * (-1) + result1;*/
	PrintResM_i(result1);

	cout << endl;

	result1[0] = valA.operator-(valB);
	cout << _A << " - " << _B << endl;
	printFirstResult(result1[0]);
	result1[1] = valA.Get_b() - valB.Get_b();
	printSecondResult(result1[1]);

	cout << endl;

	valA.operator=(valB);
	cout << _A << " = " << _B << endl;
	print(valA, _A);

	_A = _B;
	_B = _C;
}
void ModuleVect(complexClass& valAB)    // ���������� ������ ����. ���.
{
	valAB.Module = sqrt(valAB.a * valAB.a + valAB.b * valAB.b);
}
void PrModVect(complexClass& valAB, char ch)    // ����� || ������ ������������ ����� ���� ����� �������
{
	cout << "������ ����� " << ch << ":\t\t" << valAB.Module << endl;
}