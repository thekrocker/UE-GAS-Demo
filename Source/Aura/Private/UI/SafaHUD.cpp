// Copyright Safa


#include "UI/SafaHUD.h"
#include "Blueprint/UserWidget.h"

void ASafaHUD::BeginPlay()
{
	Super::BeginPlay();
	UUserWidget* Widget = CreateWidget<UUserWidget>(GetWorld(), WidgetClass);
	Widget->AddToViewport();
}
