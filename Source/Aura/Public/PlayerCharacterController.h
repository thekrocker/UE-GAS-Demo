// Copyright Safa

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "InputAction.h"
#include "PlayerCharacterController.generated.h"


class UInputMappingContext;
class UInputAction;
struct FInputActionValue;
class IEnemyInterface;

/**
 * 
 */
UCLASS()
class AURA_API APlayerCharacterController : public APlayerController
{
	GENERATED_BODY()

public:
	APlayerCharacterController();

protected:
	virtual void BeginPlay() override;
	virtual void PlayerTick(float DeltaTime) override;
	virtual void SetupInputComponent() override;

private:
	
	UPROPERTY(EditAnywhere, Category= "Input")
	TObjectPtr<UInputMappingContext> PlayerInputContext;

	UPROPERTY(EditAnywhere, Category= "Input")
	TObjectPtr<UInputAction> MoveAction;

	void Move(const FInputActionValue& Value);
	void CursorTrace();

	IEnemyInterface* LastEnemy;
	IEnemyInterface* CurrentEnemy;
	
};
