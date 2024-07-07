// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/MyTestPawn.h"
#include "InputMappingContext.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"

// Sets default values
AMyTestPawn::AMyTestPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SetRootComponent(StaticMesh);
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("My Static Mesh"));
	Arrow = CreateDefaultSubobject<UArrowComponent>(TEXT("Ok"));
	Arrow->SetupAttachment(StaticMesh);

	Speed = 500;
}

void AMyTestPawn::MovingInput(const FInputActionValue& Value)
{
	float Direction = Value.Get<float>();
	AddActorWorldOffset(FVector(0, Direction, 0) * Speed, true);
}

void AMyTestPawn::SpawnBall()
{
	FVector SpawnLocation = Arrow->GetComponentLocation();
	FRotator SpawnRotation = Arrow->GetComponentRotation();

	auto SpawnedBall = GetWorld()->SpawnActor<ABall>(BallRef, SpawnLocation, SpawnRotation);
	SpawnedBall->SetOwner(this);


}

// Called when the game starts or when spawned
void AMyTestPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyTestPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyTestPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (APlayerController* PlayerController = Cast<APlayerController>(Controller))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(InputMapping, 0);
		}
	}
	if (UEnhancedInputComponent* Input = CastChecked<UEnhancedInputComponent>(PlayerInputComponent))
	{
		Input->BindAction(Moving, ETriggerEvent::Triggered, this, &AMyTestPawn::MovingInput);
		Input->BindAction(Spawn, ETriggerEvent::Started, this, &AMyTestPawn::SpawnBall);

	}
}

