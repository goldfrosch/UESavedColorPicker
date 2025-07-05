#pragma once

#include "CoreMinimal.h"

USTRUCT()
struct SAVEDCOLORPICKER_API FSaveJsonOptionsData
{
	GENERATED_USTRUCT_BODY()

	FString& GetVersion() { return Version; }

private:
	UPROPERTY()
	FString Version;
};
