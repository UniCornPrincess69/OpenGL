#ifndef DATA_MANAGER_H
#define DATA_MANAGER_H

#include <iostream>
#include "ErrorType.h"

class CDataManager
{
public:
	std::string ReadFile(const char* a_sFilePath);

	inline const E_ERROR_TYPE GetError(void) const { return m_error; }

private:
	E_ERROR_TYPE m_error = E_ERROR_TYPE::ET_SUCCESS;
};

#endif // !DATA_MANAGER_H


