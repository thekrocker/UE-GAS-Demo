// Copyright Safa

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EffectActor.generated.h"

class UGameplayEffect;
class USphereComponent;

UCLASS()
class AURA_API AEffectActor : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AEffectActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category= "Effect")
	TSubclassOf<UGameplayEffect> EffectClass;

	UFUNCTION(BlueprintCallable)
	void ApplyEffectToTarget(AActor* Actor, TSubclassOf<UGameplayEffect> Effect);
};
