// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingObstacle.h"

// Sets default values
AMovingObstacle::AMovingObstacle()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMovingObstacle::BeginPlay()
{
	Super::BeginPlay();
	initialPos = GetActorLocation();
	FString tempString = GetActorNameOrLabel();
	//UE_LOG(LogTemp, Error, TEXT("Actor name is : %s"),*tempString);

	int32 temp = 5;
	UE_LOG(LogTemp, Error, TEXT("Name is %s Actor name is : %d"),*tempString,temp);
	//UE_LOG(LogTemp,Error,TEXT("Helloo"));
}

// Called every frame
void AMovingObstacle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);		
	Move(DeltaTime);
}
void AMovingObstacle::Move(float deltaTime) 
{
	FVector currentPos = GetActorLocation();
	currentPos = currentPos + (velocity * deltaTime);
	SetActorLocation(currentPos);
	
	if (reachMaxPoint(currentPos))
	{
		FVector moveDir = velocity.GetSafeNormal();
		initialPos = initialPos + moveDir * moveDistance;
		SetActorLocation(initialPos);
		velocity = -velocity;

	}

}

bool AMovingObstacle::reachMaxPoint(FVector f)
{

	float dist = FVector::Dist(initialPos, f);
	return dist > moveDistance?true:false;

}