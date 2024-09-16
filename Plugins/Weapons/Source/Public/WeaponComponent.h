#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "WeaponComponent.generated.h"

class AWeaponBase;

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnTakeWeapon);

UCLASS(ClassGroup=(Weapon), meta=(BlueprintSpawnableComponent))
class WEAPONS_API UWeaponComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UWeaponComponent();

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<AWeaponBase> DefaultWeaponClass;

	UPROPERTY(EditDefaultsOnly)
	FName WeaponAttachSocketName;
	
	UPROPERTY(BlueprintAssignable)
	FOnTakeWeapon OnTakeWeapon;

protected:
	virtual void BeginPlay() override;

public:
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void EquipDefaultWeapon();
	TObjectPtr<AWeaponBase> EquippedWeapon;	
};
