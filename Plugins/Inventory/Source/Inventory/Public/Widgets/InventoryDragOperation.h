// OTUS Learn Project. Made by Alex Sinkin (c)

#pragma once

#include "CoreMinimal.h"
#include "Data/ItemProperties.h"
#include "Blueprint/DragDropOperation.h"
#include "InventoryDragOperation.generated.h"

class UInventoryComponent;

UCLASS(Blueprintable, BlueprintType, ClassGroup = "Inventory Widgets")
class INVENTORY_API UInventoryDragOperation : public UDragDropOperation
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadOnly, Category = "Inventory Drag Widget")
	UInventoryComponent* WhereItemCameFrom;

	UPROPERTY(BlueprintReadOnly, Category = "Inventory Drag Widget")
	FItemStruct DraggedItem;

	UPROPERTY(BlueprintReadOnly, Category = "Inventory Drag Widget")
	int32 DraggedSlotIndex = -1;
};