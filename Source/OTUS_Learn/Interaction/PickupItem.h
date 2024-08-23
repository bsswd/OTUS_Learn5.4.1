// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InteractionInterface.h"
#include "GameFramework/Actor.h"
#include "OTUS_Learn/MainChahracter/MainCharacter.h"
#include "PickupItem.generated.h"


UENUM(BlueprintType)
enum class EItemType : uint8
{
	Health,
	Poison,
	Weapon,
	Armor,
};


UCLASS()
class OTUS_LEARN_API APickupItem : public AActor, public IInteractionInterface
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Settings")
	EItemType ItemType;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Settings",meta = (EditCondition = "ItemType == EItemType::Health", EditConditionHides, ClampMin = 0))
	float HealValue = 50.f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Settings",meta = (EditCondition = "ItemType == EItemType::Health", EditConditionHides, ClampMin = 0))
	float DamageValue = 100.f;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Settings",meta = (EditCondition = "ItemType == EItemType::Armor", EditConditionHides, ClampMin = 0, ClampMax = 1))
	float ArmorValue = 1.f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Settings",meta = (EditCondition = "ItemType == EItemType::Weapon", EditConditionHides))
	TSubclassOf<class AWeaponBase> WeaponClass;

		
public:
	APickupItem();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

	bool Interact_Implementation(AActor* User);	

private:
	bool Pickup(AActor* User);

	bool HealthPickup(AActor* User);

	bool WeaponPickup(AActor* User);
	
	bool ArmorPickup(AActor* User);

	bool PoisonPickup(AActor* User);

};
