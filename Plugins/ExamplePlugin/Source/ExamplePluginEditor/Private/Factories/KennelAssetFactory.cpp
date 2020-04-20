#include "KennelAssetFactory.h"

#include "Containers/UnrealString.h"
#include "KennelAsset.h"


/* UKennelAssetFactory structors
 *****************************************************************************/

UKennelAssetFactory::UKennelAssetFactory( const FObjectInitializer& ObjectInitializer ) : Super(ObjectInitializer)
{
	Formats.Add(FString(TEXT("knl;")) + NSLOCTEXT("UKennelAssetFactory", "FormatKennel", "Compiled Kennel File").ToString());
	SupportedClass = UKennelAsset::StaticClass();
	bCreateNew = false;
	bEditorImport = true;
}

UObject* UKennelAssetFactory::FactoryCreateBinary(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags, UObject* Context, const TCHAR* Type, const uint8*& Buffer, const uint8* BufferEnd, FFeedbackContext * Warn, bool & bOutOperationCanceled)
{
	UKennelAsset* asset = nullptr;

	asset = NewObject<UKennelAsset>(InParent, InClass, InName, Flags);
	bool success = asset->parse(Buffer, BufferEnd - Buffer);

	if (success == true)
	{
		bOutOperationCanceled = false;
	}
	else
	{
		asset = nullptr;
		bOutOperationCanceled = true;
	}

	return asset;
}