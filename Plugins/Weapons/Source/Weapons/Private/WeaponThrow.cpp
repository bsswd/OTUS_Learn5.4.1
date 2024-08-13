#include "WeaponThrow.h"


AWeaponThrow::AWeaponThrow()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AWeaponThrow::BeginPlay()
{
	Super::BeginPlay();
}

void AWeaponThrow::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AWeaponThrow::Attack()
{
	Super::Attack();
}


