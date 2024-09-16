#pragma once

#include "CoreMinimal.h"
#include "WeaponBase.h"
#include "WeaponMelee.generated.h"

UCLASS(Blueprintable)
class WEAPONS_API AWeaponMelee : public AWeaponBase
{
	GENERATED_BODY()
//Properties
private:
	//Hit effects
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Effects", meta = (AllowPrivateAccess = true))
	TObjectPtr<UParticleSystem> HitEffectParticles;

	//Hit socket
	UPROPERTY(EditDefaultsOnly, Category = "Hit", meta = (AllowPrivateAccess = true))
	FName HitSocket;
	
public:
	AWeaponMelee();

	//Functions
protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;
	virtual void Attack() override;

private:
	void PlayHitEffect(const FVector& HitLocation);
};
