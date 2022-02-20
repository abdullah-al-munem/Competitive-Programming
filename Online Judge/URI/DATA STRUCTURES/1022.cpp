#include <stdio.h>

int mdc(int, int);
int mmc(int, int);
void multi(int, int, int, int, int *, int *);
void sum(int, int, int, int, int *, int *);
void sub(int, int, int, int, int *, int *);
void div(int, int, int, int, int *, int *);

int main ()
{

	char op;
	int a, b, c, d;
	unsigned n;
	int numerator, denominator, tmp;

	scanf("%u", &n);

	while (n--)
	{

		scanf("%d / %d %c %d / %d", &a, &b, &op, &c, &d);

		if (op == '+')
			sum(a, b, c, d, &numerator, &denominator);
		else if (op == '-')
			sub(a, b, c, d, &numerator, &denominator);
		else if (op == '*')
			multi(a, b, c, d, &numerator, &denominator);
		else if (op == '/')
			div(a, b, c, d, &numerator, &denominator);

		tmp = mdc(numerator, denominator);

		if (tmp < 0)
			printf("%d/%d = %d/%d\n", numerator, denominator, -(numerator / tmp), -(denominator / tmp));
		else
			printf("%d/%d = %d/%d\n", numerator, denominator, numerator / tmp, denominator / tmp);

	}
	return 0;

}

void sum(int a, int b, int c, int d, int *numerator, int *denominator)
{

	*numerator = a * d + c * b;
	*denominator = b * d;

}

void sub(int a, int b, int c, int d, int *numerator, int *denominator)
{

	*numerator = a * d - c * b;
	*denominator = b * d;

}

void multi(int a, int b, int c, int d, int *numerator, int *denominator)
{

	*numerator = a * c;
	*denominator = b * d;

}

void div(int a, int b, int c, int d, int *numerator, int *denominator)
{

	*numerator = (a * d);
	*denominator = (c * b);

}

int mdc(int a, int b)
{

	int r = a % b;

	while (r != 0)
	{

		a = b;
		b = r;
		r = a % b;

	}

	return b;

}

int mmc(int a, int b)
{

	return (a / mdc(a , b)) * b;

}

