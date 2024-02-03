// Copyright Safa

#pragma once

#include "CoreMinimal.h"
#include "SafaWidgetController.generated.h"

class UAttributeSet;
class UAbilitySystemComponent;

/// Parameters for the widget controller
USTRUCT(BlueprintType)
struct FWidgetControllerParams
{
	GENERATED_BODY()
	
	FWidgetControllerParams() { }
	
	FWidgetControllerParams(APlayerController* APC, APlayerState* PS, UAbilitySystemComponent* ACS, UAttributeSet* AS)
	:
	PlayerController(APC),
	PlayerState(PS),
	AbilitySystemComponent(ACS),
	AttributeSet(AS) { }


	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<APlayerController> PlayerController = nullptr;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<APlayerState> PlayerState = nullptr;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent = nullptr;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UAttributeSet> AttributeSet = nullptr;
};
/**
 * 
 */
UCLASS()
class AURA_API USafaWidgetController : public UObject
{
	GENERATED_BODY()

public:
	virtual void BroadcastInitialValues();
	
	UFUNCTION(BlueprintCallable)
	void SetWidgetControllerParams(const FWidgetControllerParams& InWidgetControllerParams);
	
protected:
	UPROPERTY(BlueprintReadOnly, Category= "Widget Controller")
	TObjectPtr<APlayerController> PlayerController;
	
	UPROPERTY(BlueprintReadOnly, Category= "Widget Controller")
	TObjectPtr<APlayerState> PlayerState;
	
	UPROPERTY(BlueprintReadOnly, Category= "Widget Controller")
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;
	
	UPROPERTY(BlueprintReadOnly, Category= "Widget Controller")
	TObjectPtr<UAttributeSet> AttributeSet;
};
