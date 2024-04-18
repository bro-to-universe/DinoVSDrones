// Fill out your copyright notice in the Description page of Project Settings.


#include "Drone.h"

// Sets default values
ADrone::ADrone()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void ADrone::BeCaptured()
{
	IsCaptured = true;
	OnCaptured.Broadcast();
}

void ADrone::SetBehaviorState(EDroneState DroneState)
{
	BehaviorState = DroneState;
	OnStateChanged.Broadcast(BehaviorState);
}

void ADrone::StartReactOnModification(FModificationParameters MP)
{
	MovementSpeed *= MP.Movement;
	RotationSpeed *= MP.Rotation;
}

void ADrone::EndReactOnModification(FModificationParameters MP)
{
	MovementSpeed /= MP.Movement;
	RotationSpeed /= MP.Rotation;
}

void ADrone::Crash()
{
	SetBehaviorState(EDroneState::Crashed);
}

// Called when the game starts or when spawned
void ADrone::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADrone::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ADrone::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

