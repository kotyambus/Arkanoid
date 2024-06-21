// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "Ball.generated.h"

UCLASS()
class ARKANOID_API ABall : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABall();


protected:
	// Called when the game starts or when spawned

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components")
	UStaticMeshComponent* StaticMesh = nullptr;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Parameters")
	float Speed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Parameters")
	FVector Direction;

	virtual void BeginPlay() override;
	virtual void NotifyHit(UPrimitiveComponent* MyComp, AActor* Other, 
		UPrimitiveComponent* OtherComp, bool bSelfMoved, FVector HitLocation, FVector HitNormal, 
		FVector NormalImpulse, const FHitResult& Hit) override;

	void Move(float DeltaTime);



public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
