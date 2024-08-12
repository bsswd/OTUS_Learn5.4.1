// OTUS Learn Project. Made by Alex Sinkin (c)

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Logging/LogMacros.h"
#include "CharacterBase.generated.h"



UCLASS(config = Game)

class ACharacterBase : public ACharacter
{
	GENERATED_BODY()

public:

	ACharacterBase();

	//Character Weapon 
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Component")
	class USkeletalMeshComponent* Weapon;

	//Character Stats: health, damage amount, dead or not (for AI) 
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Stats")
	float Health = 100.f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Stats")
	float BaseDamage = 0.01f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AI")
	bool IsDead = false;

protected:

	virtual void BeginPlay() override;

	//Character movement
	UFUNCTION(BlueprintCallable)
	void MoveForward(float Value);

	UFUNCTION(BlueprintCallable)
	void MoveRight(float Value);

	UFUNCTION(BlueprintCallable)
	void LookUp(float Value);

	UFUNCTION(BlueprintCallable)
	void Turn(float Value);
};