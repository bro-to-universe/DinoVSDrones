// Fill out your copyright notice in the Description page of Project Settings.


#include "CowboyComponent.h"

// Sets default values for this component's properties
UCowboyComponent::UCowboyComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	CowboyPresentator = CreateDefaultSubobject<UCowboyPresentator>(TEXT("CowboyPresentator"));

}

void UCowboyComponent::SetCatchingTime(float Time)
{
	CatchingTime = Time;
}

void UCowboyComponent::StartCatch()
{
	if (CowboyPresentator->GetAbleToCatch() && !CowboyPresentator->GetCatching()) {
		UWorld* const World = GetWorld();
		if (World) {
			CowboyPresentator->StartCatch();
			World->GetTimerManager().SetTimer(CatchTimer, this, &UCowboyComponent::EndCatch, CatchingTime, false);
		}
		else {
			UE_LOG(LogTemp, Error, TEXT("CowboyComponent:StartCatch: Couldn't get world"));
		}
	}
}

void UCowboyComponent::EndCatch()
{
	UWorld* const World = GetWorld();
	if (World) {
		CowboyPresentator->EndCatch();
		World->GetTimerManager().ClearTimer(CatchTimer);
	}
	else {
		UE_LOG(LogTemp, Error, TEXT("CowboyComponent:EndCatch: Couldn't get world"));
	}
}

// Called when the game starts
void UCowboyComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UCowboyComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}
