// Fill out your copyright notice in the Description page of Project Settings.


#include "RotatingObstacle.h"

// Sets default values
ARotatingObstacle::ARotatingObstacle()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ARotatingObstacle::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ARotatingObstacle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	rotate(DeltaTime);

}
void ARotatingObstacle::rotate(float f) 
{
	FRotator temp = FRotator(targetRotation.X, targetRotation.Y, targetRotation.Z);
	AddActorLocalRotation(temp * f);
}