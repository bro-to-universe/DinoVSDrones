// Fill out your copyright notice in the Description page of Project Settings.


#include "DinoPresentatorTest.h"

bool FDinoPresentatorBaseTest::RunTest(const FString& Parameters) {
	UDinoPresentator* const DinoPresentator = NewObject<UDinoPresentator>();

	TestFalse(TEXT("DinoPresentator's bCanEverTick is disabled"), DinoPresentator->PrimaryComponentTick.bCanEverTick);

	return true;
}

bool FDinoPresentatorSpeedTest::RunTest(const FString& Parameters) {
	UDinoPresentator* const DinoPresentator = NewObject<UDinoPresentator>();

	TestEqual(TEXT("DinoPresentator Speed' type equal to float"), typeid(DinoPresentator->Speed), typeid(float));

	const float Modification = 5.f;
	const float DefaultSpeed = DinoPresentator->Speed;
	DinoPresentator->StartReactOnModification(Modification);
	TestEqual(TEXT("DinoPresentator StartReactOnModification(Modification) makes Speed equal to Speed*Modification"), DinoPresentator->Speed, DefaultSpeed*Modification);

	DinoPresentator->EndReactOnModification(Modification);
	TestEqual(TEXT("DinoPresentator EndReactOnModification(Modification) makes Speed equal to DefaultSpeed"), DinoPresentator->Speed, DefaultSpeed);

	return true;
}

bool FDinoPresentatorRoaringTest::RunTest(const FString& Parameters) {
	UDinoPresentator* const DinoPresentator = NewObject<UDinoPresentator>();

	TestEqual(TEXT("DinoPresentator IsRoaring by default equal to false"), DinoPresentator->GetRoaring(), false);

	DinoPresentator->StartRoar();
	TestEqual(TEXT("DinoPresentator StartRoar sets IsRoaring to true"), DinoPresentator->GetRoaring(), true);

	DinoPresentator->EndRoar();
	TestEqual(TEXT("DinoPresentator EndRoar sets IsRoaring to false"), DinoPresentator->GetRoaring(), false);

	return true;
}
