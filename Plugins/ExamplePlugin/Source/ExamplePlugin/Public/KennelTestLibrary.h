// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"

#include "KennelAsset.h"

#include "KennelTestLibrary.generated.h"

/**
 * 
 */
UCLASS()
class EXAMPLEPLUGIN_API UKennelTestLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Lists the names of dogs inside a kennel", Keywords = "Kennel doggo list"), Category = "KennelTesting")
	static TArray<FString> KennelDoggoList(UKennelAsset* kennel);
};
