// Fill out your copyright notice in the Description page of Project Settings.


#include "DinoBoyPlayerTest.h"

bool FDinoBoyPlayerMovementTest::RunTest(const FString& Parameters) {
	UWorld* World = FAutomationEditorCommonUtils::CreateNewMap();
	ADinoBoyPlayer* Player = World->SpawnActor<ADinoBoyPlayer>();

	const FVector ZeroVector = FVector::ZeroVector;
	Player->SetActorLocation(ZeroVector);
	const float MovementSpeed = Player->DinoComponent->DinoPresentator->MovementSpeed;
	const float DeltaTime = 1.f;
	FVector DirectionVector = Player->GetActorForwardVector();
	DirectionVector.Normalize();

	FVector NewLocation = ZeroVector + DirectionVector * MovementSpeed * DeltaTime;
	FVector ActorLocation = Player->GetActorLocation();
	Player->MoveForward(DeltaTime);
	ActorLocation = Player->GetActorLocation();
	TestEqual("DinoBoyPlayer MoveForward(DeltaTime=1.f) sets zero ActorLocation to Speed*DirectionVector*DeltaTime", Player->GetActorLocation(), NewLocation);

	const FVector RandomVector = { 2, 21, 1 };
	Player->SetActorLocation(RandomVector);
	NewLocation = RandomVector + DirectionVector * MovementSpeed * DeltaTime;
	Player->MoveForward(DeltaTime);
	TestEqual("DinoBoyPlayer MoveForward(DeltaTime=1.f) sets RandomLocation to RandomLocation+Speed*DirectionVector*DeltaTime", Player->GetActorLocation(), NewLocation);

	return true;
}

bool FDinoBoyPlayerRotationTest::RunTest(const FString& Parameters) {
	UWorld* const World = FAutomationEditorCommonUtils::CreateNewMap();
	ADinoBoyPlayer* const Player = World->SpawnActor<ADinoBoyPlayer>();

	const FRotator ZeroRotation = { 0.f, 0.f, 0.f };
	Player->SetActorRotation(ZeroRotation);
	const float Impulse = 1.f;
	const float RotationSpeed = Player->DinoComponent->DinoPresentator->RotationSpeed;

	FRotator NewRotation = ZeroRotation;
	NewRotation.Yaw += RotationSpeed * Impulse;
	Player->RotateYaw(Impulse);
	TestEqual("DinoBoyPlayer RotateYaw(Impulse=1.f) sets zero Yaw to RotationSpeed*DeltaTime", Player->GetActorRotation(), NewRotation);

	const FRotator RandomRotation = { 2, 21, 1 };
	Player->SetActorRotation(RandomRotation);
	NewRotation = RandomRotation;
	NewRotation.Yaw += RotationSpeed * Impulse;
	Player->RotateYaw(Impulse);
	TestEqual("DinoBoyPlayer RotateYaw(Impulse=1.f) sets", Player->GetActorRotation(), NewRotation);

	return true;
}