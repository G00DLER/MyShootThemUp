// Shoot Them Up Game, All rights reserved.


#include "UI/STUGameOverWidget.h"
#include "STUGameModeBase.h"
#include "STUPlayerState.h"
#include "STUUtils.h"
#include "UI/STUPlayerStatRowWidget.h"
#include "Components/VerticalBox.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"

void USTUGameOverWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();
	
	if (GetWorld())
	{
		const auto GameMode = Cast<ASTUGameModeBase>(GetWorld()->GetAuthGameMode());
		if (GameMode)
		{
			GameMode->OnMatchStateChanged.AddUObject(this, &USTUGameOverWidget::OnMatchStateChanged);
		}
	}

	if (RestartLevelButton)
	{
		RestartLevelButton->OnClicked.AddDynamic(this, &USTUGameOverWidget::OnRestartLevel);
	}
}

void USTUGameOverWidget::OnMatchStateChanged(ESTUMatchState State)
{
	if (State == ESTUMatchState::GameOver)
	{
		UpdatePlayersStat();
	}
}

void USTUGameOverWidget::UpdatePlayersStat()
{
	if (!GetWorld() || !PlayerStatBox) return;

	PlayerStatBox->ClearChildren();

	for (auto It = GetWorld()->GetControllerIterator(); It; It++)
	{
		const auto Controller = It->Get();
		if (!Controller) continue;

		const auto PlayerState = Cast<ASTUPlayerState>(Controller->PlayerState);
		if (!PlayerState) continue;

		const auto PlayerStatRowWidget = CreateWidget<USTUPlayerStatRowWidget>(GetWorld(), PlayerStatRowWidgetClass);
		if (!PlayerStatRowWidget) continue;

		PlayerStatRowWidget->SetPlayerName(FText::FromString(PlayerState->GetPlayerName()));
		PlayerStatRowWidget->SetKills(STUUtils::TextFromInt(PlayerState->GetKillsNum()));
		PlayerStatRowWidget->SetDeaths(STUUtils::TextFromInt(PlayerState->GetDeathsNum()));
		PlayerStatRowWidget->SetTeam(STUUtils::TextFromInt(PlayerState->GetTeamID()));
		PlayerStatRowWidget->SetPlayerIndicatorVisibility(Controller->IsPlayerController());
		PlayerStatRowWidget->SetColorTeam(PlayerState->GetTeamColor());

		PlayerStatBox->AddChild(PlayerStatRowWidget);
	}
}

void USTUGameOverWidget::OnRestartLevel()
{
	const FString CurrentLevelName = UGameplayStatics::GetCurrentLevelName(this);
	UGameplayStatics::OpenLevel(this, FName(CurrentLevelName));
}
