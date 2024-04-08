// Fill out your copyright notice in the Description page of Project Settings.


#include "DinoPresentatorTest.h"

bool FDinoPresentatorBaseTest::RunTest(const FString& Parameters) {
	UDinoPresentator* const DinoPresentator = NewObject<UDinoPresentator>();

	TestFalse(TEXT("DinoPresentator's bCanEverTick is false"), DinoPresentator->PrimaryComponentTick.bCanEverTick);

	return true;
}

bool FDinoPresentatorSpeedTest::RunTest(const FString& Parameters) {
	UDinoPresentator* const DinoPresentator = NewObject<UDinoPresentator>();

	TestEqual(TEXT("DinoPresentator MovementSpeed type is float"), typeid(DinoPresentator->MovementSpeed), typeid(float));

	const FModificationParameters Modification = {5.f, 5.f};
	const float DefaultMovementSpeed = DinoPresentator->MovementSpeed;
	const float DefaultRotationSpeed = DinoPresentator->RotationSpeed;
	DinoPresentator->StartReactOnModification(Modification);
	TestEqual(TEXT("DinoPresentator StartReactOnModification(Modification) sets MovementSpeed to MovementSpeed*Modification"), DinoPresentator->MovementSpeed, DefaultMovementSpeed*Modification.Movement);
	TestEqual(TEXT("DinoPresentator StartReactOnModification(Modification) sets RotationSpeed to RotationSpeed*Modification"), DinoPresentator->RotationSpeed, DefaultRotationSpeed * Modification.Rotation);

	DinoPresentator->EndReactOnModification(Modification);
	TestEqual(TEXT("DinoPresentator EndReactOnModification(Modification) sets MovementSpeed to DefaultMovementSpeed"), DinoPresentator->MovementSpeed, DefaultMovementSpeed);
	TestEqual(TEXT("DinoPresentator EndReactOnModification(Modification) sets RotationSpeed to DefaultRotationSpeed"), DinoPresentator->RotationSpeed, DefaultRotationSpeed);

	return true;
}

bool FDinoPresentatorRoaringTest::RunTest(const FString& Parameters) {
	UDinoPresentator* const DinoPresentator = NewObject<UDinoPresentator>();

	TestFalse(TEXT("DinoPresentator IsRoaring is false by default"), DinoPresentator->GetRoaring());

	DinoPresentator->StartRoar();
	TestTrue(TEXT("DinoPresentator StartRoar sets IsRoaring to true"), DinoPresentator->GetRoaring());

	DinoPresentator->EndRoar();
	TestFalse(TEXT("DinoPresentator EndRoar sets IsRoaring to false"), DinoPresentator->GetRoaring());

	return true;
}
