// Shoot Them Up Game, All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "STUGameDataWidget.generated.h"

class ASTUPlayerState;
class ASTUGameModeBase;

UCLASS()
class SHOOTTHEMUP_API USTUGameDataWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "UI")
	int32 GetKillsNum() const;

	UFUNCTION(BlueprintCallable, Category = "UI")
	int32 GetDeathsNum() const;

	UFUNCTION(BlueprintCallable, Category = "UI")
	int32 GetCurrentRound() const;

	UFUNCTION(BlueprintCallable, Category = "UI")
	int32 GetTotalRoundsNum() const;

	UFUNCTION(BlueprintCallable, Category = "UI")
	int32 GetCurrentSeconds() const;

private:
	ASTUGameModeBase* GetSTUGameMode() const;
	ASTUPlayerState* GetSTUPlayerState() const;
};
