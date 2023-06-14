// Shoot Them Up Game, All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "STUCoreTypes.h"
#include "STUGameInstance.generated.h"

UCLASS()
class SHOOTTHEMUP_API USTUGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	void SetStartupLevel(const FLevelData& Data) { StartupLevel = Data; }
	FLevelData GetStartupLevel() const { return StartupLevel; }

	TArray<FLevelData> GetLevelsData() const { return LevelsData; }
	
	FName GetMenuLevelName() const { return MenuLevelName; }
	
protected:
	UPROPERTY(EditDefaultsOnly, Category = "Game")
	TArray<FLevelData> LevelsData;

	UPROPERTY(EditDefaultsOnly, Category = "Game")
	FName MenuLevelName = NAME_None;

private:
	FLevelData StartupLevel;
};
