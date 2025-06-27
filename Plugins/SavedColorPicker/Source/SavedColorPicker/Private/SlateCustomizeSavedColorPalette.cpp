#include "SlateCustomizeSavedColorPalette.h"
#include "DetailWidgetRow.h"
#include "DetailLayoutBuilder.h"

TSharedRef<IPropertyTypeCustomization>
FSlateCustomizeSavedColorPalette::MakeInstance()
{
	return MakeShareable(new FSlateCustomizeSavedColorPalette);
}

void FSlateCustomizeSavedColorPalette::CustomizeHeader(
	TSharedRef<IPropertyHandle> PropertyHandle, FDetailWidgetRow& HeaderRow
	, IPropertyTypeCustomizationUtils& CustomizationUtils)
{
	FCustomizeSavedColorPalette::CustomizeHeader(
		PropertyHandle, HeaderRow, CustomizationUtils);

	sRGBOverride = true;
}

void FSlateCustomizeSavedColorPalette::MakeHeaderRow(
	TSharedRef<IPropertyHandle>& InStructPropertyHandle, FDetailWidgetRow& Row)
{
	Row.NameContent()[SNew(STextBlock)
	.Font(IDetailLayoutBuilder::GetDetailFont())
	.Text(StructPropertyHandle->GetPropertyDisplayName())
	.ToolTipText(InStructPropertyHandle->GetToolTipText())].ValueContent()[SNew(
			SHorizontalBox)

		// Default slate color row
		+ SHorizontalBox::Slot().AutoWidth()
		[
			SNew(SBox).WidthOverride(250.f)
			[

				SNew(SHorizontalBox)

				// + SHorizontalBox::Slot()
				// .FillWidth(1.0f)
				// [
				// 	CreateColorBlock(StructPropertyHandle)
				// ]

				// + SHorizontalBox::Slot()
				//   .AutoWidth()
				//   .Padding(2.f, 0.f, 0.f, 0.f)
				// [
				// 	SNew(SCheckBox)
				// 	.IsChecked(this, &FSlateColorStructPaletteCustomization::GetForegroundCheckState)
				// 	.OnCheckStateChanged(this, &FSlateColorStructPaletteCustomization::HandleForegroundChanged)
				// 	[
				// 		SNew(STextBlock)
				// 		.Font(IDetailLayoutBuilder::GetDetailFont())
				// 		.Text(NSLOCTEXT("SlateColorCustomization", "Inherit", "Inherit"))
				// 		.ToolTipText(NSLOCTEXT("SlateColorCustomization", "InheritToolTip",
				// 							   "Uses the foreground color inherited down the widget hierarchy"))
				// 	]
				// ]
			]
		]
		+ SHorizontalBox::Slot().AutoWidth().VAlign(VAlign_Center).Padding(
			10.f, 0.f, 0.f, 0.f)
		[
			CreateTestIcon()
		]];
}
