// Fill out your copyright notice in the Description page of Project Settings.


#include "DinoPresentator.h"

// Sets default values for this component's properties
UDinoPresentator::UDinoPresentator()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}

void UDinoPresentator::StartReactOnModification(FModificationParameters MP)
{
	MovementSpeed *= MP.Movement;
	RotationSpeed *= MP.Rotation;
}

void UDinoPresentator::EndReactOnModification(FModificationParameters MP)
{
	MovementSpeed /= MP.Movement;
	RotationSpeed /= MP.Rotation;
}

bool UDinoPresentator::GetRoaring()
{
	return IsRoaring;
}

void UDinoPresentator::StartRoar()
{
	IsRoaring = true;
}

void UDinoPresentator::EndRoar()
{
	IsRoaring = false;
}
