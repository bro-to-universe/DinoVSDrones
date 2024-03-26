// Fill out your copyright notice in the Description page of Project Settings.

#if WITH_EDITOR
#pragma once

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Tests/AutomationEditorCommon.h"

#include "DinoVSDrones/Public/DinoPresentator.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FDinoPresentatorBaseTest, "DinoPresentator.Base", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::CriticalPriority | EAutomationTestFlags::ProductFilter);
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FDinoPresentatorSpeedTest, "DinoPresentator.Speed", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::CriticalPriority | EAutomationTestFlags::ProductFilter);
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FDinoPresentatorRoaringTest,  "DinoPresentator.Roaring", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::CriticalPriority | EAutomationTestFlags::ProductFilter);

#endif