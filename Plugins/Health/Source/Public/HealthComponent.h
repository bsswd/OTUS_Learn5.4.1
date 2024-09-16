#pragma once


#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HealthComponent.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnDeath);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnHealthChange, float, CurrentHealth, float, MaxHealth);


UCLASS( ClassGroup=(Health), meta=(BlueprintSpawnableComponent) )
class HEALTH_API UHealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UHealthComponent();

	UPROPERTY(BlueprintAssignable)
	FOnDeath OnDeath;

	UPROPERTY(BlueprintAssignable)
	FOnHealthChange OnHealthChange;

protected:
	virtual void BeginPlay() override;


public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION()
	void TakeAnyDamage(AActor* DamagedActor, float Damage, const class UDamageType* DamageType, class AController* InstigatedBy, AActor* DamageCauser);
		
	UFUNCTION(BlueprintCallable)
	void ReceiveDamage(float Damage);

	UFUNCTION(BlueprintCallable)
	bool Heal(float HealValue);

	UFUNCTION(BlueprintCallable)
	bool ChangeArmorValue(float ArmorValue);

	UFUNCTION(BlueprintCallable)
	FORCEINLINE float GetCurrentHealth() const { return CurrentHealth; }
	
	UFUNCTION(BlueprintCallable)
	FORCEINLINE float GetMaxHealth() const { return MaxHealth; }
	
	UFUNCTION(BlueprintCallable)
	FORCEINLINE bool IsDead() const { return bDead; }

	UFUNCTION(BlueprintCallable)
	void SetMaxHealth(float NewMaxHealth);

private:
	void Death();

	UPROPERTY(EditAnywhere, Category = "Health", meta = (AllowPrivateAccess = "true"))
	float MaxHealth = 100.f;

	UPROPERTY(EditAnywhere, Category = "Death", meta = (AllowPrivateAccess = "true"))
	bool bDestroyActorOnDeath = false;

	float CurrentHealth;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Health", meta = (AllowPrivateAccess = "true", ClampMin = 0, ClampMax = 1))
	float CurrentArmorValue;

	bool bDead = false;
};