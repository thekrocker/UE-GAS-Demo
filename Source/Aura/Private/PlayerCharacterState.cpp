// Copyright Safa


#include "PlayerCharacterState.h"

#include "AbilitySystemComponent.h"
#include "AbilitySystem/SafaAbilitySystemComponent.h"
#include "AbilitySystem/SafaAttributeSet.h"


APlayerCharacterState::APlayerCharacterState()
{
	// Initialize Ability Component & Attribute Sets
	AbilitySystemComponent = CreateDefaultSubobject<USafaAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);

	// Attribute sets
	AttributeSet = CreateDefaultSubobject<USafaAttributeSet>("AttributeSet");
}

UAbilitySystemComponent* APlayerCharacterState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}
