#include "AsyncLevelLoadSceneComponent.h"
#include "UObject/UObjectGlobals.h"
#include "Kismet/GameplayStatics.h"


UAsyncLevelLoadSceneComponent::UAsyncLevelLoadSceneComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAsyncLevelLoadSceneComponent::AsyncLevelLoad(const FString& LevelDir, const FString& LevelName)
{
	LoadPackageAsync(LevelDir+LevelName,
		FLoadPackageAsyncDelegate::CreateLambda([this, LevelDir, LevelName](const FName& PackageName, UPackage*
		LoadPackage, EAsyncLoadingResult::Type Result)
		{
			if (Result == EAsyncLoadingResult::Succeeded)
			{
				UGameplayStatics::OpenLevel(this, FName(*(LevelDir+LevelName)));
			}
		}
		),
		0, PKG_ContainsMap);
}

void UAsyncLevelLoadSceneComponent::AsyncLevelLoadByObjRef(TSoftObjectPtr<UWorld> WorldSoftObject)
{
	FString LevelPath = WorldSoftObject.ToString();
	LoadPackageAsync(LevelPath,
		FLoadPackageAsyncDelegate::CreateLambda([this, WorldSoftObject](const FName& PackageName, UPackage*
		LoadPackage, EAsyncLoadingResult::Type Result)
		{
			if (Result == EAsyncLoadingResult::Succeeded)
			{
				UGameplayStatics::OpenLevelBySoftObjectPtr(this,WorldSoftObject);
			}
		}
		),
		0, PKG_ContainsMap);
}




