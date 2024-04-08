// Fill out your copyright notice in the Description page of Project Settings.
#if WITH_EDITOR
#pragma once

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Tests/AutomationEditorCommon.h"

#include "DinoVSDrones/Public/DinoBoyPlayer.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FDinoBoyPlayerMovementTest, "DinoBoyPlayer.Movement", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::CriticalPriority | EAutomationTestFlags::ProductFilter);
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FDinoBoyPlayerRotationTest, "DinoBoyPlayer.Rotation", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::CriticalPriority | EAutomationTestFlags::ProductFilter);

#endif