#pragma once

#include "CoreMinimal.h"

class SAVEDCOLORPICKER_API SColorPickerEditorOptionsTab : public SCompoundWidget
{
	SLATE_BEGIN_ARGS(SColorPickerEditorOptionsTab)
		{
		}

		SLATE_ARGUMENT(FString, Test)
	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs);
};
