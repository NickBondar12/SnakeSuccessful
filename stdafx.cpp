// stdafx.cpp : source file that includes just the standard includes
// Sceleton.pch will be the pre-compiled header
// stdafx.obj will contain the pre-compiled type information
//

#include "stdafx.h"

extern HINSTANCE hInst;

void Notebook(HDC hdc, HPEN hPen1, int wx, int wy)
{
	int a = 0;
	while (a < wx)
	{
		SelectObject(hdc, hPen1);
		a += 20;
		MoveToEx(hdc, a, 0, 0);
		LineTo(hdc, a, wy);
	}
	a = 0;
	while (a < wy)
	{
		SelectObject(hdc, hPen1);
		a += 20;
		MoveToEx(hdc, 0, a, 0);
		LineTo(hdc, wx, a);
	}
	a = 0;
}

//void AppleGeneration(int x, int y, HDC hdc, HBRUSH hBrush, HWND hWnd)
//{
//	SetTimer(hWnd, 1, 50000, 0);
//	SelectObject(hdc, hBrush);
//	Ellipse(hdc, x, y, x + 20, y + 20);
//}
//
//void SnakeSpeed(int x, int y, HDC hdc, HBRUSH hBrush, HWND hWnd)
//{
//	SetTimer(hWnd, 2, 1000, 0);
//	SelectObject(hdc, hBrush);
//	Ellipse(hdc, x, y, x + 20, y + 20);
//}
//
//void MoveSnake(int x, int y, HDC hdc, HBRUSH hBrush, HWND hWnd)
//{
//	SelectObject(hdc, hBrush);
//	Ellipse(hdc, x, y, x + 20, y + 20);
//}


//sprintf(str, "%d", segments);
//SetWindowText(hWnd, str);

void SnakeBody(HDC hdc, int i, int j, int k, int h, int segments, int snakemove, HWND hWnd, int sx, int sy)
{
	static vector <int> vecI, vecJ;
	static int n, itmp, jtmp, itmp1, itmp2, itmp3, itmp4, jtmp1, jtmp2, jtmp3, jtmp4;
	bool flag = true;
	if (snakemove == 0)
	{
		i = 60;
		itmp = i;
		for (n = segments-1; n >= 0; n--)
		{
			vecI.push_back(i);
			vecJ.push_back(j);
			i -= 20;
		}
		n = segments;
		while (n > 0)
		{
			n--;
			Ellipse(hdc, vecI[n], vecJ[n], vecI[n] + 20, vecJ[n] + 20);
		}
	}
	switch (snakemove)
	{
		case 1:    //�����
			sprintf(str, "%d", itmp);
			SetWindowText(hWnd, str);
			for (n = segments - 1; n >= 0; n--)
			{
				//������ ����������� �� ����
				if (vecJ[n] == jtmp)
				{
					i -= 20;
					vecI[n] -= 20;
				}
				//������ ��������� �� �������� (������)
				if (vecJ[n] < jtmp)
				{
					j += 20;
					vecJ[n] += 20;
				}
				//������ ��������� �� �������� (�����)
				if (vecJ[n] > jtmp)
				{
					j -= 20;
					vecJ[n] -= 20;
				}
			}
			while (n < segments - 1)
			{
				n++;
				Ellipse(hdc, vecI[n], vecJ[n], vecI[n] + 20, vecJ[n] + 20);
			}
			itmp = vecI[0];
			break;
			
		case 2:		//�����
			sprintf(str, "%d", itmp);
			SetWindowText(hWnd, str);
			for (n = segments - 1; n >= 0; n--)
			{
				//������ ����������� �� ����
				if (vecI[n] == itmp)
				{
					j -= 20;
					vecJ[n] -= 20;
				}
				//������ ��������� �� ��������(�����)
				if (vecI[n] < itmp)
				{
					i += 20;
					vecI[n] += 20;
				}
				//������ ��������� �� ��������(������)
				if (vecI[n] > itmp)
				{
					i -= 20;
					vecI[n] -= 20;
				}
			}
			while (n < segments - 1)
			{
				n++;
				Ellipse(hdc, vecI[n], vecJ[n], vecI[n] + 20, vecJ[n] + 20);
			}
			jtmp = vecJ[0];
			break;
		case 3:		//������
			sprintf(str, "%d", itmp);
			SetWindowText(hWnd, str);
			for (n = segments - 1; n >= 0; n--)
			{
				//������ ����������� �� ����
				if (vecJ[n] == jtmp)
				{
					i += 20;
					vecI[n] += 20;
				}
				//������ ��������� �� �������� (������)
				if (vecJ[n] < jtmp)
				{
					j += 20;
					vecJ[n] += 20;
				}
				//������ ��������� �� �������� (�����)
				if (vecJ[n] > jtmp)
				{
					j -= 20;
					vecJ[n] -= 20;
				}
			}
			while (n < segments - 1)
			{
				n++;
				Ellipse(hdc, vecI[n], vecJ[n], vecI[n] + 20, vecJ[n] + 20);
			}
			n < segments - 1;
			if(vecJ[n]==vecJ[0])
				itmp = vecI[0];
			break;
		case 4:		//����
			sprintf(str, "%d", itmp);
			SetWindowText(hWnd, str);
			for (n = segments - 1; n >= 0; n--)
			{
				//������ ����������� �� ����
				if (vecI[n] == itmp)
				{
					j += 20;
					vecJ[n] += 20;
				}
				//������ ��������� �� ��������(�����)
				if (vecI[n] < itmp)
				{
					i += 20;
					vecI[n] += 20;
				}
				//������ ��������� �� ��������(������)
				if (vecI[n] > itmp)
				{
					i -= 20;
					vecI[n] -= 20;
				}
			}
			while (n < segments - 1)
			{
				n++;
				Ellipse(hdc, vecI[n] , vecJ[n], vecI[n] + 20, vecJ[n] + 20);
			}
			n = segments - 1;
			if (vecI[n] == vecI[0])
				jtmp = vecJ[0];
			break;
	}
}

