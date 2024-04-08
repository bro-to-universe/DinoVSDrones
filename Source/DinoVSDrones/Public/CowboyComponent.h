// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "EngineUtils.h"

#include "CowboyPresentator.h"

#include "CowboyComponent.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class DINOVSDRONES_API UCowboyComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UCowboyComponent();

	UFUNCTION(BlueprintCallable)
	void SetCatchingTime(float Time);

	//launch timer
	UFUNCTION(BlueprintCallable)
	void StartCatch();

	//handle timer
	UFUNCTION(BlueprintCallable)
	void EndCatch();

public:	

	UPROPERTY(BlueprintReadOnly)
	float CatchingTime = 5.f;

	UPROPERTY(BlueprintReadOnly)
	UCowboyPresentator* CowboyPresentator;

private:
	FTimerHandle CatchTimer;

};
