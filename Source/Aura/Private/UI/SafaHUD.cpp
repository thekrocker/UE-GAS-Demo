// Copyright Safa


#include "UI/SafaHUD.h"
#include "Blueprint/UserWidget.h"
#include "UI/Widget/SafaUserWidget.h"
#include "UI/WidgetController/OverlayWidgetController.h"


void ASafaHUD::InitializeOverlay(APlayerController* APC, APlayerState* PS, UAbilitySystemComponent* ACS, UAttributeSet* AS)
{
	checkf(WidgetClass, TEXT("Overlay widget class uninitialized"))
	checkf(OverlayWidgetControllerClass, TEXT("Overlay widget controller class uninitialized"))

	// Initialize widget
	UUserWidget* Widget = CreateWidget<UUserWidget>(GetWorld(), WidgetClass);
	WidgetPtr = Cast<USafaUserWidget>(Widget);

	// Initialize Widget Controller
	const FWidgetControllerParams WidgetControllerParams(APC, PS, ACS, AS);
	UOverlayWidgetController* WidgetController = GetOverlayWidgetController(WidgetControllerParams);
	WidgetPtr->SetWidgetController(WidgetController);
	WidgetController->BroadcastInitialValues();
	
	Widget->AddToViewport();
}

UOverlayWidgetController* ASafaHUD::GetOverlayWidgetController(const FWidgetControllerParams& InWidgetControllerParams)
{
	if (OverlayWidgetController == nullptr)
	{
		OverlayWidgetController = NewObject<UOverlayWidgetController>(this, OverlayWidgetControllerClass);
		OverlayWidgetController->SetWidgetControllerParams(InWidgetControllerParams);
	}

	return OverlayWidgetController;
}


