// Fill out your copyright notice in the Description page of Project Settings.


#include "OTUS_Learn/Interaction/PickupItem.h"
#include "HealthComponent.h"


APickupItem::APickupItem()
{
	PrimaryActorTick.bCanEverTick = true;
}

void APickupItem::BeginPlay()
{
	Super::BeginPlay();
}

void APickupItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

bool APickupItem::Interact_Implementation(AActor* User)
{
	if (!User)
		return false;
	
	return Pickup(User);
}

bool APickupItem::Pickup(AActor* User)
{
	switch (ItemType)
	{
	case EItemType::Health:
		{
			return HealthPickup(User);
		}
	case EItemType::Weapon:
		{
			WeaponPickup(User);
		}
	case EItemType::Armor:
		{
			return ArmorPickup(User);
		}
	case EItemType::Poison:
		{
			return PoisonPickup(User);
		}
	}
	
	return false;
}

bool APickupItem::HealthPickup(AActor* User)
{
	auto HealthComponent = User->FindComponentByClass<UHealthComponent>();
	if (!HealthComponent)
		return false;
	
	if (HealthComponent->Heal(HealValue))
	{
		Destroy();
		return true;
	}
	else
	{
		return false;
	}
}

bool APickupItem::WeaponPickup(AActor* User)
{
	GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Yellow, FString::Printf(TEXT("Pick up weapon")));

	// Not working, need help
	/*
	TSubclassOf<AWeaponBase> PickupedWeapon = User->GetOwner->DefaultWeaponClass;
	PickupedWeapon = WeaponClass;
	*/
	
	Destroy();
	return true;
}

bool APickupItem::ArmorPickup(AActor* User)
{
	auto HealthComponent = User->FindComponentByClass<UHealthComponent>();
	if (!HealthComponent)
		return false;
	
	if (HealthComponent->ChangeArmorValue(ArmorValue))
	{
		Destroy();
		return true;
	}
	else
	{
		return false;
	}
}

bool APickupItem::PoisonPickup(AActor* User)
{
	auto HealthComponent = User->FindComponentByClass<UHealthComponent>();
	if (!HealthComponent)
		return false;
	
	HealthComponent->ReceiveDamage(HealthComponent->GetCurrentHealth());
	Destroy();
	return true;
}
