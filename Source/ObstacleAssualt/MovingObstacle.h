// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingObstacle.generated.h"

UCLASS()
class OBSTACLEASSUALT_API AMovingObstacle : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMovingObstacle();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(EditAnyWhere)
		float moveDistance = 300;
	UPROPERTY(EditAnyWhere)
		FVector pos = FVector(1,0,0);		
	UPROPERTY(EditAnyWhere)
		FVector velocity = FVector(10,0,0);	

	FVector initialPos;

	void Move(float f);
	bool reachMaxPoint(FVector f);

};	
