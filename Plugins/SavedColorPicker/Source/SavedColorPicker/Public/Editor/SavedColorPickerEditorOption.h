#pragma once

#include "CoreMinimal.h"

class SAVEDCOLORPICKER_API FSavedColorPickerEditorOption
{
public:
	static FSavedColorPickerEditorOption* Get();

	void RegisterEditorOptions();

	void UnregisterEditorOptions();

private:
	static TUniquePtr<FSavedColorPickerEditorOption> This;

	TSharedPtr<FExtender> LevelEditorExtender;

#pragma region Editor
	void AddCustomMenuEntry(FMenuBuilder& MenuBuilder);

	void OnSavedColorPickerOptionClicked() const;
#pragma endregion

#pragma region OptionsNomadTab
	void RegisterOptionsNomadTab();

	TSharedRef<SDockTab> OnRegisterSavedColorPickerOptionTab(
		const FSpawnTabArgs& SpawnTabArgs);
#pragma endregion
};
