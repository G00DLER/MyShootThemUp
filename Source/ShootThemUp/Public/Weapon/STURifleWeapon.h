// Shoot Them Up Game, All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Weapon/STUBaseWeapon.h"
#include "STURifleWeapon.generated.h"

class USTUWeaponFXComponent;
class UNiagaraComponent;
class UNiagaraSystem;
class UAudioComponent;

/**
 * 
 */
UCLASS()
class SHOOTTHEMUP_API ASTURifleWeapon : public ASTUBaseWeapon
{
	GENERATED_BODY()

public:
	ASTURifleWeapon();
	
	virtual void StartFire() override;
	virtual void StopFire() override;

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Weapon")
	float TimeBetweenShots = 0.2f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Weapon")
	float BulletSpread = 1.5f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Weapon", meta = (ClampMin = "1.0", ClampMax = "50.0"))
	float HitWeaponDamage = 10.0f;

	UPROPERTY(VisibleAnywhere, Category = "VFX")
	USTUWeaponFXComponent* WeaponFXComponent;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "VFX")
	UNiagaraSystem* TraceFX;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "VFX")
	FString TraceTargetName = "TraceTarget";

	virtual void BeginPlay() override;
	virtual void MakeShot() override;
	virtual bool GetTraceData(FVector& TraceStart, FVector& TraceEnd) const override;

private:
	FTimerHandle ShotTimerHandle;

	UPROPERTY()
	UNiagaraComponent* MuzzleFXComponent;

	UPROPERTY()
	UAudioComponent* FireAudioComponent;

	void MakeDamage(const FHitResult& HitResult);
	void InitFX();
	void SetFXActive(bool IsActive);
	void SpawnTraceFX(const FVector& TraceStart, const FVector& TraceEnd);

	AController* GetController() const;
};
