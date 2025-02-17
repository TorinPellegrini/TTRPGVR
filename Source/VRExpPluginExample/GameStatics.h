// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributesComponent.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "GameStatics.generated.h"


/**
 * 
 */
UCLASS()
class VREXPPLUGINEXAMPLE_API UGameStatics : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, Category = "GameStatics")
	static FAttributeChangeResult TryDamageActor(AActor* HitInstigator, AActor* Target, float Damage);

	UFUNCTION(BlueprintCallable, Category = "GameStatics")
	static FAttributeChangeResult TryHealActor(AActor* HitInstigator, AActor* Target, float HealAmount);


	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Attributes")
	static float GetPercentageOfMaxValue(const FAttribute& Attribute);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Attributes")
	static float GetCurrentAttributeValue(const FAttribute& Attribute);
};
