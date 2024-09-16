// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "WeaponWidget.generated.h"


class UTextBlock;

UCLASS()
class OTUS_LEARN_API UWeaponWidget : public UUserWidget
{
	GENERATED_BODY()
	
protected:
	virtual void NativeConstruct() override;
	
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UTextBlock> WeaponName;

private:
	UFUNCTION()
	void UpdateWeapon(FText Name);	
};
