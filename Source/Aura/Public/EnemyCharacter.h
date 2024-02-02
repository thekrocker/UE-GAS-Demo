// Copyright Safa

#pragma once

#include "CoreMinimal.h"
#include "CharacterBase.h"
#include "Interfaces/EnemyInterface.h"
#include "EnemyCharacter.generated.h"

/**
 * 
 */
UCLASS()
class AURA_API AEnemyCharacter : public ACharacterBase, public IEnemyInterface
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;
public:
	AEnemyCharacter();
	virtual void Highlight() override;
	virtual void Unhighlight() override;

	UPROPERTY(BlueprintReadOnly)
	bool bIsHighlighted = false;
};
