#include "WeaponRanged.h"
#include "Kismet/GameplayStatics.h"


AWeaponRanged::AWeaponRanged()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AWeaponRanged::BeginPlay()
{
	Super::BeginPlay();
}

void AWeaponRanged::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AWeaponRanged::Attack()
{
	Super::Attack();
	PlayMuzzleEffect();
	ShootLineTrace();
}

void AWeaponRanged::ShootLineTrace()
{
	if (ShootStartSocket.IsNone())
	{
		UE_LOG(LogTemp, Warning, TEXT("AWeaponRanged::ShootLineTrace(): ShootStartSocket.IsNone()"));
		return;
	}
	FHitResult HitResult;
	FVector StartTrace = Mesh->GetSocketLocation(ShootStartSocket);
	FVector EndTrace = StartTrace + GetActorRightVector()*10000.f; //Replace hardcode to variable
	GetWorld()->LineTraceSingleByChannel(HitResult, StartTrace, EndTrace, ECC_GameTraceChannel1);

	if (!HitResult.IsValidBlockingHit())
		return;
	
	PlayImpactEffect(HitResult.Location);

	if (AActor* TargetActor = HitResult.GetActor())
	{
		ApplyDamageToActor(TargetActor);
	}
}

void AWeaponRanged::PlayImpactEffect(const FVector& ImpactLocation)
{
	FTransform ParticleTransform;
	ParticleTransform.SetLocation(ImpactLocation);
	UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), ImpactParticles, ParticleTransform);
}

void AWeaponRanged::PlayMuzzleEffect()
{
	FTransform ParticleTransform;
	ParticleTransform.SetLocation(Mesh->GetSocketLocation(ShootStartSocket));
	UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), MuzzleFireParticles, ParticleTransform);
}