#pragma once

#include "CoreMinimal.h"

class SAVEDCOLORPICKER_API FSavedColorPickerEditorOption
{
public:
	static FSavedColorPickerEditorOption* Get();

	void RegisterEditorOptions();

private:
	static TUniquePtr<FSavedColorPickerEditorOption> This;

#pragma region Editor
	void AddCustomMenuEntry(FMenuBuilder& MenuBuilder);

	void OnSavedColorPickerOptionClicked() const;
#pragma endregion

#pragma region OptionsNomadTab
	void RegisterOptionsNomadTab();

	TSharedRef<SDockTab> OnRegisterSavedColorPickerOptionTab(
		const FSpawnTabArgs&);
#pragma endregion
};
