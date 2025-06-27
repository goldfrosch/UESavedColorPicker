// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class SavedColorPickerExam : ModuleRules
{
	public SavedColorPickerExam(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new[]
			{ "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });

		PrivateDependencyModuleNames.AddRange(new[] { "SavedColorPicker" });
	}
}