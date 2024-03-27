// Fill out your copyright notice in the Description page of Project Settings.


#include "CowboyPresentatorTest.h"

bool FCowboyPresentatorBaseTest::RunTest(const FString& Parameters)
{
	UCowboyPresentator* const CowboyPresentator = NewObject<UCowboyPresentator>();

	TestFalse(TEXT("CowboyPresentator bCanEverTick is false by default"), CowboyPresentator->PrimaryComponentTick.bCanEverTick);

	return true;
}

bool FCowboyPresentatorCatchTest::RunTest(const FString& Parameters)
{
	UCowboyPresentator* const CowboyPresentator = NewObject<UCowboyPresentator>();

	TestFalse(TEXT("CowboyPresentator IsCatching is false by default"), CowboyPresentator->GetCatching());

	CowboyPresentator->StartCatch();
	TestTrue(TEXT("CowboyPresentator->StartCatch sets IsCatching to true"), CowboyPresentator->GetCatching());

	CowboyPresentator->EndCatch();
	TestFalse(TEXT("CowboyPresentator->EndCatch sets IsCatching to false"), CowboyPresentator->GetCatching());

	return true;
}

bool FCowboyPresentatorAbleToCatchTest::RunTest(const FString& Parameters)
{
	UCowboyPresentator* const CowboyPresentator = NewObject<UCowboyPresentator>();

	TestTrue(TEXT("CowboyPresentator isAbleToCatch is true by default"), CowboyPresentator->GetAbleToCatch());

	CowboyPresentator->DisableCatch();
	TestFalse(TEXT("CowboyPresentator DisableCatch() sets isAbleToCatch to false"), CowboyPresentator->GetAbleToCatch());

	CowboyPresentator->EnableCatch();
	TestTrue(TEXT("CowboyPresentator EnableCatch() sets isAbleToCatch to true"), CowboyPresentator->GetAbleToCatch());

	return true;
}

bool FCowboyPresentatorAbilityCatchTest::RunTest(const FString& Parameters)
{
	UCowboyPresentator* const CowboyPresentator = NewObject<UCowboyPresentator>();

	CowboyPresentator->DisableCatch();
	CowboyPresentator->StartCatch();
	TestFalse(TEXT("CowboyPresentator with initial IsCatching false, DisableCatch(), StartCatch() sets IsCatching to false"), CowboyPresentator->GetCatching());
	
	CowboyPresentator->EnableCatch();
	CowboyPresentator->StartCatch();
	TestTrue(TEXT("CowboyPresentator with initial IsCatching false, EnableCatch(), StartCatch(), sets IsCatching to true"), CowboyPresentator->GetCatching());
	
	CowboyPresentator->DisableCatch();
	TestTrue(TEXT("CowboyPresentator DisableCatch() shouldn't affect on IsCatching, leave the same value (true)"), CowboyPresentator->GetCatching());

	CowboyPresentator->EndCatch();
	TestFalse(TEXT("CowboyPresentator EndCatch() should work with DisableCatch()"), CowboyPresentator->GetCatching());

	return true;
}