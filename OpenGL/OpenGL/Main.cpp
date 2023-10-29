#include "Engine.h"
#include "DataManager.h"
#include "ModelLoader.h"


int main(int a_iArgV, const char* a_argsC[])
{
	CDataManager* pData = new CDataManager();
	CModelLoader* pLoader = new CModelLoader();
	CEngine* pEngine = new CEngine(pData, pLoader);
	if (pEngine != nullptr) PROVE_RESULT(pEngine->Initialize());
	if (pEngine != nullptr) PROVE_RESULT(pEngine->Run());
	FINALIZE_DELETE(pEngine);
	SAFE_DELETE(pLoader);
	SAFE_DELETE(pData);
	return 0;
}