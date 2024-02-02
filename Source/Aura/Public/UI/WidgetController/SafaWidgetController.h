// Copyright Safa

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SafaWidgetController.generated.h"

class UAttributeSet;
class UAbilitySystemComponent;
/**
 * 
 */
UCLASS()
class AURA_API USafaWidgetController : public UObject
{
	GENERATED_BODY()
protected:

	UPROPERTY(BlueprintReadOnly, Category= "Widget Controller")
	TObjectPtr<APlayerController> PlayerController;
	
	UPROPERTY(BlueprintReadOnly, Category= "Widget Controller")
	TObjectPtr<APlayerState> PlayerState;
	
	UPROPERTY(BlueprintReadOnly, Category= "Widget Controller")
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;
	
	UPROPERTY(BlueprintReadOnly, Category= "Widget Controller")
	TObjectPtr<UAttributeSet> AttributeSet;
};
