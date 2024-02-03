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
	virtual void BindCallbacks() override;

	UPROPERTY(BlueprintAssignable, Category="GAS | Attributes")
	FOnValueChangedSignature OnHealthChanged;
	UPROPERTY(BlueprintAssignable, Category="GAS | Attributes")
	FOnValueChangedSignature OnMaxHealthChanged;

	UPROPERTY(BlueprintAssignable, Category="GAS | Attributes")
	FOnValueChangedSignature OnManaChanged;
	UPROPERTY(BlueprintAssignable, Category="GAS | Attributes")
	FOnValueChangedSignature OnMaxManaChanged;

	void HealthChange(const FOnAttributeChangeData& Data) const;
	void MaxHealthChange(const FOnAttributeChangeData& Data) const;

	void ManaChange(const FOnAttributeChangeData& Data) const;
	void MaxManaChange(const FOnAttributeChangeData& Data) const;
};
