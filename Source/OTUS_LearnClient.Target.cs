// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class OTUS_LearnClientTarget : TargetRules
{
	public OTUS_LearnClientTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Client;
		DefaultBuildSettings = BuildSettingsVersion.V5;
		IncludeOrderVersion = EngineIncludeOrderVersion.Unreal5_4;
        RegisterModulesCreatedByRider();
	}

    private void RegisterModulesCreatedByRider()
    {
	    ExtraModuleNames.AddRange(new string[] { "CustomConfig" });
    }
}