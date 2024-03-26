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

void UDinoPresentator::StartReactOnModification(float Modification)
{
	Speed *= Modification;
}

void UDinoPresentator::EndReactOnModification(float Modification)
{
	Speed /= Modification;
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
