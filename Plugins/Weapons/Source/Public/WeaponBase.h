#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WeaponBase.generated.h"


UCLASS(Abstract, NotBlueprintable)
class WEAPONS_API AWeaponBase : public AActor
{
	GENERATED_BODY()

public:
	AWeaponBase();

	//Properties
protected:
	// Visualisation of weapon
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	TObjectPtr<USkeletalMeshComponent> Mesh;
	
private:
	//Base damage
	UPROPERTY(EditDefaultsOnly, Category = "Damage", meta = (AllowPrivateAccess = true))
	float Damage = 0.1f;

	//Damage type
	UPROPERTY(EditDefaultsOnly, Category = "Damage", meta = (AllowPrivateAccess = true))
	TSubclassOf<UDamageType> DamageTypeClass;

	//Number of attacks per second
	UPROPERTY(EditDefaultsOnly, Category = "Attack", meta = (AllowPrivateAccess = true))
	float AttackSpeed = 2.f;

	
public:
	//Owner of weapon
	TWeakObjectPtr<ACharacter> OwnerCharacter;

	//Functions
protected:
	virtual void BeginPlay() override;
	void ApplyDamageToActor(AActor* TargetActor);

public:
	virtual void Tick(float DeltaTime) override;
	virtual void Attack();
};
  