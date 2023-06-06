// Shoot Them Up Game, All rights reserved.


#include "UI/STUGameDataWidget.h"
#include "STUGameModeBase.h"
#include "Player/STUPlayerState.h"

int32 USTUGameDataWidget::GetKillsNum() const
{
	return GetSTUPlayerState() ? GetSTUPlayerState()->GetKillsNum() : 0;
}

int32 USTUGameDataWidget::GetDeathsNum() const
{
	return GetSTUPlayerState() ? GetSTUPlayerState()->GetDeathsNum() : 0;
}

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

ASTUPlayerState* USTUGameDataWidget::GetSTUPlayerState() const
{
	return GetOwningPlayer() ? Cast<ASTUPlayerState>(GetOwningPlayer()->PlayerState) : nullptr;
}
