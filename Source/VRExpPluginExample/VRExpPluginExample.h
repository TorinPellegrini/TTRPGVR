// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine.h"
#include "CoreMinimal.h"
#include "VRExpPluginExample.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(TTRPGLog, Log, All);

USTRUCT(BlueprintType)
struct FAttackTextVariables
{
	GENERATED_BODY()
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FText AttackRollText;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FText AttackNameText;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FText DamageRollText;
};
