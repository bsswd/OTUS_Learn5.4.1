// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "GameHUD.generated.h"


class UMainInterfaceWidget;

UCLASS()
class OTUS_LEARN_API AGameHUD : public AHUD
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable)
	void ShowMainInterface();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UMainInterfaceWidget> InterfaceWidgetClass;

private:
	TObjectPtr<UMainInterfaceWidget> InterfaceWidget;

};