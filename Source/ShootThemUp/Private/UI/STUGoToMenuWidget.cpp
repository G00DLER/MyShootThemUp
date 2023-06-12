// Shoot Them Up Game, All rights reserved.


#include "UI/STUGoToMenuWidget.h"
#include "STUGameInstance.h"
#include "Kismet/GameplayStatics.h"
#include "Components/Button.h"

DEFINE_LOG_CATEGORY_STATIC(LogSTUGoToMenuWidget, All, All)

void USTUGoToMenuWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	if (GoMenuButton)
	{
		GoMenuButton->OnClicked.AddDynamic(this, &USTUGoToMenuWidget::OnGoToMenu);
	}
}

void USTUGoToMenuWidget::OnGoToMenu()
{
	if (!GetWorld()) return;

	const auto STUGameInstance = GetWorld()->GetGameInstance<USTUGameInstance>();
	if (!STUGameInstance) return;

	if (STUGameInstance->GetMenuLevelName().IsNone())
	{
		UE_LOG(LogSTUGoToMenuWidget, Error, TEXT("Level name is NONE"));
		return;
	}

	UGameplayStatics::OpenLevel(this, STUGameInstance->GetMenuLevelName());
}
