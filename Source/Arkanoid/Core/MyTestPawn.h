// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Ball.h"
#include "GameFramework/Pawn.h"
#include "EnhancedInput/Public/InputActionValue.h"
#include "Components/ArrowComponent.h"

#include "MyTestPawn.generated.h"

UCLASS()
class ARKANOID_API AMyTestPawn : public APawn
{
	GENERATED_BODY()

public:
	AMyTestPawn();

protected:
	// Called when the game starts or when spawned
	UPROPERTY(EditAnywhere, BlueprintReadWrite,Category = "Components")
	UStaticMeshComponent* StaticMesh = nullptr;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components")
	class UArrowComponent* Arrow = nullptr;
	UPROPERTY(EditAnywhere, Category = "EnhancedInput")
	class UInputMappingContext* InputMapping;
	UPROPERTY(EditAnywhere, Category = "EnhancedInput")
	class UInputAction* Moving;
	UPROPERTY(EditAnywhere, Category = "EnhancedInput")
	class UInputAction* Spawn;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Parameters")
	float Speed;

	void MovingInput(const FInputActionValue& Value);
	void SpawnBall();

	virtual void BeginPlay() override;

public:	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Actors")
	TSubclassOf<ABall> BallRef;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


};
