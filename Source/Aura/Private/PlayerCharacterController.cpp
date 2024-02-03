// Copyright Safa


#include "PlayerCharacterController.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "Interfaces/EnemyInterface.h"

APlayerCharacterController::APlayerCharacterController()
{
	bReplicates = true;
}

void APlayerCharacterController::BeginPlay()
{
	Super::BeginPlay();

	// Setup Input Context
	check(PlayerInputContext);
	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(
		GetLocalPlayer());

	if (Subsystem)
	{
		Subsystem->AddMappingContext(PlayerInputContext, 0);
	}

	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Default;
	FInputModeGameAndUI InputMode;
	InputMode.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	InputMode.SetHideCursorDuringCapture(false);
	SetInputMode(InputMode);
}

void APlayerCharacterController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);
	CursorTrace();
}

void APlayerCharacterController::SetupInputComponent()
{
	Super::SetupInputComponent();
	
	if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent))
	{
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &APlayerCharacterController::Move);
	}
}

void APlayerCharacterController::Move(const FInputActionValue& Value)
{
	// Move logic here.
	const FVector2D InputAxisVector = Value.Get<FVector2D>();
	UE_LOG(LogTemp, Warning, TEXT("Move: %s"), *InputAxisVector.ToString());

	const FRotator Rotation = GetControlRotation();
	const FRotator YawRotation(0, Rotation.Yaw, 0);

	// Get directions by calculating the forward and right vectors.
	const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
	
	if (APawn* ControlledPawn = GetPawn<APawn>())
	{
		ControlledPawn->AddMovementInput(ForwardDirection, InputAxisVector.Y);
		ControlledPawn->AddMovementInput(RightDirection, InputAxisVector.X);
	}
}

void APlayerCharacterController::CursorTrace()
{
	FHitResult Result;
	GetHitResultUnderCursor(ECC_Visibility, false, Result);

	if (!Result.bBlockingHit) return;

	LastEnemy = CurrentEnemy;
	CurrentEnemy = Cast<IEnemyInterface>(Result.GetActor());

	// If the current enemy is different from the last enemy, unhighlight the last enemy and highlight the current enemy.
	if (CurrentEnemy != LastEnemy)
	{
		if (LastEnemy != nullptr)
		{
			LastEnemy->Unhighlight();
		}
		if (CurrentEnemy != nullptr)
		{
			CurrentEnemy->Highlight();
		}
	}
}
