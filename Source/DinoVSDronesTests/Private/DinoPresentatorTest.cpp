// Fill out your copyright notice in the Description page of Project Settings.


#include "DinoPresentatorTest.h"

bool FDinoPresentatorBaseTest::RunTest(const FString& Parameters) {
	UDinoPresentator* const DinoPresentator = NewObject<UDinoPresentator>();

	TestFalse(TEXT("DinoPresentator's bCanEverTick is false"), DinoPresentator->PrimaryComponentTick.bCanEverTick);

	return true;
}

bool FDinoPresentatorSpeedTest::RunTest(const FString& Parameters) {
	UDinoPresentator* const DinoPresentator = NewObject<UDinoPresentator>();

	TestEqual(TEXT("DinoPresentator Speed type is float"), typeid(DinoPresentator->Speed), typeid(float));

	const float Modification = 5.f;
	const float DefaultSpeed = DinoPresentator->Speed;
	DinoPresentator->StartReactOnModification(Modification);
	TestEqual(TEXT("DinoPresentator StartReactOnModification(Modification) sets Speed to Speed*Modification"), DinoPresentator->Speed, DefaultSpeed*Modification);

	DinoPresentator->EndReactOnModification(Modification);
	TestEqual(TEXT("DinoPresentator EndReactOnModification(Modification) sets Speed to DefaultSpeed"), DinoPresentator->Speed, DefaultSpeed);

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
