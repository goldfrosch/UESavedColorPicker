#include "Editor/SavedColorPickerEditorOption.h"
#include "LevelEditor.h"
#include "Editor/Slate/SColorPickerEditorOptionsTab.h"

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

	LevelEditorExtender = MakeShared<FExtender>();

	LevelEditorExtender->AddMenuExtension("ProjectSettingsMenu"
										, EExtensionHook::After, nullptr
										, FMenuExtensionDelegate::CreateRaw(
											this
											, &
											FSavedColorPickerEditorOption::AddCustomMenuEntry));

	EditModule.GetMenuExtensibilityManager()->AddExtender(LevelEditorExtender);
	RegisterOptionsNomadTab();
}

void FSavedColorPickerEditorOption::UnregisterEditorOptions()
{
	if (!LevelEditorExtender.IsValid())
	{
		return;
	}

	if (FModuleManager::Get().IsModuleLoaded("LevelEditor"))
	{
		// TODO: NPE 발생
		FLevelEditorModule& LevelEditorModule = FModuleManager::GetModuleChecked
			<FLevelEditorModule>("LevelEditor");

		LevelEditorModule.GetMenuExtensibilityManager()->RemoveExtender(
			LevelEditorExtender);
	}
	LevelEditorExtender.Reset();
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
	const FSpawnTabArgs& SpawnTabArgs)
{
	return SNew(SDockTab).TabRole(NomadTab)
		[
			SNew(SColorPickerEditorOptionsTab).Test(TEXT("테스트 값"))
		];
}

#undef LOCTEXT_NAMESPACE
