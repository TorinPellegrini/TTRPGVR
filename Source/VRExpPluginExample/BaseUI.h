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
	
	UPROPERTY(meta = (BindWidget))
	UTextBlock* PlayerHealth;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* MaxHP;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* PlayerArmour;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* PlayerMovement;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* ConstitutionNumber;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* DexterityNumber;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* CharismaNumber;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* WisdomNumber;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* IntelligenceNumber;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* StrengthNumber;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* PlayerName;

	UFUNCTION(BlueprintCallable)
	void FillGeneralAttributes(UAttributesComponent* PlayerAttributes, FText CharacterName, FText PlayerMovementSpeed);

	//Attacks

	UPROPERTY(meta = (BindWidget))
	UTextBlock* AttackRollText1;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* Attack1Name;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* DamageRollText1;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* AttackRollText2;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* Attack2Name;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* DamageRollText2;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* AttackRollText3;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* Attack3Name;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* DamageRollText3;

	UFUNCTION(BlueprintCallable)
	void FillAttacks(TArray<FAttackTextVariables> AttackTextVariables);
	

private:
	FText GetTextFromAttributeValue(float Value);
};
