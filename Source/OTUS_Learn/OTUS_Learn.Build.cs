// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class OTUS_Learn : ModuleRules
{
	public OTUS_Learn(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[]
		{
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
		});
		
		PrivateDependencyModuleNames.AddRange(new string[]
		{
			"Weapons",
			"Health",
			"Inventory",
			"ActionSystem"
		});
	}
}