// Copyright Safa


#include "EnemyCharacter.h"

#include "AbilitySystemComponent.h"
#include "AbilitySystem/SafaAbilitySystemComponent.h"
#include "AbilitySystem/SafaAttributeSet.h"
#include "Aura/Aura.h"

void AEnemyCharacter::BeginPlay()
{
	Super::BeginPlay();
	AbilitySystemComponent->InitAbilityActorInfo(this, this);
}

AEnemyCharacter::AEnemyCharacter()
{
	GetMesh()->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block);

	// Initialize Ability Component & Attribute Sets
	AbilitySystemComponent = CreateDefaultSubobject<USafaAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Minimal);

	// Attribute sets
	AttributeSet = CreateDefaultSubobject<USafaAttributeSet>("AttributeSet");
}


void AEnemyCharacter::Highlight()
{
	bIsHighlighted = true;
	GetMesh()->SetRenderCustomDepth(true);
	GetMesh()->SetCustomDepthStencilValue(CUSTOM_DEPTH_RED);
	Weapon->SetRenderCustomDepth(true);
	Weapon->SetCustomDepthStencilValue(CUSTOM_DEPTH_RED);
}


void AEnemyCharacter::Unhighlight()
{
	bIsHighlighted = false;
	GetMesh()->SetRenderCustomDepth(false);
	GetMesh()->SetCustomDepthStencilValue(0);
	Weapon->SetRenderCustomDepth(false);
	Weapon->SetCustomDepthStencilValue(0);
}
