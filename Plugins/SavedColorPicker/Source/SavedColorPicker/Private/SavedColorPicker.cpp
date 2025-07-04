#include "SavedColorPicker.h"

#include "Editor/SavedColorPickerEditorOption.h"

#define LOCTEXT_NAMESPACE "FSavedColorPickerModule"

void FSavedColorPickerModule::StartupModule()
{
	FSavedColorPickerEditorOption::Get()->RegisterEditorOptions();
}

void FSavedColorPickerModule::ShutdownModule()
{
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FSavedColorPickerModule, SavedColorPicker)
