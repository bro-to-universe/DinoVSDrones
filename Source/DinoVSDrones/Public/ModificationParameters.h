// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "ModificationParameters.generated.h"
/**
 * 
 */
USTRUCT(BlueprintType)
struct FModificationParameters
{
	GENERATED_USTRUCT_BODY();

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float Movement;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float Rotation;

	FModificationParameters() {
		Movement = 1.f;
		Rotation = 1.f;
	}
	FModificationParameters(float MovementModification, float RotationModification) {
		Movement = MovementModification;
		Rotation = RotationModification;
	}
};
