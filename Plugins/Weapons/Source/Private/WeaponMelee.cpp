#include "WeaponMelee.h"


AWeaponMelee::AWeaponMelee()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AWeaponMelee::BeginPlay()
{
	Super::BeginPlay();
	
}

void AWeaponMelee::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AWeaponMelee::Attack()
{
	Super::Attack();
}

void AWeaponMelee::PlayHitEffect(const FVector& HitLocation)
{
}

