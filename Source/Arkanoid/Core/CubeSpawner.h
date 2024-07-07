// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Cube.h"

#include "CubeSpawner.generated.h"

UCLASS()
class ARKANOID_API ACubeSpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACubeSpawner();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Params")
	int32 SizeX;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Params")
	int32 SizeY;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Params")
	float Padding;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Actors")
	TSubclassOf<ACube> CubeToSpawn;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void Spawn();
};
