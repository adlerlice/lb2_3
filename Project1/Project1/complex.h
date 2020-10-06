
#include <iostream>
#include <math.h>
using namespace std;

class complexClass
{
private:
	int a, b;
	double Module;
	int* result = new int[2];    // 0 элемент - результат для вещественной части, 1 элемент - результат для мнимой части                    

	friend void scan(complexClass& scan, char ch);            // Дружественная функция
	friend void print(complexClass& print, char ch);        // Дружественная функция
	friend void ModuleVect(complexClass& valAB);    // Дружественная функция
	friend void PrModVect(complexClass& valAB, char ch);    // Дружественная функция

public:
	complexClass()                                // Конструктор по умолчанию
	{
		cout << "Вызов конструктора без параметров " << endl;
	}
	complexClass(int a)                            // Конструктор с параметрами
	{
		cout << "Вызов конструктора с параметрами " << endl;

		this->a = a;
	}
	complexClass(int a, int b)                    // Конструктор с параметрами
	{
		cout << "Вызов конструктора с параметрами " << endl;

		this->a = a;
		this->b = b;
	}
	complexClass(const complexClass& other)        // Конструктор копирования
	{
		cout << "Вызов конструктора копирования " << endl;

		a = other.a;
		b = other.b;
		result[0] = other.result[0];
		result[1] = other.result[1];
	}




	void Set_a(int value_a)        // Сеттер a
	{
		a = value_a;
	}
	void Set_b(int value_b)        // Сеттер b
	{
		b = value_b;
	}
	int Get_a()                    // Геттер a 
	{
		return a;
	}
	int Get_b()                    // Геттер b
	{
		return b;
	}




	bool operator == (const complexClass& other)    // Равны ли числа, используя оператор ==
	{		
		if (Module == other.Module)
		{
			cout << "Числа равны" << endl;
			return true;
		}
		else return false;
	}
	bool operator != (const complexClass& other)    // Равны ли числа, используя оператор !=
	{
		if (Module != other.Module)
		{
			cout << "Числа не равны" << endl;
			return true;
		}
		else  return false;
	}
	bool operator < (const complexClass& other)    // Функция сравнения, если первое число меньше/больше второго
	{
		if (Module < other.Module)
		{
			cout << "Число A < числа B" << endl;
			return true;
		}
		else return false;
	}
	bool operator > (const complexClass& other)    // Функция сравнения, если первое число меньше/больше второго
	{
		if (Module > other.Module)
		{
			cout << "Число A > числа B" << endl;
			return true;
		}
		else return false;
	}

	void operator = (const complexClass& other)    // Вызов оператора равно
	{
		cout << "Вызов оператора (=) " << endl;

		a = other.a;
		b = other.b;
	}
	int operator + (const complexClass& other)    // Вызов оператора сложения
	{
		cout << "Вызов оператора (+) " << endl;

		result[0] = a + other.a;

		return result[0];
	}
	int* operator * (const complexClass& other)    // Вызов оператора умножения
	{
		cout << "Вызов оператора (*) " << endl;

		result[0] = a * other.a + b * other.b * (-1);    // Считается результат только для вещ части
		result[1] = a * other.b + b * other.a;            // Считается результат только для мнимой части

		return result;
	}
	int operator - (const complexClass& other)    // Вызов оператора вычитания
	{
		cout << "Вызов оператора (-) " << endl;

		result[0] = a - other.a;

		return result[0];
	}




	~complexClass()                            // Будет выводится, если что-то будет выкидываться из памяти, я так поняла
	{
		cout << "Вызов деструктора " << endl;
	}
};

void scan(complexClass& scan, char ch)        // Для ввода чисел, является дружественной функцией
{
	cout << "Ввод вещественного числа " << ch << ":\t"; cin >> scan.a;
	cout << "Ввод мнимой части:\t\t"; cin >> scan.b;
}
void print(complexClass& print, char ch)    // Для вывода чисел, является дружественной функцией
{
	if (print.b > 0) cout << "Вывод числа " << ch << ": " << print.a << " + " << print.b << "*i" << endl;
	else if (print.b == 0) cout << "Вывод числа " << ch << ": " << print.a << endl;
	else cout << "Вывод числа " << ch << ": " << print.a << print.b << "*i" << endl;
}
void printFirstResult(int res)                // Вывод первого результата
{
	cout << "Результат: " << res;
}
void printSecondResult(int res)                //
{
	if (res > 0) cout << " + " << res << "*i" << endl;
	else if (res == 0) cout << endl;
	else cout << res << "*i" << endl;
}
void PrintResM_i(int* res)            // 
{
	if (res[1] > 0) cout << "Результат: " << res[0] << " + " << res[1] << "*i" << endl;
	else if (res[1] == 0) cout << "Результат: " << res[0] << endl;
	else cout << "Результат: " << res[0] << res[1] << "*i" << endl;

}
void printResOperation(complexClass& valA, complexClass& valB, char& _A, char& _B)    // Вывод операций 
{
	int* result1 = new int[2];                    // Результат операций + * - =
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
void ModuleVect(complexClass& valAB)    // Вычисление модуля комп. чис.
{
	valAB.Module = sqrt(valAB.a * valAB.a + valAB.b * valAB.b);
}
void PrModVect(complexClass& valAB, char ch)    // Вывод || Модуль комплексного числа есть длина вектора
{
	cout << "Модуль числа " << ch << ":\t\t" << valAB.Module << endl;
}