// Fill out your copyright notice in the Description page of Project Settings.

#include "ActionComponent.h"


UActionComponent::UActionComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UActionComponent::AddAction(AActor* Instigator, TSubclassOf<UAction> ActionClass)
{
}

void UActionComponent::RemoveAction(UAction* ActionToRemove)
{
}

void UActionComponent::GetActionByName(FName ActionName)
{
}

bool UActionComponent::StartActionByName(AActor* Instigator, FName ActionName)
{
}

bool UActionComponent::StopActionByName(AActor* Instigator, FName ActionName)
{
}


void UActionComponent::BeginPlay()
{
	Super::BeginPlay();
}