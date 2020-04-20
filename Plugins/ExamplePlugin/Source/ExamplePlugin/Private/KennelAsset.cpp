// Fill out your copyright notice in the Description page of Project Settings.


#include "KennelAsset.h"

TArray<FString> UKennelAsset::goodBoys()
{
	TArray<FString> nodes;

	for (auto& dog : kennelData.goodboys())
	{
		nodes.Emplace(FString(dog.name().c_str()));
	}

	return nodes;
}

// returns true if the buffer could be parsed into a valid program
bool UKennelAsset::parse(const uint8*& Buffer, size_t length)
{
	if (kennelData.ParseFromArray(Buffer, length))
	{
		UE_LOG(LogTemp, Warning, TEXT("Kennel parsing success"));
		return true;
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Kennel parsing failed"));
		return false;
	}
}
