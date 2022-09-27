#include<iostream>
using namespace std;

float diho(float a, float b, float(*f)(float))
{
	float e = 0.001;
	while (b - a > e)
	{
		float c = (a + b) / 2;
		float fa = f(a);
		float fc = f(c);
		if (fc == 0)
		{
			return c;
		}

		if (fa * fc < 0)
		{
			b = c;
		}
		else
		{
			a = c;
		}
	}
	return (a + b) / 2;

}

float par(float x)
{
	float y = 2 - x * x + x;
	return y;
}

float sin22(float x)
{
	float y = (sin(x) * sin(x)) - 0.2; //�-��� 2 ��� �������, �������� �� ...-0.2
	return y;
}

int main()
{
	float a, b, x;
	//�-��� 1
	a = -2;
	b = 1;
	x = diho(a, b, par);
	cout << " x = " << x;

	//�-��� 2 ��� �������, �������� �� ...-0.2

	a = 0;
	b = 1.57;//�� �������
	x = diho(a, b, sin22);
	cout << " x = " << x;


	cout << endl;
	system("pause");
}
