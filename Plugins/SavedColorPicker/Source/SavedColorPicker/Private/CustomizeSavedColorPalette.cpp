#include "CustomizeSavedColorPalette.h"
#include "Widgets/Colors/SColorPicker.h"
#include "Widgets/Images/SImage.h"
#include "Widgets/Layout/SBox.h"
#include "Widgets/Text/STextBlock.h"
#include "DetailWidgetRow.h"

TSharedRef<IPropertyTypeCustomization>
FCustomizeSavedColorPalette::MakeInstance()
{
	return MakeShareable(new FCustomizeSavedColorPalette);
}

FCustomizeSavedColorPalette::~FCustomizeSavedColorPalette()
{
}

void FCustomizeSavedColorPalette::MakeHeaderRow(
	TSharedRef<IPropertyHandle>& InStructPropertyHandle, FDetailWidgetRow& Row)
{
	TSharedPtr<SWidget> ColorWidget;
	float ContentWidth = 125.0f;

	TWeakPtr<IPropertyHandle> StructWeakHandlePtr = StructPropertyHandle;

	if (InStructPropertyHandle->HasMetaData("InlineColorPicker"))
	{
		ColorWidget = CreateInlineColorPicker(StructWeakHandlePtr);
		ContentWidth = 492.0f;
	}
	else
	{
		ColorWidget = CreateColorWidget(StructWeakHandlePtr);
	}

	Row.NameContent()[StructPropertyHandle->CreatePropertyNameWidget()].
		ValueContent().MinDesiredWidth(ContentWidth)[SNew(SHorizontalBox)
		+ SHorizontalBox::Slot().AutoWidth()
		[
			ColorWidget.ToSharedRef()
		]
		+ SHorizontalBox::Slot().AutoWidth().VAlign(VAlign_Center)
		[
			CreateTestIcon()
		]];
}

TSharedRef<SWidget> FCustomizeSavedColorPalette::CreateTestIcon()
{
	return SAssignNew(TestIcon, SImage)
		.Image(FAppStyle::GetBrush("Icons.Error"))
		.ToolTipText(INVTEXT("해당 아이콘 노출 시 특정 상황에 의한\n에러 발생으로 간주한다."))
		.Visibility(EVisibility::Visible)
		.DesiredSizeOverride(FVector2D(20.f, 20.f))
		.ColorAndOpacity(FLinearColor::Red);
}
