#pragma once

#include "Modules/ModuleManager.h"

class FSavedColorPickerModule : public IModuleInterface
{
public:
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

	FName PropertyEditor;
};
