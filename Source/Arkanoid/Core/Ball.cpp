// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/Ball.h"
#include <Kismet/KismetMathLibrary.h>

// Sets default values
ABall::ABall()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SetRootComponent(StaticMesh);
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("My Static Mesh"));

	Speed = 0;
	Direction = FVector(ForceInitToZero);

}

// Called when the game starts or when spawned
void ABall::BeginPlay()
{
	Super::BeginPlay();

	Direction = GetActorForwardVector();
	
}

void ABall::NotifyHit(UPrimitiveComponent* MyComp, AActor* Other, UPrimitiveComponent* OtherComp, bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit)
{
	Direction = UKismetMathLibrary::GetReflectionVector(Direction, Hit.Normal);
	Direction.Z = 0.0f;
	UKismetMathLibrary::Vector_Normalize(Direction);

}

void ABall::Move(float DeltaTime)
{

	AddActorWorldOffset(Direction * Speed * DeltaTime, true);
}

// Called every frame
void ABall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Move(DeltaTime); 
}

