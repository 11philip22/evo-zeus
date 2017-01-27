/*
	������ � PESETTINGS, ��������� � �������. ��������� �� ������������� ������� ������ � �������.
*/
#pragma once

#include "core.h"

namespace PeSettings
{
	/*
		�������������.
	*/
	void init();

	/*
		���������������.
	*/
	void uninit();

	/*
		��������� ������������ � ������.

		Return - ��������� �� PESETTINGS (���������� ������� Mem::free), ��� NULL � ������ ������.
	*/
	PESETTINGS* getCurrent();

	/*
		��������� ������������ � ������, � ����������� ��� ������ ��������� + �������.

		Return - ��������� �� PESETTINGS (���������� ������� Mem::free), ��� NULL � ������ ������.
	*/
	PESETTINGS* beginReadWrite();

	/*
		���������� ������������ � ������, � ����������� ��� ������ ��������� + �������.
		
		IN PESETTINGS* - ��������� �� ������������.

		Return - false � ������ ������, true - ������ ��������.
    */
	bool endReadWrite(PESETTINGS* config);

	bool setCurrent(void* data, DWORD size);
};