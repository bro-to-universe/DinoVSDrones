// Fill out your copyright notice in the Description page of Project Settings.


#include "CowboyComponentTest.h"

bool FCowboyComponentBaseTest::RunTest(const FString& Parameters) 
{
	UCowboyComponent* const CowboyComponent = NewObject<UCowboyComponent>();

	TestEqual(TEXT("CowboyComponent bCanEverTick equal to false"), CowboyComponent->PrimaryComponentTick.bCanEverTick, false);

	return true;
}

bool FCowboyComponentCatchingTimeTest::RunTest(const FString& Parameters)
{
	UCowboyComponent* const CowboyComponent = NewObject<UCowboyComponent>();

	TestEqual(TEXT("CowboyComponent CatchingTimer by default should be float"), typeid(CowboyComponent->CatchingTime), typeid(float));

	const float CatchingTime = 10.f;
	CowboyComponent->SetCatchingTime(CatchingTime);
	TestEqual(TEXT("CowboyComponent SetCatchingTimer(x) should set CatchingTimer to x"), CowboyComponent->CatchingTime, CatchingTime);

	return true;
}
