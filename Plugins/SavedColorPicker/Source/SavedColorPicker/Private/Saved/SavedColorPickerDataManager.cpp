#include "Saved/SavedColorPickerDataManager.h"

TUniquePtr<FSavedColorPickerDataManager> FSavedColorPickerDataManager::This =
	nullptr;

FSavedColorPickerDataManager* FSavedColorPickerDataManager::Get()
{
	if (!This)
	{
		This = MakeUnique<FSavedColorPickerDataManager>();
	}

	return This.Get();
}

void FSavedColorPickerDataManager::InitializeSavedData()
{
	FString FilePath = "";

	if (!FPaths::FileExists(FilePath))
	{
		// 파일 만들기

		return;
	}

	FString JsonStr;

	if (!FFileHelper::LoadFileToString(JsonStr, *FilePath))
	{
		UE_LOG(LogTemp, Error, TEXT("JSON 파일 읽기 실패: %s"), *FilePath);
	}
}
