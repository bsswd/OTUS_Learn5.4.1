// Fill out your copyright notice in the Description page of Project Settings.


#include "Action.h"
#include "ActionComponent.h"

void UAction::StartAction_Implementation(AActor* Instigator)
{
	UE_LOG(LogTemp, Log, TEXT("Start Action: %s"), *GetNameSafe(this));
	UActionComponent* Comp = GetOwningComponent();
	Comp->ActiveTags.AppendTags(GrantTags);
	bIsRunning = true;
	TimeStart = GetWorld()->GetTimeSeconds();
	GetOwningComponent()->OnActionStart.Broadcast(GetOwningComponent(), this);
}

void UAction::StopAction_Implementation(AActor* Instigator)
{
	UE_LOG(LogTemp, Log, TEXT("Stop Action: %s"), *GetNameSafe(this));
	ensureAlways(bIsRunning);
	UActionComponent* Comp = GetOwningComponent();
	Comp->ActiveTags.RemoveTags(GrantTags);
	bIsRunning = false;
	GetOwningComponent()->OnActionStop.Broadcast(GetOwningComponent(), this);
}

bool UAction::CanStart_Implementation(AActor* Instigator)
{
	if (bIsRunning()) return false;
	UActionComponent* Comp = GetOwningComponent();
	return true;
}

bool UAction::IsRunning() const
{
	return bIsRunning;
}

UWorld* UAction::GetWorld() const
{
	UActionComponent* Comp = Cast<UActionComponent>(GetOuter()); 
	if(Comp)
	{
		return Comp->GetWorld();
	}
	return nullptr;
}

UActionComponent* UAction::GetOwningComponent()
{
	return Cast<UActionComponent>(GetOuter()); 
}