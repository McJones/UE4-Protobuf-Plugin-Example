// Fill out your copyright notice in the Description page of Project Settings.


#include "KennelTestLibrary.h"

TArray<FString> UKennelTestLibrary::KennelDoggoList(UKennelAsset * kennel)
{
	return kennel->goodBoys();
}
