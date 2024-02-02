// Copyright Safa


#include "PlayerCharacter.h"

#include "AbilitySystemComponent.h"
#include "PlayerCharacterState.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/PlayerState.h"

APlayerCharacter::APlayerCharacter()
{
	GetCharacterMovement()-> bOrientRotationToMovement = true;
	GetCharacterMovement()-> RotationRate = FRotator(0.f, 400.f, 0.f);
	GetCharacterMovement()->bConstrainToPlane = true;
	GetCharacterMovement()->bSnapToPlaneAtStart = true;
	
	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;
}

void APlayerCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	// For server
	InitializeAbilityActorInfo();
}

void APlayerCharacter::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();

	// For client
	InitializeAbilityActorInfo();
}

void APlayerCharacter::InitializeAbilityActorInfo()
{
	APlayerCharacterState* State = GetPlayerState<APlayerCharacterState>();
	check(State);
	AbilitySystemComponent = State->GetAbilitySystemComponent();
	AttributeSet = State->AttributeSet;
	State->GetAbilitySystemComponent()->InitAbilityActorInfo(State, this);
}
