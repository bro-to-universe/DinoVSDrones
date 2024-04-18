// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"

#include "DinoComponent.h"
#include "CowboyComponent.h"

#include "DinoBoyPlayer.generated.h"

UCLASS()
class DINOVSDRONES_API ADinoBoyPlayer : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ADinoBoyPlayer();

	UFUNCTION(BlueprintCallable)
	void MoveForward(float DeltaTime);

	UFUNCTION(BlueprintCallable)
	void RotateYaw(float Impulse);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	UDinoComponent* DinoComponent;

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	UCowboyComponent* CowboyComponent;

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	UStaticMeshComponent* StaticMeshComponent;

};
