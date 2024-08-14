#pragma once

#include "CoreMinimal.h"
#include "WeaponBase.h"
#include "WeaponRanged.generated.h"


UCLASS(Blueprintable)
class WEAPONS_API AWeaponRanged : public AWeaponBase
{
	GENERATED_BODY()

	//Properties
private:
	//Firing effects, flashes etc
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Effects", meta = (AllowPrivateAccess = true))
	TObjectPtr<UParticleSystem> MuzzleFireParticles;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Effects", meta = (AllowPrivateAccess = true))
	TObjectPtr<UParticleSystem> ImpactParticles;

	//Muzzle socket
	UPROPERTY(EditDefaultsOnly, Category = "Shooting", meta = (AllowPrivateAccess = true))
	FName ShootStartSocket;

	//Ammo capacity
	UPROPERTY(EditDefaultsOnly, Category = "AmmoCapacity", meta = (AllowPrivateAccess = true))
	int AmmoCapacity = 0;

public:
	AWeaponRanged();

	//Functions
protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;
	virtual void Attack() override;

private:
	void ShootLineTrace();
	void PlayImpactEffect(const FVector& ImpactLocation);
	void PlayMuzzleEffect();
};