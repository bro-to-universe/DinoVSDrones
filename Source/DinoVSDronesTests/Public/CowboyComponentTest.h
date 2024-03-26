// Fill out your copyright notice in the Description page of Project Settings.

#if WITH_EDITOR
#pragma once

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Tests/AutomationEditorCommon.h"

#include "DinoVSDrones/Public/CowboyComponent.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FCowboyComponentBaseTest, "CowboyComponent.Base", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::CriticalPriority | EAutomationTestFlags::ProductFilter);
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FCowboyComponentCatchingTimeTest, "CowboyComponent.CatchingTime", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::CriticalPriority | EAutomationTestFlags::ProductFilter);

#endif