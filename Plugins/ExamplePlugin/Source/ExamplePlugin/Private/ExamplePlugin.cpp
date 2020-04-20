// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "ExamplePlugin.h"
#include "Doggo.pb.h"

#define LOCTEXT_NAMESPACE "FExamplePluginModule"

void FExamplePluginModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	Doggo goodBoy;
	goodBoy.set_name("Bork Bork");
	goodBoy.set_age(3);
	goodBoy.set_goodboyness(1);

	FString name = FString(goodBoy.name().c_str());

	UE_LOG(LogTemp, Warning, TEXT("Who's a good boy? %s is!"), *name);
}

void FExamplePluginModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FExamplePluginModule, ExamplePlugin)