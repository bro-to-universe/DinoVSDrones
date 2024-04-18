// Fill out your copyright notice in the Description page of Project Settings.


#include "DinoBoyPlayer.h"

// Sets default values
ADinoBoyPlayer::ADinoBoyPlayer()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	DinoComponent = CreateDefaultSubobject<UDinoComponent>(TEXT("DinoComponent"));
	CowboyComponent = CreateDefaultSubobject<UCowboyComponent>(TEXT("CowboyComponent"));
	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));
	RootComponent = StaticMeshComponent;
}

void ADinoBoyPlayer::MoveForward(float DeltaTime)
{
	FVector DirectionVector = GetActorForwardVector();
	FVector DeltaVector = DinoComponent->DinoPresentator->MovementSpeed * DeltaTime * DirectionVector;

	FVector NewLocation = GetActorLocation() + DeltaVector;
	SetActorLocation(NewLocation);
}

void ADinoBoyPlayer::RotateYaw(float Impulse)
{
	FRotator Rotation = GetActorRotation();
	Rotation.Yaw += DinoComponent->DinoPresentator->RotationSpeed * Impulse;

	SetActorRotation(Rotation);
}

// Called when the game starts or when spawned
void ADinoBoyPlayer::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADinoBoyPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ADinoBoyPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

