// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ModificationParameters.h"
#include "DinoPresentator.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class DINOVSDRONES_API UDinoPresentator : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UDinoPresentator();

	UFUNCTION(BlueprintCallable)
	void StartReactOnModification(FModificationParameters MP);

	UFUNCTION(BlueprintCallable)
	void EndReactOnModification(FModificationParameters MP);

	UFUNCTION(BlueprintPure)
	bool GetRoaring();

	UFUNCTION(BlueprintCallable)
	void StartRoar();

	UFUNCTION(BlueprintCallable)
	void EndRoar();

public:	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float MovementSpeed = 5.f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float RotationSpeed = 5.f;

private:

	bool IsRoaring = false;
		
};
