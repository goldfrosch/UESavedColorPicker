#pragma once

#include "CoreMinimal.h"
#include "CustomizeSavedColorPalette.h"


class SAVEDCOLORPICKER_API FSlateCustomizeSavedColorPalette
	: public FCustomizeSavedColorPalette
{
public:
	static TSharedRef<IPropertyTypeCustomization> MakeInstance();

	virtual void CustomizeHeader(TSharedRef<IPropertyHandle> PropertyHandle
								, FDetailWidgetRow& HeaderRow
								, IPropertyTypeCustomizationUtils&
								CustomizationUtils) override;
	virtual void MakeHeaderRow(
		TSharedRef<IPropertyHandle>& InStructPropertyHandle
		, FDetailWidgetRow& Row) override;
};
