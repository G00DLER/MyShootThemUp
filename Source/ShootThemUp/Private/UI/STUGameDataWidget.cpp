// Shoot Them Up Game, All rights reserved.


#include "UI/STUGameDataWidget.h"
#include "STUGameModeBase.h"

int32 USTUGameDataWidget::GetCurrentRound() const
{
	return GetSTUGameMode() ? GetSTUGameMode()->GetCurrentRoundNum() : 0;
}

int32 USTUGameDataWidget::GetTotalRoundsNum() const
{
	return GetSTUGameMode() ? GetSTUGameMode()->GetGameData().RoundsNum : 0;
}

int32 USTUGameDataWidget::GetCurrentSeconds() const
{
	return GetSTUGameMode() ? GetSTUGameMode()->GetRoundSecondsRemaining() : 0;
}

ASTUGameModeBase* USTUGameDataWidget::GetSTUGameMode() const
{
	return GetWorld() ? Cast<ASTUGameModeBase>(GetWorld()->GetAuthGameMode()) : nullptr;
}
