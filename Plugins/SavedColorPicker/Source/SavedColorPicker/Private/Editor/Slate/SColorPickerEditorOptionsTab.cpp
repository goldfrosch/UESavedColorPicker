#include "Editor/Slate/SColorPickerEditorOptionsTab.h"

void SColorPickerEditorOptionsTab::Construct(const FArguments& InArgs)
{
	bCanSupportFocus = true;

	FSlateFontInfo TitleTextFontInfo = FCoreStyle::Get().GetFontStyle(
		FName("EmbossedText"));
	TitleTextFontInfo.Size = 32.f;

	ChildSlot
	[
		SNew(SVerticalBox)
		+ SVerticalBox::Slot().AutoHeight()
		[
			SNew(STextBlock)
			.Text(FText::FromString(InArgs._Test))
			.Font(TitleTextFontInfo)
			.Justification(ETextJustify::Center)
			.ColorAndOpacity(FColor::White)
		]
		+ SVerticalBox::Slot().AutoHeight()
		[
			SNew(STextBlock)
			.Text(FText::FromString(InArgs._Test))
			.Font(TitleTextFontInfo)
			.Justification(ETextJustify::Center)
			.ColorAndOpacity(FColor::White)
		]
	];
}
