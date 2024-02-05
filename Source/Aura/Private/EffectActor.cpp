// Copyright Safa


#include "EffectActor.h"

#include "AbilitySystemComponent.h"
#include "AbilitySystemInterface.h"
#include "AttributeSet.h"
#include "AbilitySystem/SafaAttributeSet.h"
#include "Components/SphereComponent.h"
#include "AbilitySystemBlueprintLibrary.h"


// Sets default values
AEffectActor::AEffectActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	// Construct components
	SetRootComponent(CreateDefaultSubobject<USceneComponent>("RootComponent"));
}

// Called when the game starts or when spawned
void AEffectActor::BeginPlay()
{
	Super::BeginPlay();
}

void AEffectActor::ApplyEffectToTarget(AActor* Actor, TSubclassOf<UGameplayEffect> Effect)
{
	UAbilitySystemComponent* ACS = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(Actor);
	if (ACS == nullptr) return;

	const FGameplayEffectSpecHandle SpecHandle = ACS->MakeOutgoingSpec(Effect, 1, ACS->MakeEffectContext());
	ACS->ApplyGameplayEffectSpecToSelf(*SpecHandle.Data);
}






