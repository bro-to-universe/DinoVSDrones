// Fill out your copyright notice in the Description page of Project Settings.


#include "DinoComponentTest.h"

bool FDinoComponentBaseTest::RunTest(const FString& Parameters) {
	UDinoComponent* const DinoComponent = NewObject<UDinoComponent>();

	TestFalse(TEXT("DinoComponent bCanEverTick is false by default"), DinoComponent->PrimaryComponentTick.bCanEverTick);

	return true;
}

bool FDinoComponentSneakingTest::RunTest(const FString& Parameters) {
	UDinoComponent* const DinoComponent = NewObject<UDinoComponent>();
	const float DefaultMovementSpeed = DinoComponent->DinoPresentator->MovementSpeed;
	const float DefaultRotationSpeed = DinoComponent->DinoPresentator->RotationSpeed;
	const FModificationParameters ModificationSneaking = DinoComponent->ModificationSneaking;

	TestFalse(TEXT("DinoComponent IsSneaking is false by default"), DinoComponent->GetSneaking());

	DinoComponent->StartSneak();
	TestTrue(TEXT("DinoComponent StartSneak sets IsSneaking to true"), DinoComponent->GetSneaking());
	TestEqual(TEXT("DinoComponent StartSneak sets MovementSpeed to DefaultMovementSpeed*ModificationSneaking"), DinoComponent->DinoPresentator->MovementSpeed, DefaultMovementSpeed*ModificationSneaking.Movement);
	TestEqual(TEXT("DinoComponent StartSneak sets RotationSpeed to DefaultRotationSpeed*ModificationSneaking"), DinoComponent->DinoPresentator->RotationSpeed, DefaultRotationSpeed*ModificationSneaking.Rotation);

	DinoComponent->EndSneak();
	TestFalse(TEXT("DinoComponent EndSneak sets IsSneaking to false"), DinoComponent->GetSneaking());
	TestEqual(TEXT("DinoComponent EndSneak sets MovementSpeed to DefaultMovementSpeed"), DinoComponent->DinoPresentator->MovementSpeed, DefaultMovementSpeed);
	TestEqual(TEXT("DinoComponent EndSneak sets RotationSpeed to DefaultRotationSpeed"), DinoComponent->DinoPresentator->RotationSpeed, DefaultRotationSpeed);

	return true;
}

bool FDinoComponentRoaringTimeTest::RunTest(const FString& Parameters) {
	UDinoComponent* const DinoComponent = NewObject<UDinoComponent>();

	TestEqual(TEXT("DinoComponent RoaringTime type is float"), typeid(DinoComponent->RoaringTime), typeid(float));

	const float RoaringTime = 10.f;
	DinoComponent->SetRoaringTime(RoaringTime);
	TestEqual(TEXT("DinoComponent SetRoaringTime(RT) sets RoaringTime to RoaringTime"), DinoComponent->RoaringTime, RoaringTime);

	return true;
}