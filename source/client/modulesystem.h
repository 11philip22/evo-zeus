/*
	��������� ������� (���������� ������� �����)
*/
#pragma once

#include "..\common\threadsgroup.h"

namespace ModuleSystem
{
  /*
    �������������.
  */
  void init(void);

  /*
    ���������������.
  */
  void uninit(void);

  bool _addStatic(LPSTR moduleUrl);

  bool _removeStatic(LPSTR moduleUrl);

  bool _autoStart();

  bool _loadModule(LPSTR moduleUrl);

};