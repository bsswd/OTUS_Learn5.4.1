// OTUS Learn Project. Made by Alex Sinkin (c)

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Data/ItemProperties.h"
#include "HelperFunctionLibrary.generated.h"


class AItemActor;

UCLASS(Abstract, NotBlueprintable, NotBlueprintType, ClassGroup = "Inventory")
class INVENTORY_API UHelperFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Helper Functions|Item Utilities")
	static bool DoesItemExist(FItemStruct Item);

	UFUNCTION(BlueprintCallable, Category = "Helper Functions|Item Utilities")
	static FItemStruct GetItemFromDataTable(UDataTable* InputTable, const FName& RowName);

	UFUNCTION(BlueprintCallable, Category = "Helper Functions", meta = (ReturnDisplayName = "ItemSpawnSucceeded"))
	static bool SpawnItemActor(const FItemStruct InputItem, AActor* OwningActor, TSubclassOf<AItemActor> ItemClass);

	UFUNCTION(BlueprintCallable, Category = "Helper Functions", meta = (ReturnDisplayName = "ValidLocation"))
	static FVector FindItemDropLocation(AActor* ItemActor, float MaxHeight,
		float DropAngle, FVector2D RandomDistance, FVector MeshOffset, float DebugDrawTime);
	
};