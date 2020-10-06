#include <iostream>  //����/�����
#include <math.h>    //������������ ���� ��� ������ � �����������
#include "complex.h" //������������ ���� � ������� Complex � ��������� ��� ������ � ������������ �������
using namespace std;

int main()
{
	setlocale(LC_ALL, ""); //�������� ������� ����!
	cout << "��������� ����� �������� ��� ��������, ������� ����� �����������, ����� �� ����� ��������� �����-���� ������� :)" << endl;
	complexClass A;                // ����������� ��� A
	complexClass B;                // ����������� ��� B
	char charA = 'A'; char charB = 'B';

	scan(A, charA); print(A, charA);
	cout << endl;
	scan(B, charB); print(B, charB);
	// ����� ���������� ���������� �������� �������� ��������� ��������
	int saveA_a = A.Get_a();
	int saveA_b = A.Get_b();
	int saveB_a = B.Get_a();
	int saveB_b = B.Get_b();

	cout << endl;
	printResOperation(A, B, charA, charB);
	cout << endl; A.Set_a(saveA_a); A.Set_b(saveA_b);
	printResOperation(B, A, charA, charB);
	cout << endl; B.Set_a(saveB_a); B.Set_b(saveB_b);

	// ������������ � ������� ������������ ����������� 
	complexClass Par_A(4, 2);
	complexClass Par_B(3, 5);
	// ����� ���������� ���������� ���������� ��������� ��������
	saveA_a = Par_A.Get_a();
	saveA_b = Par_A.Get_b();
	saveB_a = Par_B.Get_a();
	saveB_b = Par_B.Get_b();
	charA = 'A'; charB = 'B';

	print(Par_A, charA);
	cout << endl;
	print(Par_B, charB);

	cout << endl;
	printResOperation(Par_A, Par_B, charA, charB);
	cout << endl; Par_A.Set_a(saveA_a); Par_A.Set_b(saveA_b);
	printResOperation(Par_B, Par_A, charA, charB);
	cout << endl; Par_B.Set_a(saveB_a); Par_B.Set_b(saveB_b);


	complexClass Cop_A(B);    // ����������� ����������� Cop_B
	charA = 'A'; charB = 'B';
	print(Cop_A, charA);

	cout << endl;
	printResOperation(Cop_A, B, charA, charB);
	cout << endl;
	printResOperation(B, Cop_A, charA, charB);
	cout << endl;

	charA = 'A'; charB = 'B';
	cout << "����� ��� ���������: " << endl;
	print(A, charA); print(B, charB);
	ModuleVect(A); ModuleVect(B);
	cout << endl;
	PrModVect(A, charA); PrModVect(B, charB);

	cout << endl;
	A.operator==(B);
	A.operator!=(B);
	A.operator<(B);
	A.operator>(B);



	cout << endl;
	return 0;
}
