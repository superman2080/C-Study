#include <stdio.h>
#include <malloc.h>
#include <math.h>

typedef struct Poly {
	int val;
	int deg;
	Poly* nextDeg;
}Poly;

Poly* CreatePolynomial(int v, int d) {
	//다항식 헤드 생성
	Poly* temp = (Poly*)malloc(sizeof(Poly));
	temp->val = v;
	temp->deg = d;
	temp->nextDeg = NULL;
	return temp;
}

void AddPolynomial(Poly* pol, int v, int d) {
	//같은 차수가 있을 경우 값만 더해줌
	while (true)
	{
		if (pol->deg == d)
		{
			pol->val += v;
			return;
		}
		if (pol->nextDeg == NULL)
			break;
		
		pol = pol->nextDeg;
	}

	Poly* temp = (Poly*)malloc(sizeof(Poly));
	temp->val = v;
	temp->deg = d;
	temp->nextDeg = NULL;

	if (pol == NULL)
		pol = temp;
	else
		pol->nextDeg = temp;
}

Poly* MinusPolynomial(Poly* origin, Poly* minus) {

	Poly* temp = NULL;
	Poly* minAddress = minus;
	bool isExist = false;
	while (origin)
	{
		while (minus)
		{
			if (origin->deg == minus->deg && origin->val - minus->val != 0) {
				if (!isExist) {
					temp = CreatePolynomial(origin->val - minus->val, origin->deg);
					isExist = true;
				}
				else {
					AddPolynomial(temp, origin->val - minus->val, origin->deg);
				}
			}
			minus = minus->nextDeg;
		}
		origin = origin->nextDeg;
		minus = minAddress;
	}
	return temp;
}

int GetMaxDegree(Poly* pol) {
	int max = 0;
	while (pol)
	{
		if (pol->deg > max)
			max = pol->deg;

		pol = pol->nextDeg;
	}

	return max;
}

void PrintPolynomial(Poly* pol, int maxDeg) {
	Poly* head = pol;
	while (pol)
	{
		if (pol->deg == maxDeg) {
			if (pol->val > 0) {
				printf("+");
			}
			else {
				printf("-");
			}

			if (maxDeg == 0) {
				printf(" %d", abs(pol->val));
			}
			else {
				printf(" %dx^%d ", abs(pol->val), pol->deg);
			}
			break;
		}
		pol = pol->nextDeg;
	}
	if (maxDeg > 0) {
		PrintPolynomial(head, maxDeg - 1);
	}
}

void DestroyPoly(Poly* pol) {
	if (pol->nextDeg) {
		DestroyPoly(pol->nextDeg);
	}
	free(pol);
}

int main() {
	Poly* pol1 = CreatePolynomial(7, 5);
	AddPolynomial(pol1, -4, 4);
	AddPolynomial(pol1, 8, 1);
	AddPolynomial(pol1, 4, 1);
	AddPolynomial(pol1, 3, 0);
	PrintPolynomial(pol1, GetMaxDegree(pol1));
	printf("\n");

	Poly* pol2 = CreatePolynomial(-6, 5);
	AddPolynomial(pol2, -4, 4);
	AddPolynomial(pol2, 4, 2);
	AddPolynomial(pol2, 10, 1);
	AddPolynomial(pol2, 2, 0);
	PrintPolynomial(pol2, GetMaxDegree(pol2));
	printf("\n");

	Poly* minus = MinusPolynomial(pol1, pol2);

	PrintPolynomial(minus, GetMaxDegree(minus));

	DestroyPoly(pol1);
	DestroyPoly(pol2);
	DestroyPoly(minus);
	return 0;
}