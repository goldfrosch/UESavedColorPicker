#include "Config/SavedColorPickerConfigManager.h"

#include "JsonObjectConverter.h"

TUniquePtr<FSavedColorPickerConfigManager> FSavedColorPickerConfigManager::This
	= nullptr;

FSavedColorPickerConfigManager* FSavedColorPickerConfigManager::Get()
{
	if (!This)
	{
		This = MakeUnique<FSavedColorPickerConfigManager>();
	}

	return This.Get();
}

void FSavedColorPickerConfigManager::RegisterConfiguration()
{
	if (!FPaths::FileExists(FilePath))
	{
		// 파일 만들기
		InitializeConfigData_Internal();
		return;
	}

	FString JsonStr;

	// 혹시 모를 파일 Read에 대한 실패 경우 수
	if (!FFileHelper::LoadFileToString(JsonStr, *FilePath))
	{
		UE_LOG(LogTemp, Error
				, TEXT(
					"%sCannot Read Configuration File..., Plz Check Configuration File: [ Path: %s ]"
				), SavedColorPickerConstants::LogPrefix, *FilePath);
	}

	// Json Convert 실패의 케이스
	// 예시: config 무단 변경
	if (!FJsonObjectConverter::JsonObjectStringToUStruct<FSaveJsonOptionsData>(
		JsonStr, &LoadData))
	{
		UE_LOG(LogTemp, Error
				, TEXT(
					"%sYour Configuration File is broken, So Create New Configuration Options"
				), SavedColorPickerConstants::LogPrefix);
		InitializeConfigData_Internal();
	}

	const FString CurrentPluginVersion = IPluginManager::Get().FindPlugin(
		SavedColorPickerConstants::PluginName)->GetDescriptor().VersionName;
	// Configuration 파일의 버전이 현재 버전과 일치하지 않는 경우
	if (LoadData.GetVersion() != CurrentPluginVersion)
	{
		// TODO: 데이터 마이그레이션 시 파일 추가하기
		// 현재는 기본 값으로 처리한다.
		UE_LOG(LogTemp, Warning
				, TEXT(
					"%sYour Configuration File Version Is Old, So Upgrade Myself..., [ Prev Version: %s, Current Version: %s ]"
				), SavedColorPickerConstants::LogPrefix, *LoadData.GetVersion()
				, *CurrentPluginVersion);
	}
}

void FSavedColorPickerConfigManager::InitializeConfigData_Internal()
{
	LoadData = FSaveJsonOptionsData();
	FString JsonStringify;
	FJsonObjectConverter::UStructToJsonObjectString(LoadData, JsonStringify);

	FFileHelper::SaveStringToFile(JsonStringify, *FilePath);

	UE_LOG(LogTemp, Display
			, TEXT(
				"%sCreate SavedColorPicker Configuration File! [ Version: %s ]"
			), SavedColorPickerConstants::LogPrefix, *LoadData.GetVersion());
}
