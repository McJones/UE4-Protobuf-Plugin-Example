// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Doggo.pb.h"
#include "KennelAsset.generated.h"

/**
 * 
 */
UCLASS(BlueprintType, hidecategories = (Object))
class EXAMPLEPLUGIN_API UKennelAsset : public UObject
{
	GENERATED_BODY()

public:
	Kennel kennelData;
	bool parse(const uint8*& Buffer, size_t length);
	TArray<FString> goodBoys();
};
