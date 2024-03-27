// Fill out your copyright notice in the Description page of Project Settings.


#include "CowboyComponentTest.h"

bool FCowboyComponentBaseTest::RunTest(const FString& Parameters) 
{
	UCowboyComponent* const CowboyComponent = NewObject<UCowboyComponent>();

	TestFalse(TEXT("CowboyComponent bCanEverTick is false by default"), CowboyComponent->PrimaryComponentTick.bCanEverTick);

	return true;
}

bool FCowboyComponentCatchingTimeTest::RunTest(const FString& Parameters)
{
	UCowboyComponent* const CowboyComponent = NewObject<UCowboyComponent>();

	TestEqual(TEXT("CowboyComponent CatchingTimer type is float"), typeid(CowboyComponent->CatchingTime), typeid(float));

	const float CatchingTime = 10.f;
	CowboyComponent->SetCatchingTime(CatchingTime);
	TestEqual(TEXT("CowboyComponent SetCatchingTimer(x) sets CatchingTimer to x"), CowboyComponent->CatchingTime, CatchingTime);

	return true;
}
