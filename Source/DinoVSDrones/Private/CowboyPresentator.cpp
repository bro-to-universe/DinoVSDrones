// Fill out your copyright notice in the Description page of Project Settings.


#include "CowboyPresentator.h"

// Sets default values for this component's properties
UCowboyPresentator::UCowboyPresentator()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}

void UCowboyPresentator::StartCatch()
{
	if (IsAbleToCatch)
	{
		IsCatching = true;
	}
}

void UCowboyPresentator::EndCatch()
{
	IsCatching = false;
}

void UCowboyPresentator::DisableCatch()
{
	IsAbleToCatch = false;
}

void UCowboyPresentator::EnableCatch()
{
	IsAbleToCatch = true;
}

bool UCowboyPresentator::GetCatching()
{
	return IsCatching;
}

bool UCowboyPresentator::GetAbleToCatch()
{
	return IsAbleToCatch;
}

// Called when the game starts
void UCowboyPresentator::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UCowboyPresentator::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

