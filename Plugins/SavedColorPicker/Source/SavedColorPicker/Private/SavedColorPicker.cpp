#include "SavedColorPicker.h"

#include "CustomizeSavedColorPalette.h"

#define LOCTEXT_NAMESPACE "FSavedColorPickerModule"

void FSavedColorPickerModule::StartupModule()
{
	PropertyEditor = "PropertyEditor";
	FPropertyEditorModule& PropertyModule = FModuleManager::GetModuleChecked<
		FPropertyEditorModule>(PropertyEditor);

	PropertyModule.RegisterCustomPropertyTypeLayout(
		NAME_LinearColor
		, FOnGetPropertyTypeCustomizationInstance::CreateStatic(
			&FCustomizeSavedColorPalette::MakeInstance));
	PropertyModule.RegisterCustomPropertyTypeLayout(
		NAME_Color
		, FOnGetPropertyTypeCustomizationInstance::CreateStatic(
			&FCustomizeSavedColorPalette::MakeInstance));

	PropertyModule.NotifyCustomizationModuleChanged();
}

void FSavedColorPickerModule::ShutdownModule()
{
	if (FModuleManager::Get().IsModuleLoaded(PropertyEditor))
	{
		FPropertyEditorModule& PropertyModule = FModuleManager::GetModuleChecked
			<FPropertyEditorModule>(PropertyEditor);
		PropertyModule.UnregisterCustomPropertyTypeLayout(NAME_LinearColor);
		PropertyModule.UnregisterCustomPropertyTypeLayout(NAME_Color);

		PropertyModule.NotifyCustomizationModuleChanged();
	}
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FSavedColorPickerModule, SavedColorPicker)
