#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

void result(float a, float b, float c)
{
	float discriminant;
	float x1, x2;
	FILE* fileRes = fopen("result.txt", "w");

	if ((c == 0) && (b == 0))
	{
		x1 = 0;
		discriminant = 0;
		printf("������������ = %f , � ��������� ���� ������ = %f", discriminant, x1);
		fprintf(fileRes, "������������ = %f, � ��������� ���� ������ = %f", discriminant, x1);
		fclose(fileRes);
	}
	else if ((a != 0) && (b != 0) && (c != 0))
	{
		discriminant = b * b - 4 * a * c;
		if (discriminant < 0)
		{
			printf("������ ���");
			fprintf(fileRes, "������ ���, ������������ = %f", discriminant);
			fclose(fileRes);

		}
		else if (discriminant == 0)
		{
			x1 = -b / (2 * a);
			fprintf(fileRes, "������������ = %f , � ��������� ���� ������ x = %f ", discriminant, x1);
			fclose(fileRes);
		}
		else if (discriminant > 0)
		{
			x1 = (-b + sqrt(discriminant)) / (2 * a);
			x2 = (-b - sqrt(discriminant)) / (2 * a);
			printf("������������ = %f , ��������� ����� ��� ����� x1 = %f � x2 = %f", discriminant, x1, x2);
			fprintf(fileRes, "������������ = %f , ��������� ����� ��� ����� x1 = %f � x2 = %f", discriminant, x1, x2);
			fclose(fileRes);
		}
	}
	else if (b == 0)
	{
		if (-(c / a) >= 0)
		{
			x1 = sqrt((-c / a));
			printf("��������� ����� ��� ����� x1 = %f � x2 = -%f", x1, x1);
			fprintf(fileRes, "��� ����� x1 = % f � x2 = -% f", x1, x1);
			fclose(fileRes);
		}
		else
		{
			printf("��� ������");
		}
	}
	else if (c == 0)
	{
		x1 = -b / a;
		x2 = 0;
		printf("��� ����� x1 = %f � x2 = %f", x1, x2);
		fprintf(fileRes, "��� ����� x1 = %f � x2 = %f", x1, x2);
		fclose(fileRes);
	}

}

int main()
{
	system("chcp 1251 > nul");
	float a, b, c;
	float f[4];
	FILE* file = fopen("information.txt", "r");
	if (file == NULL)
	{
		printf("���� ������! ������� ������ � ��������� ��������� ��������");
		return 0;
	}
	else
	{
		for (int i = 0; i < 3; i++)
		{
			fscanf(file, "%f", &f[i]);			
		}
		fclose(file);
		if (f[0] == 0)
		{
			printf("������ ����������� �� ������ ���� ����� 0! ������� ���������� ������ � ��������� ������");
			return 0;
		}
		else {
			if (f[0] == -107374176. || f[1] == -107374176. || f[2] == -107374176.)
			{
				printf("�� ��������� ������� ������");
				return 0;
			}
			else
			{
				result(f[0], f[1], f[2]);
			}
		}
	}
}