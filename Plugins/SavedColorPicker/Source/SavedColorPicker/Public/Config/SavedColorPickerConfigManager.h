#pragma once

#include "CoreMinimal.h"
#include "SavedOptionsData.h"
#include "SavedColorPicker/SavedColorPickerConstants.h"

class SAVEDCOLORPICKER_API FSavedColorPickerConfigManager
{
public:
	static FSavedColorPickerConfigManager* Get();

	void RegisterConfiguration();

	FString GetConfigPath() const { return FilePath; }

private:
	void InitializeConfigData_Internal();

	static TUniquePtr<FSavedColorPickerConfigManager> This;

	FSaveJsonOptionsData LoadData;

	const FString FilePath = FString::Printf(
		TEXT("%s%s"), *FPaths::ProjectDir()
		, SavedColorPickerConstants::PluginConfigurationPath);
};
