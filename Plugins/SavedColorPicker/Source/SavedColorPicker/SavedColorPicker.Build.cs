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
				"AppFramework"
			}
		);


		PrivateDependencyModuleNames.AddRange(
			new[]
			{
				"CoreUObject",
				"Engine",
				"SlateCore",
				"DetailCustomizations",
				"PropertyEditor", "Projects", "Json", "JsonUtilities"
			}
		);
	}
}