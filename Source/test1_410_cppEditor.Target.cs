// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;
using System.Collections.Generic;

public class test1_410_cppEditorTarget : TargetRules
{
	// public test1_410_cppEditorTarget(TargetInfo Target)
	public test1_410_cppEditorTarget(TargetInfo Target) : base (Target)
	{
		Type = TargetType.Editor;

		ExtraModuleNames.AddRange( new string[] { "test1_410_cpp" } );
	}

	// //
	// // TargetRules interface.
	// //

	// public override void SetupBinaries(
	// 	TargetInfo Target,
	// 	ref List<UEBuildBinaryConfiguration> OutBuildBinaryConfigurations,
	// 	ref List<string> OutExtraModuleNames
	// 	)
	// {
	// 	OutExtraModuleNames.AddRange( new string[] { "test1_410_cpp" } );
	// }
}
