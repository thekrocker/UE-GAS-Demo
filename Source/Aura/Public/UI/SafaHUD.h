// Copyright Safa

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "SafaHUD.generated.h"

/**
 * 
 */
UCLASS()
class AURA_API ASafaHUD : public AHUD
{
	GENERATED_BODY()

public:
	virtual void BeginPlay() override;
	
	UPROPERTY()
	TObjectPtr<UUserWidget> WidgetPtr;
	
	UPROPERTY(EditAnywhere, Category= "Widget")
	TSubclassOf<UUserWidget> WidgetClass;
};
