#pragma once

#include "CoreMinimal.h"
#include "WeaponBase.h"
#include "WeaponThrow.generated.h"

UCLASS(Blueprintable)
class WEAPONS_API AWeaponThrow : public AWeaponBase
{
	GENERATED_BODY()
	//Properties
private:
	//Hit effects
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Effects", meta = (AllowPrivateAccess = true))
	TObjectPtr<UParticleSystem> HitEffectParticles;

	//Hit location - add property!
	

public:
	AWeaponThrow();

	//Functions
protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;
	virtual void Attack() override;

};
