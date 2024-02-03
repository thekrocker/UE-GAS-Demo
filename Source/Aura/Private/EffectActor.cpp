// Copyright Safa


#include "EffectActor.h"

#include "AbilitySystemComponent.h"
#include "AbilitySystemInterface.h"
#include "AttributeSet.h"
#include "AbilitySystem/SafaAttributeSet.h"
#include "Components/SphereComponent.h"


// Sets default values
AEffectActor::AEffectActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	// Construct components
	SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComponent"));
	SetRootComponent(SphereComponent);
	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));
	StaticMeshComponent->SetupAttachment(SphereComponent);
}

// Called when the game starts or when spawned
void AEffectActor::BeginPlay()
{
	Super::BeginPlay();

	SphereComponent->OnComponentBeginOverlap.AddDynamic(this, &AEffectActor::OnOverlapBegin);
	SphereComponent->OnComponentEndOverlap.AddDynamic(this, &AEffectActor::OnOverlapEnd);
	
}

void AEffectActor::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (IAbilitySystemInterface * AbilitySystemInterface = Cast<IAbilitySystemInterface>(OtherActor))
	{
		const UAttributeSet* AttributeSet = AbilitySystemInterface->GetAbilitySystemComponent()->GetAttributeSet(UAttributeSet::StaticClass());
		const USafaAttributeSet* SafaAttributeSet = Cast<USafaAttributeSet>(AttributeSet);

		// Since it constant, we cant do that way. We will hack to this.
		// SafaAttributeSet->SetHealth(SafaAttributeSet->GetHealth() - 10.0f);

		// So we cast the const to non-const and then we can change the value. THIS IS HIGHLY BAD PRACTICE. WE WILL CHANGE THIS LATER.
		USafaAttributeSet* NonConstSafaAttributeSet = const_cast<USafaAttributeSet*>(SafaAttributeSet);
		NonConstSafaAttributeSet->SetMana(SafaAttributeSet->GetMana() + 10.0f);
		Destroy();
	}
}

void AEffectActor::OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	
}




