#pragma once

#include "CoreMinimal.h"
#include "SavedOptionsData.h"

class SAVEDCOLORPICKER_API FSavedColorPickerDataManager
{
public:
	static FSavedColorPickerDataManager* Get();

	void InitializeSavedData();

private:
	static TUniquePtr<FSavedColorPickerDataManager> This;

	FSaveJsonOptionsData LoadData;
};
