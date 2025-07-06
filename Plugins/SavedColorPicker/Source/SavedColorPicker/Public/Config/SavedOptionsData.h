#pragma once

#include "CoreMinimal.h"
#include "Interfaces/IPluginManager.h"
#include "SavedOptionsData.generated.h"

USTRUCT()
struct SAVEDCOLORPICKER_API FSaveJsonOptionsData
{
	GENERATED_USTRUCT_BODY()

	FSaveJsonOptionsData()
	{
		if (const TSharedPtr<IPlugin> Plugin = IPluginManager::Get().FindPlugin(
			"SavedColorPicker"))
		{
			Version = Plugin->GetDescriptor().VersionName;
			return;
		}

		Version = TEXT("0.0");
	}

	FString& GetVersion() { return Version; }

private:
	UPROPERTY()
	FString Version;
};

USTRUCT()
struct SAVEDCOLORPICKER_API FSaveJsonOptionsDataV1 : public FSaveJsonOptionsData
{
	GENERATED_USTRUCT_BODY()
};
