#include "Editor/SavedColorPickerEditorOption.h"
#include "ContentBrowserModule.h"
#include "LevelEditor.h"

#define LOCTEXT_NAMESPACE "FSavedColorPickerModule"

TUniquePtr<FSavedColorPickerEditorOption> FSavedColorPickerEditorOption::This =
	nullptr;

FSavedColorPickerEditorOption* FSavedColorPickerEditorOption::Get()
{
	if (!This)
	{
		This = MakeUnique<FSavedColorPickerEditorOption>();
	}

	return This.Get();
}

void FSavedColorPickerEditorOption::RegisterEditorOptions()
{
	FLevelEditorModule& EditModule = FModuleManager::LoadModuleChecked<
		FLevelEditorModule>("LevelEditor");

	const TSharedRef<FExtender> Extender = MakeShared<FExtender>();

	Extender->AddMenuExtension("ProjectSettingsMenu", EExtensionHook::After
								, nullptr
								, FMenuExtensionDelegate::CreateRaw(
									this
									, &
									FSavedColorPickerEditorOption::AddCustomMenuEntry));

	EditModule.GetMenuExtensibilityManager()->AddExtender(Extender);
	RegisterOptionsNomadTab();
}

void FSavedColorPickerEditorOption::AddCustomMenuEntry(
	FMenuBuilder& MenuBuilder)
{
	MenuBuilder.AddMenuEntry(
		LOCTEXT("SavedColorPickerOptions", "Saved Color Picker Options")
		, LOCTEXT("SavedColorPickerOptionTooltip"
				, "Click to Edit Saved Color Picker Options."), FSlateIcon()
		, FUIAction(FExecuteAction::CreateRaw(
			this
			, &FSavedColorPickerEditorOption::OnSavedColorPickerOptionClicked)));
}

void FSavedColorPickerEditorOption::OnSavedColorPickerOptionClicked() const
{
	FGlobalTabmanager::Get()->TryInvokeTab(
		FName("SavedColorPickerEditorOptions"));
}

void FSavedColorPickerEditorOption::RegisterOptionsNomadTab()
{
	FGlobalTabmanager::Get()->RegisterNomadTabSpawner(
								FName("SavedColorPickerEditorOptions")
								, FOnSpawnTab::CreateRaw(
									this
									, &
									FSavedColorPickerEditorOption::OnRegisterSavedColorPickerOptionTab))
							.SetDisplayName(
								FText::FromString(
									TEXT("Saved Color Picker Options")));
}

TSharedRef<SDockTab>
FSavedColorPickerEditorOption::OnRegisterSavedColorPickerOptionTab(
	const FSpawnTabArgs&)
{
	return SNew(SDockTab).TabRole(NomadTab);
}

#undef LOCTEXT_NAMESPACE
