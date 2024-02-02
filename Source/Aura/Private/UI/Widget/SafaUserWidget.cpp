// Copyright Safa


#include "UI/Widget/SafaUserWidget.h"

void USafaUserWidget::SetWidgetController(UObject* InWidgetController)
{
	WidgetController = InWidgetController;
	WidgetControllerSet();
}
