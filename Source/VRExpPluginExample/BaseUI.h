// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributesComponent.h"
#include "VRExpPluginExample.h"
#include "Blueprint/UserWidget.h"
#include "Components/TextBlock.h"
#include "BaseUI.generated.h"

/**
 * 
 */
UCLASS()
class VREXPPLUGINEXAMPLE_API UBaseUI : public UUserWidget
{
	GENERATED_BODY()
public:
	//General Attributes
	
	UPROPERTY(meta = (BindWidget), BlueprintReadWrite)
	UTextBlock* PlayerHealth;

	UPROPERTY(meta = (BindWidget), BlueprintReadWrite)
	UTextBlock* MaxHP;

	UPROPERTY(meta = (BindWidget), BlueprintReadWrite)
	UTextBlock* PlayerArmour;

	UPROPERTY(meta = (BindWidget), BlueprintReadWrite)
	UTextBlock* PlayerMovement;

	UPROPERTY(meta = (BindWidget), BlueprintReadWrite)
	UTextBlock* ConstitutionNumber;

	UPROPERTY(meta = (BindWidget), BlueprintReadWrite)
	UTextBlock* DexterityNumber;

	UPROPERTY(meta = (BindWidget), BlueprintReadWrite)
	UTextBlock* CharismaNumber;

	UPROPERTY(meta = (BindWidget), BlueprintReadWrite)
	UTextBlock* WisdomNumber;

	UPROPERTY(meta = (BindWidget), BlueprintReadWrite)
	UTextBlock* IntelligenceNumber;

	UPROPERTY(meta = (BindWidget), BlueprintReadWrite)
	UTextBlock* StrengthNumber;

	UPROPERTY(meta = (BindWidget), BlueprintReadWrite)
	UTextBlock* PlayerName;

	UFUNCTION(BlueprintCallable)
	void FillGeneralAttributes(UAttributesComponent* PlayerAttributes, FText CharacterName, FText PlayerMovementSpeed);

	//Attacks

	UPROPERTY(meta = (BindWidget), BlueprintReadWrite)
	UTextBlock* AttackRollText1;

	UPROPERTY(meta = (BindWidget), BlueprintReadWrite)
	UTextBlock* Attack1Name;

	UPROPERTY(meta = (BindWidget), BlueprintReadWrite)
	UTextBlock* DamageRollText1;

	UPROPERTY(meta = (BindWidget), BlueprintReadWrite)
	UTextBlock* AttackRollText2;

	UPROPERTY(meta = (BindWidget), BlueprintReadWrite)
	UTextBlock* Attack2Name;

	UPROPERTY(meta = (BindWidget), BlueprintReadWrite)
	UTextBlock* DamageRollText2;

	UPROPERTY(meta = (BindWidget), BlueprintReadWrite)
	UTextBlock* AttackRollText3;

	UPROPERTY(meta = (BindWidget), BlueprintReadWrite)
	UTextBlock* Attack3Name;

	UPROPERTY(meta = (BindWidget), BlueprintReadWrite)
	UTextBlock* DamageRollText3;

	UFUNCTION(BlueprintCallable)
	void FillAttacks(TArray<FAttackTextVariables> AttackTextVariables);
	

private:
	FText GetTextFromAttributeValue(float Value);
};
