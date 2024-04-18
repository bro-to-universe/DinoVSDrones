#if WITH_EDITOR
#pragma once

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Tests/AutomationEditorCommon.h"

#define protected public
#include "DinoVSDrones/Public/Drone.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FDroneBaseTest, "Drone.Base", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::CriticalPriority | EAutomationTestFlags::ProductFilter);
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FDroneCaptureTest, "Drone.Capture", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::CriticalPriority | EAutomationTestFlags::ProductFilter);
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FDroneBehaviorTest, "Drone.Behavior", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::CriticalPriority | EAutomationTestFlags::ProductFilter);
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FDroneCrashTest, "Drone.Crash", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::CriticalPriority | EAutomationTestFlags::ProductFilter);
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FDroneReactOnModificationTest, "Drone.ReactOnModification", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::CriticalPriority | EAutomationTestFlags::ProductFilter);

#undef protected

#endif