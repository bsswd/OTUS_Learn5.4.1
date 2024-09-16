#include "WeaponBase.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Character.h"


AWeaponBase::AWeaponBase()
{
	PrimaryActorTick.bCanEverTick = true;
	Mesh = CreateDefaultSubobject<USkeletalMeshComponent>("Mesh");
	RootComponent = Mesh;
}

void AWeaponBase::BeginPlay()
{
	Super::BeginPlay();
}

void AWeaponBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AWeaponBase::ApplyDamageToActor(AActor* TargetActor)
{
	if (auto Controller = OwnerCharacter->GetController())
	{
		UGameplayStatics::ApplyDamage(TargetActor, Damage, Controller, this, DamageTypeClass);
	}
}

void AWeaponBase::Attack()
{
	
}

