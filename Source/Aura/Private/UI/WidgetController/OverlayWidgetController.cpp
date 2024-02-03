// Copyright Safa


#include "UI/WidgetController/OverlayWidgetController.h"
#include "AbilitySystem/SafaAttributeSet.h"

void UOverlayWidgetController::BroadcastInitialValues()
{
	const USafaAttributeSet* SafaAttributeSet = CastChecked<USafaAttributeSet>(AttributeSet);
	
	OnHealthChanged.Broadcast(SafaAttributeSet->GetHealth());
	OnMaxHealthChanged.Broadcast(SafaAttributeSet->GetMaxHealth());
}
