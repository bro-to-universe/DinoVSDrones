// Fill out your copyright notice in the Description page of Project Settings.

#if WITH_EDITOR
#pragma once

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Tests/AutomationEditorCommon.h"

#include "DinoVSDrones/Public/CowboyPresentator.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FCowboyPresentatorBaseTest, "CowboyPresentator.Base", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::CriticalPriority | EAutomationTestFlags::ProductFilter);
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FCowboyPresentatorCatchTest, "CowboyPresentator.Catch", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::CriticalPriority | EAutomationTestFlags::ProductFilter);
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FCowboyPresentatorAbleToCatchTest, "CowboyPresentator.AbleToCatch", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::CriticalPriority | EAutomationTestFlags::ProductFilter);
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FCowboyPresentatorAbilityCatchTest, "CowboyPresentator.AbilityCatch", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::CriticalPriority | EAutomationTestFlags::ProductFilter);

#endif