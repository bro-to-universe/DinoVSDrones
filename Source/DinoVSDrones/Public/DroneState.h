
#pragma once

#include "CoreMinimal.h"
#include "UObject/ObjectMacros.h"
#include "DroneState.generated.h"

/**
 *
 */
UENUM(BlueprintType)
enum EDroneState: uint8
{
	Crashed UMETA(DisplayName = "Crashed"),
	Uncontrolled UMETA(DisplayName = "Uncontrolled"),
	Smart UMETA(DisplayName = "Smart"),
	MAX UMETA(Hidden)
};