LRESULT CALLBACK WFunc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{

	#define TIMER_APPLE 1
	#define TIMER_SNAKE 2
	static HDC hdc;
	PAINTSTRUCT ps;
	static HPEN hPen1;
	static HBRUSH hBrush1, hBrush2, hBrush3;
	static int timer1, sx, sy, x, y, timer2, i, j, n, applecount, snakemove, k, h, segments = 15;
	static vector <int> vecX, vecY;
	switch (message)
	{
	case WM_SIZE:
		//������� ����
		sx = LOWORD(lParam);
		sy = HIWORD(lParam);
		break;
	case WM_CREATE:
		srand(time(0));
		hdc = GetDC(hWnd);
		//��������� ��������
		SetTimer(hWnd, TIMER_APPLE, 10000, 0);//��������� �����
		SetTimer(hWnd, TIMER_SNAKE, 1000, 0);//�������� ����
		//����� + �������� ���� ��� ������ ���������
		hBrush1 = CreateSolidBrush(RGB(255, 0, 55));
		hBrush2 = CreateSolidBrush(RGB(255, 255, 55));
		hBrush3 = CreateSolidBrush(RGB(0, 255, 55));
		hPen1 = CreatePen(PS_SOLID, 1, RGB(100, 100, 255));
		break;

	case WM_TIMER:
		switch (wParam)
		{
		case TIMER_APPLE:
			//���������� ������� � ��������
			vecX.push_back(x);
			vecY.push_back(y);
			applecount++;
			break;
		case TIMER_SNAKE:
			switch (snakemove)
			{
			case 1:
				if ((i + k) > 0)
					k -= 20;
				break;
			case 2:
				if ((j + h) > 0)
					h -= 20;
				break;
			case 3:
				if ((i + k) < (sx - 100))
					k += 20;
				break;
			case 4:
				if ((j + h) < (sy - 100))
					h += 20;
				break;
			}
			break;
		}
		InvalidateRect(hWnd, 0, 1);
		break;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		//��������� ����� ������� 20
		x = (rand() % sx + 10) / 20 * 20;
		y = (rand() % sy + 10) / 20 * 20;
		vecX.push_back(x);
		vecY.push_back(y);
		//��������� �� �����
		Notebook(hdc, hPen1, sx, sy);
		//��������� �����
		SelectObject(hdc, hBrush1);
		for (n = 0; n <= applecount; n++)
			Ellipse(hdc, vecX[n], vecY[n], vecX[n] + 20, vecY[n] + 20);
		//����������� ����
		SelectObject(hdc, hBrush3);
		SnakeBody(hdc, i, j, k, h, segments, snakemove, hWnd, sx, sy);
		EndPaint(hWnd, &ps);
		break;
	case WM_HOTKEY:
		switch (LOWORD(wParam))
		{
		//���� �����
		case 1:
			snakemove = 1;
			SetTimer(hWnd, TIMER_SNAKE, 4000, 0);
			break;
		//���� ������
		case 2:
			snakemove = 2;
			SetTimer(hWnd, TIMER_SNAKE, 4000, 0);
			break;
		//���� ������
		case 3:
			snakemove = 3;
			SetTimer(hWnd, TIMER_SNAKE, 4000, 0);
			break;
		//���� ����
		case 4:
			snakemove = 4;
			SetTimer(hWnd, TIMER_SNAKE, 4000, 0);
			break;
		}
		break;
	case WM_DESTROY:
		PostQuitMessage(0); // ���������� ��������� ��������� ���������
		break;

	default:
		return DefWindowProc(hWnd, message, wParam, lParam); // ������� ��������������� ���������
	}
	return 0L;
}
