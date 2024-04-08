// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"

#include "DinoVSDrones/Public/DinoPresentator.h"

#include "DinoComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class DINOVSDRONES_API UDinoComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UDinoComponent();

	UFUNCTION(BlueprintCallable)
	void SetRoaringTime(float Time);

	UFUNCTION(BlueprintPure)
	bool GetSneaking();

	UFUNCTION(BlueprintCallable)
	void StartSneak();

	UFUNCTION(BlueprintCallable)
	void EndSneak();

	UFUNCTION(BlueprintCallable)
	void StartRoar();

	UFUNCTION(BlueprintCallable)
	void EndRoar();

public:

	UPROPERTY(BlueprintReadOnly)
	float RoaringTime = 5.f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UDinoPresentator* DinoPresentator;

	UPROPERTY(EditAnywhere)
	FModificationParameters ModificationSneaking = { 0.5f, 1.f };

private:

	bool IsSneaking = false;

	FTimerHandle RoarTimer;

};
