using UnrealBuildTool;
using System;
using System.IO;

public class protobuf : ModuleRules
{
	public protobuf(ReadOnlyTargetRules Target): base(Target)
	{
        Type = ModuleType.External;

        PublicSystemIncludePaths.Add(Path.Combine(ModuleDirectory, "include"));
        PublicIncludePaths.Add(Path.Combine(ModuleDirectory, "include"));

        if (Target.Platform == UnrealTargetPlatform.Win64)
        {
            PublicLibraryPaths.Add(Path.Combine(ModuleDirectory, "lib"));
            PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "lib", "libprotobuf.lib"));
        }
        else
        {
            throw new Exception("Currently " + Target.Platform.ToString() + " is unsupported");
        }

        PublicDefinitions.AddRange(
            new string[]
            {
                "GOOGLE_PROTOBUF_NO_RTTI=1",
                "GOOGLE_PROTOBUF_USE_UNALIGNED=0"
            });
    }
}
