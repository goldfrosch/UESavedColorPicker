#include "SavedColorPicker.h"

#include "Editor/SavedColorPickerEditorOption.h"
#include "Config/SavedColorPickerConfigManager.h"

#define LOCTEXT_NAMESPACE "FSavedColorPickerModule"

void FSavedColorPickerModule::StartupModule()
{
	FSavedColorPickerEditorOption::Get()->RegisterEditorOptions();
	FSavedColorPickerConfigManager::Get()->RegisterConfiguration();
}

void FSavedColorPickerModule::ShutdownModule()
{
	FSavedColorPickerEditorOption::Get()->UnregisterEditorOptions();
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FSavedColorPickerModule, SavedColorPicker)
