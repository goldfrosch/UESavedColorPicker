// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class SavedColorPicker : ModuleRules
{
	public SavedColorPicker(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(
			new[]
			{
				"Core",
				"Slate",
				"DetailCustomizations",
				"PropertyEditor",
				"AppFramework"
			}
		);


		PrivateDependencyModuleNames.AddRange(
			new[]
			{
				"CoreUObject",
				"Engine",
				"SlateCore"
			}
		);
	}
}