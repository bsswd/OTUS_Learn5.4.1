#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "AsyncLevelLoadSceneComponent.generated.h"

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class ASYNCLEVELLOAD_API UAsyncLevelLoadSceneComponent : public USceneComponent
{
	GENERATED_BODY()
public:
	UAsyncLevelLoadSceneComponent();

	UFUNCTION(BlueprintCallable, Category="AsyncLevelLoad")
	void AsyncLevelLoad(const FString& LevelDir, const FString& LevelName);

	UFUNCTION(BlueprintCallable, Category="AsyncLevelLoad")
	void AsyncLevelLoadByObjRef(TSoftObjectPtr<UWorld> WorldSoftObject);
};
