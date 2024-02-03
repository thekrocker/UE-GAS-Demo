// Copyright Safa

#pragma once

#include "CoreMinimal.h"
#include "SafaWidgetController.h"
#include "OverlayWidgetController.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnValueChangedSignature, float, NewValue);

/**
 * 
 */
UCLASS(BlueprintType, Blueprintable)
class AURA_API UOverlayWidgetController : public USafaWidgetController
{
	GENERATED_BODY()

public:
	virtual void BroadcastInitialValues() override;

	UPROPERTY(BlueprintAssignable, Category="GAS | Attributes")
	FOnValueChangedSignature OnHealthChanged;
	UPROPERTY(BlueprintAssignable, Category="GAS | Attributes")
	FOnValueChangedSignature OnMaxHealthChanged;
};
