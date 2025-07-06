#pragma once

#include "CoreMinimal.h"
#include "Interfaces/IPluginManager.h"
#include "SavedColorPicker/SavedColorPickerConstants.h"
#include "SavedOptionsData.generated.h"

USTRUCT()
struct SAVEDCOLORPICKER_API FSavedColorTreeNode
{
	GENERATED_USTRUCT_BODY()

	FString GetCategoryName() const { return CategoryName; }

	void SetCategoryName(const FString& NewCategoryName)
	{
		CategoryName = NewCategoryName;
	}

	FLinearColor GetColorValue() const { return ColorValue; }

	void SetColorValue(const FLinearColor& NewColorValue)
	{
		ColorValue = NewColorValue;
	}

private:
	UPROPERTY()
	FString CategoryName;

	UPROPERTY()
	FLinearColor ColorValue = FLinearColor();

	TMap<FString, FSavedColorTreeNode*> ChildNodes;
};

USTRUCT()
struct SAVEDCOLORPICKER_API FSaveJsonOptionsData
{
	GENERATED_USTRUCT_BODY()

	FSaveJsonOptionsData()
	{
		if (const TSharedPtr<IPlugin> Plugin = IPluginManager::Get().FindPlugin(
			SavedColorPickerConstants::PluginName))
		{
			Version = Plugin->GetDescriptor().VersionName;
			return;
		}

		Version = TEXT("0.0");
	}

	FString& GetVersion() { return Version; }
	TArray<FSavedColorTreeNode>& GetSavedColorList() { return SavedColorList; }

private:
	UPROPERTY()
	FString Version;

	UPROPERTY()
	TArray<FSavedColorTreeNode> SavedColorList;

	TMap<FString, FSavedColorTreeNode*> SavedColorTree;
};
