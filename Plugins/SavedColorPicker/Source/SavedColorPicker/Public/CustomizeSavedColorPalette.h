#pragma once

#include "CoreMinimal.h"
#include "Customizations/ColorStructCustomization.h"

class SAVEDCOLORPICKER_API FCustomizeSavedColorPalette
	: public FColorStructCustomization
{
public:
	static TSharedRef<IPropertyTypeCustomization> MakeInstance();

	virtual ~FCustomizeSavedColorPalette() override;

protected:
	virtual void MakeHeaderRow(
		TSharedRef<IPropertyHandle>& InStructPropertyHandle
		, FDetailWidgetRow& Row) override;

	TSharedRef<SWidget> CreateTestIcon();

	TSharedPtr<SImage> TestIcon;
};
