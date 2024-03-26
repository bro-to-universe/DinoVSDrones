// Fill out your copyright notice in the Description page of Project Settings.


#include "DinoComponent.h"

// Sets default values for this component's properties
UDinoComponent::UDinoComponent() 
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
	DinoPresentator = CreateDefaultSubobject<UDinoPresentator>(TEXT("DinoPresentator"));

}

void UDinoComponent::SetRoaringTime(float Time)
{
	RoaringTime = Time;
}

bool UDinoComponent::GetSneaking()
{
	return IsSneaking;
}

void UDinoComponent::StartSneak()
{
	IsSneaking = true;
	DinoPresentator->StartReactOnModification(ModificationSneaking);
}

void UDinoComponent::EndSneak()
{
	IsSneaking = false;
	DinoPresentator->EndReactOnModification(ModificationSneaking);
}

void UDinoComponent::StartRoar()
{
	if (!DinoPresentator->GetRoaring()) {
		UWorld* const World = GetWorld();
		if (World) {
			DinoPresentator->StartRoar();
			World->GetTimerManager().SetTimer(RoarTimer, this, &UDinoComponent::StartRoar, RoaringTime, false);
		}
		else {
			UE_LOG(LogTemp, Error, TEXT("DinoComponent::StartRoar: Couldn't get world"));
		}
	}
}

void UDinoComponent::EndRoar()
{
	UWorld* const World = GetWorld();
	if (World) {
		DinoPresentator->EndRoar();
		World->GetTimerManager().ClearTimer(RoarTimer);
	}
	else {
		UE_LOG(LogTemp, Error, TEXT("DinoComponent::EndRoar: Couldn't get world"));
	}
}
