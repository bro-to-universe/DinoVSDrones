// Fill out your copyright notice in the Description page of Project Settings.


#include "CowboyPresentatorTest.h"

bool FCowboyPresentatorBaseTest::RunTest(const FString& Parameters)
{
	UCowboyPresentator* const CowboyPresentator = NewObject<UCowboyPresentator>();

	TestEqual(TEXT("CowboyPresentator bCanEverTick equal to false"), CowboyPresentator->PrimaryComponentTick.bCanEverTick, false);

	return true;
}

bool FCowboyPresentatorCatchTest::RunTest(const FString& Parameters)
{
	UCowboyPresentator* const CowboyPresentator = NewObject<UCowboyPresentator>();

	TestEqual(TEXT("CowboyPresentator default IsCatching equal to false"), CowboyPresentator->GetCatching(), false);

	CowboyPresentator->StartCatch();
	TestEqual(TEXT("CowboyPresentator->StartCatch makes IsCatching equal to true"), CowboyPresentator->GetCatching(), true);

	CowboyPresentator->EndCatch();
	TestEqual(TEXT("CowboyPresentator->EndCatch makes IsCatching equal to false"), CowboyPresentator->GetCatching(), false);

	return true;
}

bool FCowboyPresentatorAbleToCatchTest::RunTest(const FString& Parameters)
{
	UCowboyPresentator* const CowboyPresentator = NewObject<UCowboyPresentator>();

	TestEqual(TEXT("CowboyPresentator isAbleToCatch by default is false"), CowboyPresentator->GetAbleToCatch(), true);

	CowboyPresentator->DisableCatch();
	TestEqual(TEXT("CowboyPresentator isAbleToCatch after DisableCatch() equal to false"), CowboyPresentator->GetAbleToCatch(), false);

	CowboyPresentator->EnableCatch();
	TestEqual(TEXT("CowboyPresentator isAbleToCatch after EnableCatch() equal to true"), CowboyPresentator->GetAbleToCatch(), true);

	return true;
}

bool FCowboyPresentatorAbilityCatchTest::RunTest(const FString& Parameters)
{
	UCowboyPresentator* const CowboyPresentator = NewObject<UCowboyPresentator>();

	CowboyPresentator->DisableCatch();
	CowboyPresentator->StartCatch();
	TestEqual(TEXT("CowboyPresentator with initial IsCatching false, DisableCatch() and then StartCatch(), set IsCatching to false"), CowboyPresentator->GetCatching(), false);
	
	CowboyPresentator->EnableCatch();
	CowboyPresentator->StartCatch();
	TestEqual(TEXT("CowboyPresentator with initial IsCatching false, EnableCatch() and then StartCatch(), set IsCatching to true"), CowboyPresentator->GetCatching(), true);
	
	CowboyPresentator->DisableCatch();
	TestEqual(TEXT("CowboyPresentator DisableCatch() shouldn't affect on IsCatching, leave the same value (true)"), CowboyPresentator->GetCatching(), true);

	CowboyPresentator->EndCatch();
	TestEqual(TEXT("CowboyPresentator EndCatch() should work even with DisableCatch()"), CowboyPresentator->GetCatching(), false);

	return true;
}