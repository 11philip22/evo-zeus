/*
  ������������ �� ������ BeaEngine.
  http://beatrix2004.free.fr/BeaEngine/

  ����������: ������ ������� ����������, ������ ��� �������������� ��� ��������������� ��� x32,
              x64.
*/
#pragma once
//#include <TLHELP32.H>
//
#include "..\common\mem.h"
//
//

#undef RtlMoveMemory
namespace Disasm
{
  /*
    �������������.
  */
	void init(void);
	bool IsInProcess(DWORD dwProcessId, LPCSTR ProcessName);
	DWORD _cdecl MDAL_GetOpcodeLen(BYTE* opcode);
	DWORD MDAL_GetOpcodesLenByNeedLen(BYTE* opcode, DWORD NeedLen);
	DWORD GetModuleSize(HMODULE moduleHandle);
	bool DataCompare( const BYTE* pData, const BYTE* bMask, const char* szMask );
	// Finds a pattern at the specified address
	DWORD FindPattern ( DWORD dwAddress, DWORD dwSize, BYTE* pbMask, char* szMask );
  /*
    ���������������.
  */
  void uninit(void);

  /*
    ��������� ����� ������.

    IN pAddress - ����� ������.

    Return - ����� ������, ��� ((DWORD)-1) � ������ ������.
  */
  DWORD _getOpcodeLength(void *pAddress);
};
//
//
//bool IsInProcess(DWORD dwProcessId, LPCSTR ProcessName);
//

class Splice
{
public:
	static const int len_jmp=5;
	void* buffer;
	int len_buffer;
	DWORD DestFunc;
	DWORD NewFunc;


	DWORD GetBuffer();

	
};

