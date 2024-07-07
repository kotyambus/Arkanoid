// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/CubeSpawner.h"

// Sets default values
ACubeSpawner::ACubeSpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SizeX = 5;
	SizeY = 5;
	Padding = 1.0;

}

// Called when the game starts or when spawned
void ACubeSpawner::BeginPlay()
{
	Super::BeginPlay();

	Spawn();
	
}

// Called every frame
void ACubeSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACubeSpawner::Spawn()
{
	FVector Location = GetActorLocation();
	FVector CenterOffset = FVector((SizeX - 1) * Padding * 0.5f, (SizeY - 1) * Padding * 0.5f, 0.f);

	for (int32 i = 0; i < SizeX; i++)
	{
		for (int32 j = 0; j < SizeY; j++)
		{
			const FVector SpawnLocation = Location + FVector(Padding * i, Padding * j, 0.f) - CenterOffset;
			GetWorld()->SpawnActor<AActor>(CubeToSpawn, FTransform(SpawnLocation));
		}
	}
}

