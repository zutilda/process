#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include <stdio.h>
#include <math.h>
#define PATH "C:\\Users\\dreyv\\source\\repos\\Project6\\x64\\Debug\\Project1.exe"


int main()
{
	system("chcp 1251>nul");
	float f[10];
	FILE* fileInfo = fopen("C:\\Users\\dreyv\\source\\repos\\Project6\\Project6\\information.txt", "r");
	if (fileInfo == NULL) //�������� �� ������ ����
	{
		printf("���� ������! ������� ������ � ��������� ������");
		return 0;
	}
	for (int i = 0; i < 3; i++)
	{
		fscanf(fileInfo, "%f", &f[i]); //������ � ������ ��������
	}
	fclose(fileInfo);
	//�������� ��������� ������� ����� �������, ������� ������ ���������� ���������. 
	STARTUPINFO si; // ����� ������� �������������� �������� ���� ��������� ��������.
	PROCESS_INFORMATION pi; // �������� ���������� � ����� ��������� �������� � ��� ������ ��� ������ �������
	ZeroMemory(&si, sizeof(si)); // ��������� ���� ������ ������.
	si.cb = sizeof(si);
	ZeroMemory(&pi, sizeof(pi)); //��������� ���� ������ ������.
	char* str = calloc(100, sizeof(char));
	sprintf(str, "%f %f %f", f[0], f[1], f[2]); // �������� ������������
	char* cmd = str;
	if (!CreateProcessA(PATH,      // ��� ������������ ������ 
		cmd,           // ��������� ������
		NULL,     // �������� ������ ��������
		NULL,           //��������������������
		FALSE,       // ���� ������������ �������� ��������
		0,              // ����� �������� �������� ��������
		NULL,           // ��������� �� ���� �����
		NULL,           // ������� ���� ��� �������
		&si,           // ��� �������� ����
		&pi)           // ���������� � ��������
		)
	{
		printf("������ %d", GetLastError());
		return;
	}
	WaitForSingleObject(pi.hProcess, INFINITE);
	DWORD d;

	CloseHandle(pi.hProcess);
	CloseHandle(pi.hThread);

	return 0;
}

