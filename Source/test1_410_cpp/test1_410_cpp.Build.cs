// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;
using System.IO;

public class test1_410_cpp : ModuleRules
{
	// private string ModulePath
	// {
	// 	get { return Path.GetDirectoryName(RulesCompiler.GetModuleFilename(this.GetType().Name)); }
	// }
	
	// private string ThirdPartyPath
	// {
	// 	get { return Path.GetFullPath(Path.Combine(ModulePath, "../../ThirdParty/")); }
	// }
	
	// public bool LoadIAPLib(TargetInfo Target)
	// {
	// 	bool isLibrarySupported = false;
		
	// 	if (Target.Platform == UnrealTargetPlatform.IOS)
	// 	{
	// 		isLibrarySupported = true;
	// 		string LibrariesPath = Path.Combine(ThirdPartyPath, "IAPLib", "Libraries");
	// 		PublicAdditionalLibraries.Add(Path.Combine(LibrariesPath, "PluginIAP.a"));
	// 		PublicAdditionalLibraries.Add(Path.Combine(LibrariesPath, "sdkbox.a"));
			
	// 		PublicFrameworks.AddRange(new string[] { 
	// 			"SystemConfiguration",
	// 			"Security"
	// 		});
	// 	}
	// 	else if (Target.Platform == UnrealTargetPlatform.Android)
	// 	{
	// 		isLibrarySupported = true;
	// 		//string LibrariesPath = Path.Combine(ThirdPartyPath, "IAPLib", "Libraries");
	// 	}
		
	// 	if (isLibrarySupported)
	// 	{
	// 		// Include path
	// 		PublicIncludePaths.Add(Path.Combine(ThirdPartyPath, "IAPLib", "Includes"));
	// 	}
		
	// 	Definitions.Add(string.Format("SDKBOX_IAP_ENABLED={0}", isLibrarySupported ? 1 : 0));
		
	// 	return isLibrarySupported;
	// }

	public test1_410_cpp(TargetInfo Target)
	{
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore" });

		PrivateDependencyModuleNames.AddRange(new string[] {  });

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });
		
		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");
		// if ((Target.Platform == UnrealTargetPlatform.Win32) || (Target.Platform == UnrealTargetPlatform.Win64))
		// {
		//		if (UEBuildConfiguration.bCompileSteamOSS == true)
		//		{
		//			DynamicallyLoadedModuleNames.Add("OnlineSubsystemSteam");
		//		}
		// }

		//LoadIAPLib(Target);
	}
}
