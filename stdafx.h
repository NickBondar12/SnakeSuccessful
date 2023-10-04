// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#if !defined(AFX_STDAFX_H__A9DB83DB_A9FD_11D0_BFD1_444553540000__INCLUDED_)
#define AFX_STDAFX_H__A9DB83DB_A9FD_11D0_BFD1_444553540000__INCLUDED_

#if _MSC_VER > 1000 // Контроль версии
#pragma once
#endif // _MSC_VER > 1000
//////////////////////////////////////////v
#include "targetver.h"
// Разрешает использовать win заголовки
#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
// Windows Header Files
#include <windows.h>

// C RunTime Header Files
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
//////////////////////////////////////////^

#include <string.h>
#include <stdio.h>
#include <ctime>
#include <cstdlib>
#include <vector>

using namespace std;

void Notebook(HDC, HPEN, int, int);
//void AppleGeneration(int, int, HDC, HBRUSH, HWND);
//void SnakeSpeed(int, int, HDC, HBRUSH, HWND);
//void MoveSnake(int, int, HDC, HBRUSH, HWND);
void SnakeBody(HDC, int, int, int, int, int, int, HWND, int, int);

LRESULT CALLBACK WFunc(HWND, UINT, WPARAM, LPARAM);

// Буфер
TCHAR str[256] = "";

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STDAFX_H__A9DB83DB_A9FD_11D0_BFD1_444553540000__INCLUDED_)
