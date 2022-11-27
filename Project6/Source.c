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
	if (fileInfo == NULL) //проверка на пустой файл
	{
		printf("Файл пустой! Введите данные и повторите запуск");
		return 0;
	}
	for (int i = 0; i < 3; i++)
	{
		fscanf(fileInfo, "%f", &f[i]); //запись в массив значений
	}
	fclose(fileInfo);
	//основная программа создает новый процесс, который решает квадратное уравнение. 
	STARTUPINFO si; // чтобы указать характеристики главного окна дочернего процесса.
	PROCESS_INFORMATION pi; // содержит информацию о новом созданном процессе и его потоке при вызове функции
	ZeroMemory(&si, sizeof(si)); // Заполняет блок памяти нулями.
	si.cb = sizeof(si);
	ZeroMemory(&pi, sizeof(pi)); //Заполняет блок памяти нулями.
	char* str = calloc(100, sizeof(char));
	sprintf(str, "%f %f %f", f[0], f[1], f[2]); // передача коэфициентов
	char* cmd = str;
	if (!CreateProcessA(PATH,      // имя исполняемого модуля 
		cmd,           // командная строка
		NULL,     // атрибуты защиты процесса
		NULL,           //атрибутызащитыпотока
		FALSE,       // флаг наследования текущего процесса
		0,              // флаги способов создания процесса
		NULL,           // указатель на блок среды
		NULL,           // текущий диск или каталог
		&si,           // вид главного окна
		&pi)           // информация о процессе
		)
	{
		printf("Ошибка %d", GetLastError());
		return;
	}
	WaitForSingleObject(pi.hProcess, INFINITE);
	DWORD d;

	CloseHandle(pi.hProcess);
	CloseHandle(pi.hThread);

	return 0;
}

