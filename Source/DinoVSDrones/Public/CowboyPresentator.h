// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CowboyPresentator.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class DINOVSDRONES_API UCowboyPresentator : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UCowboyPresentator();

	UFUNCTION(BlueprintCallable)
	void StartCatch();

	UFUNCTION(BlueprintCallable)
	void EndCatch();

	UFUNCTION(BlueprintCallable)
	void DisableCatch();

	UFUNCTION(BlueprintCallable)
	void EnableCatch();

	UFUNCTION(BlueprintPure)
	bool GetCatching();

	UFUNCTION(BlueprintPure)
	bool GetAbleToCatch();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;


private:

	bool IsCatching = false;

	bool IsAbleToCatch = true;
		
};
