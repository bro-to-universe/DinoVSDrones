// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"

#include "DroneState.h"
#include "ModificationParameters.h"

#include "Drone.generated.h"

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnStateChanged, EDroneState, DroneState);

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnCaptured);

UCLASS()
class DINOVSDRONES_API ADrone : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ADrone();

	UFUNCTION(BlueprintCallable)
	void BeCaptured();

	UFUNCTION(BlueprintCallable)
	void SetBehaviorState(EDroneState DroneState);

	UFUNCTION(BlueprintCallable)
	void StartReactOnModification(FModificationParameters MP);

	UFUNCTION(BlueprintCallable)
	void EndReactOnModification(FModificationParameters MP);

	UFUNCTION(BlueprintCallable)
	void Crash();

	UPROPERTY(BlueprintAssignable)
	FOnStateChanged OnStateChanged;

	UPROPERTY(BlueprintAssignable)
	FOnCaptured OnCaptured;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	float MovementSpeed = 5.f;

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	float RotationSpeed = 5.f;
	
	UPROPERTY(BlueprintReadOnly)
	bool IsCaptured = false;

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	TEnumAsByte<EDroneState> BehaviorState = EDroneState::Crashed;

};
