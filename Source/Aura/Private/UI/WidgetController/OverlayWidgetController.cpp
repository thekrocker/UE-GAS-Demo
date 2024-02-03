// Copyright Safa


#include "UI/WidgetController/OverlayWidgetController.h"
#include "AbilitySystem/SafaAttributeSet.h"

void UOverlayWidgetController::BroadcastInitialValues()
{
	const USafaAttributeSet* SafaAttributeSet = CastChecked<USafaAttributeSet>(AttributeSet);
	
	OnHealthChanged.Broadcast(SafaAttributeSet->GetHealth());
	OnMaxHealthChanged.Broadcast(SafaAttributeSet->GetMaxHealth());
	OnManaChanged.Broadcast(SafaAttributeSet->GetMana());
	OnMaxManaChanged.Broadcast(SafaAttributeSet->GetMaxMana());
}


void UOverlayWidgetController::BindCallbacks()
{
	const USafaAttributeSet* SafaAttributeSet = CastChecked<USafaAttributeSet>(AttributeSet);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(SafaAttributeSet->GetHealthAttribute()).AddUObject(this, &UOverlayWidgetController::HealthChange);
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(SafaAttributeSet->GetMaxHealthAttribute()).AddUObject(this, &UOverlayWidgetController::MaxHealthChange);
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(SafaAttributeSet->GetManaAttribute()).AddUObject(this, &UOverlayWidgetController::ManaChange);
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(SafaAttributeSet->GetMaxManaAttribute()).AddUObject(this, &UOverlayWidgetController::MaxManaChange);
}

// Bind events to the attribute changes
void UOverlayWidgetController::HealthChange(const FOnAttributeChangeData& Data) const
{
	OnHealthChanged.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::MaxHealthChange(const FOnAttributeChangeData& Data) const
{
	OnMaxHealthChanged.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::ManaChange(const FOnAttributeChangeData& Data) const
{
	OnManaChanged.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::MaxManaChange(const FOnAttributeChangeData& Data) const
{
	OnMaxManaChanged.Broadcast(Data.NewValue);
}
