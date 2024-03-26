// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "DinoPresentator.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class DINOVSDRONES_API UDinoPresentator : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UDinoPresentator();

	UFUNCTION(BlueprintCallable)
	void StartReactOnModification(float Modification);

	UFUNCTION(BlueprintCallable)
	void EndReactOnModification(float Modification);

	UFUNCTION(BlueprintPure)
	bool GetRoaring();

	UFUNCTION(BlueprintCallable)
	void StartRoar();

	UFUNCTION(BlueprintCallable)
	void EndRoar();

public:	
	UPROPERTY(EditAnywhere)
	float Speed = 5.f;

private:

	bool IsRoaring = false;
		
};
