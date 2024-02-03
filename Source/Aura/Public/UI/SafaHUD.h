// Copyright Safa

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "SafaHUD.generated.h"

class USafaUserWidget;
class UAttributeSet;
class UAbilitySystemComponent;
struct FWidgetControllerParams;
class UOverlayWidgetController;
/**
 * 
 */
UCLASS()
class AURA_API ASafaHUD : public AHUD
{
	GENERATED_BODY()

public:

	void InitializeOverlay(APlayerController* APC, APlayerState* PS, UAbilitySystemComponent* ACS, UAttributeSet* AS);

	// Create if doesnt exist, otherwise return the widget
	UOverlayWidgetController* GetOverlayWidgetController(const FWidgetControllerParams& InWidgetControllerParams);
	
	UPROPERTY()
	TObjectPtr<USafaUserWidget> WidgetPtr;
	
	UPROPERTY(EditAnywhere, Category= "Widget")
	TSubclassOf<UUserWidget> WidgetClass;

	UPROPERTY()
	TObjectPtr<UOverlayWidgetController> OverlayWidgetController;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UOverlayWidgetController> OverlayWidgetControllerClass;
};
