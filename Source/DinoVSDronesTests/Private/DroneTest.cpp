// Fill out your copyright notice in the Description page of Project Settings.


#include "DroneTest.h"


bool FDroneBaseTest::RunTest(const FString& Parameters) {
	UWorld* const World = FAutomationEditorCommonUtils::CreateNewMap();
	ADrone* const Drone = World->SpawnActor<ADrone>();

	TestEqual(TEXT("Drone's MovementSpeed type is float"), typeid(Drone->MovementSpeed), typeid(float));
	TestEqual(TEXT("Drone's RoatationSpeed type is float"), typeid(Drone->RotationSpeed), typeid(float));
	TestEqual(TEXT("Drone's IsCaptured type is bool"), typeid(Drone->IsCaptured), typeid(bool));
	TestEqual(TEXT("Drone's BehaviorState type is DroneState"), typeid(Drone->BehaviorState), typeid(TEnumAsByte<EDroneState>));

	return true;
}

bool FDroneCaptureTest::RunTest(const FString& Parameters) {
	UWorld* const World = FAutomationEditorCommonUtils::CreateNewMap();
	ADrone* const Drone = World->SpawnActor<ADrone>();

	TestFalse(TEXT("Drone's IsCaptured is equal to false by default"), Drone->IsCaptured);

	Drone->BeCaptured();
	TestTrue(TEXT("Drone's BeCaptured sets IsCaptured to true"), Drone->IsCaptured);

	return true;
}

bool FDroneBehaviorTest::RunTest(const FString& Parameters) {
	UWorld* const World = FAutomationEditorCommonUtils::CreateNewMap();
	ADrone* const Drone = World->SpawnActor<ADrone>();

	TestEqual(TEXT("Drone's BehaviorState is equal to Crashed by default"), Drone->BehaviorState, EDroneState::Crashed);

	Drone->SetBehaviorState(EDroneState::Smart);
	TestEqual(TEXT("Drone's SetBehaviorState(Smart) sets BehaviorState to Smart"), Drone->BehaviorState, EDroneState::Smart);

	Drone->SetBehaviorState(EDroneState::Uncontrolled);
	TestEqual(TEXT("Drone's SetBehaviorState(Uncontrolled) sets BehaviorState to Uncontrolled"), Drone->BehaviorState, EDroneState::Uncontrolled);

	Drone->SetBehaviorState(EDroneState::Crashed);
	TestEqual(TEXT("Drone's SetBehaviorState(Crashed) sets BehaviorState to Crashed"), Drone->BehaviorState, EDroneState::Crashed);

	return true;
}

bool FDroneCrashTest::RunTest(const FString& Parameters) {
	UWorld* const World = FAutomationEditorCommonUtils::CreateNewMap();
	ADrone* const Drone = World->SpawnActor<ADrone>();

	Drone->SetBehaviorState(EDroneState::Uncontrolled);
	Drone->Crash();
	TestEqual(TEXT("Drone Crash sets BehaviorState to Crashed"), Drone->BehaviorState, EDroneState::Crashed);

	return true;
}

bool FDroneReactOnModificationTest::RunTest(const FString& Parameters) {
	UWorld* const World = FAutomationEditorCommonUtils::CreateNewMap();
	ADrone* const Drone = World->SpawnActor<ADrone>();

	const FModificationParameters Modification = {3.f, 0.5f};
	const float DefaultMovementSpeed = Drone->MovementSpeed;
	const float DefaultRotationSpeed = Drone->RotationSpeed;

	Drone->StartReactOnModification(Modification);
	TestEqual(TEXT("Drone StartReactOnModification sets MovementSpeed to DefaultMovementSpeed*Modification.MovementSpeed"), Drone->MovementSpeed, DefaultMovementSpeed*Modification.Movement);
	TestEqual(TEXT("Drone StartReactOnModification sets RotationSpeed to DefaultRotationSpeed*Modification.RotationSpeed"), Drone->RotationSpeed, DefaultRotationSpeed*Modification.Rotation);

	Drone->EndReactOnModification(Modification);
	TestEqual(TEXT("Drone EndReactOnModification sets MovementSpeed to DefaultMovementSpeed"), Drone->MovementSpeed, DefaultMovementSpeed);
	TestEqual(TEXT("Drone EndReactOnModification sets MovementSpeed to DefaultRotationSpeed"), Drone->RotationSpeed, DefaultRotationSpeed);

	return true;
}